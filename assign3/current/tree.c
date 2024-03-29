/* Joel Doumit
 * tree.c
 * Code written by Andrew Schwartzmeyer for his 120++ compiler.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "tree.h"
#include "list.h"

/*
 * Initializes tree with reference to parent and data, and an empty
 * (but initialized) list of children.
 */
struct tree *tree_init(struct tree *parent, void *data)
{
	struct tree *t = malloc(sizeof(*t));
	if (t == NULL) {
		perror("tree_init()");
		return NULL;
	}

	struct list *l = list_init();
	if (l == NULL) {
		free(t);
		return NULL;
	}

	t->parent = parent;
	t->data = data;
	t->children = l;

	return t;
}

/*
 * Initializes tree with reference to parent and data, and pushes
 * count number of following struct tree * as children. If given child
 * is NULL it is not added.
 */
struct tree *tree_initv(struct tree *parent, void *data, int count, ...)
{
	va_list ap;
	va_start(ap, count);

	struct tree *t = tree_init(parent, data);

	for (int i = 0; i < count; ++i) {
		struct tree *c = va_arg(ap, void *);
		if (c != NULL) {
			c->parent = t;
			list_push(t->children, c);
		}
	}

	va_end(ap);
	return t;
}

/*
 * Recursively calculates size of tree.
 */
size_t tree_size(struct tree *self)
{
	if (self == NULL)
		return 0;

	size_t size = 1;

	const struct list_node *iter = list_head(self->children);
	while (!list_end(iter)) {
		size += tree_size(iter->data);
		iter = iter->next;
	}

	return size;
}

/*
 * Pre-order traversal of tree. Takes a function and applies it to
 * each subtree.
 */
void tree_preorder(struct tree *self, int depth, void (*f)(struct tree *t, int d))
{
	if (self == NULL)
		return;

	f(self, depth);

	const struct list_node *iter = list_head(self->children);
	while (!list_end(iter)) {
		tree_preorder(iter->data, depth+1, f);
		iter = iter->next;
	}
}

/*
 * Initializes a child tree with self as parent and data
 * reference. Pushes the child tree as data to self's list of
 * children. Returns reference to child tree.
 */
struct tree *tree_push(struct tree *self, void *data)
{
	struct tree *child = tree_init(self, data);
	if (child == NULL) {
		perror("tree_push()");
		return NULL;
	}

	list_push(self->children, child);

	return child;
}

/*
 * Recursively deallocates a tree, and optionally frees data if given
 * a non-NULL function pointer.
 */
void tree_destroy(struct tree *self, void (*destroy)(void *data, bool leaf))
{
	if (destroy != NULL)
		destroy(self->data, list_empty(self->children));

	while (!list_empty(self->children)) {
		void *d = list_pop(self->children);
		tree_destroy(d, destroy);
	}

	free(self->children->sentinel);
	free(self->children);
}
