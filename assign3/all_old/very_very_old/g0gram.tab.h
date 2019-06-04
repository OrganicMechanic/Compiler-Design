/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOLEAN = 258,
     BREAK = 259,
     CLASS = 260,
     DOUBLE = 261,
     ELSE = 262,
     FOR = 263,
     STRING = 264,
     IF = 265,
     INT = 266,
     RETURN = 267,
     THIS = 268,
     D = 269,
     TABLE = 270,
     LIST = 271,
     UNSIZE = 272,
     VOID = 273,
     WHILE = 274,
     IDENT = 275,
     NULLLITERAL = 276,
     BOOLLITERAL = 277,
     INTLITERAL = 278,
     FLOATLITERAL = 279,
     STRINGLITERAL = 280,
     LP = 281,
     RP = 282,
     LC = 283,
     RC = 284,
     LB = 285,
     RB = 286,
     SM = 287,
     CM = 288,
     DOT = 289,
     ASN = 290,
     LT = 291,
     GT = 292,
     BANG = 293,
     COLON = 294,
     EQ = 295,
     NE = 296,
     LE = 297,
     GE = 298,
     ANDAND = 299,
     OROR = 300,
     PLUS = 301,
     MINUS = 302,
     MUL = 303,
     DIV = 304,
     AND = 305,
     OR = 306,
     SWAP = 307,
     MOD = 308,
     SHL = 309,
     SHR = 310,
     LSHR = 311,
     PLASN = 312,
     MIASN = 313
   };
#endif
/* Tokens.  */
#define BOOLEAN 258
#define BREAK 259
#define CLASS 260
#define DOUBLE 261
#define ELSE 262
#define FOR 263
#define STRING 264
#define IF 265
#define INT 266
#define RETURN 267
#define THIS 268
#define D 269
#define TABLE 270
#define LIST 271
#define UNSIZE 272
#define VOID 273
#define WHILE 274
#define IDENT 275
#define NULLLITERAL 276
#define BOOLLITERAL 277
#define INTLITERAL 278
#define FLOATLITERAL 279
#define STRINGLITERAL 280
#define LP 281
#define RP 282
#define LC 283
#define RC 284
#define LB 285
#define RB 286
#define SM 287
#define CM 288
#define DOT 289
#define ASN 290
#define LT 291
#define GT 292
#define BANG 293
#define COLON 294
#define EQ 295
#define NE 296
#define LE 297
#define GE 298
#define ANDAND 299
#define OROR 300
#define PLUS 301
#define MINUS 302
#define MUL 303
#define DIV 304
#define AND 305
#define OR 306
#define SWAP 307
#define MOD 308
#define SHL 309
#define SHR 310
#define LSHR 311
#define PLASN 312
#define MIASN 313




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 29 "g0gram.y"
{
   struct tree *t;
   }
/* Line 1529 of yacc.c.  */
#line 169 "g0gram.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

