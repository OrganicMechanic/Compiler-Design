OBJ= g0.o g0gram.tab.o lex.yy.o cntable.o
CFLAGS=-c -g -Wall
CC=gcc

g0: $(OBJ)
	$(CC) -o g0 $(OBJ)

g0.o: g0.c
	$(CC) $(CFLAGS) g0.c

g0gram.tab.o: g0gram.tab.c
	$(CC) $(CFLAGS) g0gram.tab.c

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) lex.yy.c

cntable.o: cntable.c cntable.h
	$(CC) $(CFLAGS) cntable.c

g0gram.tab.c g0gram.tab.h: g0gram.y
	bison -d g0gram.y

lex.yy.c: g0lex.l
	flex g0lex.l

