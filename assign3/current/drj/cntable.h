/* class name table. to keep as simple as possible, hardwire #buckets
 */
#define CNT_NUMBUCKETS 43

typedef struct cntable {
   struct cntab_entry *tbl[CNT_NUMBUCKETS];
} *ClassNameTable;

extern ClassNameTable cnt;

struct cntab_entry {
   char *s;
   struct cntab_entry *next;
};

ClassNameTable new_cnt();
int insert_cnt(ClassNameTable, char *);
int lookup_cnt(ClassNameTable, char *);
int hash_cnt(char *);
