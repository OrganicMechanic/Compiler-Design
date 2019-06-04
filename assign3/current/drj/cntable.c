#include <stdlib.h>
#include <string.h>
#include "cntable.h"

ClassNameTable cnt;

ClassNameTable new_cnt()
{
   ClassNameTable rv = malloc(sizeof(struct cntable));
   return rv;
}
struct cntab_entry *new_cntab_entry(char *s)
{
   struct cntab_entry *rv = malloc(sizeof(struct cntab_entry));
   rv->s = strdup(s);
   rv->next = NULL;
   return rv;
}
int insert_cnt(ClassNameTable t, char *s)
{
   int i = hash_cnt(s);
   struct cntab_entry *e = t->tbl[i];
   while (e != NULL) {
      if (!strcmp(s, e->s)) return 0;
      e = e->next;
      }
   e = new_cntab_entry(s);
   e->next = t->tbl[i];
   t->tbl[i] = e;
   return 1;
}
int lookup_cnt(ClassNameTable t, char *s)
{
   struct cntab_entry *e = t->tbl[hash_cnt(s)];
   while (e != NULL) {
      if (!strcmp(s, e->s)) return 1;
      e = e->next;
      }
   return 0;
}

/*
 * Compute hash value.
 */
int hash_cnt(char *s)
{
   register int h = 0;
   register char c;
   while ((c = *s++)) {
      h += c & 0377;
      h *= 37;
      }
   if (h < 0) h = -h;
   return h % CNT_NUMBUCKETS;
}
