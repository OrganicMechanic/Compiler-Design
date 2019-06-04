%option noyywrap
%option nounput 
%option noinput
%option yylineno

%{
#include <sys/stat.h>
#include <string.h>
#include "g0gram.tab.h"
#include "token.h"
#include "cntable.h"

struct token *yytoken;
struct token *lastToken = NULL;
int firstOnLine = 0,		// track when we go to a new line
EOFSemicolonReturned = 0;	// used to track if we've returned a ; at EOF
int beginner = 0, ender = 0;
int lex(int, int, int);
int baselex(int);
struct token* MakeSemicolonToken();
struct token* CopyToken(struct token*);

char* yyfilename;
void yySetup(char*);
int yyWrapUp();
void yyLexError();
void yyLexWarning();

YY_BUFFER_STATE buff;


%}

/*body next*/

number		[0-9]+
scinote		[eE][+-]?{number}
text		([^"])|(\\.)
mlc "/*"([^*]|"*"+[^/*])*"*"+"/"
slc "//".*"\n"

%%
{mlc}		{if(strchr(yytext,'\n')!=NULL) firstOnLine=1;}
{slc}		{firstOnLine = 1;}
[ \t\r\f]+	{ /*discard whitespace*/}

\n	{firstOnLine = 1;}

"break" {return lex(1, 1, BREAK);}
"d"	{return lex(1, 0, DROLL);}
"double" {return lex(1, 0, DOUBLE);} 
"else"	{return lex(1, 0, ELSE);}
"false" {return lex(0, 1, BOOLFALSE);}
"for"	{return lex(1, 0, FOR);}
"if"	{return lex(1, 0, IF);}
"int"	{return lex(1, 0, INT);}
"null"	{return lex(0, 1, NULLVAL);}
"return" {return lex(1, 1, RETURN);}
"string" {return lex(1, 0, STRING);}
"true"	{return lex(0, 1, BOOLTRUE);}
"bool"	{return lex(1, 0, BOOL);}
"void"	{return lex(1, 0, VOID);}
"while" {return lex(1, 0, WHILE);}
"class" {return lex(1, 0, CLASS);}
"list"	{return lex(1, 0, LIST);}
"table" {return lex(1, 0, TABLE);}
("d"[0-9]+[a-zA-Z]+[a-zA-Z0-9]*|"d"[a-zA-Z]+[a-zA-Z0-9]*|[a-ce-zA-Z][a-zA-Z0-9]*) {
if(strlen(yytext) > 12) yyLexError("max variable name length of 12 exceeded");
if(lookup_cnt(cnt, yytext)) 
return lex(1,0,CLASSNAME); 
else 
return lex(1, 1, IDENTIFIER);}
{number} { return lex(0, 1, INTLIT);}
({number}*"."{number}*){scinote}? {int l = (strcmp(yytext,".")) ? DOUBLELIT : PERIOD; return lex(0, ((l == DOUBLELIT) ? 1 : 0), l);}
{number}{scinote} {return lex(0, 1, DOUBLELIT);}
"\""{text}*"\""	{return lex(0, 1, STRINGLIT);}
"\""[^"\""] {yyLexError("Unterminated String Constant");}
"(" {return lex(0, 0, LEFTPAREN);}
")" {return lex(0, 1, RIGHTPAREN);}
"[" {return lex(0, 0, LEFTSUBSCRIPT);}
"]" {return lex(0, 1, RIGHTSUBSCRIPT);}
"{" {return lex(0, 0, LEFTBRACE);}
"}" {return lex(1, 1, RIGHTBRACE);}
";" {return lex(0, 0, SEMICOLON);}
":" {return lex(0, 0, COLON);}
"!" {return lex(0, 0, LOGICALNOT);}
"#" {return lex(1, 0, SIZE);}
"*" {return lex(0, 0, MULTIPLY);}
"/" {return lex(0, 0, DIVIDE);}
"%" {return lex(0, 0, MODULUS);}
"+" {return lex(0, 0, PLUS);}
"-" {return lex(0, 0, MINUS);}
"<" {return lex(0, 0, LESSTHAN);}
"<=" {return lex(0, 0, LESSTHANOREQUAL);}
">"	{return lex(0, 0, GREATERTHAN);}
">=" {return lex(0, 0, GREATERTHANOREQUAL);}
"==" {return lex(0, 0, ISEQUALTO);}
"!=" {return lex(0, 0, NOTEQUALTO);}
"&&" {return lex(0, 0, LOGICALAND);}
"||" {return lex(0, 0, LOGICALOR);}
"=" {return lex(0, 0, EQUALS);}
"+=" {return lex(0, 0, INCREMENT);}
"-=" {return lex(0, 0, DECREMENT);}
":=:" {return lex(0, 0, SWAP);}
","	{return lex(0, 0, COMMA);}
.	{ yyLexError("Unrecognized character"); }
<<EOF>> {return yyWrapUp();/*should check to return SEMICOLON if ending on an expression*/}
%%


int lex(int validBeginner, int validEnder, int type)
{
	beginner = validBeginner;
// If we saved last token and returned a semi-colon last time
	if(lastToken != NULL)	
	{	// THEN return saved token
		yylval.tok = lastToken;
		int tcat = lastToken->category;
		lastToken = NULL;
		ender = validEnder;
		firstOnLine = 0;
		return tcat;
	}	
	else
	{
		baselex(type);
		// If first-on-a-line AND this iteration's yytoken is a valid expression beginner and last iteration's yytoken was a valid expression ending
		// or if last iterations yytoken is a valid expression ender and this token is a right brace
		if((firstOnLine && beginner && ender) || (ender && yytoken->category == RIGHTBRACE))
		{
		// THEN save_token: return a semi-colon
			lastToken = CopyToken(yytoken);
			struct token* semiToken = MakeSemicolonToken();
			yylval.tok = semiToken;
			yyless(0);	// put back the token that yylex() grabbed this iteration
			ender = validEnder;
			firstOnLine = 0;
			return SEMICOLON;
		}
		else
		{ // no semi-colon insertion, return the actual token grabbed this iteration of yylex
			yylval.tok = yytoken;
			ender = validEnder;
			firstOnLine = 0;
			return type;
		}
	}	
}

struct token* MakeSemicolonToken()
{
	struct token* t = (struct token *)malloc(sizeof(struct token));
	t->text = strdup(";");
	t->category = SEMICOLON;
	t->lineno = yylineno-1;
	t->filename = strdup(yyfilename);
	return t;
}

struct token* CopyToken(struct token* t)
{
	struct token* newToken = (struct token *)malloc(sizeof(struct token));
	newToken->category = yytoken->category;
	newToken->text = strdup(yytoken->text);
	newToken->lineno = yytoken->lineno;
	newToken->filename = strdup(yytoken->filename);
	return newToken;
}

/*helper functions*/
int baselex(int type)
{
   yytoken = (struct token *)malloc(sizeof(struct token));

   if((yytoken->text = strdup(yytext)) == NULL) {
      yyLexError("yytoken text could not be copied");
   }

   switch(type) {
      //assign ival, dval, and sval for those literal categories
      case INTLIT:
	 break;
      case DOUBLELIT:
	 break;
      case STRINGLIT:
	 break;
      default:
	 break;
   }
   yytoken->category = type;
   yytoken->lineno = yylineno;
   yytoken->filename = yyfilename;
   return type;
}

void yySetup(char* filename)
{
   struct stat st;
   if (stat(filename, &st))
      yyLexError("failed to get stat() data from file");

   if ((yyin = fopen(filename, "r")) == NULL) {
      fprintf(stderr, "cannot open '%s'\n", filename);
      fflush(stderr);
      exit(10);
      }
   if((yyfilename = strdup(filename)) == NULL)
      yyLexError("ERROR COPYING FILE NAME"); 
	
   if((buff = yy_create_buffer(yyin, st.st_size)) == NULL) {	
	printf("YY_CREATE_BUFFER FAILED TO CREATE BUFFER");
	exit(1);
	}	
   yylineno = 1;
   lastToken = NULL;
   firstOnLine = 0,		
   EOFSemicolonReturned = 0;
   beginner = 0;
   ender = 0;
}

void yyLexError(char* msg)
{
   printf("ERROR: in %s on line %d: %s\n", yyfilename, yylineno, msg);
   exit(1);	
}

void yyLexWarning(char* msg)
{
	printf("WARNING: in %s on line %d: %s\n", yyfilename, yylineno, msg);
}

int yyWrapUp()
{
	if(buff != NULL)
	{
		yy_delete_buffer(buff);
		buff = NULL;
	}

// semicolon insertion for end of file
if(ender && yytoken->category != SEMICOLON && !EOFSemicolonReturned) {
   struct token* semiToken = MakeSemicolonToken();
   yylval.tok = semiToken;
   EOFSemicolonReturned = 1;
   return SEMICOLON;
}
	return 0;
}
