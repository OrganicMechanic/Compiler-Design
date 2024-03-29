/*
 * symbol.c - Implementation of symbol data.
 *
 * Copyright (C) 2014 Andrew Schwartzmeyer
 *
 * This file released under the AGPLv3.
 *
 */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "symbol.h"
#include "args.h"

#include "token.h"
#include "clex.h"
#include "g0gram.tab.h"

#include "list.h"
#include "hasht.h"
#include "tree.h"

/* from lexer */
extern struct hasht *typenames;

/* stack of scopes */
struct list *yyscopes;

#define scope_current() (struct hasht *)list_back(yyscopes)
#define scope_push(s) list_push_back(yyscopes, s)
#define scope_pop() list_pop_back(yyscopes)

/* syntax tree helpers */
#define get_rule(n) *(enum rule *)((struct tree *)n)->data
#define get_token(n, i) ((struct token *)tree_index(n, i)->data)

/* local functions */
static enum type map_type(enum yytokentype t);
static void set_type_comparators();
static char *print_basetype(struct typeinfo *t);
static void print_typeinfo(FILE *stream, char *k, struct typeinfo *v);

static struct typeinfo *symbol_search(char *k);
static void symbol_insert(char *k, struct typeinfo *v, struct tree *n, struct hasht *l);
static void symbol_free(struct hash_node *n);

static struct tree *get_production(struct tree *n, enum rule r);
static struct token *get_category(struct tree *n, int target, int before);
static struct token *get_category_(struct tree *n, int target, int before);
static char *get_identifier(struct tree *n);
static bool get_pointer(struct tree *n);
static int get_array(struct tree *n);
static char *get_class(struct tree *n);
static bool get_public(struct tree *n);
static bool get_private(struct tree *n);
static char *class_member(struct tree *n);

static struct typeinfo *type_check(struct tree *n);
static struct typeinfo *get_left_type(struct tree *n);
static struct typeinfo *get_right_type(struct tree *n);

static struct typeinfo *typeinfo_new(struct tree *n);
static struct typeinfo *typeinfo_new_array(struct tree *n, struct typeinfo *t);
static struct typeinfo *typeinfo_new_function(struct tree *n, struct typeinfo *t, bool define);
static struct typeinfo *typeinfo_copy(struct typeinfo *t);
static struct typeinfo *typeinfo_return(struct typeinfo *t);
static void typeinfo_delete(struct typeinfo *t);
static bool typeinfo_compare(struct typeinfo *a, struct typeinfo *b);
static bool typeinfo_list_compare(struct list *a, struct list *b);

static bool handle_node(struct tree *n, int d);
static void handle_init(struct typeinfo *v, struct tree *n);
static void handle_init_list(struct typeinfo *v, struct tree *n);
static void handle_function(struct typeinfo *t, struct tree *n, char *k);
static void handle_param(struct typeinfo *v, struct tree *n, struct hasht *s, struct list *l);
static void handle_param_list(struct tree *n, struct hasht *s, struct list *l);
static void handle_class(struct typeinfo *t, struct tree *n);

/* basic type comparators */
static struct typeinfo int_type;
static struct typeinfo double_type;
static struct typeinfo char_type;
static struct typeinfo string_type;
static struct typeinfo bool_type;
static struct typeinfo void_type;
static struct typeinfo class_type;
static struct typeinfo unknown_type;

/*
 * Initialize comparator types
 */
static void set_type_comparators()
{
	int_type.base = INT_T;
	int_type.pointer = false;

	double_type.base = DOUBLE_T;
	double_type.pointer = false;

	char_type.base = CHAR_T;
	char_type.pointer = false;

	string_type.base = CHAR_T;
	string_type.pointer = true; /* a C string is a char* */

	bool_type.base = BOOL_T;
	bool_type.pointer = false;

	void_type.base = VOID_T;
	void_type.pointer = false;

	class_type.base = CLASS_T;
	class_type.pointer = false;

	unknown_type.base = UNKNOWN_T;
	unknown_type.pointer = false;
}

/*
 * Maps a Bison type to a 120++ type.
 */
static enum type map_type(enum yytokentype t)
{
	switch (t) {
	case INTEGER:
	case INT:
	case SHORT:
	case LONG:
		return INT_T;
	case FLOATING:
	case FLOAT:
	case DOUBLE:
		return DOUBLE_T;
	case CHARACTER:
	case CHAR:
		return CHAR_T;
	case STRING:
		return ARRAY_T;
	case TRUE:
	case FALSE:
	case BOOL:
		return BOOL_T;
	case CLASS_NAME:
	case CLASS:
	case STRUCT:
		return CLASS_T;
	case VOID:
		return VOID_T;
	default:
		return UNKNOWN_T;
	}
}

/*
 * Populate a global symbol table given the root of a syntax tree.
 */
struct hasht *symbol_populate(struct tree *syntax)
{
	set_type_comparators();

	struct hasht *global = hasht_new(32, true, NULL, NULL, &symbol_free);

	/* initialize scope stack */
	yyscopes = list_new(NULL, NULL);

	scope_push(global);

	/* handle standard libraries */
	if (libs.usingstd) {
		/* iostream includes fstream */
		if (libs.fstream || libs.iostream) {
			struct typeinfo *ifstream = malloc(sizeof(*ifstream));
			ifstream->base = CLASS_T;
			ifstream->pointer = false;
			ifstream->class.type = "std::ifstream";
			ifstream->class.public = hasht_new(2, true, NULL, NULL, &symbol_free);
			symbol_insert("ifstream", ifstream, NULL, NULL);

			/* adding ifstream.ignore() */
			struct typeinfo *ignore = malloc(sizeof(*ignore));
			ignore->base = FUNCTION_T;
			ignore->pointer = false;
			ignore->function.type = typeinfo_copy(&void_type);
			ignore->function.parameters = list_new(NULL, NULL);
			ignore->function.symbols = NULL;

			scope_push(ifstream->class.public);
			symbol_insert("ignore", ignore, NULL, NULL);
			scope_pop();

			struct typeinfo *ofstream = malloc(sizeof(*ofstream));
			ofstream->base = CLASS_T;
			ofstream->pointer = false;
			ofstream->class.type = "std::ofstream";
			symbol_insert("ofstream", ofstream, NULL, NULL);
		}
		if (libs.iostream) {
			struct typeinfo *cin = malloc(sizeof(*cin));
			cin->base = CLASS_T;
			cin->pointer = false;
			cin->class.type = "ifstream";
			symbol_insert("cin", cin, NULL, NULL);

			struct typeinfo *cout = malloc(sizeof(*cout));
			cout->base = CLASS_T;
			cout->pointer = false;
			cout->class.type = "ofstream";
			symbol_insert("cout", cout, NULL, NULL);

			struct typeinfo *endl = typeinfo_copy(&char_type);
			symbol_insert("endl", endl, NULL, NULL);
		}
		if (libs.string) {
			struct typeinfo *string = malloc(sizeof(*string));
			string->base = CLASS_T;
			string->pointer = false;
			string->class.type = "std::string";
			symbol_insert("string", string, NULL, NULL);
		}
	}

	/* do a top-down pre-order traversal to populate symbol tables */
	tree_preorder(syntax, 0, &handle_node);
	type_check(syntax);

	list_free(yyscopes);

	return global;
}

/*
 * Search the stack of scopes for a given identifier.
 */
static struct typeinfo *symbol_search(char *k)
{
	if (k == NULL)
		return NULL;

	struct list_node *iter = list_tail(yyscopes);
	while (!list_end(iter)) {
		struct typeinfo *t = hasht_search(iter->data, k);
		if (t)
			return t;
		iter = iter->prev;
	}
	return NULL;
}

/*
 * Insert symbol as ident/typeinfo pair.
 *
 * Tree used to find token on error. If attempting to insert a
 * function symbol, if the function has been previously declared, it
 * will define the function with the given symbol table. Will error
 * for duplicate symbols or mismatched function declarations.
 */
static void symbol_insert(char *k, struct typeinfo *v, struct tree *n, struct hasht *l)
{
	if (v == NULL)
		printf("symbol_insert(): type for %s was null", k);

	struct typeinfo *e = NULL;
	if (l && v->base == FUNCTION_T)
		/* search for function declaration to define */
		e = symbol_search(k);
	else
		/* search just current scope */
		e = hasht_search(list_tail(yyscopes)->data, k);

	if (e == NULL) {
		hasht_insert(scope_current(), k, v);
		if (arguments.symbols) {
			fprintf(stderr, "Inserting at depth %zu: ",
			        list_size(yyscopes));
			print_typeinfo(stderr, k, v);
		}
	} else if (e->base == FUNCTION_T && v->base == FUNCTION_T) {
		if (!typeinfo_compare(e, v)) {
			printf(n, "function signatures for %s mismatched", k);
		} else if (l) {
			/* define the function */
			if (e->function.symbols == NULL) {
				e->function.symbols = l;
				("function %s defined", k);
			} else {
				printf(n, "function %s already defined", k);
			}
		}
	} else {
		printf(n, "identifier %s already declared", k);
	}
}

/*
 * Frees key and deletes value.
 */
static void symbol_free(struct hash_node *n)
{
	free(n->key);
	typeinfo_delete(n->value);
}

/*
 * Given a tree node, get the first subtree with the production rule.
 */
static struct tree *get_production(struct tree *n, enum rule r)
{

	if (tree_size(n) != 1 && get_rule(n) == r)
		return n;

	struct list_node *iter = list_head(n->children);
	while (!list_end(iter)) {
		struct tree *t = get_production(iter->data, r);
		if (t)
			return t;
		iter = iter->next;
	}
	return NULL;
}

/*
 * Wrapper to return null if token not found, else return token.
 */
static struct token *get_category(struct tree *n, int target, int before)
{
	struct token *t = get_category_(n, target, before);
	if (t && t->category == target)
		return t;
	else
		return NULL;
}

/*
 * Walks tree returning first token matching category, else null.
 */
static struct token *get_category_(struct tree *n, int target, int before)
{

	if (tree_size(n) == 1) {
		struct token *t = n->data;
		if (t->category == target || t->category == before)
			return t;
	}

	struct list_node *iter = list_head(n->children);
	while (!list_end(iter)) {
		struct token *t = get_category_(iter->data, target, before);
		if (t && (t->category == target || t->category == before))
			return t;
		iter = iter->next;
	}

	return NULL;
}

/*
 * Returns true identifier if found, else null.
 */
static char *get_identifier(struct tree *n)
{
	struct token *t = get_category(n, IDENTIFIER, -1);
	if (t)
		return t->text;
	else
		return NULL;
}

/*
 * Returns if pointer is found in tree.
 */
static bool get_pointer(struct tree *n)
{
	return get_category(n, '*', IDENTIFIER);
}

/*
 * Returns size of array if found, 0 if not given, -1 if not array.
 */
static int get_array(struct tree *n)
{
	if (get_category(n, '[', INTEGER)) {
		struct token *t = get_category(n, INTEGER, ']');
		return t ? t->ival : 0;
	}
	return -1;
}

/*
 * Returns class name if found, else null.
 */
static char *get_class(struct tree *n)
{
	struct token *t = get_category(n, CLASS_NAME, IDENTIFIER);
	if (t)
		return t->text;
	else
		return NULL;
}

static bool get_public(struct tree *n)
{
	return get_category(n, PUBLIC, PRIVATE);
}

static bool get_private(struct tree *n)
{
	return get_category(n, PRIVATE, PUBLIC);
}

/*
 * Returns class name only if like class::something
 */
static char *class_member(struct tree *n)
{
	struct tree *prod = NULL;
	if ((prod = get_production(n, DIRECT_DECL4))     /* class::ident */
	    || (prod = get_production(n, DIRECT_DECL5))) /* class::class */
		return get_class(prod);
	return NULL;
}

/*
 * Constructs new empty typeinfo.
 */
static struct typeinfo *typeinfo_new(struct tree *n)
{

	struct typeinfo *t = calloc(1, sizeof(*t));

	t->base = (get_rule(n) == FUNCTION_DEF1)
		? CLASS_T /* constructor return type is always class */
		: map_type(get_token(n, 0)->category); /* TODO: factor out dependency */
	t->pointer = get_pointer(n);

	if (t->base == CLASS_T)
		t->class.type = get_class(n);

	return t;
}

/*
 * Constructs a typeinfo for an array.
 */
static struct typeinfo *typeinfo_new_array(struct tree *n, struct typeinfo *t)
{
	struct typeinfo *array = typeinfo_new(n);
	array->base = ARRAY_T;
	array->array.type = t;
	array->array.size = get_array(n);
	return array;
}

/*
 * Constructs a typeinfo for a function.
 */
static struct typeinfo *typeinfo_new_function(struct tree *n, struct typeinfo *t, bool define)
{
	/* make new symbol table if defining */
	struct hasht *local = (define)
		? hasht_new(8, true, NULL, NULL, &symbol_free)
		: NULL;

	struct list *params = list_new(NULL, NULL);

	handle_param_list(n, local, params);

	struct typeinfo *function = typeinfo_new(n);
	function->base = FUNCTION_T;
	function->pointer = false; /* 120++ does not have function pointers */
	function->function.type = t;
	function->function.parameters = params;
	function->function.symbols = local;

	return function;
}

/*
 * Returns a copy of a typeinfo object.
 */
static struct typeinfo *typeinfo_copy(struct typeinfo *t)
{

	struct typeinfo *n = malloc(sizeof(*n));

	n->base = t->base;
	n->pointer = t->pointer;

	switch(n->base) {
	case ARRAY_T: {
		n->array.type = t->array.type;
		n->array.size = t->array.size;
		break;
	}
	case FUNCTION_T: {
		n->function.type = t->function.type;
		n->function.parameters = t->function.parameters;
		n->function.symbols = t->function.symbols;
		break;
	}
	case CLASS_T: {
		n->class.type = t->class.type;
		n->class.public = t->class.public;
		n->class.private = t->class.private;
		break;
	}
	default:
		break;
	}

	return n;
}

/*
 * Returns the actual type for a typeinfo.
 *
 * For primitives and classes returns itself.
 */
static struct typeinfo *typeinfo_return(struct typeinfo *t)
{

	if (t->base == FUNCTION_T)
		return t->function.type;
	else
		return t;
}

/*
 * Get typeinfo for identifier or literal value.
 */
static struct typeinfo *get_typeinfo(struct tree *n) {

	/* reset base type comparators */
	set_type_comparators();

	/* attempt to get identifier or class */
	char *k = get_identifier(n);
	char *c = get_class(n);

	if (k) {
		/* return function typeinfo */
		return symbol_search(k);
	} else if (c) {
		/* return class typeinfo comparator */
		class_type.class.type = c;
		return &class_type;
	} else {
		/* return global basic typeinfo for literal */
		struct token *token = n->data;

		switch (map_type(token->category)) {
		case INT_T:
			return &int_type;
		case DOUBLE_T:
			return &double_type;
		case CHAR_T:
			return &char_type;
		case ARRAY_T:
			return &string_type;
		case BOOL_T:
			return &bool_type;
		case VOID_T:
			return &void_type;
		case FUNCTION_T:
		case CLASS_T:
		case UNKNOWN_T:
			return &unknown_type;
		}
	}
	return NULL;
}

/*
 * Require symbol for child 0, left operand.
 */
static struct typeinfo *get_left_type(struct tree *n)
{
	struct tree *n_= tree_index(n, 0);
	struct typeinfo *t = type_check(n_);
	if (t == NULL)
		printf(n_, "left operand undeclared");
	return t;
}

/*
 * Require symbol for child 2, right operand.
 */
static struct typeinfo *get_right_type(struct tree *n)
{
	struct tree *n_= tree_index(n, 2);
	struct typeinfo *t = type_check(n_);
	if (t == NULL)
		printf(n_, "right operand undeclared");
	return t;
}

/*
 * Recursively perform type checking on the relevant expression
 * production rules for the given syntax tree.
 */
static struct typeinfo *type_check(struct tree *n)
{

	if (tree_size(n) == 1)
		return get_typeinfo(n);

	enum rule production = get_rule(n);
	switch (production) {
	case INITIALIZER: {
		/* initialization of simple variable */
		char *k = get_identifier(n->parent);
		if (k == NULL)
			printf(n, "could not get identifier in init");

		struct typeinfo *l = symbol_search(k);
		if (l == NULL)
			printf(n, "could not get symbol for %s in init", k);

		struct typeinfo *r = type_check(tree_index(n, 0));
		if (r == NULL)
			printf(n, "symbol %s undeclared", k);

		if (typeinfo_compare(l, r)) {
			printf("initialized %s", k);
			return l;
		} else if (l->base == CLASS_T
		           && (strcmp(l->class.type, "string") == 0)
		           && r->base == CHAR_T && r->pointer) {
			printf("initialized std::string %s with string literal", k);
			return l;
		} else {
			printf(n, "could not initialize %s with given type", k);
		}
	}
	case INIT_LIST2: {
		/* arrays get lists of initializers, check that each
		   type matches the array's element type */
		char *k = get_identifier(n->parent->parent);
		if (k == NULL)
			printf(n, "could not get identifier in initializer list");

		struct typeinfo *l = symbol_search(k);
		if (l == NULL)
			printf(n, "could not get symbol for %s in initializer list", k);

		if (l->base != ARRAY_T)
			printf(n, "initializer list assignee %s was not an array", k);

		struct list_node *iter = list_head(n->children);
		size_t items = 0;
		while (!list_end(iter)) {
			++items;
			struct typeinfo *elem = type_check(iter->data);
			if (!typeinfo_compare(l->array.type, elem))
				printf(n, "initializer item did not match %s element type", k);
			if (items > l->array.size)
				printf(n, "array %k size %zu exceeded by initializer list", k, l->array.size);
			iter = iter->next;
		}
		printf("initialized %s with list", k);
		return l;
	}
	case NEW_EXPR1: {
		/* new operator */
		struct tree *type_spec = get_production(n, TYPE_SPEC_SEQ);
		if (type_spec == NULL)
			printf(n, "new operator missing type spec");

		struct typeinfo *type = typeinfo_copy(type_check(tree_index(type_spec, 0)));
		type->pointer = true;

		if (type->base == CLASS_T) {
			size_t scopes = list_size(yyscopes);

			char *c = type->class.type;
			struct typeinfo *class = symbol_search(c);
			if (class) {
				scope_push(class->class.public);
				scope_push(class->class.private);
			}

			struct typeinfo *l = symbol_search(c);
			if (l == NULL)
				printf(n, "could not find constructor for %s", c);

			struct typeinfo *r = typeinfo_copy(l);
			r->function.parameters = list_new(NULL, NULL);

			struct tree *expr_list = get_production(n, EXPR_LIST);
			if (expr_list) {
				struct list_node *iter = list_head(expr_list->children);
				while (!list_end(iter)) {
					struct typeinfo *t = type_check(iter->data);
					if (t == NULL)
						printf(iter->data, "could not get type for parameter to %s constructor", c);
					list_push_back(r->function.parameters, t);
					iter = iter->next;
				}
			}

			if (!typeinfo_compare(l, r))
				printf(n, "new operator types mismatched");

			list_free(r->function.parameters);
			free(r);

			/* pop newly pushed scopes */
			while (list_size(yyscopes) != scopes)
				scope_pop();
			printf("new operator");
		}

		return type;
	}
	case DELETE_EXPR1:
	case DELETE_EXPR2: {
		/* delete operator */
		struct typeinfo *t = type_check(tree_index(n, 1));
		if (t == NULL)
			printf(n, "symbol %s undeclared", get_identifier(n));

		if (!t->pointer)
			printf(n, "delete operator expected a pointer");

		return NULL;
	}
	case ASSIGN_EXPR2: {
		/* assignment operator */
		char *k = get_identifier(tree_index(n, 0));
		if (k == NULL)
			printf(n, "left assignment operand not assignable");

		struct typeinfo *l = get_left_type(n);
		struct typeinfo *r = get_right_type(n);

		switch (get_token(n, 1)->category) {
		case '=': {
			break;
		}
		case ADDEQ:
		case SUBEQ:
		case MULEQ:
		case DIVEQ: {
			if (!(typeinfo_compare(l, &int_type) || typeinfo_compare(l, &double_type)))
				printf(n, "left operand not an int or double");

			if (!(typeinfo_compare(r, &int_type) || typeinfo_compare(r, &double_type)))
				printf(n, "right operand not an int or double");
			break;
		}
		case MODEQ: {
			if (!typeinfo_compare(l, &int_type) || !typeinfo_compare(r, &int_type))
				printf(n, "modulo operand not an integer");
			break;
		}
		case SREQ:
		case SLEQ:
		case ANDEQ:
		case XOREQ:
		case OREQ: {
			printf(n, "compound bitwise equality operator unsupported");
		}
		}

		if (typeinfo_compare(l, r)) {
			printf("assigned %s", k);
			return l;
		} else if (l->base == CLASS_T
		           && (strcmp(l->class.type, "string") == 0)
		           && r->base == CHAR_T && r->pointer) {
			printf("std::string %s assigned with string literal", k);
			return l;
		} else {
			printf(n, "could not assign to %s", k);
		}
	}
	case EQUAL_EXPR2:
	case EQUAL_EXPR3: {
		struct typeinfo *l = get_left_type(n);
		struct typeinfo *r = get_right_type(n);

		if (!typeinfo_compare(l, r))
			printf(n, "equality operands don't match");

		printf("equality comparison");
		return &bool_type;
	}
	case REL_EXPR2: /* < */
	case REL_EXPR3: /* > */
	case REL_EXPR4: /* <= */
	case REL_EXPR5: /* >= */ {
		struct typeinfo *l = get_left_type(n);
		if (!(typeinfo_compare(l, &int_type) || typeinfo_compare(l, &double_type)))
			printf(n, "left operand not an int or double");

		struct typeinfo *r = get_right_type(n);
		if (!(typeinfo_compare(r, &int_type) || typeinfo_compare(r, &double_type)))
			printf(n, "right operand not an int or double");

		if (!typeinfo_compare(l, r))
			printf(n, "could not order operands");

		printf("order comparison");
		return &bool_type;
	}
	case ADD_EXPR2:  /* + */
	case ADD_EXPR3:  /* - */
	case MULT_EXPR2: /* * */
	case MULT_EXPR3: /* / */ {
		struct typeinfo *l = get_left_type(n);
		if (!(typeinfo_compare(l, &int_type) || typeinfo_compare(l, &double_type)))
			printf(n, "left operand not an int or double");

		struct typeinfo *r = get_right_type(n);
		if (!(typeinfo_compare(r, &int_type) || typeinfo_compare(r, &double_type)))
			printf(n, "right operand not an int or double");

		if (!typeinfo_compare(l, r))
			printf(n, "could not perform arithmetic on operands");

		printf("binary arithmetic");
		return l;
	}
	case MULT_EXPR4: {
		/* modulo operator */
		struct typeinfo *l = get_left_type(n);
		struct typeinfo *r = get_right_type(n);

		if (!typeinfo_compare(l, &int_type) || !typeinfo_compare(r, &int_type))
			printf(n, "modulo operand not an integer");

		printf("modulo arithmetic");
		return l;
	}
	case AND_EXPR2:
	case XOR_EXPR2:
	case OR_EXPR2: {
		printf(n, "C++ bitwise operation unsupported in 120++");
	}
	case LOGICAL_AND_EXPR2: /* && */
	case LOGICAL_OR_EXPR2:  /* || */ {
		struct typeinfo *l = get_left_type(n);
		if (!(typeinfo_compare(l, &int_type) || typeinfo_compare(l, &bool_type)))
			printf(n, "left operand not an int or bool");

		struct typeinfo *r = get_right_type(n);
		if (!(typeinfo_compare(r, &int_type) || typeinfo_compare(r, &bool_type)))
			printf(n, "right operand not an int or bool");

		printf("logical comparison");
		return &bool_type;
	}
	case POSTFIX_EXPR2: {
		/* array indexing: check identifier is an array and index is an int */
		char *k = get_identifier(n);

		struct typeinfo *l = symbol_search(k);
		if (l == NULL)
			printf(n, "array %s not declared", k);
		if (l->base != ARRAY_T)
			printf(n, "trying to index non array symbol %s", k);

		struct typeinfo *r = get_right_type(n);
		if (!typeinfo_compare(&int_type, r))
			printf(n, "array index not an integer");

		printf("%s[index]", k);
		return l->array.type;
	}
	case POSTFIX_EXPR3: {
		/* function invocation: build typeinfo list from
		   EXPR_LIST, recursing on each item */
		struct typeinfo *l = get_left_type(n);
		struct typeinfo *r = typeinfo_copy(l);

		r->function.parameters = list_new(NULL, NULL);
		struct tree *expr_list = get_production(n, EXPR_LIST);
		if (expr_list) {
			struct list_node *iter = list_head(expr_list->children);
			while (!list_end(iter)) {
				struct typeinfo *t = type_check(iter->data);
				if (t == NULL)
					printf(iter->data, "symbol for parameter undeclared");
				list_push_back(r->function.parameters, t);
				iter = iter->next;
			}
		}

		if (!typeinfo_compare(l, r)) {
			printf(n, "function invocation did not match signature");
		}

		list_free(r->function.parameters);
		free(r);

		printf("function invocation");
		return typeinfo_return(l);
	}
	case POSTFIX_EXPR5:
	case POSTFIX_EXPR6: {
		/* class_instance.field access */
		char *k = get_identifier(n);
		char *f = get_identifier(tree_index(n, 2));

		struct typeinfo *l = symbol_search(k);
		if (l == NULL)
			printf(n, "symbol %s undeclared", k);
		if (l->base != CLASS_T || l->pointer)
			printf(n, "expected %s to be a class instance", k);

		char *c = l->class.type;
		struct typeinfo *class = symbol_search(c);
		if (class == NULL)
			printf(n, " symbol %s undeclared", c);

		struct typeinfo *r = hasht_search(class->class.public, f);
		if (r == NULL)
			printf(n, "field %s not in public scope of %s", f, c);

		printf("%s.%s", k, f);
		return typeinfo_return(r);
	}
	case POSTFIX_EXPR7:
	case POSTFIX_EXPR8: {
		/* class_ptr->field access */
		char *k = get_identifier(n);
		char *f = get_identifier(tree_index(n, 2));

		struct typeinfo *l = symbol_search(k);
		if (l == NULL)
			printf(n, "symbol %s undeclared", k);
		if (l->base != CLASS_T || !l->pointer)
			printf(n, "expected %s to be a class pointer", k);

		char *c = l->class.type;
		struct typeinfo *class = symbol_search(c);
		if (class == NULL)
			printf(n, "symbol %s undeclared", c);

		struct typeinfo *r = hasht_search(class->class.public, f);
		if (r == NULL)
			printf(n, "field %s not in public scope of %s", f, c);

		printf("%s->%s", k, f);
		return typeinfo_return(r);
	}
	case POSTFIX_EXPR9:  /* i++ */
	case POSTFIX_EXPR10: /* i-- */ {
		struct typeinfo *t = type_check(tree_index(n, 0));
		if (!typeinfo_compare(t, &int_type))
			printf(n, "operand to postfix ++/-- not an int");

		printf("postfix ++/--");
		return t;
	}
	case UNARY_EXPR2: /* ++i */
	case UNARY_EXPR3: /* --i */ {
		struct typeinfo *t = type_check(tree_index(n, 1));
		if (t == NULL)
			printf(n, "symbol undeclared");
		if (!typeinfo_compare(t, &int_type))
			printf(n, "operand to prefix ++/-- not an int");

		printf("prefix ++/--");
		return t;
	}
	case UNARY_EXPR4: {
		/* dereference operator */
		char *k = get_identifier(n);

		struct typeinfo *t = symbol_search(k);
		if (t == NULL)
			printf(n, "symbol %s undeclared", k);

		if (!t->pointer)
			printf(n, "cannot dereference non-pointer %s", k);

		struct typeinfo *copy = typeinfo_copy(t);
		copy->pointer = false;

		printf("*%s", k);
		return copy;
	}
	case UNARY_EXPR5: {
		/* address operator */
		char *k = get_identifier(n);

		struct typeinfo *t = symbol_search(k);
		if (t == NULL)
			printf(n, "symbol %s undeclared", k);

		if (t->pointer)
			printf(n, "double pointers unsupported in 120++");

		struct typeinfo *copy = typeinfo_copy(t);
		copy->pointer = true;

		printf("&%s", k);
		return copy;
	}
	case UNARY_EXPR6: {
		struct typeinfo *t = type_check(tree_index(n, 1));
		if (t == NULL)
			printf(n, "symbol undeclared");

		switch (get_token(n, 0)->category) {
		case '+':
		case '-':
			if (!typeinfo_compare(t, &int_type))
				printf(n, "unary + or - operand not an int");

			printf("unary + or -");
			return t;
		case '!':
			if (!(typeinfo_compare(t, &int_type) || typeinfo_compare(t, &bool_type)))
				printf(n, "! operand not an int or bool");

			printf("logical not");
			return &bool_type;
		case '~':
			printf(n, "destructors not yet supported");
		}
	}
	case SHIFT_EXPR2: {
		/* << only used for puts-to IO */
		if (!(libs.usingstd && (libs.fstream || libs.iostream)))
			printf(n, "<< can only be used with std streams in 120++");

		/* recurse on items of shift expression */
		struct list_node *iter = list_head(n->children);
		struct typeinfo *ret = NULL;
		while (!list_end(iter)) {
			struct typeinfo *t = type_check(iter->data);
			if (t == NULL)
				printf(iter->data, "symbol undeclared");

			/* ensure leftmost child is of type std::ofstream */
			if (iter == list_head(n->children)) {
				if (!(t->base == CLASS_T && (strcmp(t->class.type, "ofstream") == 0)))
					printf(iter->data, "leftmost << operand not a ofstream");
				/* return leftmost type as result of << */
				ret = t;
			} else if (!(typeinfo_compare(t, &int_type)
			             || typeinfo_compare(t, &double_type)
			             || typeinfo_compare(t, &bool_type)
			             || typeinfo_compare(t, &char_type)
			             || typeinfo_compare(t, &string_type)
			             || (t->base == CLASS_T && (strcmp(t->class.type, "string") == 0)))) {
				printf(iter->data, "a << operand is not an appropriate type");
			}
			iter = iter->next;
		}

		printf("<<");
		return ret;
	}
	case SHIFT_EXPR3: {
		/* << only used for gets-from IO */
		if (!(libs.usingstd && (libs.fstream || libs.iostream)))
			printf(n, ">> can only be used with std streams in 120++");

		struct tree *l = tree_index(n, 0);
		struct tree *r = tree_index(n, 1);
		char *cin = get_identifier(l);
		if (strcmp(cin, "cin") != 0)
			printf(l, "left operand of >> is not cin");

		struct typeinfo *t = type_check(r);
		if (t == NULL)
			printf(r, "symbol undeclared");
		if (!(typeinfo_compare(t, &int_type)
		      || typeinfo_compare(t, &double_type)
		      || typeinfo_compare(t, &char_type)
		      || typeinfo_compare(t, &string_type)
		      || (t->base == CLASS_T && (strcmp(t->class.type, "string") == 0))))
			printf(r, "right operand of >> is not int, double, char, char *, or std::string");

		printf(">>");
		return NULL;

	}
	case FUNCTION_DEF1:
	case FUNCTION_DEF2: {
		/* manage scopes for function recursion */
		size_t scopes = list_size(yyscopes);

		/* retrieve class scopes */
		struct typeinfo *class = symbol_search(class_member(n));
		if (class) {
			scope_push(class->class.public);
			scope_push(class->class.private);
		}

		/* retrieve function scope */
		char *k = (production == FUNCTION_DEF1)
			? get_class(n) /* ctor function name is class name */
			: get_identifier(n);

		struct typeinfo *function = symbol_search(k);
		if (function == NULL)
			printf(n, "symbol %s undeclared", k);

		scope_push(function->function.symbols);

		/* check return type of function */
		struct tree *jump = get_production(n, JUMP3);
		struct typeinfo *ret = NULL;
		if (production == FUNCTION_DEF1)
			/* constructor always returns class */
			ret = typeinfo_return(function);
		else if (jump == NULL || tree_size(jump) == 2)
			/* no or empty return */
			ret = &void_type;
		else
			/* recurse on return value */
			ret = type_check(tree_index(jump, 1));

		if (!typeinfo_compare(ret, typeinfo_return(function))
		    /* accept void return for 0 if expecting int */
		    && (typeinfo_compare(ret, &int_type)
		        && typeinfo_compare(typeinfo_return(function), &void_type))) {
			printf(n, "return value of wrong type for function %s", k);
		}

		printf("function %s return type", k);

		/* recursive type check of children while in subscope(s) */
		struct list_node *iter = list_head(n->children);
		while (!list_end(iter)) {
			type_check(iter->data);
			iter = iter->next;
		}

		while (list_size(yyscopes) != scopes)
			scope_pop();

		return function;
	}
	case EXPR_LIST: {
		/* recurse into expression lists */
		return type_check(tree_index(n, 0));
	}
	default: {
		/* recursive search for non-expressions */
		struct list_node *iter = list_head(n->children);
		while (!list_end(iter)) {
			type_check(iter->data);
			iter = iter->next;
		}

	}
	}
	return NULL;
}

/*
 * Frees types for arrays and functions, and parameter lists.
 */
static void typeinfo_delete(struct typeinfo *t)
{
	switch (t->base) {
	case ARRAY_T: {
		typeinfo_delete(t->array.type);
		return;
	}
	case FUNCTION_T: {
		list_free(t->function.parameters);
		typeinfo_delete(t->function.type);
		return;
	}
	default:
		return;
	}
}

/*
 * Recursively compares two typeinfos.
 */
static bool typeinfo_compare(struct typeinfo *a, struct typeinfo *b)
{
	/* Two null types are the same */
	if (a == NULL && b == NULL)
		return true;

	/* Null is unlike not null */
	if (a == NULL || b == NULL)
		return false;

	/* Same base type */
	if (a->base != b->base)
		return false;

	/* Both pointers (or not) */
	if (a->pointer != b->pointer)
		return false;

	switch (a->base) {
	case ARRAY_T: {
		if (!typeinfo_compare(a->array.type, b->array.type))
			return false;

		if (a->array.size != 0 && a->array.size != b->array.size)
			return false;

		return true;
	}
	case FUNCTION_T: {
		if (!typeinfo_compare(a->function.type, b->function.type))
			return false;

		if (!typeinfo_list_compare(a->function.parameters, b->function.parameters))
			return false;

		return true;
	}
	case CLASS_T: {
		return (strcmp(a->class.type, b->class.type) == 0);
	}
	default:
		return true;
	}
}

/*
 * Compares each type of two lists of types (for functions).
 */
static bool typeinfo_list_compare(struct list *a, struct list *b)
{
	struct list_node *a_iter = list_head(a);
	struct list_node *b_iter = list_head(b);

	while (!list_end(a_iter) && !list_end(b_iter)) {
		if (!typeinfo_compare(a_iter->data, b_iter->data))
			return false;

		a_iter = a_iter->next;
		b_iter = b_iter->next;
	}
	return list_end(a_iter) && list_end(b_iter);
}

/*
 * Recursively handles nodes, processing SIMPLE_DECL1 and
 * FUNCTION_DEF2 for symbols.
 */
static bool handle_node(struct tree *n, int d)
{
	switch (get_rule(n)) {
	case SIMPLE_DECL1: { /* variable and function declarations */
		handle_init_list(typeinfo_new(n), tree_index(n, 1));
		return false;
	}
	case FUNCTION_DEF1: { /* constructor definition */
		handle_function(typeinfo_new(n), n, get_class(n));
		return false;
	}
	case FUNCTION_DEF2: { /* function or member definition */
		handle_function(typeinfo_new(n), n, get_identifier(n));
		return false;
	}
	case CLASS_SPEC: { /* class declaration */
		handle_class(typeinfo_new(n), n);
		return false;
	}
	default: /* rule did not provide a symbol, so recurse on children */
		return true;
	}
}

/*
 * Handles an init declarator recursively.
 *
 * Works for basic types, pointers, arrays, and function declarations.
 */
static void handle_init(struct typeinfo *v, struct tree *n)
{
	char *k = get_identifier(n);

	switch (get_rule(n)) {
	case INIT_DECL:
	case UNARY_EXPR4:
	case DECL2:
	case MEMBER_DECL1:
	case MEMBER_DECLARATOR1: {
		/* recurse if necessary (for pointers) */
		struct list_node *iter = list_head(n->children);
		while (!list_end(iter)) {
			if (tree_size(iter->data) != 1
			    && (get_rule(iter->data) != INITIALIZER)) {
				handle_init(v, iter->data);
				return;
			}
			iter = iter->next;
		}
		/* might not recurse */
		break;
	}
	case DIRECT_DECL2: { /* function declaration */
		v = typeinfo_new_function(n, v, false);
		break;
	}
	case DIRECT_DECL3: { /* class constructor */
		k = get_class(n);

		v->base = CLASS_T;
		v->class.type = get_class(n);
		v = typeinfo_new_function(n, v, false);
		break;
	}
	case DIRECT_DECL6: { /* array with size */
		v = typeinfo_new_array(n, v);
		if (v->array.size < 1)
			printf(n, "bad array initializer size");
		break;
	}
	default:
		printf(n, "unsupported init declaration");
	}

	if (k && v) {
		symbol_insert(k, v, n, NULL);
	} else {
		printf(n, "failed to get init declarator symbol");
	}
}

/*
 * Handles lists of init declarators recursively.
 */
static void handle_init_list(struct typeinfo *v, struct tree *n)
{
	enum rule r = get_rule(n);
	if (r == INIT_DECL_LIST2 || r == MEMBER_SPEC1 || r == MEMBER_DECL_LIST2) {
		/* recurse through lists of declarators */
		struct list_node *iter = list_head(n->children);
		while (!list_end(iter)) {
			handle_init_list(v, iter->data);
			iter = iter->next;
		}
	} else if (r == MEMBER_SPEC2) {
		/* begining of class access specifier tree */
		if (get_public(n)) {
			v->class.public = hasht_new(8, true, NULL, NULL, &symbol_free);
			scope_push(v->class.public);
		} else if (get_private(n)) {
			v->class.private = hasht_new(8, true, NULL, NULL, &symbol_free);
			scope_push(v->class.private);
		} else {
			printf(n, "unrecognized class access specifier");
		}

		handle_init_list(v, tree_index(n, 1));

		scope_pop();
	} else if (r == MEMBER_DECL1) {
		/* recurse to end of class declaration */
		handle_init_list(typeinfo_new(n), tree_index(n, 1));
	} else {
		/* process a single declaration with copy of type */
		struct typeinfo *c = typeinfo_copy(v);
		c->pointer = get_pointer(n); /* for pointers in lists */
		handle_init(c, n);
	}
}

/*
 * Handles function definitions, recursing with handle_node().
 */
static void handle_function(struct typeinfo *t, struct tree *n, char *k)
{
	struct typeinfo *v = typeinfo_new_function(n, t, true);

	size_t scopes = list_size(yyscopes);

	struct typeinfo *class = symbol_search(class_member(n));
	if (class) {
		scope_push(class->class.public);
		scope_push(class->class.private);
	}

	symbol_insert(k, v, n, v->function.symbols);

	/* recurse on children while in subscope */
	scope_push(v->function.symbols);
	tree_preorder(get_production(n, COMPOUND_STATEMENT), 0, &handle_node);

	while (list_size(yyscopes) != scopes)
		scope_pop();
}

/*
 * Handles a PARAM_DECL1 or a PARAM_DECL3 rules.
 *
 * Works for basic types, pointers, and arrays. If given a scope hash
 * table and able to find an indentifier, inserts into the scope. If
 * given a parameters list, will insert into the list.
 */
static void handle_param(struct typeinfo *v, struct tree *n, struct hasht *s, struct list *l)
{
	char *k = get_identifier(n);

	if (tree_size(n) > 3) { /* not a simple type */
		struct tree *m = tree_index(n, 1);
		enum rule r = get_rule(m);

		/* array (with possible size) */
		if (r == DIRECT_ABSTRACT_DECL4 || r == DIRECT_DECL6)
			v = typeinfo_new_array(m, v);
	}

	if (l && v)
		list_push_back(l, v);
	if (s && k && v)
		hasht_insert(s, k, v);
}

/*
 * Handles an arbitrarily nested list of parameters recursively.
 */
static void handle_param_list(struct tree *n, struct hasht *s, struct list *l)
{
	if (tree_size(n) != 1) { /* recurse on list */
		enum rule r = get_rule(n);
		if (r == PARAM_DECL1 || r == PARAM_DECL3) {
			struct typeinfo *v = typeinfo_new(n);
			v->pointer = get_pointer(n); /* for pointers in list */
			handle_param(v, n, s, l);
		} else {
			struct list_node *iter = list_head(n->children);
			while (!list_end(iter)) {
				handle_param_list(iter->data, s, l);
				iter = iter->next;
			}
		}
	}
}

/*
 * Handles a class declaration with public and/or private scopes.
 */
static void handle_class(struct typeinfo *t, struct tree *n)
{
	char *k = get_identifier(n);
	t->base = CLASS_T; /* class definition is still a class */
	handle_init_list(t, tree_index(n, 1));

	if (t->class.public == NULL) {
		t->class.public = hasht_new(2, true, NULL, NULL, &symbol_free);
	}

	if (hasht_search(t->class.public, k) == NULL) {
		struct typeinfo *ret = typeinfo_new(n);
		ret->base = CLASS_T;
		ret->class.type = k;
		struct typeinfo *ctor = typeinfo_new_function(n, ret, false);
		scope_push(t->class.public);
		symbol_insert(k, ctor, NULL, NULL);
		scope_pop();
	}

	symbol_insert(k, t, n, NULL);
}

/*
 * Given a type enum, returns its name as a static string.
 */
#define R(rule) case rule: return #rule
static char *print_basetype(struct typeinfo *t)
{
	switch (t->base) {
		R(INT_T);
		R(DOUBLE_T);
		R(CHAR_T);
		R(BOOL_T);
		R(ARRAY_T);
		R(VOID_T);
		R(UNKNOWN_T);
	case FUNCTION_T:
		return print_basetype(t->function.type);
	case CLASS_T:
		return (t->class.type) ? t->class.type : "CLASS_T";
	}

	return NULL; /* error */
}
#undef R

/*
 * Prints a realistic reprensentation of a symbol to the stream.
 *
 * Example: DOUBLE_T foobar(INT_T *, AClass)
 */
static void print_typeinfo(FILE *stream, char *k, struct typeinfo *v)
{
	if (v == NULL)
		printf("print_typeinfo(): type for %s was null", k);

	switch (v->base) {
	case INT_T:
	case DOUBLE_T:
	case CHAR_T:
	case BOOL_T:
	case VOID_T: {
		fprintf(stream, "%s", print_basetype(v));
		break;
	}
	case ARRAY_T: {
		print_typeinfo(stream, NULL, v->array.type);
		if (k)
			fprintf(stream, " %s%s",
			        (v->array.type->pointer) ? "*" : "", k);
		if (v->array.size)
			fprintf(stream, "[%zu]", v->array.size);
		else
			fprintf(stream, "[]");
		if (k)
			fprintf(stream, "\n");
		return;
	}
	case FUNCTION_T: {
		print_typeinfo(stream, NULL, v->function.type);
		fprintf(stream, " %s%s(",
		        (v->function.type->pointer) ? "*" : "", k);

		struct list_node *iter = list_head(v->function.parameters);
		while (!list_end(iter)) {
			struct typeinfo *p = iter->data;
			print_typeinfo(stream, NULL, p);
			fprintf(stream, "%s", (p->pointer) ? " *" : "");
			iter = iter->next;
			if (!list_end(iter))
				fprintf(stream, ", ");
		}
		fprintf(stream, ")\n");
		return;
	}
	case CLASS_T: {
		fprintf(stream, "%s", print_basetype(v));
		break;
	}
	case UNKNOWN_T: {
		fprintf(stream, "unknown type");
		break;
	}
	}
	if (k)
		fprintf(stream, " %s%s\n", (v->pointer) ? "*" : "", k);
}

#undef scope_current
#undef scope_push
#undef scope_pop
#undef get_rule
#undef get_token
