#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "ytab.h"

char *format_sval(char * string)
{
	int length = 0;
	char* strPtr = string;
	char* strLen = malloc(strlen(string));	
	while(*strPtr++ != '\"')
	{
		// Iterate past first "
		strPtr++;
	}	
	while(*strPtr != '\"') // Skip "
	{		
		if(strPtr[0] == '\\') // If escape character detected
		{	
			char esc = strPtr[1]; // Grab next char
			if(esc == 'n' || esc == 't' || esc == '\'' || esc == '\\' || esc == '\"' || esc == '\0')
			{
				strPtr = strPtr + 2;
			} 
			else
			{
				strPtr++; 
			}

		} 
		else 
		{
			strLen[length] = *strPtr;
			length++; strPtr++;
		}		
	}
	strLen[length] = '\0';
	strLen = realloc(strLen, length);
	return strLen;
}

tokenP createTok(int cat, char *message, int lineNum, char *file_name)
{
	// Creates a token object and returns the pointer
	tokenP tP = malloc(sizeof(struct token));	
	tP -> ival = 0;
	tP -> sval = " ";
	tP -> category = cat;
	tP -> lineno = lineNum;	
	
	tP -> text = malloc(strlen(message)+1); 
	strcpy(tP -> text, message);	
	tP -> filename = malloc(strlen(file_name)+1); 
	strcpy(tP -> filename, file_name);
		
	if(cat == ICON)
	{
		tP -> ival = atoi(message);
	}

	if(cat == DCON)
	{
		tP -> dval = atof(message);
	}

	if(cat == STRING)
	{
		tP -> sval = format_sval(message);
	}
	
	return tP;
}

void popNode(nodeP *head){
	// Pops the top off the node stack
	nodeP currP = NULL;
	currP = *head;
	*head = (*head)-> next;
	free(currP);
}

void pushNode(nodeP *head, char *file_name){
	// Pushes a node onto the node stack 
	nodeP currP = (nodeP)malloc(sizeof(struct node));
	currP -> filename = malloc(sizeof(file_name)+1); // +1 for safety.
	currP -> next = NULL;
	strcpy(currP -> filename, file_name);
	if( head == NULL){
		*head = currP;
	} else {
		currP -> next = *head;
		*head = currP;
	}
}

void addNode(nodeP *head, tokenP nextPtr){
	nodeP currP = malloc(sizeof(struct node));
	currP -> tokPtr = nextPtr;
	currP -> next = NULL;
	if( *head == NULL){
		*head = currP;
	} else {
		nodeP move = *head;
		while(move -> next != NULL){
			move = move -> next;
		}
		move -> next = currP;
	}
}

void printTok(tokenP tP){
	if(tP -> category == DCON)
	{
		printf("%d\t\t %s\t\t %d\t %s\t %f\n", tP -> category, tP -> text, tP -> lineno, tP -> filename, tP -> dval );
	}
	else if(tP -> category == ICON)
	{
		printf("%d\t\t %s\t\t %d\t %s\t %d\n", tP -> category, tP -> text, tP -> lineno, tP -> filename, tP -> ival );
	}
	else if(tP -> category == STRING)
	{
		printf("%d\t\t %s\t\t %d\t %s\t %s\n", tP -> category, tP -> text, tP -> lineno, tP -> filename, tP -> sval );
	}
	else 
	{
		printf("%d\t\t %s\t\t %d\t %s\n", tP -> category, tP -> text, tP -> lineno, tP -> filename );
	}
}


void printNode(nodeP *head){
	nodeP curr = *head;
	while(curr -> next != NULL){
		printTok(curr -> tokPtr);
		curr = curr -> next;
	}
}

void printStack(nodeP *head){
	if(*head == NULL){
		printf("Stack Empty\n");
	} else {
		nodeP curr = *head;
		while(curr != NULL){
			printf("%s\n", curr -> filename);
			curr = curr -> next;
		}
	}
}

void clearNodes(nodeP* head){
	nodeP curr = *head;
	while(curr != NULL){
		nodeP deleteMe = curr;
		curr = curr -> next;
		free(deleteMe);
	}
}
