/* 
 * tokenprint.h | Brian Cartwright | CS445 | 9/24/18
 */
#ifndef TOKENPRINT_H
#define TOKENRINT_H

#include <stdio.h>
#include "token.h"
#include "gram.tab.h"

void print_token( token* t){
	printf("%-16i%-16s%-16i%-16s",
		t->category, t->text, t->lineno, t->filename);
	switch(t->category){
		case INTLITERAL:
			printf("%-20i\n", t->ival);
			break;
		case FLOATLITERAL:
			printf("%-20f\n", t->dval);
			break;
		case STRINGLITERAL:
			printf("%-20s\n", t->sval);
			break;
		default:  
			printf("%-20s\n", t->sval);
	}
}

void print_token_list(struct tokenlist* node){
	if(node == NULL){ return; } 

	if(node->next != NULL){
		print_token_list(node->next);
	}

	print_token(node->t);

}


#endif