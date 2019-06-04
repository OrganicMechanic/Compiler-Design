/* Joel Doumit
 * main.c
 * Adapted from code written by Andrew Schwartzmeyer,
 * and Seth Forrest.
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 
#include <string.h>

#include "g0gram.tab.h"
#include "token.h"
#include "tree.h"
#include "symtab.h"

char* currentfile = "";

nodeptr myTree = NULL;
extern void checkdeclared(nodeptr t);
extern int errors;

int main(int argc, char *argv[])
{
	int i;
	extern FILE* yyin;
	char *fileList[argc];
	char *ext;
	char *new_filename;
		
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
		char* nextfile = *argv++;
		currentfile = nextfile;
		yyparse();
		globals = new_st(43);
		pushscope(globals);
		
		typeptr read = alctype(METHOD_TYPE);
		read->u.m.name = "read";
		read->u.m.returntype = string_typeptr;
		insert_sym(globals, "read", read);

		typeptr write = alctype(METHOD_TYPE);
		write->u.m.name = "write";

		struct param* bigiron = malloc(sizeof(struct param));
		bigiron->type = string_typeptr;
		bigiron->next = NULL;

		write->u.m.parameters = bigiron;
		insert_sym(globals, "write", write);

		populate_symboltables(myTree);
		checkdeclared(myTree);
	}
	return 0; 
}