/* Joel Doumit */
/* clex.l */
/* Some lines adapted from code written by Andrew Schwartzmeyer, */
/* And code given by Dr. J in class. */

%option warn nounput noinput
%option header-file="clex.h"
%option yylineno
%x COMMENT

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
#include "g0gram.tab.h"
#include "token.h"
#include "tree.h"

token* yy_token = NULL;

int linenum = 1;
extern char *currentfile;
int lexerr();


int new_token(int lexeme){
	token* nToken = malloc(sizeof(token));

	nToken -> category = lexeme;
	nToken -> text = strdup(yytext);
	nToken -> lineno = linenum;
	nToken -> filename = currentfile;

	nToken -> ival = 0;
	nToken -> dval = 0;
	nToken -> sval = "";

	switch(lexeme){
		case INTLITERAL :
			nToken -> ival = atoi(yytext);
			break;
		case FLOATLITERAL :
			nToken -> dval = atof(yytext);
			break;
		case STRINGLITERAL :
			nToken -> sval = strdup(yytext);
	
	int ss = 0; // source string
	int ls = 0; // literal string
	char literal;
	while(yytext[++ss] != '\"') {
		if(yytext[ss] == '\\') {
			ss++;
			switch(yytext[ss]) {
				case 'n':
					literal = '\n';
					break;
				case 't':
					literal = '\t';
					break;
				case 'a':
					literal = '\a';
					break;
				case 'b':
					literal = '\b';
					break;
				case 'f':
					literal = '\f';
					break;
				case 'r':
					literal = '\r';
					break;
				case 'v':
					literal = '\v';
					break;
				default:
					literal = yytext[ss];
				}
		}
		else
		{
				literal = yytext[ss];
		}
		nToken->sval[ls++] = literal;
	}
	nToken->sval[ls] = '\0';
	break;
}
yylval.t = ntree(lexeme, 0, nToken);

yy_token = nToken;
return lexeme;
};

%}

%%

\n|\r|\r\n              { linenum++; } 
[ \t\f]+                { /*whitespace*/}

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
"bool"                  { new_token(BOOL);       return BOOL; }
"list"                  { new_token(LIST);        return LIST; }
"string"                { new_token(STRING);        return STRING;}


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

<<EOF>>         { return  -1 ; }
.           { lexerr(); }

%%

struct tree *ntree(int prodrule, int n, ...) {
	va_list ap;
	int i;

	struct tree *t = calloc(1, sizeof (struct tree) +
			n * sizeof (struct tree*));
	t->prodrule = prodrule;
	t->n = n;

if (n == 0) {
		va_start(ap, n);
		t->leaf = va_arg(ap, struct token*);
		va_end(ap);
	}else{
		
		va_start(ap, n);
		for (i = 0; i < n; i++) {
			t->kids[i] = va_arg(ap, struct tree*);
		}
		va_end(ap);
		t->kids[n] = calloc(9-n, sizeof(struct tree*));
	} 
	return t;
}

int yywrap(){
	return 1;
}

int lexerr(){
	printf("Lexical error: %s:%i - Unmatched char '%s'\n",  
	currentfile, linenum, yytext);
	exit(1);
} 
