/* Joel Doumit */
/* clex.l */
/* Some lines adapted from code written by Andrew Schwartzmeyer */

%option warn nounput noinput
%option header-file="clex.h"
%option yylineno noyywrap
%x COMMENT

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

#include "list.h"
#include "tree.h"
#include "token.h"
#include "g0gram.tab.h"

struct typename {
    char *name;
    int category;
};

extern struct list *typenames;
extern struct list *filenames;
extern void handle_error(char *c);
extern char *current_filename();

struct token *yytoken = NULL;

void lexerror(const char *s);
void new_token(int category);
void handle_include(const char *s);
bool typename_compare(const char *s, const struct typename *t);
void typenames_insert(char *s, int category);
void typenames_insert_tree(struct tree *t, int category);
int check_identifier(const char *s);
%}

%%

[ \r\t\v\f\n]*          { /* eat whitespace */ }

"//".*$                 { /* eat in-line comments */ }
"/*"                    { BEGIN(COMMENT); /* eat block comments */ }
<COMMENT>{
  [^*]*           { /* eat comment in chunks */ }
  "*"+[^*/]*      { /* eat the lone star */ }
  "*"+"/"         { BEGIN(INITIAL); }
}

"ident"                 { new_token(IDENT); return IDENT;}
"break"                 { new_token(BREAK); 		  return BREAK; }
"class"                 { new_token(CLASS); 		  return CLASS; }
"double"                { new_token(DOUBLE); 	  return DOUBLE; }
"else"                  { new_token(ELSE); 		  return ELSE; }
"false"                 { new_token(BOOLLITERAL); 		    return BOOLLITERAL; }
"for"                   { new_token(FOR); 	      return FOR; }
"if"                    { new_token(IF); 		    return IF; }
"int"                   { new_token(INT);        return INT; }
"null"                  { new_token(NULLLITERAL); 		    return NULLLITERAL; }
"return"                { new_token(RETURN); 	  return RETURN; }
"d"                     { new_token(D);          return D; }
d/[0-9]+                { new_token(D);          return D; }
"table"                 { new_token(TABLE); 		  return TABLE; }
"true"                  { new_token(BOOLLITERAL);         return BOOLLITERAL; }
"void"                  { new_token(VOID); 	    return VOID; }
"while"                 { new_token(WHILE); 	    return WHILE; }
"bool"                  { new_token(BOOLEAN);       return BOOLEAN; }
"list"                  { new_token(LIST);        return LIST; }


"("                     { new_token(LP);     return LP; }
")"                     { new_token(RP);     return RP; }
"["                     { new_token(LB);      return LB; }
"]"                     { new_token(RB);      return RB; }
"{"                     { new_token(LC);       return LC; }
"}"                     { new_token(RC);       return RC; }
";"                     { new_token(SM);      return SM; }
"\""                    { new_token(STRINGLITERAL);      return STRINGLITERAL; }
"!"                     { new_token(BANG); 	    return BANG; }
"#"                     { new_token(UNSIZE);     return UNSIZE;}
"*"                     { new_token(MUL);       return MUL; }
"/"                     { new_token(DIV);        return DIV; }
"%"                     { new_token(MOD);        return MOD; }
"+"                     { new_token(PLUS);       return PLUS; }
"-"                     { new_token(MINUS); 	    return MINUS; }
"<"                     { new_token(LT); 		  return LT; }
"<="                    { new_token(LE);     return LE; }
">"                     { new_token(GT); 		return GT; }
">="                    { new_token(GE);  return GE; }
"=="                    { new_token(EQ);      return EQ; }
"!="                    { new_token(NE);      return NE; }
"&&"                    { new_token(ANDAND);     return ANDAND; }
"||"                    { new_token(OROR);      return OROR; }
"="                     { new_token(ASN);     return ASN; }
"+="                    { new_token(PLASN);  return PLASN; }
"-="                    { new_token(MIASN);  return MIASN; }
":=:"                   { new_token(SWAP);       return SWAP; }
"."                     { new_token(DOT);       return DOT; }
","                     { new_token(CM);       return CM; }

{LIT}                   { new_token(STRINGLITERAL);     return STRINGLITERAL; }
{DICE}                  { new_token(D);          return D; }
[a-zA-Z][a-zA-Z0-9]*    { new_token(IDENT); return IDENT; }
{DIG}+                  { new_token(INTLITERAL);       return INTLITERAL; }
{DEC}                   { new_token(FLOATLITERAL);       return FLOATLITERAL; }
{DEC}[e|E]{DIG}+        { new_token(FLOATLITERAL);       return FLOATLITERAL; }

<<EOF>>                 { 

  yypop_buffer_state();
  list_pop(filenames);

  /* if there's another file to process, chdir to it */
  char *filename = current_filename();
  if (filename) {
    chdir(dirname(filename));
    free(filename);
  }

  yylineno = 1; /* restart line numbering count */

  if (!YY_CURRENT_BUFFER) /* if buffer stack is empty, stop */
    yyterminate();
  }

%%

/*
 * Prints relevant information for lexical errors and exits returning 1
 * per assignment requirements;
 */
void lexerror(const char *s)
{
  fprintf(stderr, "Lexical error: file %s, line %d, token %s: %s\n",
          (const char *)list_peek(filenames), yylineno, yytext, s);
  exit(1);
}

/*
 * Creates a token with the necessary information, then allocates a
 * tree node as a leaf for the token, saving it into yylval for Bison.
 */
void new_token(int category)
{
  yytoken = token_create(category, yylineno, yytext,
                                       (const char *)list_peek(filenames));
  yylval.t = tree_init(NULL, yytoken);
}

/*
 * Given yytext of the literal form "somefile.h", this extracts the
 * substring corresponding to the path, determines the full path to
 * the file, pushes that path to the filenames list, opens the file
 * into yyin, resets the line number count to 1, and pushes a new Flex
 * buffer for the file.
 */
void handle_include(const char *s)
{
  /* get the include path */
  size_t len = strlen(s) - 2; /* size without surrounding quotes */
  char *include = calloc(len+1, sizeof(char));
  if (include == NULL)
    handle_error("handle include buffer");
  strncpy(include, s+1, len); /* copy substring */
  include[len] = '\0';

  /* get the real path */
  char *filename = realpath(include, NULL);
  if (filename == NULL) {
    fprintf(stderr, "Could not resolve path to included file: %s, included from %s\n", include, current_filename());
    exit(EXIT_FAILURE);
  }
  free(include);
  list_push(filenames, filename);

  /* open file and push buffer */
  yyin = fopen(filename, "r");
  if (yyin == NULL) {
    fprintf(stderr, "Could not open included file: %s, include from %s\n", filename, current_filename());
    exit(EXIT_FAILURE);
  }
  yylineno = 1;
  yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));

  return;
}

/*
 * Returns true if given name string matches the typename's name.
 */
bool typename_compare(const char *s, const struct typename *t)
{
  return 0 == strcmp(s, t->name);
}

/*
 * Given name string and integer category, inserts a new typename into
 * typenames list.
 */
void typenames_insert(char *s, int category)
{
  struct list_node *l = list_find(typenames, (void *)s,
          (bool (*)(void *, void *))&typename_compare);
  if (!list_end(l)) {
    lexerror("token previously declared as IDENT");
  }
  struct typename *type = malloc(sizeof(*type));
  type->name = strdup(s);
  type->category = category;
  list_push(typenames, type);
}

/*
 * Unwraps a tree leaf and passes token text as name to insert
 * function.
 */
void typenames_insert_tree(struct tree *t, int category)
{
  typenames_insert(((struct token *)t->data)->text, category);
}

/*
 * Returns corresponding integer category for given IDENT name
 * and creates the necessary token.
 */
int check_identifier(const char *s)
{
  struct list_node *l = list_find(typenames, (void *)s,
          (bool (*)(void *, void *))&typename_compare);
  if (list_end(l)) {
    new_token(IDENT);
    return IDENT;
  }
  else {
    int category = ((struct typename *)l->data)->category;
    new_token(category);
    return category;
  }
}
