/* Joel Doumit
 * main.c
 * Adapted from Andrew Schwartzmeyer's 120++ code.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>

#include "clex.h"
#include "token.h"
#include "list.h"
#include "tree.h"
#include "g0gram.tab.h"

struct tree *yyprogram;
struct list *filenames = NULL;
struct list *typenames = NULL;
char error_buf[256];

void handle_error(char *c);
char *current_filename();
void print_tree(struct tree *t, int d);
void destroy_syntax_tree(void *data, bool leaf);

int main(int argc, char **argv)
{

	int i;
	tokenP fetch;
	int errCode = -1;
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


	char *cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		handle_error("getcwd");

	filenames = list_init();
	if (filenames == NULL)
		handle_error("main filenames");

	/* setup lexer and parse each argument (or stdin) as a new 'program' */
	for (int i = 1; i <= argc; ++i) {
		typenames = list_init();
		if (typenames == NULL)
			handle_error("main typenames");

		char *filename = NULL;
		if (argc == 1) {
			printf("No CLI arguments, exiting.\n");
			return 1;
		} else {
			if (i == argc)
				break;
			printf("Reading from argument %d: %s\n", i, argv[i]);

			/* get real path for argument */
			chdir(cwd);
			filename = realpath(argv[i], NULL);
			if (filename == NULL) {
				sprintf(error_buf, "Could not resolve CLI argument '%s'", argv[i]);
				handle_error(error_buf);
			}
			chdir(dirname(strdup(filename))); /* for relative path lookups */

			/* open file and push buffer for flex */
			if (!(yyin = fopen(filename, "r"))) {
				sprintf(error_buf, "Could not open CLI argument '%s'", argv[i]);
				handle_error(error_buf);
			}
		}

		/* push filename and buffer state for lexer */
		list_push(filenames, filename);
		yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));

		/* call Bison */
		int result = yyparse();
		if (result == 0)
			tree_preorder(yyprogram, 0, &print_tree);
		else
			return 2;

		/* clean up */
		tree_destroy(yyprogram, &destroy_syntax_tree);
		yylex_destroy();
		list_destroy(typenames, NULL);
	}

	list_destroy(filenames, NULL);

	return EXIT_SUCCESS;
}

/*
 * Passes given string to perror and exits with EXIT_FAILURE, used for
 * internal program errors.
 */
void handle_error(char *c)
{
	perror(c);
	exit(EXIT_FAILURE);
}

/*
 * Returns current filename string on top of stack (filenames list),
 * copied and thus safe for potential modification by library
 * functions.
 */
char *current_filename()
{
	const char *filename = list_peek(filenames);
	if (filename == NULL)
		return NULL;

	char *copy = strdup(filename);
	if (copy == NULL)
		handle_error("current_filename()");

	return copy;
}

/*
 * Helper function passed to tree_preorder().
 */
void print_tree(struct tree *t, int d)
{
	if (tree_size(t) == 1) /* holds a token */
		printf("%*s %s (%d)\n", d*2, " ",
		       (char *)((struct token *)t->data)->text,
		       (int)((struct token *)t->data)->category);
	else /* holds a production rule name */
		printf("%*s %s: %zu\n", d*2, " ",
		       (char *)t->data,
		       list_size(t->children));
}

/*
 * Destroys tokens contained in leaves of syntax tree. 
 */
void destroy_syntax_tree(void *data, bool leaf)
{
	if (leaf)
		token_destroy(data);
}
