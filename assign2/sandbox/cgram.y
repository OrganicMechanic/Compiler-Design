
%{

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

%union {
	struct tree *t;
}

%defines

%token <t> IDENTIFIER INTEGER FLOATING CHARACTER STRING CLASS_NAME
%token <t> ADDEQ SUBEQ
%token <t> EQ NOTEQ LTEQ GTEQ ANDAND OROR
%token <t> BOOL BREAK
%token <t> CLASS DOUBLE ELSE FALSE FLOAT
%token <t> FOR IF INT RETURN
%token <t> TRUE VOID WHILE
%token <t> ';' '{' '}' ',' ':' '=' '(' ')' '[' ']' '.' '&' '!' '-'
%token <t> '+' '*' '/' '%' '<' '>' '#' '"'

%type <t> literal boolean program primary_expression id_expression
%type <t> unqualified_id
%type <t> postfix_expression expression_list unary_expression
%type <t> unary_operator new_placement new_type_id
%type <t> new_declarator direct_new_declarator new_initializer
%type <t> conditional_expression
%type <t> assignment_expression assignment_operator expression
%type <t> constant_expression statement
%type <t> expression_statement compound_statement statement_seq
%type <t> selection_statement condition iteration_statement
%type <t> for_init_statement jump_statement declaration_statement
%type <t> declaration_seq declaration block_declaration
%type <t> simple_declaration decl_specifier decl_specifier_seq
%type <t> type_specifier simple_type_specifier
%type <t> init_declarator_list
%type <t> init_declarator declarator
%type <t> type_id type_specifier_seq abstract_declarator
%type <t> direct_abstract_declarator parameter_declaration_clause
%type <t> parameter_declaration_list parameter_declaration
%type <t> function_definition function_body initializer
%type <t> initializer_clause initializer_list class_specifier
%type <t> class_head class_key member_specification member_declaration
%type <t> member_declarator_list member_declarator
%type <t> constant_initializer ctor_initializer
%type <t> mem_initializer_list mem_initializer mem_initializer_id
%type <t> declaration_seq_opt expression_list_opt new_placement_opt
%type <t> new_initializer_opt new_declarator_opt expression_opt
%type <t> statement_seq_opt condition_opt initializer_opt
%type <t> constant_expression_opt abstract_declarator_opt
%type <t> type_specifier_seq_opt ctor_initializer_opt COMMA_opt
%type <t> member_specification_opt SEMICOLON_opt

%start program

%%

/*----------------------------------------------------------------------
 * Lexical elements.
 *----------------------------------------------------------------------*/

literal:
	INTEGER	    { $$ = $1; }
	| CHARACTER { $$ = $1; }
	| FLOATING  { $$ = $1; }
	| STRING    { $$ = $1; }
	| boolean   { $$ = $1; }
	;

boolean:
	TRUE    { $$ = $1; }
	| FALSE { $$ = $1; }
	;

program:
	declaration_seq_opt { $$ = P(program, 1, $1); yyprogram = $$; }
	;

/*----------------------------------------------------------------------
 * Expressions.
 *----------------------------------------------------------------------*/

primary_expression:
	literal		     { $$ = $1; }
	| '(' expression ')' { $$ = P(primary-expr2, 3, $1, $2, $3); }
	| id_expression	     { $$ = $1; }
	;

id_expression:
	unqualified_id { $$ = $1; }
	;

unqualified_id:
	IDENTIFIER	 { $$ = $1; }
	;

postfix_expression:
	primary_expression				    { $$ = $1; }
	| postfix_expression '[' expression ']'		    { $$ = P(postfix-expr2, 4, $1, $2, $3, $4); }
	| postfix_expression '(' expression_list_opt ')'    { $$ = P(postfix-expr3, 4, $1, $2, $3, $4); }
	| simple_type_specifier '(' expression_list_opt ')' { $$ = P(postfix-expr4, 4, $1, $2, $3, $4); }
	| postfix_expression '.' id_expression		    { $$ = P(postfix-expr6, 3, $1, $2, $3); }
	;

expression_list:
	assignment_expression			    { $$ = $1; }
	| expression_list ',' assignment_expression { $$ = P(expr-list2, 3, $1, $2, $3); }
	;

unary_expression:
	postfix_expression		  { $$ = $1; }
	| '*' unary_expression		  { $$ = P(unary-expr4, 2, $1, $2); }
	| unary_operator unary_expression { $$ = P(unary-expr6, 2, $1, $2); }
	;

unary_operator:
	'+'   { $$ = $1; }
	| '-' { $$ = $1; }
	| '!' { $$ = $1; }
	;

new_placement:
	'(' expression_list ')' { $$ = P(new-placement, 3, $1, $2, $3); }
	;

new_type_id:
	type_specifier_seq new_declarator_opt { $$ = P(new-type-id, 2, $1, $2); }
	;

new_declarator:
	new_declarator_opt { $$ = P(new-decl1, 2, $1); }
	| direct_new_declarator	        { $$ = $1; }
	;

direct_new_declarator:
	'[' expression ']'				    { $$ = P(direct-new-decl1, 3, $1, $2, $3); }
	| direct_new_declarator '[' constant_expression ']' { $$ = P(direct-new-decl1, 4, $1, $2, $3, $4); }
	;

new_initializer:
	'(' expression_list_opt ')' { $$ = P(new-init, 3, $1, $2, $3); }
	;

conditional_expression:
	expression ':' assignment_expression { $$ = P(cond-expr2, 5, $1, $2, $3); }
	;

assignment_expression:
	conditional_expression						  { $$ = $1; }
	| assignment_operator assignment_expression { $$ = P(assign-expr2, 3, $1, $2); }
	;

assignment_operator:
	'='     { $$ = $1; }
	| ADDEQ { $$ = $1; }
	| SUBEQ { $$ = $1; }
	;

expression:
	assignment_expression		       { $$ = $1; }
	| expression ',' assignment_expression { $$ = P(expr2, 3, $1, $2, $3); }
	;

constant_expression:
	conditional_expression { $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Statements.
 *----------------------------------------------------------------------*/

statement:
	expression_statement  { $$ = $1; }
	| compound_statement    { $$ = $1; }
	| selection_statement   { $$ = $1; }
	| iteration_statement   { $$ = $1; }
	| jump_statement        { $$ = $1; }
	| declaration_statement { $$ = $1; }
	;

expression_statement:
	expression_opt ';' { $$ = P(expr-statement, 2, $1, $2); }
	;

compound_statement:
	'{' statement_seq_opt '}' { $$ = P(compound-statement, 3, $1, $2, $3); }
	;

statement_seq:
	statement		  { $$ = $1; }
	| statement_seq statement { $$ = P(statement-seq2, 2, $1, $2); }
	;

selection_statement:
	IF '(' condition ')' statement		        { $$ = P(select1, 5, $1, $2, $3, $4, $5); }
	| IF '(' condition ')' statement ELSE statement { $$ = P(select2, 7, $1, $2, $3, $4, $5, $6, $7); }
	;

condition:
	expression						  { $$ = $1; }
	| type_specifier_seq declarator '=' assignment_expression { $$ = P(condition2, 4, $1, $2, $3, $4); }
	;

iteration_statement:
	FOR '(' for_init_statement condition_opt ';' expression_opt ')' statement { $$ = P(iter3, 8, $1, $2, $3, $4, $5, $6, $7, $8); }
	;

for_init_statement:
	expression_statement { $$ = $1; }
	| simple_declaration { $$ = $1; }
	;

jump_statement:
	BREAK ';'		    { $$ = P(jump1, 2, $1, $2); }
	| RETURN expression_opt ';' { $$ = P(jump3, 3, $1, $2, $3); }
	;

declaration_statement:
	block_declaration { $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Declarations.
 *----------------------------------------------------------------------*/

declaration_seq:
	declaration		      { $$ = $1; }
	| declaration_seq declaration { $$ = P(decl-seq2, 2, $1, $2); }
	;

declaration:
	block_declaration     { $$ = $1; }
	| function_definition { $$ = $1; }
	;

block_declaration:
	simple_declaration { $$ = $1; }
	;

simple_declaration:
	decl_specifier_seq init_declarator_list ';' { $$ = P(simple-decl1, 3, $1, $2, $3); }
	| decl_specifier_seq ';'		    { $$ = P(simple-decl2, 2, $1, $2); }
	;

decl_specifier:
	type_specifier { $$ = $1; }
	;

decl_specifier_seq:
	decl_specifier			    { $$ = $1; }
	| decl_specifier_seq decl_specifier { $$ = P(decl-spec-seq2, 2, $1, $2); }
	;

type_specifier:
	simple_type_specifier	    { $$ = $1; }
	| class_specifier	    { $$ = $1; }
	;

simple_type_specifier:
	CLASS_NAME				      { $$ = $1; }
	| BOOL					      { $$ = $1; }
	| INT					      { $$ = $1; }
	| FLOAT					      { $$ = $1; }
	| DOUBLE				      { $$ = $1; }
	| VOID					      { $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Declarators.
 *----------------------------------------------------------------------*/

init_declarator_list:
	init_declarator				   { $$ = $1; }
	| init_declarator_list ',' init_declarator { $$ = P(init-decl-list2, 3, $1, $2, $3); }
	;

init_declarator:
	declarator initializer_opt { $$ = P(init-decl, 2, $1, $2); }
	;

declarator:
	declarator { $$ = P(decl2, 2, $1); }
	;

type_id:
	type_specifier_seq abstract_declarator_opt { $$ = P(type-id, 2, $1, $2); }
	;

type_specifier_seq:
	type_specifier type_specifier_seq_opt { $$ = P(type-spec-seq, 2, $1, $2); }
	;

abstract_declarator:
	abstract_declarator_opt { $$ = P(abstract-decl1, 2, $1); }
	| direct_abstract_declarator	     { $$ = $1; }
	;

direct_abstract_declarator:
	direct_abstract_declarator '(' parameter_declaration_clause ')' { $$ = P(direct-abstract-decl1, 4, $1, $2, $3, $4); }
	| '(' parameter_declaration_clause ')'			        { $$ = P(direct-abstract-decl2, 3, $1, $2, $3); }
	| direct_abstract_declarator '[' constant_expression_opt ']'    { $$ = P(direct-abstract-decl3, 4, $1, $2, $3, $4); }
	| '[' constant_expression_opt ']'			        { $$ = P(direct-abstract-decl4, 3, $1, $2, $3); }
	| '(' abstract_declarator ')'				        { $$ = P(direct-abstract-decl5, 3, $1, $2, $3); }
	;

parameter_declaration_clause:
	parameter_declaration_list { $$ = $1; }
	| %empty		   { $$ = E(); }
	;

parameter_declaration_list:
	parameter_declaration				       { $$ = $1; }
	| parameter_declaration_list ',' parameter_declaration { $$ = P(param-decl-list1, 3, $1, $2, $3); }
	;

parameter_declaration:
	decl_specifier_seq declarator					       { $$ = $1; }
	| decl_specifier_seq declarator '=' assignment_expression	       { $$ = P(param-decl2, 4, $1, $2, $3, $4); }
	| decl_specifier_seq abstract_declarator_opt			       { $$ = P(param-decl3, 2, $1, $2); }
	| decl_specifier_seq abstract_declarator_opt '=' assignment_expression { $$ = P(param-decl4, 4, $1, $2, $3, $4); }
	;

function_definition:
	declarator ctor_initializer_opt function_body			   { $$ = P(function-def1, 3, $1, $2, $3); }
	| decl_specifier_seq declarator ctor_initializer_opt function_body { $$ = P(function-def2, 4, $1, $2, $3, $4); }
	;

function_body:
	compound_statement { $$ = $1; }
	;

initializer:
	'=' initializer_clause	  { $$ = P(init1, 2, $1, $2); }
	| '(' expression_list ')' { $$ = P(init2, 3, $1, $2, $3); }
	;

initializer_clause:
	assignment_expression		     { $$ = $1; }
	| '{' initializer_list COMMA_opt '}' { $$ = P(init-clause2, 3, $1, $2, $3); }
	| '{' '}'			     { $$ = P(init-clause3, 2, $1, $2); }
	;

initializer_list:
	initializer_clause			  { $$ = $1; }
	| initializer_list ',' initializer_clause { $$ = P(init-list2, 3, $1, $2, $3); }
	;

/*----------------------------------------------------------------------
 * Classes.
 *----------------------------------------------------------------------*/

class_specifier:
	class_head '{' member_specification_opt '}' { $$ = P(class-spec, 4, $1, $2, $3, $4); }
	;

class_head:
	class_key IDENTIFIER			     { $$ = P(class-head1, 2, $1, $2); typenames_insert_tree($2, CLASS_NAME); }
	;

class_key:
	CLASS	 { $$ = $1; }
	;

member_specification:
	member_declaration member_specification_opt     { $$ = P(member-spec1, 2, $1, $2); }
	|  ':' member_specification_opt { $$ = P(member-spec2, 3, $1, $2); }
	;

member_declaration:
	decl_specifier_seq member_declarator_list ';' { $$ = P(member-decl1, 3, $1, $2, $3); }
	| decl_specifier_seq ';'		      { $$ = P(member-decl2, 2, $1, $2); }
	| member_declarator_list ';'		      { $$ = P(member-decl3, 2, $1, $2); }
	| ';'					      { $$ = $1; }
	| function_definition SEMICOLON_opt	      { $$ = P(member-decl5, 2, $1, $2); }
	;

member_declarator_list:
	member_declarator			       { $$ = $1; }
	| member_declarator_list ',' member_declarator { $$ = P(member-decl-list2, 3, $1, $2, $3); }
	;

member_declarator:
	declarator			     { $$ = $1; }
	| declarator constant_initializer    { $$ = P(member-declarator2, 2, $1, $2); }
	| IDENTIFIER ':' constant_expression { $$ = P(member-declarator3, 3, $1, $2, $3); }
	;

constant_initializer:
	'=' constant_expression { $$ = P(constant-init, 2, $1, $2); }
	;

/*----------------------------------------------------------------------
 * Special member functions.
 *----------------------------------------------------------------------*/

ctor_initializer:
	':' mem_initializer_list { $$ = P(ctor-init, 2, $1, $2); }
	;

mem_initializer_list:
	mem_initializer				   { $$ = $1; }
	| mem_initializer ',' mem_initializer_list { $$ = P(mem-init-list2, 3, $1, $2, $3); }
	;

mem_initializer:
	mem_initializer_id '(' expression_list_opt ')' { $$ = P(mem-init, 4, $1, $2, $3, $4); }
	;

mem_initializer_id:
	CLASS_NAME				    { $$ = $1; }
	| IDENTIFIER				    { $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Epsilon (optional) definitions.
 *----------------------------------------------------------------------*/

declaration_seq_opt:
	%empty		  { $$ = E(); }
	| declaration_seq { $$ = $1; }
	;

expression_list_opt:
	%empty		  { $$ = E(); }
	| expression_list { $$ = $1; }
	;

new_placement_opt:
	%empty	        { $$ = E(); }
	| new_placement { $$ = $1; }
	;

new_initializer_opt:
	%empty		  { $$ = E(); }
	| new_initializer { $$ = $1; }
	;

new_declarator_opt:
	%empty		 { $$ = E(); }
	| new_declarator { $$ = $1; }
	;

expression_opt:
	%empty	     { $$ = E(); }
	| expression { $$ = $1; }
	;

statement_seq_opt:
	%empty	        { $$ = E(); }
	| statement_seq { $$ = $1; }
	;

condition_opt:
	%empty	    { $$ = E(); }
	| condition { $$ = $1; }
	;

initializer_opt:
	%empty	      { $$ = E(); }
	| initializer { $$ = $1; }
	;

constant_expression_opt:
	%empty		      { $$ = E(); }
	| constant_expression { $$ = $1; }
	;

abstract_declarator_opt:
	%empty		      { $$ = E(); }
	| abstract_declarator { $$ = $1; }
	;

type_specifier_seq_opt:
	%empty		     { $$ = E(); }
	| type_specifier_seq { $$ = $1; }
	;

ctor_initializer_opt:
	%empty		   { $$ = E(); }
	| ctor_initializer { $$ = $1; }
	;

COMMA_opt:
	%empty { $$ = E(); }
	| ','  { $$ = $1; }
	;

member_specification_opt:
	%empty		       { $$ = E(); }
	| member_specification { $$ = $1; }
	;

SEMICOLON_opt:
	%empty { $$ = E(); }
	| ';'  { $$ = $1; }
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
