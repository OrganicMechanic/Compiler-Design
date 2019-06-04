/* Joel Doumit
 * main.c
 * Adapted from code written by Andrew Schwartzmeyer,
 * and Seth Forrest.
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
#include "symtab.h"

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
			printf("No files given. exiting.\n");
			return 1;
		} else {
			if (i == argc)
				break;
			printf("Reading from file %d: %s\n", i, argv[i]);

		char* file = argv[i];
		//test for extension
		if(strchr(file, '.') > strchr(file, '/')){ 
			// matches ./foo.g0 or foo.g0
		}else{
			//matches ./foo or foo
			char* addg0 = malloc(sizeof(file)+sizeof(".g0"));
			strcpy(addg0, file);
			strcat(addg0, ".g0");
			file = addg0; 
		}

			/* get real path for argument */
			chdir(cwd);
			filename = realpath(file, NULL);
			if (filename == NULL) {
				sprintf(error_buf, "Could not resolve file '%s'", file);
				handle_error(error_buf);
			}
			chdir(dirname(strdup(file))); /* for relative path lookups */

			/* open file and push buffer for flex */
			if (!(yyin = fopen(filename, "r"))) {
				sprintf(error_buf, "Could not open file '%s'", file);
				handle_error(error_buf);
			}
		}

		/* push filename and buffer state for lexer */
		list_push(filenames, filename);
		yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));

		/* call Bison */
		int result = yyparse();
		if (result == 0)
		{
			globals = new_st(41);
			pushscope(globals);

			populate_symboltables(yyprogram);

			printsymbols(globals, 0);
			//tree_preorder(yyprogram, 0, &print_tree);
		}
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
