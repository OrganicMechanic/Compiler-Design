/* Joel Doumit
 * token.h 
 * Code written by Andrew Schwartzmeyer for his 120++ compiler.
 */

#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>

/* Given by Dr. J */
struct token
{
	int category;
	int linenum;
	char *text;
	char *filename;
	int ival;
	double fval;
	char *sval;
	size_t ssize;
};

struct token *token_create(int category, int lineno,
                           const char *text, const char* filename);
void token_destroy(struct token *t);
void token_append_sval_char(struct token *t, char c);
void token_append_sval_string(struct token *t, const char *s);
void token_append_text(struct token *t, const char* s);
void token_finish_sval();

#endif /* TOKEN_H */
