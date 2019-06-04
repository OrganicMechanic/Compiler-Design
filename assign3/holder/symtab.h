/*
 * Joel Doumit
 * symtab.h is code taken from Dr. J.
 */

#ifndef SYMTAB_H
#define SYMTAB_H

#include "type.h"

typedef struct sym_table {
   int nBuckets;			/* # of buckets */
   int nEntries;			/* # of symbols in the table */
   struct sym_table *parent;		/* enclosing scope, superclass etc. */
   typeptr scope;			/* what type do we belong to? */
   struct sym_entry **tbl;		/* array of buckets */
   /*
	* more per-scope/per-symbol-table attributes go here
	*/
   } *SymbolTable;

/*
 * Entry in symbol table.
 */
typedef struct sym_entry {
   SymbolTable table;			/* what symbol table do we belong to*/
   char *s;				/* string */
   struct typeinfo *type;		/* a.k.a. typeptr, struct c_type *... */
   /* more symbol attributes go here for code generation */
   struct sym_entry *next;
   } *SymbolTableEntry;

/*
 * Prototypes
 */


SymbolTable new_st(int size);			/* create symbol table */
void delete_st(SymbolTable);			/* destroy symbol table */
char *insert_stringpool(char *);		/* enter string into pool */
char *install_sym(SymbolTable, char *, typeptr);/* enter string into table */
int insert_sym(SymbolTable, char *, typeptr);	/* enter symbol into table */
SymbolTableEntry lookup_st(SymbolTable, char *); /* lookup symbol */
void populate_symboltables(nodeptr n);			/* populate symbol table with a node */


extern SymbolTable stringpool;	       /* all idents seen in entire program */
extern SymbolTable globals;	       /* global symbols */
extern SymbolTable current;	       /* current */

extern void printsymbols(SymbolTable st, int level);

#define pushscope(stp) do { stp->parent = current; current = stp; } while (0)
#define popscope() do { current = current->parent; } while(0)

#endif					/* SYMTAB_H */
