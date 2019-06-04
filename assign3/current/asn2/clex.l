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

#include "tree.h"
#include "token.h"
#include "g0gram.tab.h"

struct token *yytoken = NULL;


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

