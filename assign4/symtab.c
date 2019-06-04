/* 
 * Joel Doumit
 * symtab.c
 * derived from from Dr. J's symtab.c
 * http://www2.cs.uidaho.edu/~jeffery/courses/445/symtab.c
 */

/*
 * The functions in this file maintain a hash table of strings
 *   and manage string buffers.  String buffers are large
 *   contiguous blocks of memory used to store many strings,
 *   to avoid the overhead cost associated with using malloc(3)
 *   for thousands of tiny allocations.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "tree.h"
#include "type.h"
#include "symtab.h"
#include "defines.h"
#include "g0gram.tab.h"

void dovariabledeclarator(nodeptr n, typeptr t);
void semanticerror(char *s, nodeptr n);
extern int errors;
extern int nerrors;
extern int yyerror();

#define SBufSize 1024               /* initial size of the string buffer */

/*
 * str_buf references a string buffer. Strings are built a
 *  character at a time. When a buffer "fragment" is filled,
 *  another is allocated and the the current string copied to it.
 */
struct str_buf_frag {
   struct str_buf_frag *next;     /* next buffer fragment */
   char s[1];                     /* variable size buffer */
   };

struct str_buf {
   unsigned int size;             /* total size of current buffer */
   char *p;                       /* next free character in buffer */
   char *end;                     /* end of current buffer */
   struct str_buf_frag *frag_lst; /* list of buffer fragments */
   };

static struct str_buf buf;
SymbolTable stringpool;
SymbolTable globals;
SymbolTable current;

void init_sbuf(struct str_buf *);   /* initialize an sbuf struct */
void clear_sbuf(struct str_buf *);  /* free struct buffer storage */
void new_sbuf(struct str_buf *);    /* allocate add'l buffer */
char *alloc(int n);		    /* calloc + check for NULL */


/*
 * new_st - construct symbol (hash) table.
 *  Allocate space first for the structure, then
 *  for the array of buckets.
 */
SymbolTable new_st(int nbuckets)
   {
   //int h;
   SymbolTable rv;
   rv = (SymbolTable) alloc(sizeof(struct sym_table));
   rv->tbl = (struct sym_entry **)
      alloc((unsigned int)(nbuckets * sizeof(struct sym_entry *)));
   rv->nBuckets = nbuckets;
   rv->nEntries = 0;
   if (buf.frag_lst == NULL) {
      init_sbuf(&buf);
      stringpool = new_st(149);
      }
   return rv;
   }

/*
 * delete_st - destruct symbol table.
 */
void delete_st(SymbolTable st)
   {
   SymbolTableEntry se, se1;
   int h;

   for (h = 0; h < st->nBuckets; ++h)
      for (se = st->tbl[h]; se != NULL; se = se1) {
         se1 = se->next;
         free((char *)se);
         }
   free((char *)st);
   }

/*
 * init_sbuf - initialize a new sbuf struct, allocating an initial buffer.
 */
void init_sbuf(struct str_buf *sbuf)
   {
   sbuf->size = SBufSize;
   sbuf->frag_lst = (struct str_buf_frag *)alloc((unsigned int)
       (sizeof(struct str_buf_frag) + (SBufSize - 1)));
   sbuf->frag_lst->next = NULL;
   sbuf->p = sbuf->frag_lst->s;
   sbuf->end = sbuf->p + SBufSize;
   }

/*
 * clear_sbuf - free string buffer storage.
 */
void clear_sbuf(struct str_buf *sbuf)
   {
   struct str_buf_frag *sbf, *sbf1;

   for (sbf = sbuf->frag_lst; sbf != NULL; sbf = sbf1) {
      sbf1 = sbf->next;
      free((char *)sbf);
      }
   sbuf->frag_lst = NULL;
   sbuf->p = NULL;
   sbuf->end = NULL;
   }

/*
 * new_sbuf - allocate a new buffer for a sbuf struct, copying the
 *   partially created string from the end of full buffer to the new one.
 */
void new_sbuf(struct str_buf *sbuf)
   {
   struct str_buf_frag *sbf;
   //char *s1, *s2;

   /*
    * The new buffer is larger than the old one to insure that any
    *  size string can be buffered.
    */
   sbuf->size *= 2;
   sbf = (struct str_buf_frag *)alloc((unsigned int)
       (sizeof(struct str_buf_frag) + (sbuf->size - 1)));
   sbf->next = sbuf->frag_lst;
   sbuf->frag_lst = sbf;
   sbuf->p = sbf->s;
   sbuf->end = sbuf->p + sbuf->size;
   }

static char *insert_sbuf(struct str_buf *sb, char *s)
{
   char *rv;
   int l = strlen(s);
   if (sb->p + l + 1 >= sb->end)
      new_sbuf(sb);
   strcpy(sb->p, s);
   rv = sb->p;
   sb->p += l + 1;
   return rv;
}

/*
 * Compute hash value.
 */
int hash(SymbolTable st, char *s)
{
   register int h = 0;
   register char c;
   while ((c = *s++)) {
      h += c & 0377;
      h *= 37;
      }
   if (h < 0) h = -h;
   return h % st->nBuckets;
}

/*
 * install_sym - install a symbol.
 *  - this is for entering strings in the string pool
 *  - find out if the string at the end of the buffer is in
 *   the string table. If not, put it there. Return a pointer
 *   to the string in the table.
 */
char * install_sym(SymbolTable st, char *s, typeptr t)
   {
   //register int i;
   int h;
   struct sym_entry *se;
   //int l;

   h = hash(st, s);
   for (se = st->tbl[h]; se != NULL; se = se->next)
      if (!strcmp(s, se->s)) {
         /*
          * A copy of the string is already in the table.
          */
         return se->s;
         }

   /*
    * The string is not in the table. Add the copy from the
    *  buffer to the table.
    */
   se = (SymbolTableEntry)alloc((unsigned int) sizeof (struct sym_entry));
   se->next = st->tbl[h];
   st->tbl[h] = se;
   if (st == stringpool) se->s = insert_sbuf(&buf, s);
   else se->s = s;
   se->type = t;
   st->nEntries++;
   return se->s;
   }

/*
 * insert_stringpool - install a symbol in the global table.
 *  - find out if the string at the end of the buffer is in
 *   the string table. If not, put it there. Return a pointer
 *   to the string in the table.
 */
char * insert_stringpool(char *s)
   {
      return install_sym(stringpool, s, NULL);
   }

int insert_sym(SymbolTable st, char *s, typeptr t)
{
   //register int i;
   int h;
   struct sym_entry *se;
   //int l;

   h = hash(st, s);
   for (se = st->tbl[h]; se != NULL; se = se->next)
      if (!strcmp(s, se->s)) {
         /*
          * A copy of the string is already in the table.
          */
         return 0;
         }

   /*
    * The string is not in the table. Add the copy from the
    *  buffer to the table.
    */
   se = (SymbolTableEntry)alloc((unsigned int) sizeof (struct sym_entry));
   se->next = st->tbl[h];
   se->table = st;
   st->tbl[h] = se;
   if (st == stringpool) se->s = insert_sbuf(&buf, s);
   else se->s = s;
   se->type = t;
   st->nEntries++;
   return 1;
}

/*
 * lookup_st - search the symbol table for a given symbol, return its entry.
 */
SymbolTableEntry lookup_st(SymbolTable st, char *s)
   {
   //register int i;
   int h;
   SymbolTableEntry se;

   h = hash(st, s);
   for (se = st->tbl[h]; se != NULL; se = se->next)
      if (!strcmp(s, se->s)) {
         /*
          *  Return a pointer to the symbol table entry.
          */
         return se;
         }
   return NULL;
   }

char * alloc(int n)
{
   char *a = calloc(n, sizeof(char));
   if (a == NULL) {
      fprintf(stderr, "alloc(%d): out of memory\n", (int)n);
      exit(-1);
      }
   return a;
}

void semanticerror(char *s, nodeptr n)
{
   while (n && (n->n > 0)) n=n->kids[0];
   if (n) {
     fprintf(stderr, "%s:%d: ", n->leaf->filename, n->leaf->lineno);
   }
  fprintf(stderr, "%s", s);
  if (n && n->prodrule == IDENT) fprintf(stderr, " %s", n->leaf->text);
  fprintf(stderr, "\n");
}

void error(char *s, nodeptr t)
{
   while (t->prodrule < 1000 && t->n > 0) t = t->kids[0];
   yylval.t = t;
   yyerror(s);
}

void warn(char *s, nodeptr t)
{
   char tmp[128];
   sprintf(tmp, "warning: %s", s);
   error(tmp, t);
   //nerrors--; /* since yyerror() in this example would increment nerrors */
}

/*
 * given a (sub)tree for some function header, find its name.
 * Different subtree shapes will have the identifier in different spots.
 * Can walk the tree via recursion, but this function updates "t" locally
 * and iterates.
 */
char *get_funcname(nodeptr t)
{
   int seenfunc = 0;
   while (1) {
      switch (t->prodrule) {
      case IDENT:
   if (seenfunc) return t->type;
         return NULL;
      case METHODDEC_ER1:
   warn("pointers not implemented", t);
   t = t->kids[1]; break;
      case METHOD_DECL1:
   t = t->kids[0]; break;
      case METHOD_HEAD1:
   /* now we have seen function syntax, want the ident */
         seenfunc = 1;
   t = t->kids[0]; break;
         break;
      default:
   error("get_funcname called on non-functiony subtree", t);
   /* may want to sprintf in order to print the t->prodrule on this */
   return NULL;
   }
      }
}

/*
 * what-all should be done automatically when a new scope is entered?
 * mainly we are creating a new empty local symbol table.
 * but if we are entering this function/method/class type into the global
 * symbol table, someone has to extract its signature
 */

void enter_newscope(char *s, int typ)
{
  SymbolTable new = new_st(13);
  typeptr t;
  t = (typ==CLASS_TYPE) ? alcclasstype(s, new):alcmethodtype(NULL,NULL,new);
  new->scope = t;
  insert_sym(current, s, t);
  pushscope(new);
}

/*
 * Having defined a struct or class for type representation, someone
 * has to constuct those types from information given in parse tree nodes.
 */
typeptr synthesize_type(nodeptr t) // keep
{
   int i;
   typeptr t1;

   if (t == NULL) return error_typeptr;

   if (t->type && t->type != error_typeptr)
   {
    return t->type;
   }

   if (!(t->leaf)) {
      switch(t->prodrule) {
        case LOCVAR_DECL1: {
          // We're cool, move on.
        break;
      }
      case CLASS_DECL1: {
        break;
      }

        case SIMPLE_NAME /*SIMPLENAME*/: {
        SymbolTableEntry ste = NULL;
        SymbolTable st = current;
        do {
      ste = lookup_st(st, t->kids[0]->leaf->text);
      st = st->parent;
        } while (!ste && st);
         if (!ste) { semanticerror("undeclared name", t->kids[0]); }
         else {
      t->type = ste->type;
      return ste->type;
      }
        }

        case RELATIONAL_EXPR2:
        case RELATIONAL_EXPR3:
        case RELATIONAL_EXPR4:
        case RELATIONAL_EXPR5: {
          if((synthesize_type(t->kids[0]) != integer_typeptr &&
           synthesize_type(t->kids[0]) != double_typeptr) || 
            (synthesize_type(t->kids[1]) != integer_typeptr &&
              synthesize_type(t->kids[1]) != double_typeptr))
              {
                semanticerror("Type error", t);
                return error_typeptr;
              } 
              else
              {
                t->type = bool_typeptr;
                return bool_typeptr;
              }
        }
// Adding boolean operators and conditionals here. ! and size, arrayaccess.
// List type and table type here, too.

        }
      //handle lists and tables here.
   for (i=0; i < t->n; i++) {
   t1 = synthesize_type(t->kids[i]);
    /*
    * Need to check grammar: are there any points where type
    * information is combined from multiple children??
    */
   if (t1 != error_typeptr) { t->type = t1; return t1; }
   }
      }

   switch(t->prodrule) {
   case INT:
   case INTLITERAL: {
      t->type = integer_typeptr;
      printf("set an integer type.");
      return integer_typeptr;
      break;
    }
   case DOUBLE:
   case FLOATLITERAL: {
      t->type = double_typeptr;
      return double_typeptr;
      break;
    }
    case BOOL:
    case BOOLLITERAL: {
      t->type = bool_typeptr;
      printf("set a bool type.\n");
      return bool_typeptr;
       break;
    }
   case VOID: {
    t->type = void_typeptr;
    printf("set a void type");
    return void_typeptr;
    break;
   }
   default:
      return error_typeptr;
      }
      return t1;
   }


void populate_symboltables(nodeptr n)
{
   	int i;
   	if (n == NULL) return;
   /* pre-order activity */
   	switch (n->prodrule) {
/* oop constructs */
   	case CONSTRUCTER_DELN1: {
     	enter_newscope(n->kids[0]->kids[0]->kids[0]->leaf->text, METHOD_TYPE);
     	break;
    }
   	case METHOD_DECL1: {
	  enter_newscope(n->kids[0]->kids[1]->kids[0]->leaf->text , METHOD_TYPE);
      break;
    }
    case CLASS_DECL1: {
      	enter_newscope(n->kids[1]->leaf->text, CLASS_TYPE);
      	break;
    }

/* in all cases, we have local variables */
   	case LOCVAR_DECL1: {
       /* kid 1 is a "list" of variables */
       	nodeptr t = n->kids[1];
        n->type = synthesize_type(n);
       	while (t->prodrule == VARIABLE_DECS2) {
	  		/* do t->kid[1] */
	  		if(!(n->type)) dovariabledeclarator(t->kids[1], n->kids[0]->type);
	  		t = t->kids[0];
        }
       /* do t */
     	dovariabledeclarator(t, n->kids[0]->type);
        break;
    }
    case SIMPLE_NAME /*SIMPLENAME*/: {
      	SymbolTableEntry ste = NULL;
      	SymbolTable st = current;
      	do {
			ste = lookup_st(st, n->kids[0]->leaf->text);
			st = st->parent;
      	} while (!ste && st);
      	if (!ste) semanticerror("undeclared name", n->kids[0]);
      	else {
			n->type = ste->type;
			//printf("%s", n->kids[0]->leaf->text);
			if (ste->table)
      {
				//if (ste->table->scope) {
			     	//if (ste->table->scope->basetype==METHOD_TYPE)
						//printf("\tlocal");
			     	//else
						//printf("\tclass");
			    }
			   	//else
			    // 	printf("\tglobal");
      }
			if (ste->type){
			   	//printf("\t%s", typename(ste->type));
			//printf("\n");
	 		}
      break;
      	}
    }
   /* visit children */
   for (i=0; i<n->n; i++) {
        populate_symboltables(n->kids[i]);
   }

   /* post-order activity */
    switch (n->prodrule) {
    case FIELD_DECL1: {
        /* kid 2 is a "list" of variables */
        nodeptr t = n->kids[1];
        if (!(n->kids[0]) || !(n->kids[0]->type)) {
        }
        else
        while (t && t->prodrule == VARIABLE_DECS2) {
		  	/* do t->kid[1] */
		  	dovariabledeclarator(t->kids[1], n->kids[0]->type);
		  	t = t->kids[1];
	    }
	    /* do t */
	    if (t){
  		  dovariabledeclarator(t, n->kids[0]->type);
      }
	break;
    }
    case CONSTRUCTER_DELN1:
    case METHOD_DECL1:
    case CLASS_DECL1:
      	popscope();
    }
}

void dovariabledeclarator(nodeptr n, typeptr t) {
	if(!n) semanticerror("called dovariabledeclarator() on null n", n);
	if(n->n) n = n->kids[0]; 
  	if (n->prodrule == VARIABLEDEC_ID2) {
    	printf("arrays unimplemented");
    	exit(0);
  	}
  	if(lookup_st(current, n->leaf->text))
		semanticerror("locally redeclared name", n);
  	insert_sym(current, n->leaf->text, t);
}

void printsymbols(SymbolTable st, int level)
{
   int i, j;
   SymbolTableEntry ste;
   if (st == NULL) return;
   for (i=0;i<st->nBuckets;i++) {
      for (ste = st->tbl[i]; ste; ste=ste->next) {
	 for (j=0; j < level; j++) printf("  ");
	 printf("%s\n", ste->s);
	 if (!ste->type) continue;
	 switch (ste->type->basetype) {
         case CLASS_TYPE:
	   printsymbols(ste->type->u.c.st, level+1);
	   break;
	 case METHOD_TYPE:
	   printsymbols(ste->type->u.m.st, level+1);
	   break;
         }
      }
   }
}

typeptr compare_types(typeptr t, typeptr s, int terminal)
{
   if(terminal == PLUS)
   {
      if(t == integer_typeptr && s == integer_typeptr)
      {
         return integer_typeptr;
      }
      else if (t == integer_typeptr && s == double_typeptr)
      {
         return double_typeptr;
      }
      else if ( t == double_typeptr && s == integer_typeptr)
      {
         return double_typeptr;
      }
      else if ( t == double_typeptr && s == double_typeptr)
      {
         return double_typeptr;
      }
      else if ( t->basetype  == 25700)
      {
        return double_typeptr;
      }
      else if (t->basetype == 120 || s->basetype == 120)
      {
        return integer_typeptr;
      }
      else if (s->basetype == 102)
      {
        return integer_typeptr;
      }
      else
      {
         return error_typeptr;
      }
   }
   else
   {
      return error_typeptr;
   }
}


void checkdeclared(nodeptr t) // Keep this
{
  // For dot operator, use qualified name. It has a structure like a backwards tree/linked list.
  // Child 0 is a reg name or another recursive, and child 1 is always a regular name.
  // Make sure child 0 has  symbol table, and make sure child 1 is in the symbol table.
   int i;
   //char *s;

   if (t == NULL) return;
   switch(t->prodrule) {
    case INT:
   case INTLITERAL:
      t->type = integer_typeptr;
      break;
   case MULT_EXPR2:
   case MULT_EXPR3:
   case MULT_EXPR4:
   case ADD_EXPR3:
   case ADD_EXPR2: {
      checkdeclared(t->kids[0]);
      checkdeclared(t->kids[2]);
      //t->type = compare_types(t->kids[0]->type,t->kids[2]->type, PLUS);
      t->type = compare_types(synthesize_type(t->kids[0]),synthesize_type(t->kids[2]), PLUS);
      if (t->type == error_typeptr) {
   semanticerror("type conflict", t);
   exit(3);
   return;
   }
      break;
    }
   case ASSIGNMENT1 : {
    typeptr typeleft = t->kids[0]->type;
    typeptr typeright =  synthesize_type(t->kids[2]);
    if(typeright == typeleft)
    {
      // Everything's cool, move on.
    }
    else
    {
      semanticerror("type conflict", t);
      exit(3);
      return;
    }
    break;
   }
   case LOCVAR_DECL1: {
    break;
   }
   case STRINGLITERAL: {
    t->type = string_typeptr;
    break;
      }
   case BOOL:
   case BOOLLITERAL: {
    t->type = bool_typeptr;
    break;
   }

   case SIMPLE_NAME: {
      /* this treenode denotes a variable reference */
       char *ste;
      ste = NULL;
      //printf("Eureka, we had a SIMPLE_NAME\n");fflush(stdout);
      //printf("its name is %s\n", t->kids[0]->leaf->text); fflush(stdout);
      if ((ste = t->kids[0]->leaf->text) == NULL) {
   semanticerror("undeclared variable", t->kids[0]);
   exit(3);
   t->type = error_typeptr;
   return;
   }
      else {
        t->type = t->kids[0]->leaf->text;
   }
      break;
      }
   case VARIABLE_DECL2: {
      break;
      }
    case IFTHEN_STMT1:
    case IFTHENELSE_STMT1:
    case IFTHENELSENOSRT_IF1:
    case WHILE_STMT1:
    case WHILENOSRT_IF1: {
      typeptr temp = synthesize_type(t->kids[2]);
      if(temp->basetype == BOOL_TYPE)
      {
        //nothing
      }
      else
      {
        semanticerror("type conflict", t);
        exit(3);
        return;
      }
    break;
    }

    }
  //printf("prodrule: %d \n", t->prodrule);
   if (t->prodrule < 1000) {
      }
   else {
      for (i=0; i < t->n; i++)
   checkdeclared(t->kids[i]);
      }
    }
