/*
 * symtab.c
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
#include <string.h>
#include "symtab.h"
#include "nonterm.h"
#include "g0gram.tab.h"

void dovariabledeclarator(nodeptr n, typeptr t);
void semanticerror(char *s, nodeptr n);
extern int errors;

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
char *alloc(int n);       /* calloc + check for NULL */


/*
 * new_st - construct symbol (hash) table.
 *  Allocate space first for the structure, then
 *  for the array of buckets.
 */
SymbolTable new_st(int nbuckets)
   {
   int h;
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
   char *s1, *s2;

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
   while (c = *s++) {
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
   register int i;
   int h;
   struct sym_entry *se;
   int l;

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
   register int i;
   int h;
   struct sym_entry *se;
   int l;

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
   register int i;
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

void populate_symboltables(nodeptr n)
{
   int i;
   if (n == NULL) return;
   /* pre-order activity */
   switch (n->id) {
/* oop constructs */
   case CONSTRUCTORDECLARATION: {
     enter_newscope(n->u.kid[1]->u.kid[0]->u.leaf.text, METHOD_TYPE);
     break;
     }
   case METHODDECLARATION: {
     enter_newscope(n->u.kid[0]->u.kid[2]->u.kid[0]->u.leaf.text,METHOD_TYPE);
     break;
     }
   case CLASSDECLARATION: {
      enter_newscope(n->u.kid[1]->u.leaf.text, CLASS_TYPE);
      break;
      }
/* supposing we are doing a C subset, we have non-OOP functions.
   enter_newscope will create a new local symbol table on its way in.
 */
   case FUNCTIONDEFINITION_3: {
      typeptr t;
      /* construct a type for this function */
      t = alcfunctype(n->u.kid[0], 
          /* paramlist subtree */, )
      /* enter scope, inserting this function's type into the global */
      enter_newscope(/* function name found in $2 */, FUNC_TYPE, n);
      }
/* in all cases, we have local variables */
   case LOCALVARIABLEDECLARATION_1: {
       /* kid 1 is a "list" of variables */
       nodeptr t = n->u.kid[1];
       while (t->id == VARIABLEDECLARATORS_2) {
    /* do t->kid[1] */
    dovariabledeclarator(t->u.kid[1], n->u.kid[0]->type);
    t = t->u.kid[0];
          }
       /* do t */
       dovariabledeclarator(t->u.kid[0], n->u.kid[0]->type);
       break;
   }
   case SIMPLENAME: {
      SymbolTableEntry ste = NULL;
      SymbolTable st = current;
      do {
   ste = lookup_st(st, n->u.kid[0]->u.leaf.text);
   st = st->parent;
         } while (!ste && st);
      if (!ste) semanticerror("undeclared name", n->u.kid[0]);
      else {
   n->type = ste->type;
   printf("%s", n->u.kid[0]->u.leaf.text);
   if (ste->table)
      if (ste->table->scope) {
        if (ste->table->scope->basetype==METHOD_TYPE)
    printf("\tlocal");
        else
    printf("\tclass");
        }
      else
        printf("\tglobal");
   if (ste->type)
      printf("\t%s", typename(ste->type));
   printf("\n");
   }
      }
   }
   /* visit children */
   for (i=0; i<n->n; i++)
      populate_symboltables(n->u.kid[i]);

   /* post-order activity */
   switch (n->id) {
   case FIELDDECLARATION: {
       /* kid 2 is a "list" of variables */
       nodeptr t = n->u.kid[2];
       if (!(n->u.kid[1]) || !(n->u.kid[1]->type)) {
    printf("fielddecl no type\n"); fflush(stdout);
          }
       else
    printf("fielddecl type %s\n", typename(n->u.kid[1]->type));
       while (t && t->id == VARIABLEDECLARATORS_2) {
    /* do t->kid[1] */
    dovariabledeclarator(t->u.kid[1], n->u.kid[1]->type);
    t = t->u.kid[0];
          }
       /* do t */
       if (t)
     dovariabledeclarator(t->u.kid[0], n->u.kid[1]->type);
       break;
       }
   case CONSTRUCTORDECLARATION:
   case METHODDECLARATION:
   case CLASSDECLARATION:
     popscope();
   }
}

void dovariabledeclarator(nodeptr n, typeptr t)
{
  n = n->u.kid[0]; /* get variabledeclaratorid */
  if (n->id == VARIABLEDECLARATORID_2) {
    yyerror("arrays unimplemented");
    exit(0);
  }
  insert_sym(current, n->u.kid[0]->u.leaf.text, t);
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

void semanticerror(char *s, nodeptr n)
{
   while (n && (n->n > 0)) n=n->u.kid[0];
   if (n) {
     fprintf(stderr, "%s:%d: ", n->u.leaf.filename, n->u.leaf.line);
   }
  fprintf(stderr, "%s", s);
  if (n && n->id == IDENT) fprintf(stderr, " %s", n->u.leaf.text);
  fprintf(stderr, "\n");
  errors++;
}
