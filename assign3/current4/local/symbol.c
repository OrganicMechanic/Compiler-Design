/*
 * Joel Doumit
 * Code adapted from code by Andrew Schwartzmeyer for his 120++ compiler.
 * symbol.c
 *
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "symbol.h"
#include "args.h"
#include "logger.h"

#include "token.h"
#include "g0gram.tab.h"
#include "list.h"
#include "hasht.h"
#include "tree.h"

/* stack of scopes */
struct list *yyscopes;

#define scope_current() (struct hasht *)list_back(yyscopes)
#define scope_push(s) list_push_back(yyscopes, s)
#define scope_pop() list_pop_back(yyscopes)

static void symbol_free(struct hash_node *n);
/*
 * Populate a global symbol table given the root of a syntax tree.
 */
struct hasht *symbol_populate(struct tree *syntax)
{
	struct hasht *global = hasht_new(32, true, NULL, NULL, &symbol_free);
	log_assert(global);

	/* initialize scope stack */
	yyscopes = list_new(NULL, NULL);
	log_assert(yyscopes);

	scope_push(global);

	/* do a top-down pre-order traversal to populate symbol tables */
	tree_preorder(syntax, 0, true);

	list_free(yyscopes);

	return global;
}

/*
 * Frees key and deletes value.
 */
static void symbol_free(struct hash_node *n)
{
	log_assert(n);

	free(n->key);
}

/*
 * Recursively handles nodes, processing SIMPLE_DECL1 and
 * FUNCTION_DEF2 for symbols.
 */
static bool handle_node(struct tree *n, int d)
{
	return true;
}

#undef scope_current
#undef scope_push
#undef scope_pop