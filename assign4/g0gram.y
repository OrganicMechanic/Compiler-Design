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
#include "type.h"


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
%token <t> BOOL BREAK CLASS
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

Goal:	CompilationUnit { $$ = ntree(PROGRAM, 1, $1); myTree = $$; }
		

Literal:	INTLITERAL { $$ = $1; $1->type = integer_typeptr; }
		| FLOATLITERAL { $$ = $1; $1->type = double_typeptr; }
		| BOOLLITERAL { $$ = $1; $1->type = bool_typeptr; }
		| STRINGLITERAL { $$ = $1; $1->type = string_typeptr; }
		| NULLLITERAL { $$ = $1; $1->type = null_typeptr; }
		;
	
Type:		PrimitiveType { $$ = $1; }
		| ReferenceType { $$ = $1; }
		;

PrimitiveType:	NumericType { $$ = $1; }
		| BOOL { $$ = $1; $1->type = bool_typeptr; }
		| STRING { $$ = $1; $1->type = string_typeptr; }
		;

NumericType:	IntegralType { $$ = $1; }
		| FloatingPointType { $$ = $1; }
		;

IntegralType:	INT { $$ = $1; $1->type = integer_typeptr; }
		;

FloatingPointType: DOUBLE { $$ = $1; $1->type = double_typeptr; }
		;

ReferenceType: Name { $$ = $1; }
		| ArrayType { $$ = $1; }
		| ListType { $$ = $1; }
		| TableType { $$ = $1; }
		;

ListType: LIST  { $$ = $1; }
		| LIST LT Type GT { $$ = ntree(LIST_TYPE2, 4, $1, $2, $3, $4); }
		;

TableType: TABLE { $$ = $1; }
		| TABLE LT Type GT { $$ = ntree(TABLE_TYPE2, 4, $1, $2, $3, $4); }
		| TABLE LT Type CM Type GT { $$ = ntree(TABLE_TYPE3, 6, $1, $2, $3, $4, $5, $6); }
		;

ArrayType:	  PrimitiveType LB RB { $$ = ntree(ARRAY_TYPE1, 3, $1, $2, $3); }
		| Name LB RB { $$ = ntree(ARRAY_TYPE2, 3, $1, $2, $3); }
		| ArrayType LB RB { $$ = ntree(ARRAY_TYPE3, 3, $1, $2, $3); }
		;

Name:		  SimpleName { $$ = $1; }
		| QualifiedName { $$ = $1; }
		;

SimpleName:	IDENT { $$ = ntree(SIMPLE_NAME, 1, $1); }
		;

QualifiedName:	  Name DOT IDENT { $$ = ntree(QUALIFIED_NAME1, 3, $1, $2, $3); }
		;

CompilationUnit: TypeDeclaration CompilationUnitOpt { $$ = ntree(COMPIL_UNIT1, 2, $1, $2); }
		| FieldDeclaration CompilationUnitOpt        { $$ = ntree(COMPIL_UNIT2, 2, $1, $2); }
		| MethodDeclaration CompilationUnitOpt       { $$ = ntree(COMPIL_UNIT3, 2, $1, $2); }
		;

CompilationUnitOpt: CompilationUnit { $$ = $1; }
		| %empty { $$ = NULL; }
		;

TypeDeclaration:  ClassDeclaration { $$ = $1; }
		;

ClassDeclaration: CLASS IDENT ClassBody { $$ = ntree(CLASS_DECL1, 3, $1, $2, $3); }
		;

ClassBody:	  LC ClassBodyDeclarationsOpt RC { $$ = ntree(CLASS_BODY1, 3, $1, $2, $3); }
		;

ClassBodyDeclarationsOpt: ClassBodyDeclarations { $$ = $1; }
	| %empty { $$ = NULL; }
	;

ClassBodyDeclarations: ClassBodyDeclaration { $$ = $1; }
		| ClassBodyDeclarations ClassBodyDeclaration { $$ = ntree(CLASSBODY_DECL2, 2, $1, $2); }
		;

ClassBodyDeclaration: ClassMemberDeclaration { $$ = $1; }
		| ConstructorDeclaration { $$ = $1; }
		;

ClassMemberDeclaration: FieldDeclaration { $$ = $1; }
		| MethodDeclaration { $$ = $1; }
		;

FieldDeclaration: Type VariableDeclarators { $$ = ntree(FIELD_DECL1, 2, $1, $2); }
		;

VariableDeclarators: VariableDeclarator { $$ = $1; }
		| VariableDeclarators CM VariableDeclarator { $$ = ntree(VARIABLE_DECS2, 3, $1, $2, $3); }
		;

VariableDeclarator: VariableDeclaratorId { $$ = $1; }
		| VariableDeclaratorId ASN VariableInitializer { $$ = ntree(VARIABLE_DECL2, 3, $1, $2, $3); }
		;

VariableDeclaratorId: IDENT { $$ = $1; }
		| VariableDeclaratorId LB RB { $$ = ntree(VARIABLEDEC_ID2, 3, $1, $2, $3); }
		;

VariableInitializer: Expression { $$ = $1; }
		| ArrayInitializer { $$ = $1; }
		;

MethodDeclaration: MethodHeader MethodBody { $$ = ntree(METHOD_DECL1, 2, $1, $2); $1 -> type = method_typeptr; } 
		;

MethodHeader: Type MethodDeclarator { $$ = ntree(METHOD_HEAD1, 2, $1, $2); }
		| VOID MethodDeclarator { $$ = ntree(METHOD_HEAD2, 2, $1, $2); }
		;

FormalParameterListOpt: FormalParameterList { $$ = $1; }
	| %empty { $$ = NULL; }
	;

MethodDeclarator: IDENT LP FormalParameterListOpt RP { $$ = ntree(METHODDEC_ER1, 4, $1, $2, $3, $4); }
		| MethodDeclarator LB RB { $$ = ntree(METHODDEC_ER2, 3, $1, $2, $3); }
		;

FormalParameterList: FormalParameter { $$ = $1; }
		| FormalParameterList CM FormalParameter { $$ = ntree(FORMALPARAM_LIST2, 3, $1, $2, $3); }
		;

FormalParameter: Type VariableDeclaratorId { $$ = ntree(FORMAL_PARA1, 2, $1, $2); }
		;

MethodBody: Block { $$ = $1; }
		;

ConstructorDeclaration: ConstructorDeclarator
				ConstructorBody { $$ = ntree(CONSTRUCTER_DELN1, 2, $1, $2); }
		;

ConstructorDeclarator: SimpleName LP FormalParameterListOpt RP { $$ = ntree(CONSTRUCTER_DECL1, 4, $1, $2, $3, $4); }
		;

BlockStatementsOpt: BlockStatements { $$ = $1; }
| %empty { $$ = NULL; } ;

ConstructorBody: LC BlockStatementsOpt RC { $$ = ntree(CONSTRUCTER_BODY1, 3, $1, $2, $3); }
		;

VariableInitializersOpt: VariableInitializers { $$ = $1; }
	| %empty { $$ = NULL; }
	;

CMOpt:	CM { $$ = NULL; } 
	| %empty { $$ = NULL; } 
	;

ArrayInitializer: LC VariableInitializersOpt CMOpt RC { $$ = ntree(ARRAY_INIT1, 4, $1, $2, $3, $4); }
		;

VariableInitializers: VariableInitializer { $$ = $1; }
		| VariableInitializers CM VariableInitializer { $$ = ntree(VARIABLEINIT_ZERS2, 3, $1, $2, $3); }
		;

Block:		  LC BlockStatementsOpt RC { $$ = ntree(BLOCK1, 3, $1, $2, $3); }
		;

BlockStatements:  BlockStatement { $$ = $1; }
		| BlockStatements BlockStatement { $$ = ntree(BLOCK_STMT2, 2, $1, $2); }
		;

BlockStatement:   LocalVariableDeclarationStatement { $$ = $1; }
		| Statement { $$ = $1; }
		;

ArgumentListOpt: ArgumentList { $$ = $1; }
	| %empty { $$ = NULL; }
	;

LocalVariableDeclarationStatement: LocalVariableDeclaration { $$ = $1; }
		;

LocalVariableDeclaration: Type VariableDeclarators { $$ = ntree(LOCVAR_DECL1, 2, $1, $2); }
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

LabeledStatement: IDENT COLON Statement { $$ = ntree(LABELED_STMT1, 3, $1, $2, $3); }
		;

LabeledStatementNoShortIf: IDENT COLON StatementNoShortIf { $$ = ntree(LABELEDSTMTNOSRT_IF1, 3, $1, $2, $3); }
		;

ExpressionStatement: StatementExpression { $$ = $1; }
		;

StatementExpression: Assignment { $$ = $1; }
		| MethodInvocation { $$ = $1; }
		;

IfThenStatement:  IF LP Expression RP Statement { $$ = ntree(IFTHEN_STMT1, 5, $1, $2, $3, $4, $5); }
		;

IfThenElseStatement:  IF LP Expression RP StatementNoShortIf ELSE Statement { $$ = ntree(IFTHENELSE_STMT1, 7, $1, $2, $3, $4, $5, $6, $7); }
		;

IfThenElseStatementNoShortIf:  IF LP Expression RP StatementNoShortIf
			ELSE StatementNoShortIf { $$ = ntree(IFTHENELSENOSRT_IF1, 7, $1, $2, $3, $4, $5, $6, $7); }
		;

WhileStatement:	  WHILE LP Expression RP Statement { $$ = ntree(WHILE_STMT1, 5, $1, $2, $3, $4, $5); }
		;

WhileStatementNoShortIf:  WHILE LP Expression RP StatementNoShortIf { $$ = ntree(WHILENOSRT_IF1, 5, $1, $2, $3, $4, $5); }
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
			Statement { $$ = ntree(FOR_STMT1, 9, $1, $2, $3, $4, $5, $6, $7, $8, $9); }
		;

ForStatementNoShortIf:	FOR LP ForInitOpt SM ExpressionOpt SM ForUpdateOpt RP
			StatementNoShortIf { $$ = ntree(FORSTMTNOSHORT_IF1, 9, $1, $2, $3, $4, $5, $6, $7, $8, $9); }
		;

StatementExpressionList: StatementExpression { $$ = $1; }
		| StatementExpressionList CM StatementExpression { $$ = ntree(STATEMENTEXPRESSION_LIST2, 3, $1, $2, $3); }
		;

IDENTOpt: IDENT { $$ = $1; }
	| %empty { $$ = NULL; }
	;

BreakStatement:	  BREAK IDENTOpt { $$ = ntree(BREAK_STMT1, 2, $1, $2); }
		;

ReturnStatement:  RETURN ExpressionOpt { $$ = ntree(RETURN_STMT1, 2, $1, $2); }
		;

Primary:	Literal { $$ = $1; }
		| LP Expression RP { $$ = ntree(PRIMARY3, 2, $1, $2); }
		| FieldAccess { $$ = $1; }
		| ArrayAccess { $$ = $1; }
		| MethodInvocation { $$ = $1; }
		;

ArgumentList:	Expression { $$ = $1; }
		| ArgumentList CM Expression { $$ = ntree(ARGS_LIST2, 3, $1, $2, $3); }
		;

DimsOpt: Dims { $$ = $1; }
	| %empty { $$ = NULL; }
	;

Dims:		LB RB { $$ = ntree(DIMS1, 2, $1, $2); }
		| Dims LB RB { $$ = ntree(DIMS2, 3, $1, $2, $3); }
		;

FieldAccess:	Primary DOT IDENT { $$ = ntree(FIELD_ACCS1, 3, $1, $2, $3); }
		;

MethodInvocation: Name LP ArgumentListOpt RP { $$ = ntree(METHOD_INVO1, 4, $1, $2, $3, $4); }
		| Primary DOT IDENT LP ArgumentListOpt RP { $$ = ntree(METHOD_INVO2, 5, $1, $2, $3, $4, $5); }
		| Name LC ArgumentListOpt RC { $$ = ntree(METHOD_INVO3, 3, $1, $2, $3); }
		| Primary DOT IDENT LC RC { $$ = ntree(METHOD_INVO4, 5, $1, $2, $3, $4, $5); }
			;

ArrayAccess: Name LB Expression RB        { $$ = ntree(ARRAY_ACCS1, 4, $1, $2, $3, $4); }
		| Primary LB Expression RB { $$ = ntree(ARRAY_ACCS2, 4, $1, $2, $3, $4); }
		| Name LB Expression COLON Expression RB { $$ = ntree(ARRAY_ACCS3, 4, $1, $2, $3, $4); }
		| Primary LB Expression COLON Expression RB { $$ = ntree(ARRAY_ACCS4, 4, $1, $2, $3, $4); }
		;

UnaryExpression: MINUS UnaryExpression { $$ = ntree(UNARY_EXPR2, 2, $1, $2); }
		| UnaryExpressionNotPlusMinus { $$ = $1; }
		;

UnaryExpressionNotPlusMinus: Primary { $$ = $1; }
		| Name { $$ = $1; }
		| BANG UnaryExpression { $$ = ntree(UNARYEXPRNOTPLUS_MIN3, 2, $1, $2); }
		| D INTLITERAL { $$ = ntree(UNARYEXPRNOTPLUS_MIN4, 2, $1, $2); }
		| INTLITERAL D INTLITERAL { $$ = ntree(UNARYEXPRNOTPLUS_MIN5, 3, $1, $2, $3); }
		| UNSIZE IDENT { $$ = ntree(UNARYEXPRNOTPLUS_MIN6, 2, $1, $2); }
		| CastExpression { $$ = $1; }
		;

CastExpression: LP PrimitiveType DimsOpt RP UnaryExpression { $$ = ntree(CAST_EXPR1, 5, $1, $2, $3, $4, $5); }
		| LP Expression RP UnaryExpressionNotPlusMinus { $$ = ntree(CAST_EXPR2, 4, $1, $2, $3, $4); }
		| LP Name Dims RP UnaryExpressionNotPlusMinus { $$ = ntree(CAST_EXPR3, 5, $1, $2, $3, $4, $5); }
		;

MultiplicativeExpression: UnaryExpression { $$ = $1; }
		| MultiplicativeExpression MUL UnaryExpression { $$ = ntree(MULT_EXPR2, 3, $1, $2, $3); }
		| MultiplicativeExpression DIV UnaryExpression { $$ = ntree(MULT_EXPR3, 3, $1, $2, $3); }
		| MultiplicativeExpression MOD UnaryExpression { $$ = ntree(MULT_EXPR4, 3, $1, $2, $3); }
		;

AdditiveExpression: MultiplicativeExpression { $$ = $1; }
		| AdditiveExpression PLUS MultiplicativeExpression { $$ = ntree(ADD_EXPR2, 3, $1, $2, $3); }
		| AdditiveExpression MINUS MultiplicativeExpression { $$ = ntree(ADD_EXPR3, 3, $1, $2, $3); }
		| STRINGLITERAL AdditiveExpression { $$ = ntree(ADD_EXPR4, 2, $1, $2); }
		| AdditiveExpression STRINGLITERAL { $$ = ntree(ADD_EXPR5, 2, $1, $2); }
		;

RelationalExpression: AdditiveExpression { $$ = $1; } 
		| RelationalExpression LT AdditiveExpression { $$ = ntree(RELATIONAL_EXPR2, 3, $1, $2, $3); }
		| RelationalExpression GT AdditiveExpression { $$ = ntree(RELATIONAL_EXPR3, 3, $1, $2, $3); }
		| RelationalExpression LE AdditiveExpression { $$ = ntree(RELATIONAL_EXPR4, 3, $1, $2, $3); }
		| RelationalExpression GE AdditiveExpression { $$ = ntree(RELATIONAL_EXPR5, 3, $1, $2, $3); }
		;

EqualityExpression: RelationalExpression { $$ = $1; }
		| EqualityExpression EQ RelationalExpression { $$ = ntree(EQUALITY_EXPR2, 3, $1, $2, $3); }
		| EqualityExpression NE RelationalExpression { $$ = ntree(EQUALITY_EXPR3, 3, $1, $2, $3); }
		;

AndExpression: EqualityExpression { $$ = $1; }
		| AndExpression AND EqualityExpression { $$ = ntree(AND_EXPR2, 3, $1, $2, $3); }
		;

ExclusiveOrExpression: AndExpression { $$ = $1; }
		;

InclusiveOrExpression: ExclusiveOrExpression { $$ = $1; }
		| InclusiveOrExpression OR ExclusiveOrExpression { $$ = ntree(INCLUSIVEOR_EXPR2, 3, $1, $2, $3); }
		;

ConditionalAndExpression: InclusiveOrExpression { $$ = $1; }
		| ConditionalAndExpression ANDAND InclusiveOrExpression { $$ = ntree(CONDITIONALAND_EXPR2, 3, $1, $2, $3); }
		;

ConditionalOrExpression: ConditionalAndExpression { $$ = $1; }
		| ConditionalOrExpression OROR ConditionalAndExpression  { $$ = ntree(CONDITIONALOR_EXPR2, 3, $1, $2, $3); }
		;

ConditionalExpression: ConditionalOrExpression { $$ = $1; }
		;

AssignmentExpression: ConditionalExpression { $$ = $1; }
		| Assignment { $$ = $1; }
		| STRINGLITERAL Assignment { $$ = ntree(ASSIGN_EXPR3, 2, $1, $2); }
		| Assignment STRINGLITERAL { $$ = ntree(ASSIGN_EXPR4, 2, $1, $2); }
		| LB ListFill RB { $$ = ntree(ASSIGN_EXPR5, 3, $1, $2, $3); }
		;

ListFill: INTLITERAL { $$ = $1; }
		| STRINGLITERAL { $$ = $1; }
		| FLOATLITERAL { $$ = $1; }
		| NULLLITERAL { $$ = $1; }
		| ListFill CM ListFill { $$ = ntree(LIST_FILL5, 3, $1, $2, $3); }
		;

Assignment:	 LeftHandSide AssignmentOperator AssignmentExpression { $$ = ntree(ASSIGNMENT1, 3, $1, $2, $3); }
		| LeftHandSide SWAP AssignmentExpression { $$ = ntree(ASSIGNMENT2, 3, $1, $2, $3); }
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
