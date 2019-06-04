/* Joel Doumit
 * tree.h
 * Code written by Andrew Schwartzmeyer for his 120++ compiler.
 */

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <malloc.h> 
#include <string.h>
#include "token.h"


//C Structures
struct tree *ntree(int prodrule, int nkids, ...);

typedef struct tree {
	void* type;
	int prodrule;
	int n;
	struct tree *kids[9];
	struct token *leaf;
}tree;

typedef struct tree* nodeptr;

#endif