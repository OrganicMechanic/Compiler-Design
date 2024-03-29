/* Joel Doumit
 * token.c
 *
 * Adapted from code written by Andrew Schwartzmeyer
 * for his 120++ compiler.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "token.h"
#include "cgram.tab.h"

#define TEXT_CHUNK_SIZE 128

extern void handle_error(char *c);

size_t token_sval_size = 0;

/* malloc token and assign values */
struct token *token_create(int category, int lineno,
                           const char *text, const char* filename)
{
	struct token *t = malloc(sizeof(*t));
	if (t == NULL)
		handle_error("token create");

	t->category = category;
	t->lineno = lineno;

	t->text = strdup(text);

	t->filename = strdup(filename);

	if (category == INTEGER)
		t->ival = atoi(text);

	if (category == FLOATING)
		t->fval = atof(text);

	if (category == STRING) {
		t->ssize = 0; /* append null later */
		token_sval_size = TEXT_CHUNK_SIZE;
		t->sval = calloc(token_sval_size, sizeof(char));
	}

	return t;
}

/* free internal values */
void token_destroy(struct token *t)
{
	free(t->text);
	free(t->filename);
	if (t->category == STRING)
		free(t->sval);
	free(t);
}

/*
 * reallocate t->sval with additional chunks of memory
 */
void token_realloc_sval(struct token *t)
{
	while (t->ssize > token_sval_size)
		token_sval_size += TEXT_CHUNK_SIZE;

	t->sval = realloc(t->sval, token_sval_size);
	if (t->sval == NULL)
		handle_error("token_sval");
}

/*
 * append a single char to sval (used for processing escape codes)
 */
void token_append_sval_char(struct token *t, char c)
{
	++t->ssize;
	token_realloc_sval(t);
	t->sval[t->ssize-1] = c; /* 0 indexed */
}

/*
 * append a string (without escape codes) to sval
 */
void token_append_sval_string(struct token *t, const char *s)
{
	size_t end = t->ssize;
	t->ssize += strlen(s);
	token_realloc_sval(t);
	memcpy(t->sval + end, s, strlen(s));
}

/*
 * called at end of string pattern
 */
void token_finish_sval(struct token *t)
{
	token_sval_size = 0;
	++t->ssize;
	token_append_sval_char(t, '\0');
	t->sval = realloc(t->sval, t->ssize);
	if (t->sval == NULL)
		handle_error("finish sval");
}

/*
 * reallocate text field to append string and terminating null
 */
void token_realloc_text(struct token *t, const char *s)
{
	size_t size = strlen(t->text)+strlen(s)+1;
	t->text = realloc(t->text, size);
	if (t->text == NULL)
		handle_error("token text");
}

/*
 * append string to text field (these are actual null terminated
 * strings, so the issues with sval do not apply)
 */
void token_append_text(struct token *t, const char* s)
{
	token_realloc_text(t, s);
	strcat(t->text, s);
}
