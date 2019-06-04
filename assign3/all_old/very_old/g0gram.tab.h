/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_G0GRAM_TAB_H_INCLUDED
# define YY_YY_G0GRAM_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "g0gram.y" /* yacc.c:1909  */

   struct tree *t;
   

#line 118 "g0gram.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_G0GRAM_TAB_H_INCLUDED  */
