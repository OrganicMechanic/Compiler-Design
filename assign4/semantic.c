#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "tree.h"
#include "symtab.h"
#include "g0gram.tab.h"
#include "type.h"
#include "defines.h"

extern int nerrors;
extern int yyerror();

/*
 * An error function during a tree traversal will typically occur
 * at some particular tree node. But to report it, compiler will
 * have to map back to some source location, given by some token.
 */
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
 * When implemented, this probably would insert parameter information
 * into a (local) symbol table for a given function.  Anyhow, it
 * demonstrates the (more typical) recursive tree traversal style.
 */
// void populateparams(nodeptr t)
// {
//    int i;
//    if (t==NULL) return;

//    switch(t->prodrule) {
//    default:
//       for (i=0; i < t->n; i++)
// 	 populateparams(t->kids[i]);
//       }
// }

// /*
//  * Find local declarations in a compound statement.
//  * Illustrates a more general tree traversal that calls a
//  * more specific (helper) tree traversal when it finds an
//  * subtree type of interest (DECLARATION triggers populatesymbols).
//  */
// void populatelocals(nodeptr t)
// {
//    int i;
//    while(1) {
//       switch(t->prodrule) {
//   //     case COMPOUND_STATEMENT: return;
//   //     case COMPOUND_STATEMENT-1:
//   //     case COMPOUND_STATEMENT-3:
// 	 // t = t->kids[0];
// 	 // break;
//   //     case COMPOUND_STATEMENT-2: return;
//   //     case DECLARATION: {
// 	 // populatesymbols(t);
// 	 // return;
// 	 // }
//       default:
// 	 if (is_nonterminal(t)) {
// 	    for (i=0; i < t->n; i++)
// 	       populatelocals(t->kids[i]);
// 	    }
// 	 return;
// 	 }
//       }
//    }

/*
 * Having defined a struct or class for type representation, someone
 * has to constuct those types from information given in parse tree nodes.
 */
typeptr synthesize_type(nodeptr t) // keep
{
   int i;
   typeptr t1;

   if (t == NULL) return error_typeptr;

   if (!(t->leaf)) {
      switch(t->prodrule) {
         case SIMPLE_NAME:
         SymbolTableEntry ste = NULL;
         SymbolTable st = current;
         do {
         ste = lookup_st(st, t->kids[0]->leaf->text);
         st = st->parent;
         } while (!ste && st);
         if (!ste) semanticerror("undeclared name", n->kids[0]);
         else {
         n->type = ste->type;
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
//      }

    printf("Entering switch statement");
   switch(t->prodrule) {
   case INT:
   case INTLITERAL:
      t->type = integer_typeptr;
      return integer_typeptr;
      break;
   case DOUBLE:
   case FLOATLITERAL:
      t->type = double_typeptr;
      return double_typeptr;
      break;
    case CLASS:
       printf("You have found a class. Prepare to seg fault.\n");
       t->type = alcclasstype(t->kids[1]->leaf->text, NULL);
       break;
   default:
      return error_typeptr;
      }
   }
}


/*
 * A more specialized tree traversal, only called in a known subset of
 * the tree, it is still written to recurse on children so it can skip
 * over enclosing non-terminal nodes and trigger on two production rules
 * for function definition, and one production rule for declarations.
 * In these cases, it will call helper functions like get_funcname(),
 * and perform symbol table insertions. Since functions have local
 * scopes, they must be traversed and their symbols inserted into new
 * symbol tables.  Global variable "current" tracks the current scope.
 */
// void populatesymbols(nodeptr t)
// {
//    int i, typ;
//    char *s;
//    if (t == NULL) return;
//    switch(t->prodrule) {
//    case METHOD_DECL1:
//       if (s = get_funcname(t->kids[0])) {
// 	 struct st_entry *ste;
// 	 typeptr typ = method_typeptr;
// 	 ste = insert(current, s, typ);
// 	 if (ste == NULL) {
// 	    printf("redeclared function %s\n", s);
// 	    return;
// 	    }
// 	 current = mksym(current);
// 	 populateparams(t->kids[0]);
// 	 populatelocals(t->kids[1]);
// 	 current = current->parent;
// 	 }
//       return;
//    case VARIABLE_DECL2:
//       /* child 0 is a declaration specifiers containing a base type */
//       t->type = synthesize_type(t->kids[0]);

//       /* child 1 is an init_declarator_list, with symbols to insert */
//       populate_init_declarators(t->kids[1], t->type);
//       break;
//       }

//    if (t->prodrule > 0) {
//       }
//    else {
//       for (i=0; i < t->n; i++)
// 	 populatesymbols(t->kids[i]);
//       }
// }

// void populate_init_declarators(nodeptr t, typeptr typ)
// {
//    switch (t->prodrule) {
//    case VARIABLE_DECL2: /* it is a pointer and a direct_declarator */
//       warn("pointers not supported in C370!", t);
//       populate_init_declarators(t->kids[1], typ);
//       break;
//    case IDENT:
//       if (insert(current, t->type, typ) == NULL) {
// 	 error("illegal redeclaration", t);
// 	 }
//       break;
//       }
// }

typeptr compare_types(typeptr t, typeptr s, int terminal)
{
   printf("Ayyy, we're comparing some types up in here!\n");
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
   int i;
   //char *s;

   if (t == NULL) return;
   switch(t->prodrule) {
   case INTLITERAL:
      t->type = integer_typeptr;
      return;
   case MULT_EXPR2:
   case ADD_EXPR2: {
      checkdeclared(t->kids[0]);
      checkdeclared(t->kids[1]);
      t->type = compare_types(t->kids[0]->type,t->kids[1]->type, PLUS);
      if (t->type == error_typeptr) {
	 error("type conflict", t);
	 }
      }
      return;
   case SIMPLE_NAME: {
      /* this treenode denotes a variable reference */
      struct st_entry *ste;
      //printf("Eureka, we had a SIMPLE_NAME\n");fflush(stdout);
      //printf("its name is %s\n", t->kids[0]->leaf->text); fflush(stdout);
      if ((ste= t->kids[0]->leaf->text) == NULL) {
	 error("undeclared variable", t->kids[0]);
	 t->type = error_typeptr;
	 }
      else {
	 }
      }
  //  case METHOD_DECL1:
  //     printf("I SAW A METHOD_DELC1! You're FUCKED! \n");
  //     if (s = get_funcname(t->kids[0])) {
	 // struct st_entry *ste;
	 // struct st *sav;
	 // sav = current;
	 // //current = ste->type->f.sym;
	 // checkdeclared(t->kids[1]);
	 // current = sav;
	 // }
      return;
   case VARIABLE_DECL2:
      break;
      }
	//printf("prodrule: %d \n", t->prodrule);
   if (t->prodrule < 1000) {
      }
   else {
      for (i=0; i < t->n; i++)
	 checkdeclared(t->kids[i]);
      }

}
