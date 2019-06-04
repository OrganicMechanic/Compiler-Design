/* 
 * Joel Doumit
 * type.c
 * Derived from Dr. J's code of the same name.
 * http://www2.cs.uidaho.edu/~jeffery/courses/445/
 */

#include <stdio.h>
#include "type.h"
#include "symtab.h"
#include "g0gram.tab.h"

struct typeinfo integer_type = { INT_TYPE };
struct typeinfo double_type = { DOUBLE_TYPE };
struct typeinfo bool_type = { BOOL_TYPE };
struct typeinfo null_type = { NULL_TYPE };
struct typeinfo string_type = { STRING_TYPE };
struct typeinfo list_type = { LIST_TYPE };
struct typeinfo void_type = { VOID_TYPE };
struct typeinfo class_type = { CLASS_TYPE };
struct typeinfo error_type = { ERROR_TYPE };
struct typeinfo method_type = { METHOD_TYPE };
typeptr null_typeptr = &null_type;
typeptr integer_typeptr = &integer_type;
typeptr double_typeptr = &double_type;
typeptr bool_typeptr = &bool_type;
typeptr string_typeptr = &string_type;
typeptr list_typeptr = &list_type;
typeptr void_typeptr = &void_type;
typeptr class_typeptr = &class_type;
typeptr error_typeptr = &error_type;
typeptr method_typeptr = &method_type;
char *typenam[] = {"void", "int", "class", "list", "double", "string", "bool", "table", "method", "null", "error"};

typeptr alctype(int base)
{
   typeptr rv;
   if(base == INT_TYPE) return &integer_type;
   if(base == VOID_TYPE) return &void_type;
   if(base == BOOL_TYPE) return &bool_type;
   if(base == DOUBLE_TYPE) return &double_type;

   rv = (typeptr)calloc(1, sizeof(struct typeinfo));
   if(rv == NULL)
      return rv;
   rv->basetype = base;
return rv;
}

typeptr alcclasstype(char *name, SymbolTable st)
{
   typeptr rv = alctype(CLASS_TYPE);
   if (rv == NULL) return NULL;
   rv->u.c.name = strdup(name);
   rv->u.c.st = st;
   return rv;
}

/* in order for this to make any sense, you have to pass in the subtrees
 * for the return type (r) and the parameter list (p), but the calls to
 * to this function in the example are just passing NULL at present!
 */
typeptr alcmethodtype(nodeptr r, nodeptr p, SymbolTable st)
{
   typeptr rv = alctype(METHOD_TYPE);
   rv->u.m.st = st;
   /* fill in return type and paramlist by traversing subtrees */
   return rv;
}


char *typename(typeptr t)
{
   if (!t){ return "(NULL)"; }
   else if (t->basetype == CLASS_TYPE) {
      return t->u.c.name;
      }
      else if(t->basetype == IDENT)
      {
         printf("We found an ident.\n");
         return 0;
      }
      else { return typenam[t->basetype-1000000]; }
}
