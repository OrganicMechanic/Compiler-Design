/* Joel Doumit
 * g0 Grammar
 * Derived from the Godiva Grammar, which was given to us
 * by Dr. J to edit. Additional Code adapted from Andrew
 * Schwartzmeyer's code for his 120++ compiler.
 */

%{
#include <stdio.h>
#include "tree.h"

#include "clex.h"
#include "list.h"
#include "tree.h"

extern struct tree *yyprogram;
extern struct list *filenames;

void yyerror(const char *s);
void typenames_insert_tree(struct tree *t, int category);

#define P(name, ...) tree_initv(NULL, #name, __VA_ARGS__)
#define E() NULL
%}

/*
 * %union declares of what kinds of values appear on the value stack
 */
%union {
   struct tree *t;
   }

%token-table

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

Goal:	CompilationUnit { $$ = P(program, 1, $1); yyprogram = $$; }
		

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
		| LIST LT Type GT { $$ = P(List-Type2, 4, $1, $2, $3, $4); }
		;

TableType: TABLE { $$ = $1; }
		| TABLE LT Type GT { $$ = P(Table-Type2, 4, $1, $2, $3, $4); }
		| TABLE LT Type CM Type GT { $$ = P(Table-Type3, 6, $1, $2, $3, $4, $5, $6); }
		;

ArrayType:	  PrimitiveType LB RB { $$ = P(Array-Type1, 3, $1, $2, $3); }
		| Name LB RB { $$ = P(Array-Type2, 3, $1, $2, $3); }
		| ArrayType LB RB { $$ = P(Array-Type3, 3, $1, $2, $3); }
		;

Name:		  SimpleName { $$ = $1; }
		| QualifiedName { $$ = $1; }
		;

SimpleName:	IDENT { $$ = $1; }
		;

QualifiedName:	  Name DOT IDENT { $$ = P(Qualified-Name1, 3, $1, $2, $3); }
		;

CompilationUnit: TypeDeclaration CompilationUnitOpt { $$ = P(Compil-Unit1, 2, $1, $2); }
		| FieldDeclaration CompilationUnitOpt        { $$ = P(Compil-Unit2, 2, $1, $2); }
		| MethodDeclaration CompilationUnitOpt       { $$ = P(Compil-Unit3, 2, $1, $2); }
		;

CompilationUnitOpt: CompilationUnit { $$ = $1; }
		| { $$ = NULL; }
		;

TypeDeclaration:  ClassDeclaration { $$ = $1; }
		;

ClassDeclaration: CLASS IDENT ClassBody { $$ = P(Class-Decl1, 3, $1, $2, $3); }
		;

ClassBody:	  LC ClassBodyDeclarationsOpt RC { $$ = P(Class-Body1, 3, $1, $2, $3); }
		;

ClassBodyDeclarationsOpt: ClassBodyDeclarations { $$ = $1; }
	| { $$ = NULL; }
	;

ClassBodyDeclarations: ClassBodyDeclaration { $$ = $1; }
		| ClassBodyDeclarations ClassBodyDeclaration { $$ = P(ClassBody-Decl2, 2, $1, $2); }
		;

ClassBodyDeclaration: ClassMemberDeclaration { $$ = $1; }
		| ConstructorDeclaration { $$ = $1; }
		;

ClassMemberDeclaration: FieldDeclaration { $$ = $1; }
		| MethodDeclaration { $$ = $1; }
		;

FieldDeclaration: Type VariableDeclarators { $$ = P(Field-Decl1, 2, $1, $2); }
		;

VariableDeclarators: VariableDeclarator { $$ = $1; }
		| VariableDeclarators CM VariableDeclarator { $$ = P(Variable-Decs2, 3, $1, $2, $3); }
		;

VariableDeclarator: VariableDeclaratorId { $$ = $1; }
		| VariableDeclaratorId ASN VariableInitializer { $$ = P(Variable-Decl2, 3, $1, $2, $3); }
		;

VariableDeclaratorId: IDENT { $$ = $1; }
		| VariableDeclaratorId LB RB { $$ = P(VariableDec-Id2, 3, $1, $2, $3); }
		;

VariableInitializer: Expression { $$ = $1; }
		| ArrayInitializer { $$ = $1; }
		;

MethodDeclaration: MethodHeader MethodBody { $$ = P(Method-Decl1, 2, $1, $2); }
		;

MethodHeader: Type MethodDeclarator { $$ = P(Method-Head1, 2, $1, $2); }
		| VOID MethodDeclarator { $$ = P(Method-Head2, 2, $1, $2); }
		;

FormalParameterListOpt: FormalParameterList { $$ = $1; }
	| { $$ = NULL; }
	;

MethodDeclarator: IDENT LP FormalParameterListOpt RP { $$ = P(MethodDec-er1, 4, $1, $2, $3, $4); }
		| MethodDeclarator LB RB { $$ = P(MethodDec-er2, 3, $1, $2, $3); }
		;

FormalParameterList: FormalParameter { $$ = $1; }
		| FormalParameterList CM FormalParameter { $$ = P(FormalParam-List2, 3, $1, $2, $3); }
		;

FormalParameter: Type VariableDeclaratorId { $$ = P(Formal-Para1, 2, $1, $2); }
		;

MethodBody: Block { $$ = $1; }
		;

ConstructorDeclaration: ConstructorDeclarator
				ConstructorBody { $$ = P(Constructer-Deln1, 2, $1, $2); }
		;

ConstructorDeclarator: SimpleName LP FormalParameterListOpt RP { $$ = P(Constructer-Decl1, 4, $1, $2, $3, $4); }
		;

BlockStatementsOpt: BlockStatements { $$ = $1; }
| { $$ = NULL; } ;

ConstructorBody: LC BlockStatementsOpt RC { $$ = P(Constructer-Body1, 3, $1, $2, $3); }
		;

VariableInitializersOpt: VariableInitializers { $$ = $1; }
	| { $$ = NULL; }
	;

CMOpt:	CM { $$ = NULL; } 
	| { $$ = NULL; } 
	;

ArrayInitializer: LC VariableInitializersOpt CMOpt RC { $$ = P(Array-Init1, 4, $1, $2, $3, $4); }
		;

VariableInitializers: VariableInitializer { $$ = $1; }
		| VariableInitializers CM VariableInitializer { $$ = P(VariableInit-zers2, 3, $1, $2, $3); }
		;

Block:		  LC BlockStatementsOpt RC { $$ = P(Block1, 3, $1, $2, $3); }
		;

BlockStatements:  BlockStatement { $$ = $1; }
		| BlockStatements BlockStatement { $$ = P(Block-Stmt2, 2, $1, $2); }
		;

BlockStatement:   LocalVariableDeclarationStatement { $$ = $1; }
		| Statement { $$ = $1; }
		;

ArgumentListOpt: ArgumentList { $$ = $1; }
	| { $$ = NULL; }
	;

LocalVariableDeclarationStatement: LocalVariableDeclaration { $$ = $1; }
		;

LocalVariableDeclaration: Type VariableDeclarators { $$ = P(LocVar-Decl1, 2, $1, $2); }
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

LabeledStatement: IDENT COLON Statement { $$ = P(Labeled-Stmt1, 3, $1, $2, $3); }
		;

LabeledStatementNoShortIf: IDENT COLON StatementNoShortIf { $$ = P(LabeledStmtNoSrt-If1, 3, $1, $2, $3); }
		;

ExpressionStatement: StatementExpression { $$ = $1; }
		;

StatementExpression: Assignment { $$ = $1; }
		| MethodInvocation { $$ = $1; }
		;

IfThenStatement:  IF LP Expression RP Statement { $$ = P(IfThen-Stmt1, 4, $1, $2, $3, $4); }
		;

IfThenElseStatement:  IF LP Expression RP StatementNoShortIf ELSE Statement { $$ = P(IfThenElse-Stmt1, 7, $1, $2, $3, $4, $5, $6, $7); }
		;

IfThenElseStatementNoShortIf:  IF LP Expression RP StatementNoShortIf
			ELSE StatementNoShortIf { $$ = P(IfThenElseNoSrt-If1, 7, $1, $2, $3, $4, $5, $6, $7); }
		;

WhileStatement:	  WHILE LP Expression RP Statement { $$ = P(While-Stmt1, 4, $1, $2, $3, $4); }
		;

WhileStatementNoShortIf:  WHILE LP Expression RP StatementNoShortIf { $$ = P(WhileNoSrt-If1, 5, $1, $2, $3, $4, $5); }
		;

ForInitOpt: ForInit { $$ = $1; }
	| { $$ = NULL; }
	;

ForUpdateOpt: ForUpdate { $$ = $1; }
	| { $$ = NULL; }
	;

ForInit:	StatementExpressionList { $$ = $1; }
		| LocalVariableDeclaration { $$ = $1; }
		;

ExpressionOpt: Expression { $$ = $1; }
	| { $$ = NULL; }
	;

ForUpdate:	StatementExpressionList { $$ = $1; }
		;

ForStatement:	 FOR LP ForInitOpt SM ExpressionOpt SM ForUpdateOpt RP
			Statement { $$ = P(For-Stmt1, 9, $1, $2, $3, $4, $5, $6, $7, $8, $9); }
		;

ForStatementNoShortIf:	FOR LP ForInitOpt SM ExpressionOpt SM ForUpdateOpt RP
			StatementNoShortIf { $$ = P(ForStmtNoShort-If1, 9, $1, $2, $3, $4, $5, $6, $7, $8, $9); }
		;

StatementExpressionList: StatementExpression { $$ = $1; }
		| StatementExpressionList CM StatementExpression { $$ = P(StatementExpression-List2, 3, $1, $2, $3); }
		;

IDENTOpt: IDENT { $$ = $1; }
	| { $$ = NULL; }
	;

BreakStatement:	  BREAK IDENTOpt { $$ = P(Break-Stmt1, 2, $1, $2); }
		;

ReturnStatement:  RETURN ExpressionOpt { $$ = P(Return-Stmt1, 2, $1, $2); }
		;

Primary:	Literal { $$ = $1; }
		| LP Expression RP { $$ = P(Primary3, 2, $1, $2); }
		| FieldAccess { $$ = $1; }
		| ArrayAccess { $$ = $1; }
		| MethodInvocation { $$ = $1; }
		;

ArgumentList:	Expression { $$ = $1; }
		| ArgumentList CM Expression { $$ = P(Args-List2, 3, $1, $2, $3); }
		;

DimsOpt: Dims { $$ = $1; }
	| { $$ = NULL; }
	;

Dims:		LB RB { $$ = P(Dims1, 2, $1, $2); }
		| Dims LB RB { $$ = P(Dims2, 3, $1, $2, $3); }
		;

FieldAccess:	Primary DOT IDENT { $$ = P(Field-Accs1, 3, $1, $2, $3); }
		;

MethodInvocation: Name LP ArgumentListOpt RP { $$ = P(Method-Invo1, 4, $1, $2, $3, $4); }
		| Primary DOT IDENT LP ArgumentListOpt RP { $$ = P(Method-Invo2, 5, $1, $2, $3, $4, $5); }
		| Name LC ArgumentListOpt RC { $$ = P(Method-Invo4, 3, $1, $2, $3); }
		| Primary DOT IDENT LC RC { $$ = P(Method-Invo5, 5, $1, $2, $3, $4, $5); }
			;

ArrayAccess: Name LB Expression RB        { $$ = P(Array-Accs1, 4, $1, $2, $3, $4); }
		| Primary LB Expression RB { $$ = P(Array-Accs2, 4, $1, $2, $3, $4); }
		| Name LB Expression COLON Expression RB { $$ = P(Array-Accs3, 4, $1, $2, $3, $4); }
		| Primary LB Expression COLON Expression RB { $$ = P(Array-Accs4, 4, $1, $2, $3, $4); }
		;

UnaryExpression: MINUS UnaryExpression { $$ = P(Unary-Expr2, 2, $1, $2); }
		| UnaryExpressionNotPlusMinus { $$ = $1; }
		;

UnaryExpressionNotPlusMinus: Primary { $$ = $1; }
		| Name { $$ = $1; }
		| BANG UnaryExpression { $$ = P(UnaryExprNotPlus-Min3, 2, $1, $2); }
		| D INTLITERAL { $$ = P(UnaryExprNotPlus-Min4, 2, $1, $2); }
		| INTLITERAL D INTLITERAL { $$ = P(UnaryExprNotPlus-Min5, 3, $1, $2, $3); }
		| UNSIZE IDENT { $$ = P(UnaryExprNotPlus-Min6, 2, $1, $2); }
		| CastExpression { $$ = $1; }
		;

CastExpression: LP PrimitiveType DimsOpt RP UnaryExpression { $$ = P(Cast-Expr1, 5, $1, $2, $3, $4, $5); }
		| LP Expression RP UnaryExpressionNotPlusMinus { $$ = P(Cast-Expr2, 4, $1, $2, $3, $4); }
		| LP Name Dims RP UnaryExpressionNotPlusMinus { $$ = P(Cast-Expr3, 5, $1, $2, $3, $4, $5); }
		;

MultiplicativeExpression: UnaryExpression { $$ = $1; }
		| MultiplicativeExpression MUL UnaryExpression { $$ = P(Mult-Expr2, 3, $1, $2, $3); }
		| MultiplicativeExpression DIV UnaryExpression { $$ = P(Mult-Expr3, 3, $1, $2, $3); }
		| MultiplicativeExpression MOD UnaryExpression { $$ = P(Mult-Expr4, 3, $1, $2, $3); }
		;

AdditiveExpression: MultiplicativeExpression { $$ = $1; }
		| AdditiveExpression PLUS MultiplicativeExpression { $$ = P(Add-Expr2, 3, $1, $2, $3); }
		| AdditiveExpression MINUS MultiplicativeExpression { $$ = P(Add-Expr3, 3, $1, $2, $3); }
		| STRINGLITERAL AdditiveExpression { $$ = P(Add-Expr4, 2, $1, $2); }
		| AdditiveExpression STRINGLITERAL { $$ = P(Add-Expr5, 2, $1, $2); }
		;

RelationalExpression: AdditiveExpression { $$ = $1; } 
		| RelationalExpression LT AdditiveExpression { $$ = P(Relational-Expr2, 3, $1, $2, $3); }
		| RelationalExpression GT AdditiveExpression { $$ = P(Relational-Expr3, 3, $1, $2, $3); }
		| RelationalExpression LE AdditiveExpression { $$ = P(Relational-Expr4, 3, $1, $2, $3); }
		| RelationalExpression GE AdditiveExpression { $$ = P(Relational-Expr5, 3, $1, $2, $3); }
		;

EqualityExpression: RelationalExpression { $$ = $1; }
		| EqualityExpression EQ RelationalExpression { $$ = P(Equality-Expr2, 3, $1, $2, $3); }
		| EqualityExpression NE RelationalExpression { $$ = P(Equality-Expr3, 3, $1, $2, $3); }
		;

AndExpression: EqualityExpression { $$ = $1; }
		| AndExpression AND EqualityExpression { $$ = P(And-Expr2, 3, $1, $2, $3); }
		;

ExclusiveOrExpression: AndExpression { $$ = $1; }
		;

InclusiveOrExpression: ExclusiveOrExpression { $$ = $1; }
		| InclusiveOrExpression OR ExclusiveOrExpression { $$ = P(InclusiveOr-Expr2, 3, $1, $2, $3); }
		;

ConditionalAndExpression: InclusiveOrExpression { $$ = $1; }
		| ConditionalAndExpression ANDAND InclusiveOrExpression { $$ = P(ConditionalAnd-Expr2, 3, $1, $2, $3); }
		;

ConditionalOrExpression: ConditionalAndExpression { $$ = $1; }
		| ConditionalOrExpression OROR ConditionalAndExpression  { $$ = P(ConditionalOr-Expr2, 3, $1, $2, $3); }
		;

ConditionalExpression: ConditionalOrExpression { $$ = $1; }
		;

AssignmentExpression: ConditionalExpression { $$ = $1; }
		| Assignment { $$ = $1; }
		| STRINGLITERAL Assignment { $$ = P(Assign-Expr3, 2, $1, $2); }
		| Assignment STRINGLITERAL { $$ = P(Assign-Expr4, 2, $1, $2); }
		| LB ListFill RB { $$ = P(Assign-Expr5, 3, $1, $2, $3); }
		;

ListFill: INTLITERAL { $$ = $1; }
		| STRINGLITERAL { $$ = $1; }
		| FLOATLITERAL { $$ = $1; }
		| NULLLITERAL { $$ = $1; }
		| ListFill CM ListFill { $$ = P(List-Fill5, 3, $1, $2, $3); }
		;

Assignment:	 LeftHandSide AssignmentOperator AssignmentExpression { $$ = P(Assignment1, 3, $1, $2, $3); }
		| LeftHandSide SWAP AssignmentExpression { $$ = P(Assignment2, 3, $1, $2, $3); }
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
void yyerror(const char *s)
{
	fprintf(stderr, "Syntax error: file %s, line %d, token %s: %s\n",
			(const char *)list_peek(filenames), yylineno, yytext, s);
	exit(2);
}
