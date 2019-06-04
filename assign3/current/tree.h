/* Joel Doumit
 * tree.h
 * Code modified from code by Andrew Schwartzmeyer for his 120++ compiler.
 */

#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct tree {
   int id;
   int n;
   struct tree *kid[9];
   struct token *leaf;
} *nodeptr;



#endif /* TREE_H */
