/*
 * Joel Doumit
 * type.h, written and provided by Dr. J.
 */

#ifndef TYPE_H
#define TYPE_H

#include "tree.h"
typedef struct param {
   char *name;
   struct typeinfo *type;
   struct param *next;
   } *paramlist;

/* base types. In the real thing, there will be many more base types */
#define VOID_TYPE 1000000
#define INT_TYPE 1000001
#define CLASS_TYPE 1000002
#define LIST_TYPE 1000003
#define DOUBLE_TYPE 1000004
#define STRING_TYPE 1000005
#define BOOL_TYPE 1000006
#define TABLE_TYPE 1000007
#define METHOD_TYPE 1000008
#define NULL_TYPE 1000009
#define ERROR_TYPE 1000010

typedef struct typeinfo {
   int basetype;
   union {
      struct arrayinfo {
         int size;
	 struct typeinfo *elemtype;
         }a;
      struct classinfo {
	 char *name;
	 struct sym_table *st;
	 }c;
      struct methodinfo {
	 char *name;
	 struct sym_table *st;
	 struct typeinfo *returntype;
	 struct param *parameters;
	 }m;
      } u;
   } *typeptr;

extern struct typeinfo integer_type;
extern struct sym_table *foo;

typeptr alctype(int);
typeptr alcclasstype(char *, struct sym_table *);
typeptr alcmethodtype(nodeptr r, nodeptr p, struct sym_table *);
char *typename(typeptr t);

extern typeptr integer_typeptr;
extern typeptr double_typeptr;
extern typeptr null_typeptr;
extern typeptr bool_typeptr;
extern typeptr string_typeptr;
extern typeptr list_typeptr;
extern typeptr void_typeptr;
extern typeptr error_typeptr;
extern typeptr method_typeptr;
extern char *typenam[];

#endif
