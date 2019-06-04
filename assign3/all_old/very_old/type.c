#include <stdio.h>
#include "type.h"
#include "symtab.h"

struct typeinfo integer_type = { INT_TYPE };
struct typeinfo null_type = { NULL_TYPE };
typeptr null_typeptr = &null_type;
typeptr integer_typeptr = &integer_type;
typeptr String_typeptr;
char *typenam[] = {"null", "int", "class", "method"};

typeptr alctype(int base)
{
   typeptr rv;
   if (base == INT_TYPE) return &integer_type;
   rv = (typeptr) calloc(1, sizeof(struct typeinfo));
   if (rv == NULL) return rv;
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

typeptr alcfunctype(struct tree *r, struct tree *p, SymbolTable st)
{
   typeptr rv = alctype(METHOD_TYPE);
   if (rv == NULL) return NULL;
   rv->u.m.name = strdup(name);
   rv->u.m.st = st;
   return rv;

}

/* in order for this to make any sense, you have to pass in the subtrees
 * for the return type (r) and the parameter list (p), but the calls to
 * to this function in the example are just passing NULL at present!
 */
typeptr alcmethodtype(struct tree *r, struct tree *p, SymbolTable st)
{
   typeptr rv = alctype(METHOD_TYPE);
   rv->u.m.st = st;
   /* fill in return type and paramlist by traversing subtrees */
   return rv;
}
char *typename(typeptr t)
{
   if (!t) return "(NULL)";
   else if (t->basetype == CLASS_TYPE) {
      return t->u.c.name;
      }
   else return typenam[t->basetype-1000000];
}
