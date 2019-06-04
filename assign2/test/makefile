CC=gcc
CFLAGS=-c -g -Wfatal-errors

g0: g0.o lex.yy.o token.o
	$(CC) -o g0 g0.o lex.yy.o token.o

g0.o: g0.c
	$(CC) $(CFLAGS) g0.c

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) lex.yy.c
	
token.o: token.c token.h
	$(CC) $(CFLAGS) token.c

lex.yy.c: clex.l ytab.h
	flex clex.l
 
zip:
	zip HW1_Doumit clex.l g0.c makefile token.c token.h ytab.h

clean:
	rm *.o g0 *.yy.c