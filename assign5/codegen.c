#include <stdio.h>
#include "tree.h"
#include "tac.h"

FILE *ofp;
char outputFilename[] = "out.ic";

void codegen(struct tree * t)
{
   int i/*j */;
   if (t==NULL) return;

   /*
    * this is a post-order traversal, so visit children first
    */
   for(i=0;i<t->n;i++)
   {
      if (t->kids[i] != NULL)
      codegen(t->kids[i]);
   }

   /*
    * back from children, consider what we have to do with
    * this node. The main thing we have to do, one way or
    * another, is assign t->code
    */
   switch (t->prodrule) {
    case O_SUB:
    case O_MUL:
    case O_DIV:
    case O_NEG:
    case O_ASN:
    case O_ADDR:
    case O_LCONT:
    case O_SCONT:
    case O_GOTO:
    case O_BLT:
    case O_BLE:
    case O_BGT:
    case O_BGE:
    case O_BEQ:
    case O_BNE:
    case O_BIF:
    case O_BNIF:
    case O_PARM:
    case O_CALL:
    case O_RET:
    case D_GLOB:
    case D_PROC:
    case D_LOCAL:
    case D_LABEL:
    case D_END:
   case O_ADD: {
      struct instr *g;
      t->code = concat(t->kids[0]->code, t->kids[1]->code);
      g = gen(O_ADD, t->address,
              t->kids[0]->address, t->kids[1]->address);
      t->code = concat(t->code, g);
      break;
      }
   /*
    * ... really, a bazillion cases, up to one for each
    * production rule (in the worst case)
    */
   default:
      /* default is: concatenate our children's code */
      t->code = NULL;
      for(i=0;i<t->n;i++)
      {
        if(t->kids[i]!= NULL)
         t->code = concat(t->code, t->kids[i]->code);
      }
   }
   ofp = fopen(outputFilename, "w");

  if (ofp == NULL) {
    fprintf(stderr, "Can't open output file %s!\n",
            outputFilename);
    exit(1);
  }
  else
  {
    if(t->code != NULL){
    fprintf(ofp, "%d\n", t->code->opcode);

    }
  }
  fclose(ofp);
}
