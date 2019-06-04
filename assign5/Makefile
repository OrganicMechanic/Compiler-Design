YACC=bison
LEX=flex
CC=gcc
CFLAGS=-g -Wall

all: g0

%.o: %.c
	$(CC) -c $(CFLAGS) $<

g0: main.o g0gram.tab.h g0gram.tab.o clex.o symtab.o type.o tac.o codegen.o
	cc -o g0 main.o clex.o g0gram.tab.o symtab.o type.o tac.o codegen.o

symtab.c: symtab.h defines.h g0gram.tab.h

codegen.c: tree.h

tac.c: tac.h

type.c: type.h symtab.h

g0gram.tab.c g0gram.tab.h: g0gram.y tree.h token.h defines.h
	$(YACC) -dt --verbose g0gram.y

clex.c: clex.l g0gram.tab.h token.h tree.h
	$(LEX) -t clex.l > clex.c

main.o: main.c g0gram.tab.h tree.h token.h symtab.h 
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f g0 *.o
	rm -f lex.c g0gram.tab.c g0gram.tab.h g0gram.output
