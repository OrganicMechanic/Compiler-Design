/*
Joel Doumit
CS445
Assignment 1
Lexical Analyzer
Partially adapted from code written by Seth Forrest, with additional help 
from StackOverflow user Charlie Martin.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "token.h"
#include "ytab.h"

extern FILE *yyin;
extern char *yytext;
extern tokenP yytoken;

char* fText = NULL;
nodeP fStack = NULL;

int main(int argc, char* argv[])
{

	int i;
	tokenP fetch;
	int errCode = -1;
	char *fileList[argc];
	char *ext;
	char *new_filename;
	struct node *tail = NULL;
		
	if(argc == 1)
	{
		// If no files are given
		printf("Error: no file given.\n");
		return 0;
	}
	
	argc--; argv++; // Skip compiler in command line list.
	for(i=0; i<argc; i++)
	{
		// Check if each filename has an extension, and add one if necessary.
		fileList[i] = argv[i];
		ext = strrchr(fileList[i], '.');
		if (!ext)
		{
			if((new_filename = malloc(strlen(fileList[i])+strlen(".g0")+1)) != NULL)
			{
	    		new_filename[0] = '\0';   // ensures the memory is an empty string
	    		strcat(new_filename,fileList[i]);
	    		strcat(new_filename,".g0");
	    		fileList[i] = new_filename;
			}
		}
		else if (strncmp(ext,".g0",4) != 0)
		{
			printf("Error: file of invalid type given.");
			return 0;
		}
		else
		{
			// We have a valid file. All is well.
		}
	}

	for(i=0; i<argc; i++){
		yyin = fopen(fileList[i], "r");
		if(yyin == NULL){
			printf("Invalid File: %s", fileList[i]);
			return 0;
		}
		fText = fileList[i];
		pushNode(&fStack, fText);
		yypush_buffer_state(yy_create_buffer(yyin, YY_BUFFER_SIZE));
	}
	
	while(errCode != 0)
	{
		errCode = yylex();
		if(yytoken != NULL)
		{
			fetch = yytoken; 
			addNode(&tail, fetch); 
		} 
	}
	
	printf("\nCategory\t Text\t\t LineNo\t FileName\t iVal/sVal/dVal\n");
	printf("-------------------------------------------------------------------------------\n");
	if(tail == NULL)
	{
		printf("Nothing to Print\n");
	} 
	else 
	{
		printNode(&tail);
	}
	printf("\n");
  return 0;
}
