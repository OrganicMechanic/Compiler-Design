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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "gram.tab.h"
#include "token.h"
#include "tree.h"

struct token *yytoken = NULL;

int linecount = 1;
extern char *currentfile;
int lexerr();
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

int yywrap(){
  return 1;
}
int lexerr(){
  printf("Lex error: %s:%i - unmatched char '%s'\n",  
    currentfile, linecount, yytext);
  exit(1);
}

struct tree *newt(int prodrule, int nkids, ...) {
    va_list ap;
  int i;

    struct tree *t = calloc(1, sizeof (struct tree) +
            nkids * sizeof (struct tree*));
    t->prodrule = prodrule;
    t->nkids = nkids;

  if (nkids == 0) { //Terminal
        va_start(ap, nkids);
        t->leaf = va_arg(ap, struct token*);
        va_end(ap);
    }else{  //Nonterminal
        
        va_start(ap, nkids);           
        for (i = 0; i < nkids; i++) {
            t->child[i] = va_arg(ap, struct tree*);
        }
        va_end(ap);
        //t->child[nkids] = calloc(9-nkids, sizeof(struct tree*));
    } 
    return t;
}

int makeToken(int lexeme ){
  token* newToken = malloc(sizeof(token));

  new_token -> category = lexeme;
  new_token -> text = strdup(yytext);  
  new_token -> lineno = linecount;     
  new_token -> filename = currentfile; 
  new_token -> ival = 0;       
  new_token -> dval = 0;       
  new_token -> sval = "";       


  switch(lexeme){
    case INTLITERAL :
      new_token -> ival = atoi(yytext);     
      break;
    case FLOATLITERAL :
      new_token -> dval = atof(yytext);  
      break;
    case STRINGLITERAL :
      new_token -> sval = strdup(yytext);     
      
      int i = 0; //for source string
      int j = 0; //for literal string
      char literal;
      while(yytext[++i] != '\"'){ //++ skips initial " and iterates.
        if(yytext[i] == '\\'){
          i++;
          switch(yytext[i]){
            case 'a':
              literal = '\a';
              break;
            case 'b':
              literal = '\b';
              break;
            case 'f':
              literal = '\f';
              break;
            case 'n':
              literal = '\n';
              break;
            case 'r':
              literal = '\r';
              break;
            case 't':
              literal = '\t';
              break;
            case 'v':
              literal = '\v';
              break;
            default: //works for \\ and \" as well.
              literal = yytext[i];
          }
        }else{
          literal = yytext[i];
        }
        new_token->sval[j++] = literal;
      }
      new_token->sval[j] = '\0';
      break;
  }
  yylval.t = newt(lexeme,0,newToken);
  
  yy_token = newToken;
  return lexeme;
};
