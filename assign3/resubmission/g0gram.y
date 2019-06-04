/* Joel Doumit
 * g0 Grammar
 * Derived from the Godiva Grammar, which was given to us
 * by Dr. J to edit. Additional Code adapted from Andrew
 * Schwartzmeyer's code for his 120++ compiler.
 */

%{
#include <stdio.h>
#include "tree.h"
#include "token.h"
#include "defines.h"


extern tree* myTree;
extern int linenum;
extern char* currentfile;
extern char* yytext;

extern struct tree *yyprogram;
extern struct list *filenames;

int yylex();
void yyerror(char *s);
void typenames_insert_tree(struct tree *t, int category);

#define E() NULL
%}

/*
 * %union declares of what kinds of values appear on the value stack
 */
%union {
   struct tree *t;
   }

/*
 * each token is declared.  tokens store leaf values on the value stack
 *
 * Back in javalex.l, we put things on the stack by assigning to yylval

 "if"           { yylval.node = alcnode(IF, 0); return IF; }

 *
 */
%token <t> BOOLEAN BREAK CLASS
%token <t> DOUBLE ELSE FOR STRING
%token <t> IF INT
%token <t> RETURN
%token <t> THIS
%token <t> D TABLE LIST UNSIZE
%token <t> VOID WHILE IDENT
%token <t> NULLLITERAL BOOLLITERAL INTLITERAL
%token <t> FLOATLITERAL STRINGLITERAL
%token <t> LP RP LC RC LB RB SM CM DOT ASN LT GT BANG COLON
%token <t> EQ NE LE GE ANDAND OROR PLUS MINUS MUL DIV AND OR SWAP
%token <t> MOD SHL SHR LSHR PLASN MIASN

/*
 * each nonterminal is declared.  nonterminals correspond to internal nodes
 */
%type <t> Goal Literal Type PrimitiveType NumericType IntegralType
%type <t> FloatingPointType ReferenceType
%type <t> ArrayType ListType TableType Name SimpleName
%type <t> QualifiedName CompilationUnit
%type <t> TypeDeclaration ClassDeclaration
%type <t> ClassBody ListFill
%type <t> ClassBodyDeclarations ClassBodyDeclaration
%type <t> ClassMemberDeclaration FieldDeclaration VariableDeclarators
%type <t> VariableDeclarator VariableDeclaratorId VariableInitializer
%type <t> MethodDeclaration MethodHeader MethodDeclarator
%type <t> FormalParameterList FormalParameter
%type <t> MethodBody ConstructorDeclaration
%type <t> ConstructorDeclarator ConstructorBody
%type <t> ArrayInitializer ArgumentList ArgumentListOpt
%type <t> VariableInitializers Block BlockStatements BlockStatement
%type <t> LocalVariableDeclarationStatement LocalVariableDeclaration
%type <t> Statement Expression Assignment StatementNoShortIf
%type <t> StatementWithoutTrailingSubstatement
%type <t> LabeledStatement AndExpression AssignmentExpression
%type <t> ExpressionStatement StatementExpression
%type <t> ForStatement ForStatementNoShortIf ForInit ForUpdate
%type <t> StatementExpressionList BreakStatement ExpressionOpt
%type <t> ReturnStatement AssignmentOperator IfThenStatement
%type <t> IfThenElseStatement IfThenElseStatementNoShortIf
%type <t> ExclusiveOrExpression InclusiveOrExpression
%type <t> ConditionalAndExpression ConditionalOrExpression
%type <t> Primary LeftHandSide ConditionalExpression
%type <t> UnaryExpression ArrayAccess LabeledStatementNoShortIf
%type <t> WhileStatement WhileStatementNoShortIf
%type <t> UnaryExpressionNotPlusMinus CastExpression
%type <t> Dims DimsOpt
%type <t> MultiplicativeExpression AdditiveExpression
%type <t> RelationalExpression EqualityExpression
%type <t> FieldAccess MethodInvocation
%type <t> CompilationUnitOpt
%type <t> ClassBodyDeclarationsOpt
%type <t> FormalParameterListOpt IDENTOpt
%type <t> BlockStatementsOpt
%type <t> VariableInitializersOpt CMOpt
%type <t> ForInitOpt ForUpdateOpt

/*
 * the start symbol, Goal, may seem to be here for rhetorical purposes,
 * but it is also the ideal spot to insert a semantic action that passes
 * the completed parse tree to a later phase of compilation.
 */
%start Goal

%%

Goal:	CompilationUnit { $$ = newt(PROGRAM, 1, $1); myTree = $$; }
		

Literal:	INTLITERAL { $$ = $1; }
		| FLOATLITERAL { $$ = $1; }
		| BOOLLITERAL { $$ = $1; }
		| STRINGLITERAL { $$ = $1; }
		| NULLLITERAL { $$ = $1; }
		;
	
Type:		PrimitiveType { $$ = $1; }
		| ReferenceType { $$ = $1; }
		;

PrimitiveType:	NumericType { $$ = $1; }
		| BOOLEAN { $$ = $1; }
		| STRING { $$ = $1; }
		;

NumericType:	IntegralType { $$ = $1; }
		| FloatingPointType { $$ = $1; }
		;

IntegralType:	INT { $$ = $1; }
		;

FloatingPointType: DOUBLE { $$ = $1; }
		;

ReferenceType: Name { $$ = $1; }
		| ArrayType { $$ = $1; }
		| ListType { $$ = $1; }
		| TableType { $$ = $1; }
		;

ListType: LIST  { $$ = $1; }
		| LIST LT Type GT { $$ = newt(LIST_TYPE2, 4, $1, $2, $3, $4); }
		;

TableType: TABLE { $$ = $1; }
		| TABLE LT Type GT { $$ = newt(TABLE_TYPE2, 4, $1, $2, $3, $4); }
		| TABLE LT Type CM Type GT { $$ = newt(TABLE_TYPE3, 6, $1, $2, $3, $4, $5, $6); }
		;

ArrayType:	  PrimitiveType LB RB { $$ = newt(ARRAY_TYPE1, 3, $1, $2, $3); }
		| Name LB RB { $$ = newt(ARRAY_TYPE2, 3, $1, $2, $3); }
		| ArrayType LB RB { $$ = newt(ARRAY_TYPE3, 3, $1, $2, $3); }
		;

Name:		  SimpleName { $$ = $1; }
		| QualifiedName { $$ = $1; }
		;

SimpleName:	IDENT { $$ = newt(SIMPLE_NAME, 1, $1); }
		;

QualifiedName:	  Name DOT IDENT { $$ = newt(QUALIFIED_NAME1, 3, $1, $2, $3); }
		;

CompilationUnit: TypeDeclaration CompilationUnitOpt { $$ = newt(COMPIL_UNIT1, 2, $1, $2); }
		| FieldDeclaration CompilationUnitOpt        { $$ = newt(COMPIL_UNIT2, 2, $1, $2); }
		| MethodDeclaration CompilationUnitOpt       { $$ = newt(COMPIL_UNIT3, 2, $1, $2); }
		;

CompilationUnitOpt: CompilationUnit { $$ = $1; }
		| %empty { $$ = NULL; }
		;

TypeDeclaration:  ClassDeclaration { $$ = $1; }
		;

ClassDeclaration: CLASS IDENT ClassBody { $$ = newt(CLASS_DECL1, 3, $1, $2, $3); }
		;

ClassBody:	  LC ClassBodyDeclarationsOpt RC { $$ = newt(CLASS_BODY1, 3, $1, $2, $3); }
		;

ClassBodyDeclarationsOpt: ClassBodyDeclarations { $$ = $1; }
	| %empty { $$ = NULL; }
	;

ClassBodyDeclarations: ClassBodyDeclaration { $$ = $1; }
		| ClassBodyDeclarations ClassBodyDeclaration { $$ = newt(CLASSBODY_DECL2, 2, $1, $2); }
		;

ClassBodyDeclaration: ClassMemberDeclaration { $$ = $1; }
		| ConstructorDeclaration { $$ = $1; }
		;

ClassMemberDeclaration: FieldDeclaration { $$ = $1; }
		| MethodDeclaration { $$ = $1; }
		;

FieldDeclaration: Type VariableDeclarators { $$ = newt(FIELD_DECL1, 2, $1, $2); }
		;

VariableDeclarators: VariableDeclarator { $$ = $1; }
		| VariableDeclarators CM VariableDeclarator { $$ = newt(VARIABLE_DECS2, 3, $1, $2, $3); }
		;

VariableDeclarator: VariableDeclaratorId { $$ = $1; }
		| VariableDeclaratorId ASN VariableInitializer { $$ = newt(VARIABLE_DECL2, 3, $1, $2, $3); }
		;

VariableDeclaratorId: IDENT { $$ = $1; }
		| VariableDeclaratorId LB RB { $$ = newt(VARIABLEDEC_ID2, 3, $1, $2, $3); }
		;

VariableInitializer: Expression { $$ = $1; }
		| ArrayInitializer { $$ = $1; }
		;

MethodDeclaration: MethodHeader MethodBody { $$ = newt(METHOD_DECL1, 2, $1, $2); }
		;

MethodHeader: Type MethodDeclarator { $$ = newt(METHOD_HEAD1, 2, $1, $2); }
		| VOID MethodDeclarator { $$ = newt(METHOD_HEAD2, 2, $1, $2); }
		;

FormalParameterListOpt: FormalParameterList { $$ = $1; }
	| %empty { $$ = NULL; }
	;

MethodDeclarator: IDENT LP FormalParameterListOpt RP { $$ = newt(METHODDEC_ER1, 4, $1, $2, $3, $4); }
		| MethodDeclarator LB RB { $$ = newt(METHODDEC_ER2, 3, $1, $2, $3); }
		;

FormalParameterList: FormalParameter { $$ = $1; }
		| FormalParameterList CM FormalParameter { $$ = newt(FORMALPARAM_LIST2, 3, $1, $2, $3); }
		;

FormalParameter: Type VariableDeclaratorId { $$ = newt(FORMAL_PARA1, 2, $1, $2); }
		;

MethodBody: Block { $$ = $1; }
		;

ConstructorDeclaration: ConstructorDeclarator
				ConstructorBody { $$ = newt(CONSTRUCTER_DELN1, 2, $1, $2); }
		;

ConstructorDeclarator: SimpleName LP FormalParameterListOpt RP { $$ = newt(CONSTRUCTER_DECL1, 4, $1, $2, $3, $4); }
		;

BlockStatementsOpt: BlockStatements { $$ = $1; }
| %empty { $$ = NULL; } ;

ConstructorBody: LC BlockStatementsOpt RC { $$ = newt(CONSTRUCTER_BODY1, 3, $1, $2, $3); }
		;

VariableInitializersOpt: VariableInitializers { $$ = $1; }
	| %empty { $$ = NULL; }
	;

CMOpt:	CM { $$ = NULL; } 
	| %empty { $$ = NULL; } 
	;

ArrayInitializer: LC VariableInitializersOpt CMOpt RC { $$ = newt(ARRAY_INIT1, 4, $1, $2, $3, $4); }
		;

VariableInitializers: VariableInitializer { $$ = $1; }
		| VariableInitializers CM VariableInitializer { $$ = newt(VARIABLEINIT_ZERS2, 3, $1, $2, $3); }
		;

Block:		  LC BlockStatementsOpt RC { $$ = newt(BLOCK1, 3, $1, $2, $3); }
		;

BlockStatements:  BlockStatement { $$ = $1; }
		| BlockStatements BlockStatement { $$ = newt(BLOCK_STMT2, 2, $1, $2); }
		;

BlockStatement:   LocalVariableDeclarationStatement { $$ = $1; }
		| Statement { $$ = $1; }
		;

ArgumentListOpt: ArgumentList { $$ = $1; }
	| %empty { $$ = NULL; }
	;

LocalVariableDeclarationStatement: LocalVariableDeclaration { $$ = $1; }
		;

LocalVariableDeclaration: Type VariableDeclarators { $$ = newt(LOCVAR_DECL1, 2, $1, $2); }
		;

Statement:	StatementWithoutTrailingSubstatement { $$ = $1; }
		| LabeledStatement { $$ = $1; }
		| IfThenStatement { $$ = $1; }
		| IfThenElseStatement { $$ = $1; }
		| WhileStatement { $$ = $1; }
		| ForStatement { $$ = $1; }
		;

StatementNoShortIf: StatementWithoutTrailingSubstatement { $$ = $1; }
		| LabeledStatementNoShortIf { $$ = $1; }
		| IfThenElseStatementNoShortIf { $$ = $1; }
		| WhileStatementNoShortIf { $$ = $1; }
		| ForStatementNoShortIf { $$ = $1; }
		;

StatementWithoutTrailingSubstatement: Block { $$ = $1; }
		| ExpressionStatement { $$ = $1; }
		| BreakStatement { $$ = $1; }
		| ReturnStatement { $$ = $1; }
		;

LabeledStatement: IDENT COLON Statement { $$ = newt(LABELED_STMT1, 3, $1, $2, $3); }
		;

LabeledStatementNoShortIf: IDENT COLON StatementNoShortIf { $$ = newt(LABELEDSTMTNOSRT_IF1, 3, $1, $2, $3); }
		;

ExpressionStatement: StatementExpression { $$ = $1; }
		;

StatementExpression: Assignment { $$ = $1; }
		| MethodInvocation { $$ = $1; }
		;

IfThenStatement:  IF LP Expression RP Statement { $$ = newt(IFTHEN_STMT1, 4, $1, $2, $3, $4); }
		;

IfThenElseStatement:  IF LP Expression RP StatementNoShortIf ELSE Statement { $$ = newt(IFTHENELSE_STMT1, 7, $1, $2, $3, $4, $5, $6, $7); }
		;

IfThenElseStatementNoShortIf:  IF LP Expression RP StatementNoShortIf
			ELSE StatementNoShortIf { $$ = newt(IFTHENELSENOSRT_IF1, 7, $1, $2, $3, $4, $5, $6, $7); }
		;

WhileStatement:	  WHILE LP Expression RP Statement { $$ = newt(WHILE_STMT1, 4, $1, $2, $3, $4); }
		;

WhileStatementNoShortIf:  WHILE LP Expression RP StatementNoShortIf { $$ = newt(WHILENOSRT_IF1, 5, $1, $2, $3, $4, $5); }
		;

ForInitOpt: ForInit { $$ = $1; }
	| %empty { $$ = NULL; }
	;

ForUpdateOpt: ForUpdate { $$ = $1; }
	| %empty { $$ = NULL; }
	;

ForInit:	StatementExpressionList { $$ = $1; }
		| LocalVariableDeclaration { $$ = $1; }
		;

ExpressionOpt: Expression { $$ = $1; }
	| %empty { $$ = NULL; }
	;

ForUpdate:	StatementExpressionList { $$ = $1; }
		;

ForStatement:	 FOR LP ForInitOpt SM ExpressionOpt SM ForUpdateOpt RP
			Statement { $$ = newt(FOR_STMT1, 9, $1, $2, $3, $4, $5, $6, $7, $8, $9); }
		;

ForStatementNoShortIf:	FOR LP ForInitOpt SM ExpressionOpt SM ForUpdateOpt RP
			StatementNoShortIf { $$ = newt(FORSTMTNOSHORT_IF1, 9, $1, $2, $3, $4, $5, $6, $7, $8, $9); }
		;

StatementExpressionList: StatementExpression { $$ = $1; }
		| StatementExpressionList CM StatementExpression { $$ = newt(STATEMENTEXPRESSION_LIST2, 3, $1, $2, $3); }
		;

IDENTOpt: IDENT { $$ = $1; }
	| %empty { $$ = NULL; }
	;

BreakStatement:	  BREAK IDENTOpt { $$ = newt(BREAK_STMT1, 2, $1, $2); }
		;

ReturnStatement:  RETURN ExpressionOpt { $$ = newt(RETURN_STMT1, 2, $1, $2); }
		;

Primary:	Literal { $$ = $1; }
		| LP Expression RP { $$ = newt(PRIMARY3, 2, $1, $2); }
		| FieldAccess { $$ = $1; }
		| ArrayAccess { $$ = $1; }
		| MethodInvocation { $$ = $1; }
		;

ArgumentList:	Expression { $$ = $1; }
		| ArgumentList CM Expression { $$ = newt(ARGS_LIST2, 3, $1, $2, $3); }
		;

DimsOpt: Dims { $$ = $1; }
	| %empty { $$ = NULL; }
	;

Dims:		LB RB { $$ = newt(DIMS1, 2, $1, $2); }
		| Dims LB RB { $$ = newt(DIMS2, 3, $1, $2, $3); }
		;

FieldAccess:	Primary DOT IDENT { $$ = newt(FIELD_ACCS1, 3, $1, $2, $3); }
		;

MethodInvocation: Name LP ArgumentListOpt RP { $$ = newt(METHOD_INVO1, 4, $1, $2, $3, $4); }
		| Primary DOT IDENT LP ArgumentListOpt RP { $$ = newt(METHOD_INVO2, 5, $1, $2, $3, $4, $5); }
		| Name LC ArgumentListOpt RC { $$ = newt(METHOD_INVO3, 3, $1, $2, $3); }
		| Primary DOT IDENT LC RC { $$ = newt(METHOD_INVO4, 5, $1, $2, $3, $4, $5); }
			;

ArrayAccess: Name LB Expression RB        { $$ = newt(ARRAY_ACCS1, 4, $1, $2, $3, $4); }
		| Primary LB Expression RB { $$ = newt(ARRAY_ACCS2, 4, $1, $2, $3, $4); }
		| Name LB Expression COLON Expression RB { $$ = newt(ARRAY_ACCS3, 4, $1, $2, $3, $4); }
		| Primary LB Expression COLON Expression RB { $$ = newt(ARRAY_ACCS4, 4, $1, $2, $3, $4); }
		;

UnaryExpression: MINUS UnaryExpression { $$ = newt(UNARY_EXPR2, 2, $1, $2); }
		| UnaryExpressionNotPlusMinus { $$ = $1; }
		;

UnaryExpressionNotPlusMinus: Primary { $$ = $1; }
		| Name { $$ = $1; }
		| BANG UnaryExpression { $$ = newt(UNARYEXPRNOTPLUS_MIN3, 2, $1, $2); }
		| D INTLITERAL { $$ = newt(UNARYEXPRNOTPLUS_MIN4, 2, $1, $2); }
		| INTLITERAL D INTLITERAL { $$ = newt(UNARYEXPRNOTPLUS_MIN5, 3, $1, $2, $3); }
		| UNSIZE IDENT { $$ = newt(UNARYEXPRNOTPLUS_MIN6, 2, $1, $2); }
		| CastExpression { $$ = $1; }
		;

CastExpression: LP PrimitiveType DimsOpt RP UnaryExpression { $$ = newt(CAST_EXPR1, 5, $1, $2, $3, $4, $5); }
		| LP Expression RP UnaryExpressionNotPlusMinus { $$ = newt(CAST_EXPR2, 4, $1, $2, $3, $4); }
		| LP Name Dims RP UnaryExpressionNotPlusMinus { $$ = newt(CAST_EXPR3, 5, $1, $2, $3, $4, $5); }
		;

MultiplicativeExpression: UnaryExpression { $$ = $1; }
		| MultiplicativeExpression MUL UnaryExpression { $$ = newt(MULT_EXPR2, 3, $1, $2, $3); }
		| MultiplicativeExpression DIV UnaryExpression { $$ = newt(MULT_EXPR3, 3, $1, $2, $3); }
		| MultiplicativeExpression MOD UnaryExpression { $$ = newt(MULT_EXPR4, 3, $1, $2, $3); }
		;

AdditiveExpression: MultiplicativeExpression { $$ = $1; }
		| AdditiveExpression PLUS MultiplicativeExpression { $$ = newt(ADD_EXPR2, 3, $1, $2, $3); }
		| AdditiveExpression MINUS MultiplicativeExpression { $$ = newt(ADD_EXPR3, 3, $1, $2, $3); }
		| STRINGLITERAL AdditiveExpression { $$ = newt(ADD_EXPR4, 2, $1, $2); }
		| AdditiveExpression STRINGLITERAL { $$ = newt(ADD_EXPR5, 2, $1, $2); }
		;

RelationalExpression: AdditiveExpression { $$ = $1; } 
		| RelationalExpression LT AdditiveExpression { $$ = newt(RELATIONAL_EXPR2, 3, $1, $2, $3); }
		| RelationalExpression GT AdditiveExpression { $$ = newt(RELATIONAL_EXPR3, 3, $1, $2, $3); }
		| RelationalExpression LE AdditiveExpression { $$ = newt(RELATIONAL_EXPR4, 3, $1, $2, $3); }
		| RelationalExpression GE AdditiveExpression { $$ = newt(RELATIONAL_EXPR5, 3, $1, $2, $3); }
		;

EqualityExpression: RelationalExpression { $$ = $1; }
		| EqualityExpression EQ RelationalExpression { $$ = newt(EQUALITY_EXPR2, 3, $1, $2, $3); }
		| EqualityExpression NE RelationalExpression { $$ = newt(EQUALITY_EXPR3, 3, $1, $2, $3); }
		;

AndExpression: EqualityExpression { $$ = $1; }
		| AndExpression AND EqualityExpression { $$ = newt(AND_EXPR2, 3, $1, $2, $3); }
		;

ExclusiveOrExpression: AndExpression { $$ = $1; }
		;

InclusiveOrExpression: ExclusiveOrExpression { $$ = $1; }
		| InclusiveOrExpression OR ExclusiveOrExpression { $$ = newt(INCLUSIVEOR_EXPR2, 3, $1, $2, $3); }
		;

ConditionalAndExpression: InclusiveOrExpression { $$ = $1; }
		| ConditionalAndExpression ANDAND InclusiveOrExpression { $$ = newt(CONDITIONALAND_EXPR2, 3, $1, $2, $3); }
		;

ConditionalOrExpression: ConditionalAndExpression { $$ = $1; }
		| ConditionalOrExpression OROR ConditionalAndExpression  { $$ = newt(CONDITIONALOR_EXPR2, 3, $1, $2, $3); }
		;

ConditionalExpression: ConditionalOrExpression { $$ = $1; }
		;

AssignmentExpression: ConditionalExpression { $$ = $1; }
		| Assignment { $$ = $1; }
		| STRINGLITERAL Assignment { $$ = newt(ASSIGN_EXPR3, 2, $1, $2); }
		| Assignment STRINGLITERAL { $$ = newt(ASSIGN_EXPR4, 2, $1, $2); }
		| LB ListFill RB { $$ = newt(ASSIGN_EXPR5, 3, $1, $2, $3); }
		;

ListFill: INTLITERAL { $$ = $1; }
		| STRINGLITERAL { $$ = $1; }
		| FLOATLITERAL { $$ = $1; }
		| NULLLITERAL { $$ = $1; }
		| ListFill CM ListFill { $$ = newt(LIST_FILL5, 3, $1, $2, $3); }
		;

Assignment:	 LeftHandSide AssignmentOperator AssignmentExpression { $$ = newt(ASSIGNMENT1, 3, $1, $2, $3); }
		| LeftHandSide SWAP AssignmentExpression { $$ = newt(ASSIGNMENT2, 3, $1, $2, $3); }
		;

LeftHandSide:	Name { $$ = $1; }
		| FieldAccess { $$ = $1; }
		| ArrayAccess { $$ = $1; }
		;

AssignmentOperator: ASN { $$ = $1; }
		| PLASN { $$ = $1; }
		| MIASN { $$ = $1; }
		;

Expression:	AssignmentExpression { $$ = $1; }
		;

%%
/*
 * Prints relevant information for syntax errors and exits returning 2
 * per assignment requirements.
 */
void yyerror(char *s)
{
    fprintf(stderr, "%s in %s:%d on token '%s'\n", s, currentfile, linenum, yytext);
	exit(2);
}
