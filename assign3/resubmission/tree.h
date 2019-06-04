/* Joel Doumit
 * tree.h
 * Code adapted from the tree structure given by Dr. J.
 */

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <malloc.h> 
#include <string.h>
#include "token.h"


struct tree *newt(int prodrule, int nkids, ...);

typedef struct tree {
	void* type;
	int prodrule;
	int n;
	struct tree *kids[9];
	struct token *leaf;
}tree;

typedef struct tree* nodeptr;

#endif