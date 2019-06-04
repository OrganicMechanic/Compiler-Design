# Joel Doumit
# Makefile
# Adapted from Andrew Schwartzmeyer's 120++ makefile.

# binaries
BIN=g0
CC=gcc
LEX=flex
YACC=bison
RM=rm -f

# compile options
CFLAGS=-g -Wall -std=gnu99
YFLAGS= -dt 

# archive options
GITREF=HEAD
PREFIX=$(BIN)

# targets
all: $(BIN)

clean:
	$(RM) $(BIN) $(OBJECTS) lex.yy.c clex.h g0gram.tab.h

.PHONY: all test-lex tar clean

# source
SOURCES=main.c token.c list.c tree.c lex.yy.c g0gram.tab.c hasht.c \
lookup3.c symbol.c
OBJECTS=$(SOURCES:.c=.o)

$(BIN): $(OBJECTS)
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

main.c: clex.h g0gram.tab.h hasht.h

g0gram.tab.h g0gram.tab.c: g0gram.y
	$(YACC) $(YFLAGS) $<

clex.h: lex.yy.c

lex.yy.c: clex.l g0gram.tab.h
	$(LEX) $<

token.c: token.h

list.c: list.h

tree.c: tree.h

hasht.o: hasht.h lookup3.o

symbol.o: symbol.h args.h \
	token.h clex.h g0gram.tab.h list.h hasht.h tree.h
