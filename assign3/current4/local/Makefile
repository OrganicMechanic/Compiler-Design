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
	$(RM) $(BIN) $(OBJECTS) lex.yy.c lexer.h parser.tab.h

.PHONY: all test-lex tar clean

# source
SOURCES=main.c logger.c symbol.c token.c hasht.c list.c rules.c tree.c lookup3.c lex.yy.c parser.tab.c
OBJECTS=$(SOURCES:.c=.o)

$(BIN): $(OBJECTS)
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

main.c: args.h logger.h lexer.h list.h tree.h hasht.h

parser.tab.h parser.tab.c: parser.y defines.h
	$(YACC) $(YFLAGS) $<

lexer.h: logger.h token.h parser.tab.h list.h tree.h hasht.h

lex.yy.c: lexer.l parser.tab.h
	$(LEX) $<

token.c: token.h logger.h parser.tab.h

list.c: list.h

tree.c: tree.h

hasht.o: hasht.h lookup3.o

logger.o: logger.h args.h token.h lexer.h list.h tree.h

symbol.o: symbol.h args.h logger.h \
	token.h lexer.h parser.tab.h list.h hasht.h tree.h
