DIG     [0-9]
LET     [a-zA-Z]
LIT     \"(\\.|[^\\"])*\"
DICE    [dD][2-9]+
DEC     [0-9]*\.[0-9]*


%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "token.h"
#include "ytab.h"

extern int yychar;
extern char *fText;
extern nodeP fStack;
extern FILE *yyin;

tokenP yytoken;
FILE *yyin_mem;
int LineNo_mem;
char* fText_mem;

void lexerr(char *s);
void tokenize(int);

int line_num = 1;
int errors = 0;
FILE *saved_yyin;
%}

%%

\n                      		{ line_num++; }
[ \t\f]+                		{ }
\/[\/]+.*										{ }
"/*"([^*]*|"*"*+[^/]*)"*/" 	{ }
"/*"([^*]*|"*"*)"/*"([^*]*|"*"*+[^/]*)"*/"([^*]*|"*"*+[^/]*)"*/" { lexerr("Nested comments not supported"); }

"identifier"            { tokenize(IDENTIFIER); return IDENTIFIER;}
"break"                 { tokenize(BREAK); 		  return BREAK; }
"class"                 { tokenize(CLASS); 		  return CLASS; }
"double"                { tokenize(DOUBLE); 	  return DOUBLE; }
"else"                  { tokenize(ELSE); 		  return ELSE; }
"false"                 { tokenize(FL); 		    return FL; }
"for"                   { tokenize(FOR); 	      return FOR; }
"if"                    { tokenize(IF); 		    return IF; }
"int"                   { tokenize(INT);        return INT; }
"list"                  { tokenize(LIST); 		  return LIST; }
"null"                  { tokenize(NUL); 		    return NUL; }
"return"                { tokenize(RETURN); 	  return RETURN; }
"d"                     { tokenize(D);          return D; }
"table"                 { tokenize(TABLE); 		  return TABLE; }
"true"                  { tokenize(TR);         return TR; }
"void"                  { tokenize(VOID); 	    return VOID; }
"while"                 { tokenize(WHILE); 	    return WHILE; }
"bool"                  { tokenize(BOOL);       return BOOL; }


"("                     { tokenize(LPAREN);     return LPAREN; }
")"                     { tokenize(RPAREN);     return RPAREN; }
"["                     { tokenize(LSUBS);      return LSUBS; }
"]"                     { tokenize(RSUBS);      return RSUBS; }
"{"                     { tokenize(LCUR);       return LCUR; }
"}"                     { tokenize(RCUR);       return RCUR; }
";"                     { tokenize(SEMIC);      return SEMIC; }
"\""                    { tokenize(QUOTE);      return QUOTE; }
"!"                     { tokenize(BANG); 	    return BANG; }
"#"                     { tokenize(UNSIZE);     return UNSIZE;}
"*"                     { tokenize(MULT);       return MULT; }
"/"                     { tokenize(DIV);        return DIV; }
"%"                     { tokenize(MOD);        return MOD; }
"+"                     { tokenize(PLUS);       return PLUS; }
"-"                     { tokenize(MINUS); 	    return MINUS; }
"<"                     { tokenize(LESS); 		  return LESS; }
"<="                    { tokenize(LESSEQ);     return LESSEQ; }
">"                     { tokenize(GREATER); 		return GREATER; }
">="                    { tokenize(GREATEREQ);  return GREATEREQ; }
"=="                    { tokenize(EQUAL);      return EQUAL; }
"!="                    { tokenize(NOTEQ);      return NOTEQ; }
"&&"                    { tokenize(LOGAND);     return LOGAND; }
"||"                    { tokenize(LOGOR);      return LOGOR; }
"="                     { tokenize(ASSIGN);     return ASSIGN; }
"+="                    { tokenize(INCREMENT);  return INCREMENT; }
"-="                    { tokenize(DECREMENT);  return DECREMENT; }
":=:"                   { tokenize(SWAP);       return SWAP; }

{LIT}                   { tokenize(STRING);     return STRING; }
{DICE}                  { tokenize(D);          return D; }
{LET}*                  { tokenize(IDENTIFIER); return IDENTIFIER; }
{DIG}+                  { tokenize(ICON);       return ICON; }
{DEC}                   { tokenize(DCON);       return DCON; }
{DEC}[e|E]{DIG}+        { tokenize(DCON);       return DCON; }

<<EOF>>                 { 

  yypop_buffer_state();
  popNode(&fStack);
  yylineno = 1;
	line_num = 1;
  if (fStack == NULL) {
    yyterminate();    
  }

  if (!YY_CURRENT_BUFFER) {
    yyterminate();
  } 

}

%%

void tokenize(int cat){
	fText = fStack -> filename;
	yytoken = createTok(cat, yytext, line_num, fText);
};

void lexerr(char *s)
{
	errors++;

	fprintf(stderr, "%s: lexical error", s);

	fprintf(stderr, ", token = \"%s\"\n", yytext);
};

/* Return 1 if done, 0 if yyin points at more inputs */
int yywrap()
{
   return 1;
}
