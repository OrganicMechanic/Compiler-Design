/*
 * lexer.l - Flex scanner for 120++.
 *
 * Copyright (C) 2014 Andrew Schwartzmeyer
 *
 * This file released under the AGPLv3.
 *
 */

%option warn nounput noinput
%option header-file="lexer.h"
%option yylineno noyywrap
%x COMMENT STR CHR CHREND INC

DIG     [0-9]
LET     [a-zA-Z]
LIT     \"(\\.|[^\\"])*\"
DICE    [dD][2-9]+
DEC     [0-9]*\.[0-9]*

%{

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <libgen.h>

#include "logger.h"
#include "token.h"
#include "parser.tab.h"

#include "list.h"
#include "tree.h"
#include "hasht.h"

/* syntactic action helpers */
#define TOKEN(name) do { prepare_token(name); return name; } while(0)
#define YYAPPENDTEXT() token_push_text(yytoken, yytext)
#define YYAPPENDCHAR(character) token_push_sval_char(yytoken, character)

/* from main */
extern struct list *filenames;
void chdirname(char *c);

/* from parser */
void delete_tree(void *data, bool leaf);

/* creation of tokens */
static struct token *yytoken;
static void prepare_token(int category);

/* handle #include files */
static void handle_include(const char *s);

/* typenames data */
struct hasht *typenames;
void insert_typename(char *k, int c);
void insert_typename_tree(struct tree *t, int category);
static int check_identifier(const char *s);

%}

%%

[ \r\t\v\f\n]*          { /* eat whitespace */ }

"//".*$                 { /* eat C++ comments */ }

"/*"                    { BEGIN(COMMENT); /* eat C comments */ }

<COMMENT>{
        [^*]*           { /* eat comment in chunks */ }
        "*"+[^*/]*      { /* eat the lone star */ }
        "*"+"/"         { BEGIN(INITIAL); }
}

  /* keywords */
"ident"                 { TOKEN(IDENT); }
"break"                 { TOKEN(BREAK); }
"class"                 { TOKEN(CLASS); }
"double"                { TOKEN(DOUBLE); }
"else"                  { TOKEN(ELSE); }
"false"                 { TOKEN(BOOLLITERAL); }
"for"                   { TOKEN(FOR); }
"if"                    { TOKEN(IF); }
"int"                   { TOKEN(INT); }
"null"                  { TOKEN(NULLLITERAL); }
"return"                { TOKEN(RETURN); }
"d"                     { TOKEN(D); }
d/[0-9]+                { TOKEN(D); }
"table"                 { TOKEN(TABLE); }
"true"                  { TOKEN(BOOLLITERAL); }
"void"                  { TOKEN(VOID); }
"while"                 { TOKEN(WHILE); }
"bool"                  { TOKEN(BOOLEAN); }
"list"                  { TOKEN(LIST); }

  /* unsupported keywords */
"const"                 { /* const qualifier is discarded */ }
"auto"                  |
"..."                   |
"enum"                  |
"extern"                |
"friend"                |
"goto"                  |
"namespace"             |
"register"              |
"static"                |
"this"                  |
"typedef"               |
"union"                 |
"using"                 |
"virtual"               |
"volatile"              { log_unsupported(); }

{LIT}                   { TOKEN(STRINGLITERAL); }
{DICE}                  { TOKEN(D); }
[a-zA-Z][a-zA-Z0-9]*    { TOKEN(IDENT); }
{DIG}+                  { TOKEN(INTLITERAL); }
{DEC}                   { TOKEN(FLOATLITERAL); }
{DEC}[e|E]{DIG}+        { TOKEN(FLOATLITERAL); }

  /* string literal */
\"                      { prepare_token(STRING); BEGIN(STR); }

  /* operators */
"("                     { TOKEN(LP); }
")"                     { TOKEN(RP); }
"["                     { TOKEN(LB); }
"]"                     { TOKEN(RB); }
"{"                     { TOKEN(LC); }
"}"                     { TOKEN(RC); }
";"                     { TOKEN(SM); }
"\""                    { TOKEN(STRINGLITERAL); }
"!"                     { TOKEN(BANG); }
"#"                     { TOKEN(UNSIZE); }
"*"                     { TOKEN(MUL); }
"/"                     { TOKEN(DIV); }
"%"                     { TOKEN(MOD); }
"+"                     { TOKEN(PLUS); }
"-"                     { TOKEN(MINUS); }
"<"                     { TOKEN(LT); }
"<="                    { TOKEN(LE); }
">"                     { TOKEN(GT); }
">="                    { TOKEN(GE); }
"=="                    { TOKEN(EQ); }
"!="                    { TOKEN(NE); }
"&&"                    { TOKEN(ANDAND); }
"||"                    { TOKEN(OROR); }
"="                     { TOKEN(ASN); }
"+="                    { TOKEN(PLASN); }
"-="                    { TOKEN(MIASN); }
":=:"                   { TOKEN(SWAP); }
"."                     { TOKEN(DOT); }
","                     { TOKEN(CM); }

  /* identifer */
{LET}({LET}|{DIG})*           { return check_identifier(yytext); }

<*>.                    { log_lexical("Unrecognized token"); }

<<EOF>>                 { /* pop the current buffer and filename */
                          yypop_buffer_state();
                          list_pop_back(filenames);

                          /* if there's another file to process, chdir to it */
                          char *filename = list_back(filenames);
                          if (filename)
                                  chdirname(filename);

                          yylineno = 1; /* restart line numbering count */

                          /* if buffer stack is empty, stop */
                          if (!YY_CURRENT_BUFFER)
                                  yyterminate(); }
%%

/*
 * Creates a token with the necessary information, then allocates a
 * tree node as a leaf for the token, saving it into yylval for Bison.
 */
void prepare_token(int category)
{
	yytoken = token_new(category, yylineno, yytext,
                            (const char *)list_back(filenames));
	yylval.t = tree_new(NULL, yytoken, NULL,
                            (void (*)(void *, bool))&delete_tree);
}

/*
 * Insert "string" into typenames hash table.
 */
void handle_string()
{
	if (!hasht_search(typenames, "string"))
		insert_typename("string", CLASS);
}

/*
 * Inserts typename into typenames hash table.
 *
 * Copies both the typename string (key) and integer category (value)
 * so that a) the table can be freed later b) the table is not
 * dependent on the source of the typename and c) the table wants
 * void*, not a plain int.
 */
void insert_typename(char *k, int c)
{
	char *key = strdup(k);
	int *i = malloc(sizeof(*i));
	log_assert(key && i);

	*i = c;

	if (hasht_search(typenames, key))
		log_lexical("Typename %s previously declared", k);

	if (hasht_insert(typenames, key, i) == NULL)
		log_error("Failed to insert into typenames table");
}

/*
 * Unwraps a tree leaf and inserts token's text as key with category
 * as value into typenames hash table.
 */
void insert_typename_tree(struct tree *t, int category)
{
	char *key = ((struct token *)t->data)->text;
	insert_typename(key, category);
}

void free_typename(struct hash_node *t)
{
	free(t->key);
	free(t->value);
}

/*
 * Returns corresponding integer category for given identifier name
 * and creates the necessary token.
 */
int check_identifier(const char *s)
{
	int *c = hasht_search(typenames, (void *)s);
	if (c)
		TOKEN(*c);
	else
		TOKEN(IDENT);
}

#undef TOKEN
#undef YYAPPENDTEXT
#undef YYAPPENDCHAR
