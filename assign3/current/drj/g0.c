/*
 * This reference main() does not do everything that HW#1/HW#2 required.
 */

#include <stdio.h>
#include <stdlib.h>
#include "cntable.h"

extern FILE *yyin;
extern char *yyfilename;
extern ClassNameTable cnt;
extern int yyparse();

int main(int argc, char *argv[])
{
   int i, rv=0;
   if (argc < 2) {
      fprintf(stderr, "usage: g0 [files...]\n");
      exit(5);
      }
   for (i=1; i<argc; i++) {
      yyfilename = argv[i];
      yyin = fopen(yyfilename, "r");
      if (yyin == NULL) {
	 fprintf(stderr, "cannot open %s\n", yyfilename);
	 }
      cnt = new_cnt();
      rv = yyparse();
      fclose(yyin);
      if (rv != 0) {
	 fprintf(stderr, "There were errors\n");
	 break;
	 }
      }
   if (rv == 0) fprintf(stdout, "No errors\n");
   return rv;
}
