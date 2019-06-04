/* 
 * Joel Doumit
 * token.h, based off the token structure given to us in class by Dr. J
 */
#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

typedef struct token {
	int category;   /* the integer code returned by yylex */
	char *text;     /* the actual string (lexeme) matched */
	int lineno;     /* the line number on which the token occurs */
	char *filename; /* the source file in which the token occurs */
	int ival;       /* for integer constants, store binary value here */
	double dval;	/* for real constants, store binary value here */
	char *sval;     /* for string constants, malloc space, de-escape, store */
}token;

typedef struct tokenlist {
 struct token *t;
 struct tokenlist *next;
}tokenlist;

#endif