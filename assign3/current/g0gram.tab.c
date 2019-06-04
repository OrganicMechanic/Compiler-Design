/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 8 "g0gram.y"

#include <stdio.h>
#include "tree.h"

#include "clex.h"
#include "list.h"
#include "tree.h"

extern struct tree *yyprogram;
extern struct list *filenames;

void yyerror(const char *s);
void typenames_insert_tree(struct tree *t, int category);

#define P(name, ...) tree_initv(NULL, #name, __VA_ARGS__)
#define E() NULL


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 29 "g0gram.y"
{
   struct tree *t;
   }
/* Line 193 of yacc.c.  */
#line 234 "g0gram.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 247 "g0gram.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   739

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNRULES -- Number of states.  */
#define YYNSTATES  349

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    48,    50,    55,    62,    66,    70,    74,
      76,    78,    80,    84,    87,    90,    93,    95,    96,    98,
     102,   106,   108,   109,   111,   114,   116,   118,   120,   122,
     125,   127,   131,   133,   137,   139,   143,   145,   147,   150,
     153,   156,   158,   159,   164,   168,   170,   174,   177,   179,
     182,   187,   189,   190,   194,   196,   197,   199,   200,   205,
     207,   211,   215,   217,   220,   222,   224,   226,   227,   229,
     232,   234,   236,   238,   240,   242,   244,   246,   248,   250,
     252,   254,   256,   258,   260,   262,   266,   270,   272,   274,
     276,   282,   290,   298,   304,   310,   312,   313,   315,   316,
     318,   320,   322,   323,   325,   335,   345,   347,   351,   353,
     354,   357,   360,   362,   366,   368,   370,   372,   374,   378,
     380,   381,   384,   388,   392,   397,   404,   409,   415,   420,
     425,   432,   439,   442,   444,   446,   448,   451,   454,   458,
     461,   463,   469,   474,   480,   482,   486,   490,   494,   496,
     500,   504,   507,   510,   512,   516,   520,   524,   528,   530,
     534,   538,   540,   544,   546,   548,   552,   554,   558,   560,
     564,   566,   568,   570,   573,   576,   580,   582,   584,   586,
     588,   592,   596,   600,   602,   604,   606,   608,   610,   612
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      60,     0,    -1,    74,    -1,    23,    -1,    24,    -1,    22,
      -1,    25,    -1,    21,    -1,    63,    -1,    67,    -1,    64,
      -1,     3,    -1,     9,    -1,    65,    -1,    66,    -1,    11,
      -1,     6,    -1,    71,    -1,    70,    -1,    68,    -1,    69,
      -1,    16,    -1,    16,    36,    62,    37,    -1,    15,    -1,
      15,    36,    62,    37,    -1,    15,    36,    62,    33,    62,
      37,    -1,    63,    30,    31,    -1,    71,    30,    31,    -1,
      70,    30,    31,    -1,    72,    -1,    73,    -1,    20,    -1,
      71,    34,    20,    -1,    76,    75,    -1,    83,    75,    -1,
      88,    75,    -1,    74,    -1,    -1,    77,    -1,     5,    20,
      78,    -1,    28,    79,    29,    -1,    80,    -1,    -1,    81,
      -1,    80,    81,    -1,    82,    -1,    95,    -1,    83,    -1,
      88,    -1,    62,    84,    -1,    85,    -1,    84,    33,    85,
      -1,    86,    -1,    86,    35,    87,    -1,    20,    -1,    86,
      30,    31,    -1,   157,    -1,   101,    -1,    89,    94,    -1,
      62,    91,    -1,    18,    91,    -1,    92,    -1,    -1,    20,
      26,    90,    27,    -1,    91,    30,    31,    -1,    93,    -1,
      92,    33,    93,    -1,    62,    86,    -1,   103,    -1,    96,
      98,    -1,    72,    26,    90,    27,    -1,   104,    -1,    -1,
      28,    97,    29,    -1,   102,    -1,    -1,    33,    -1,    -1,
      28,    99,   100,    29,    -1,    87,    -1,   102,    33,    87,
      -1,    28,    97,    29,    -1,   105,    -1,   104,   105,    -1,
     107,    -1,   109,    -1,   133,    -1,    -1,   108,    -1,    62,
      84,    -1,   111,    -1,   112,    -1,   116,    -1,   117,    -1,
     119,    -1,   126,    -1,   111,    -1,   113,    -1,   118,    -1,
     120,    -1,   127,    -1,   103,    -1,   114,    -1,   130,    -1,
     131,    -1,    20,    39,   109,    -1,    20,    39,   110,    -1,
     115,    -1,   154,    -1,   137,    -1,    10,    26,   157,    27,
     109,    -1,    10,    26,   157,    27,   110,     7,   109,    -1,
      10,    26,   157,    27,   110,     7,   110,    -1,    19,    26,
     157,    27,   109,    -1,    19,    26,   157,    27,   110,    -1,
     123,    -1,    -1,   125,    -1,    -1,   128,    -1,   108,    -1,
     157,    -1,    -1,   128,    -1,     8,    26,   121,    32,   124,
      32,   122,    27,   109,    -1,     8,    26,   121,    32,   124,
      32,   122,    27,   110,    -1,   115,    -1,   128,    33,   115,
      -1,    20,    -1,    -1,     4,   129,    -1,    12,   124,    -1,
      61,    -1,    26,   157,    27,    -1,   136,    -1,   138,    -1,
     137,    -1,   157,    -1,   133,    33,   157,    -1,   135,    -1,
      -1,    30,    31,    -1,   135,    30,    31,    -1,   132,    34,
      20,    -1,    71,    26,   106,    27,    -1,   132,    34,    20,
      26,   106,    27,    -1,    71,    28,   106,    29,    -1,   132,
      34,    20,    28,    29,    -1,    71,    30,   157,    31,    -1,
     132,    30,   157,    31,    -1,    71,    30,   157,    39,   157,
      31,    -1,   132,    30,   157,    39,   157,    31,    -1,    47,
     139,    -1,   140,    -1,   132,    -1,    71,    -1,    38,   139,
      -1,    14,    23,    -1,    23,    14,    23,    -1,    17,    20,
      -1,   141,    -1,    26,    63,   134,    27,   139,    -1,    26,
     157,    27,   140,    -1,    26,    71,   135,    27,   140,    -1,
     139,    -1,   142,    48,   139,    -1,   142,    49,   139,    -1,
     142,    53,   139,    -1,   142,    -1,   143,    46,   142,    -1,
     143,    47,   142,    -1,    25,   143,    -1,   143,    25,    -1,
     143,    -1,   144,    36,   143,    -1,   144,    37,   143,    -1,
     144,    42,   143,    -1,   144,    43,   143,    -1,   144,    -1,
     145,    40,   144,    -1,   145,    41,   144,    -1,   145,    -1,
     146,    50,   145,    -1,   146,    -1,   147,    -1,   148,    51,
     147,    -1,   148,    -1,   149,    44,   148,    -1,   149,    -1,
     150,    45,   149,    -1,   150,    -1,   151,    -1,   154,    -1,
      25,   154,    -1,   154,    25,    -1,    30,   153,    31,    -1,
      23,    -1,    25,    -1,    24,    -1,    21,    -1,   153,    33,
     153,    -1,   155,   156,   152,    -1,   155,    52,   152,    -1,
      71,    -1,   136,    -1,   138,    -1,    35,    -1,    57,    -1,
      58,    -1,   152,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   110,   110,   113,   114,   115,   116,   117,   120,   121,
     124,   125,   126,   129,   130,   133,   136,   139,   140,   141,
     142,   145,   146,   149,   150,   151,   154,   155,   156,   159,
     160,   163,   166,   169,   170,   171,   174,   175,   178,   181,
     184,   187,   188,   191,   192,   195,   196,   199,   200,   203,
     206,   207,   210,   211,   214,   215,   218,   219,   222,   225,
     226,   229,   230,   233,   234,   237,   238,   241,   244,   247,
     251,   254,   255,   257,   260,   261,   264,   265,   268,   271,
     272,   275,   278,   279,   282,   283,   286,   287,   290,   293,
     296,   297,   298,   299,   300,   301,   304,   305,   306,   307,
     308,   311,   312,   313,   314,   317,   320,   323,   326,   327,
     330,   333,   336,   340,   343,   346,   347,   350,   351,   354,
     355,   358,   359,   362,   365,   369,   373,   374,   377,   378,
     381,   384,   387,   388,   389,   390,   391,   394,   395,   398,
     399,   402,   403,   406,   409,   410,   411,   412,   415,   416,
     417,   418,   421,   422,   425,   426,   427,   428,   429,   430,
     431,   434,   435,   436,   439,   440,   441,   442,   445,   446,
     447,   448,   449,   452,   453,   454,   455,   456,   459,   460,
     461,   464,   465,   468,   471,   472,   475,   476,   479,   480,
     483,   486,   487,   488,   489,   490,   493,   494,   495,   496,
     497,   500,   501,   504,   505,   506,   509,   510,   511,   514
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLEAN", "BREAK", "CLASS", "DOUBLE",
  "ELSE", "FOR", "STRING", "IF", "INT", "RETURN", "THIS", "D", "TABLE",
  "LIST", "UNSIZE", "VOID", "WHILE", "IDENT", "NULLLITERAL", "BOOLLITERAL",
  "INTLITERAL", "FLOATLITERAL", "STRINGLITERAL", "LP", "RP", "LC", "RC",
  "LB", "RB", "SM", "CM", "DOT", "ASN", "LT", "GT", "BANG", "COLON", "EQ",
  "NE", "LE", "GE", "ANDAND", "OROR", "PLUS", "MINUS", "MUL", "DIV", "AND",
  "OR", "SWAP", "MOD", "SHL", "SHR", "LSHR", "PLASN", "MIASN", "$accept",
  "Goal", "Literal", "Type", "PrimitiveType", "NumericType",
  "IntegralType", "FloatingPointType", "ReferenceType", "ListType",
  "TableType", "ArrayType", "Name", "SimpleName", "QualifiedName",
  "CompilationUnit", "CompilationUnitOpt", "TypeDeclaration",
  "ClassDeclaration", "ClassBody", "ClassBodyDeclarationsOpt",
  "ClassBodyDeclarations", "ClassBodyDeclaration",
  "ClassMemberDeclaration", "FieldDeclaration", "VariableDeclarators",
  "VariableDeclarator", "VariableDeclaratorId", "VariableInitializer",
  "MethodDeclaration", "MethodHeader", "FormalParameterListOpt",
  "MethodDeclarator", "FormalParameterList", "FormalParameter",
  "MethodBody", "ConstructorDeclaration", "ConstructorDeclarator",
  "BlockStatementsOpt", "ConstructorBody", "VariableInitializersOpt",
  "CMOpt", "ArrayInitializer", "VariableInitializers", "Block",
  "BlockStatements", "BlockStatement", "ArgumentListOpt",
  "LocalVariableDeclarationStatement", "LocalVariableDeclaration",
  "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "LabeledStatement",
  "LabeledStatementNoShortIf", "ExpressionStatement",
  "StatementExpression", "IfThenStatement", "IfThenElseStatement",
  "IfThenElseStatementNoShortIf", "WhileStatement",
  "WhileStatementNoShortIf", "ForInitOpt", "ForUpdateOpt", "ForInit",
  "ExpressionOpt", "ForUpdate", "ForStatement", "ForStatementNoShortIf",
  "StatementExpressionList", "IDENTOpt", "BreakStatement",
  "ReturnStatement", "Primary", "ArgumentList", "DimsOpt", "Dims",
  "FieldAccess", "MethodInvocation", "ArrayAccess", "UnaryExpression",
  "UnaryExpressionNotPlusMinus", "CastExpression",
  "MultiplicativeExpression", "AdditiveExpression", "RelationalExpression",
  "EqualityExpression", "AndExpression", "ExclusiveOrExpression",
  "InclusiveOrExpression", "ConditionalAndExpression",
  "ConditionalOrExpression", "ConditionalExpression",
  "AssignmentExpression", "ListFill", "Assignment", "LeftHandSide",
  "AssignmentOperator", "Expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    61,    61,    61,    62,    62,
      63,    63,    63,    64,    64,    65,    66,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    70,    70,    70,    71,
      71,    72,    73,    74,    74,    74,    75,    75,    76,    77,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    94,    95,
      96,    97,    97,    98,    99,    99,   100,   100,   101,   102,
     102,   103,   104,   104,   105,   105,   106,   106,   107,   108,
     109,   109,   109,   109,   109,   109,   110,   110,   110,   110,
     110,   111,   111,   111,   111,   112,   113,   114,   115,   115,
     116,   117,   118,   119,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   126,   127,   128,   128,   129,   129,
     130,   131,   132,   132,   132,   132,   132,   133,   133,   134,
     134,   135,   135,   136,   137,   137,   137,   137,   138,   138,
     138,   138,   139,   139,   140,   140,   140,   140,   140,   140,
     140,   141,   141,   141,   142,   142,   142,   142,   143,   143,
     143,   143,   143,   144,   144,   144,   144,   144,   145,   145,
     145,   146,   146,   147,   148,   148,   149,   149,   150,   150,
     151,   152,   152,   152,   152,   152,   153,   153,   153,   153,
     153,   154,   154,   155,   155,   155,   156,   156,   156,   157
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     4,     6,     3,     3,     3,     1,
       1,     1,     3,     2,     2,     2,     1,     0,     1,     3,
       3,     1,     0,     1,     2,     1,     1,     1,     1,     2,
       1,     3,     1,     3,     1,     3,     1,     1,     2,     2,
       2,     1,     0,     4,     3,     1,     3,     2,     1,     2,
       4,     1,     0,     3,     1,     0,     1,     0,     4,     1,
       3,     3,     1,     2,     1,     1,     1,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       5,     7,     7,     5,     5,     1,     0,     1,     0,     1,
       1,     1,     0,     1,     9,     9,     1,     3,     1,     0,
       2,     2,     1,     3,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     3,     4,     6,     4,     5,     4,     4,
       6,     6,     2,     1,     1,     1,     2,     2,     3,     2,
       1,     5,     4,     5,     1,     3,     3,     3,     1,     3,
       3,     2,     2,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     2,     2,     3,     1,     1,     1,     1,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,     0,    16,    12,    15,    23,    21,     0,    31,
       0,     0,     8,    10,    13,    14,     9,    19,    20,    18,
      17,    29,    30,     2,    37,    38,    37,    37,     0,     0,
       0,     0,     0,    60,     1,    54,    49,    50,    52,    59,
       0,     0,     0,     0,    36,    33,    34,    35,    72,    58,
      68,    42,    39,     0,     0,    62,     0,     0,     0,     0,
      26,    28,    27,    32,   129,     0,     0,   122,     0,    31,
       7,     5,     3,     4,     6,     0,   132,     0,   203,     0,
     101,    71,    82,    84,    88,    85,    90,    91,   102,   107,
      92,    93,    94,    95,   103,   104,     0,   134,   109,   135,
     108,     0,    29,     0,    41,    43,    45,    47,    48,    46,
       0,     0,    24,    22,     0,     0,    61,    65,    64,    54,
      51,    55,     0,     0,     3,     6,     0,    75,     0,     0,
       0,   155,    53,    57,   154,   136,   164,   153,   160,   168,
     173,   178,   181,   183,   184,   186,   188,   190,   191,   209,
     192,    56,   128,   130,   116,     0,   131,   121,     0,     0,
       0,    89,    87,    87,     0,    81,    83,     0,     0,   206,
       0,   207,   208,     0,    62,    40,    44,    72,    69,     0,
      67,    63,     0,   157,   159,     0,     6,   171,   193,   140,
     155,     0,    79,    77,    74,   199,   196,   198,   197,     0,
     155,   134,   135,   156,   152,     0,     0,     0,     0,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,   120,   126,     0,   115,   119,     0,     0,
     203,   105,   133,     0,    86,   137,     0,     0,     0,   143,
     202,   201,     0,     0,    25,    66,   158,     0,     0,   139,
       0,     0,   133,    76,     0,     0,   195,     0,   165,   166,
     167,   169,   170,   174,   175,   176,   177,   179,   180,   182,
     185,   187,   189,   122,     0,     0,     0,   144,     0,   146,
     148,     0,   149,     0,    87,     0,    70,    73,   141,     0,
       0,     0,   162,    78,    80,   200,     0,   127,     0,     0,
       0,    31,   110,     0,    90,    97,    98,    99,   100,   113,
     138,     0,     0,     0,   147,   161,   142,   163,   118,   116,
       0,     0,     0,     0,   150,   151,   145,     0,   117,   123,
       0,     0,     0,   106,   111,     0,   122,     0,     0,   124,
       0,     0,   114,   118,     0,     0,   112,     0,   125
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    76,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   131,    21,    22,    44,    45,    24,    25,    52,
     103,   104,   105,   106,    26,    36,    37,    38,   132,    27,
      28,   115,    33,   116,   117,    49,   109,   110,    79,   178,
     193,   254,   133,   194,    80,    81,    82,   233,    83,    84,
      85,   303,    86,    87,   305,    88,    89,    90,    91,   306,
      92,   307,   225,   327,   226,   156,   328,    93,   308,   227,
     153,    94,    95,   134,   234,   248,   249,    97,   135,    99,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   199,   150,   101,   173,   151
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -305
static const yytype_int16 yypact[] =
{
     703,  -305,    -8,  -305,  -305,  -305,    -4,    40,    87,  -305,
     109,   115,    72,  -305,  -305,  -305,  -305,  -305,  -305,    97,
      29,  -305,  -305,  -305,   703,  -305,   703,   703,   114,   122,
     719,   719,   131,   132,  -305,   131,   142,  -305,    -2,   132,
     134,   145,   149,   161,  -305,  -305,  -305,  -305,   596,  -305,
    -305,   354,  -305,    52,   146,   719,   153,   165,   156,   223,
    -305,  -305,  -305,  -305,   168,   163,   164,   525,   166,   157,
    -305,  -305,  -305,  -305,  -305,   525,  -305,   165,    80,   169,
    -305,   596,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,    71,    22,    82,    25,
    -305,    38,   173,   172,   354,  -305,  -305,  -305,  -305,  -305,
     167,   719,  -305,  -305,   165,   175,   171,  -305,  -305,  -305,
    -305,  -305,   182,   189,   215,   544,   469,   223,   128,   563,
     563,    89,  -305,  -305,    71,  -305,  -305,  -305,  -305,    50,
      -3,   102,    21,   180,  -305,   181,   194,   196,  -305,  -305,
     214,  -305,  -305,  -305,   679,   525,  -305,  -305,   525,   619,
     228,   142,   525,   525,   427,  -305,  -305,   525,   222,  -305,
     525,  -305,  -305,   525,   719,  -305,  -305,   596,  -305,   213,
     226,  -305,   719,  -305,  -305,   234,   544,    -3,  -305,   229,
     258,   231,  -305,   227,   233,  -305,  -305,  -305,  -305,    16,
      -5,  -305,  -305,  -305,  -305,   525,   563,   563,   563,  -305,
     563,   563,   544,   544,   544,   544,   544,   544,   544,   544,
     544,   544,  -305,  -305,  -305,   230,  -305,   235,   240,   242,
      -5,  -305,  -305,   245,   247,  -305,   244,     7,    19,    28,
    -305,  -305,   256,   261,  -305,  -305,  -305,   254,   260,   265,
     497,   107,   655,  -305,   269,   223,  -305,   128,  -305,  -305,
    -305,    50,    50,    -3,    -3,    -3,    -3,   102,   102,    21,
    -305,   181,   194,   525,   202,   642,   619,  -305,   525,  -305,
    -305,   525,  -305,   525,   525,   272,  -305,  -305,  -305,   563,
     273,   655,  -305,  -305,  -305,   276,   281,  -305,   288,   291,
     294,   282,  -305,   318,   321,  -305,  -305,  -305,  -305,  -305,
    -305,   298,   300,   307,  -305,  -305,  -305,  -305,   202,   679,
     525,   525,   642,   619,  -305,  -305,  -305,   312,  -305,   235,
     308,   314,   315,  -305,  -305,   619,   525,   642,   642,  -305,
     313,   339,  -305,   202,   642,   323,  -305,   642,  -305
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -305,  -305,  -305,   -14,   232,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,     0,   -40,  -305,   355,    94,  -305,  -305,  -305,
    -305,  -305,   250,  -305,   -33,   284,   316,   278,  -122,   -32,
    -305,   190,   364,  -305,   197,  -305,  -305,  -305,   216,  -305,
    -305,  -305,  -305,  -305,   366,  -305,   317,  -162,  -305,  -152,
    -144,  -302,  -269,  -305,  -305,  -305,  -146,  -305,  -305,  -305,
    -305,  -305,    78,    58,  -305,  -270,  -305,  -305,  -305,  -304,
    -305,  -305,  -305,   -11,  -305,  -305,   212,   170,    77,   219,
    -120,  -239,  -305,   -55,  -121,   -46,   185,  -305,   187,   184,
     186,  -305,  -305,    -9,   151,   -41,  -305,  -305,   204
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -206
static const yytype_int16 yytable[] =
{
      20,   236,   223,   296,   187,   192,   304,   100,   224,   203,
     204,   102,    29,   292,   329,   231,    53,    54,   107,   108,
     333,   162,   209,   163,    20,   205,    20,    20,    58,    43,
      20,    20,    30,    59,    77,   341,   342,    96,   280,   329,
     100,   114,   346,   210,   211,   348,   281,   256,    78,   257,
     282,    20,   317,   304,   284,    20,   285,  -204,   283,    42,
    -205,   216,   217,    43,   102,   187,   340,    77,   304,   304,
      96,   107,   108,   169,  -204,   304,    31,  -205,   304,  -204,
    -204,    78,  -205,  -205,   188,   111,   258,   259,   260,   112,
     170,   263,   264,   265,   266,   171,   172,   179,   206,   207,
     -17,   167,    40,   208,    20,   168,   162,    32,   163,    34,
     164,    20,  -136,   100,    43,   162,  -136,   163,   100,   205,
      46,    47,   313,    43,  -203,    98,   190,    41,   297,   200,
     200,   302,   309,   294,   291,    35,   100,   290,   212,   213,
      77,  -203,    48,    96,   214,   215,  -203,  -203,    96,   195,
      51,   196,   197,   198,    78,   261,   262,    55,    98,   230,
     114,   240,    56,    77,   241,    60,    96,   223,   114,   315,
     267,   268,   224,   224,    20,    57,    61,    78,   231,   334,
      62,    63,    20,   113,   118,   119,   200,   121,   152,   154,
     155,   339,   158,   302,   309,   177,   159,   224,   165,   174,
     334,   175,   181,   339,   182,   183,   200,   200,   200,   184,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,     9,    70,    71,    72,    73,    74,    75,   185,
     218,    98,   219,   100,   100,   100,    98,   122,   220,   222,
     123,   221,   239,     9,    70,    71,   124,    73,   125,   126,
     244,   127,   200,   128,    98,   232,    58,   246,   252,   247,
     253,   129,   273,    96,    96,    96,   255,   275,   274,   276,
     130,   157,   277,   279,   230,   230,   230,   100,   100,   160,
     278,   100,   100,   286,   162,   288,   163,   289,   250,   200,
     287,   200,    43,  -203,   100,   290,   100,   100,   293,   201,
     201,   314,   100,   100,   316,    77,   100,    96,    96,   257,
    -203,    96,    96,   318,   319,  -203,  -203,   320,   230,    78,
     321,   322,   230,   230,    96,   323,    96,    96,   -96,   324,
     191,   325,    96,    96,   326,   230,    96,   230,   230,   335,
     336,   337,   338,   230,   230,   343,   344,   230,   202,   202,
     347,    98,    98,    98,   176,    23,   201,     1,   189,   228,
       3,   161,   229,     4,   242,     5,   235,   235,   237,     6,
       7,   238,     8,   120,     9,    39,   201,   201,   201,   245,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   180,   243,    50,    98,    98,   330,   166,    98,
      98,   345,   251,   269,   271,   202,   270,   272,   295,   237,
       0,     0,    98,     0,    98,    98,     0,     0,     0,     0,
      98,    98,   201,     0,    98,   202,   202,   202,     0,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   122,     0,     0,   123,     0,     0,     9,    70,    71,
     124,    73,   125,   126,   237,     0,     0,   128,    62,   201,
       0,   201,     0,     0,     0,   129,     0,     0,     0,     0,
       0,   202,     1,     0,   130,     3,     0,   157,     4,     0,
       5,     0,   310,   122,     0,   311,   123,   312,   235,     9,
      70,    71,   124,    73,   125,   126,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   129,   202,     0,
     202,   122,     0,     0,   123,     0,   130,     9,    70,    71,
     124,    73,   125,   126,   331,   332,     0,   128,   288,     0,
       0,     0,     0,     0,     0,   129,     0,     0,     0,   122,
     157,     0,   123,     0,   130,     9,    70,    71,   124,    73,
     125,   126,     0,     0,     0,   128,     0,     0,   122,     0,
       0,   123,     0,   129,     9,    70,    71,   124,    73,   186,
     126,     0,   130,     0,     0,     0,     0,   122,     0,     0,
     123,     0,   129,     9,    70,    71,   124,    73,    74,   126,
       0,   130,     0,     0,     0,     0,     0,     0,     0,     1,
      64,   129,     3,     0,    65,     4,    66,     5,    67,     0,
     130,     6,     7,     0,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    64,    48,     0,     0,    65,     0,    66,
       0,    67,     0,     0,     0,     0,     0,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    64,    48,     0,     0,
     298,     0,   299,     0,    67,     0,     0,     0,     0,     0,
       0,   300,   301,    70,    71,    72,    73,    74,    75,   122,
      48,     0,   123,     0,     0,     9,    70,    71,   124,    73,
      74,   126,     1,     0,     0,     3,     0,     0,     4,     0,
       5,     0,     0,   129,     6,     7,     0,     0,     0,     9,
      70,    71,    72,    73,    74,    75,     1,     0,     2,     3,
       0,     0,     4,     0,     5,     0,     0,     0,     6,     7,
       0,     8,     1,     9,     0,     3,     0,     0,     4,     0,
       5,     0,     0,     0,     6,     7,     0,     0,     0,     9
};

static const yytype_int16 yycheck[] =
{
       0,   163,   154,   273,   125,   127,   275,    48,   154,   129,
     130,    51,    20,   252,   318,   159,    30,    31,    51,    51,
     322,    26,    25,    28,    24,    30,    26,    27,    30,    34,
      30,    31,    36,    35,    48,   337,   338,    48,    31,   343,
      81,    55,   344,    46,    47,   347,    39,    31,    48,    33,
      31,    51,   291,   322,    26,    55,    28,    35,    39,    30,
      35,    40,    41,    34,   104,   186,   336,    81,   337,   338,
      81,   104,   104,    35,    52,   344,    36,    52,   347,    57,
      58,    81,    57,    58,   125,    33,   206,   207,   208,    37,
      52,   212,   213,   214,   215,    57,    58,   111,    48,    49,
      20,    30,    30,    53,   104,    34,    26,    20,    28,     0,
      30,   111,    30,   154,    34,    26,    34,    28,   159,    30,
      26,    27,   284,    34,    35,    48,   126,    30,   274,   129,
     130,   275,   276,   255,    27,    20,   177,    30,    36,    37,
     154,    52,    28,   154,    42,    43,    57,    58,   159,    21,
      28,    23,    24,    25,   154,   210,   211,    26,    81,   159,
     174,   170,    30,   177,   173,    31,   177,   319,   182,   289,
     216,   217,   318,   319,   174,    33,    31,   177,   322,   323,
      31,    20,   182,    37,    31,    20,   186,    31,    20,    26,
      26,   335,    26,   337,   338,    28,    39,   343,    29,    26,
     344,    29,    27,   347,    33,    23,   206,   207,   208,    20,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    20,    21,    22,    23,    24,    25,    26,    14,
      50,   154,    51,   274,   275,   276,   159,    14,    44,    25,
      17,    45,    20,    20,    21,    22,    23,    24,    25,    26,
      37,    28,   252,    30,   177,    27,    30,    23,    27,    30,
      33,    38,    32,   274,   275,   276,    33,    27,    33,    27,
      47,    67,    27,    29,   274,   275,   276,   318,   319,    75,
      33,   322,   323,    27,    26,    31,    28,    27,    30,   289,
      29,   291,    34,    35,   335,    30,   337,   338,    29,   129,
     130,    29,   343,   344,    31,   319,   347,   318,   319,    33,
      52,   322,   323,    32,    26,    57,    58,    26,   318,   319,
      26,    39,   322,   323,   335,     7,   337,   338,     7,    31,
     126,    31,   343,   344,    27,   335,   347,   337,   338,    27,
      32,    27,    27,   343,   344,    32,     7,   347,   129,   130,
      27,   274,   275,   276,   104,     0,   186,     3,   126,   155,
       6,    77,   158,     9,   174,    11,   162,   163,   164,    15,
      16,   167,    18,    57,    20,    11,   206,   207,   208,   182,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   114,   177,    28,   318,   319,   319,    81,   322,
     323,   343,   190,   218,   220,   186,   219,   221,   257,   205,
      -1,    -1,   335,    -1,   337,   338,    -1,    -1,    -1,    -1,
     343,   344,   252,    -1,   347,   206,   207,   208,    -1,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,    14,    -1,    -1,    17,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,   250,    -1,    -1,    30,    31,   289,
      -1,   291,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,   252,     3,    -1,    47,     6,    -1,   273,     9,    -1,
      11,    -1,   278,    14,    -1,   281,    17,   283,   284,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,   289,    -1,
     291,    14,    -1,    -1,    17,    -1,    47,    20,    21,    22,
      23,    24,    25,    26,   320,   321,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    14,
     336,    -1,    17,    -1,    47,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    14,    -1,
      -1,    17,    -1,    38,    20,    21,    22,    23,    24,    25,
      26,    -1,    47,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      17,    -1,    38,    20,    21,    22,    23,    24,    25,    26,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,    38,     6,    -1,     8,     9,    10,    11,    12,    -1,
      47,    15,    16,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,     4,    28,    -1,    -1,     8,    -1,    10,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,     4,    28,    -1,    -1,
       8,    -1,    10,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    14,
      28,    -1,    17,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,     3,    -1,    -1,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    38,    15,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,     3,    -1,     5,     6,
      -1,    -1,     9,    -1,    11,    -1,    -1,    -1,    15,    16,
      -1,    18,     3,    20,    -1,     6,    -1,    -1,     9,    -1,
      11,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     9,    11,    15,    16,    18,    20,
      60,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    76,    77,    83,    88,    89,    20,
      36,    36,    20,    91,     0,    20,    84,    85,    86,    91,
      30,    30,    30,    34,    74,    75,    75,    75,    28,    94,
     103,    28,    78,    62,    62,    26,    30,    33,    30,    35,
      31,    31,    31,    20,     4,     8,    10,    12,    19,    20,
      21,    22,    23,    24,    25,    26,    61,    62,    71,    97,
     103,   104,   105,   107,   108,   109,   111,   112,   114,   115,
     116,   117,   119,   126,   130,   131,   132,   136,   137,   138,
     154,   155,    72,    79,    80,    81,    82,    83,    88,    95,
      96,    33,    37,    37,    62,    90,    92,    93,    31,    20,
      85,    31,    14,    17,    23,    25,    26,    28,    30,    38,
      47,    71,    87,   101,   132,   137,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     154,   157,    20,   129,    26,    26,   124,   157,    26,    39,
     157,    84,    26,    28,    30,    29,   105,    30,    34,    35,
      52,    57,    58,   156,    26,    29,    81,    28,    98,    62,
      86,    27,    33,    23,    20,    14,    25,   143,   154,    63,
      71,   157,    87,    99,   102,    21,    23,    24,    25,   153,
      71,   136,   138,   139,   139,    30,    48,    49,    53,    25,
      46,    47,    36,    37,    42,    43,    40,    41,    50,    51,
      44,    45,    25,   108,   115,   121,   123,   128,   157,   157,
      71,   109,    27,   106,   133,   157,   106,   157,   157,    20,
     152,   152,    90,    97,    37,    93,    23,    30,   134,   135,
      30,   135,    27,    33,   100,    33,    31,    33,   139,   139,
     139,   142,   142,   143,   143,   143,   143,   144,   144,   145,
     147,   148,   149,    32,    33,    27,    27,    27,    33,    29,
      31,    39,    31,    39,    26,    28,    27,    29,    31,    27,
      30,    27,   140,    29,    87,   153,   124,   115,     8,    10,
      19,    20,   109,   110,   111,   113,   118,   120,   127,   109,
     157,   157,   157,   106,    29,   139,    31,   140,    32,    26,
      26,    26,    39,     7,    31,    31,    27,   122,   125,   128,
     121,   157,   157,   110,   109,    27,    32,    27,    27,   109,
     124,   110,   110,    32,     7,   122,   110,    27,   110
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 110 "g0gram.y"
    { (yyval.t) = P(program, 1, (yyvsp[(1) - (1)].t)); yyprogram = (yyval.t); ;}
    break;

  case 3:
#line 113 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 4:
#line 114 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 5:
#line 115 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 6:
#line 116 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 7:
#line 117 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 8:
#line 120 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 9:
#line 121 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 10:
#line 124 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 11:
#line 125 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 12:
#line 126 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 13:
#line 129 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 14:
#line 130 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 15:
#line 133 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 16:
#line 136 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 17:
#line 139 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 18:
#line 140 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 19:
#line 141 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 20:
#line 142 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 21:
#line 145 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 22:
#line 146 "g0gram.y"
    { (yyval.t) = P(List-Type2, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].t)); ;}
    break;

  case 23:
#line 149 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 24:
#line 150 "g0gram.y"
    { (yyval.t) = P(Table-Type2, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].t)); ;}
    break;

  case 25:
#line 151 "g0gram.y"
    { (yyval.t) = P(Table-Type3, 6, (yyvsp[(1) - (6)].t), (yyvsp[(2) - (6)].t), (yyvsp[(3) - (6)].t), (yyvsp[(4) - (6)].t), (yyvsp[(5) - (6)].t), (yyvsp[(6) - (6)].t)); ;}
    break;

  case 26:
#line 154 "g0gram.y"
    { (yyval.t) = P(Array-Type1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 27:
#line 155 "g0gram.y"
    { (yyval.t) = P(Array-Type2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 28:
#line 156 "g0gram.y"
    { (yyval.t) = P(Array-Type3, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 29:
#line 159 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 30:
#line 160 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 31:
#line 163 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 32:
#line 166 "g0gram.y"
    { (yyval.t) = P(Qualified-Name1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 33:
#line 169 "g0gram.y"
    { (yyval.t) = P(Compil-Unit1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 34:
#line 170 "g0gram.y"
    { (yyval.t) = P(Compil-Unit2, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 35:
#line 171 "g0gram.y"
    { (yyval.t) = P(Compil-Unit3, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 36:
#line 174 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 37:
#line 175 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 38:
#line 178 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 39:
#line 181 "g0gram.y"
    { (yyval.t) = P(Class-Decl1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 40:
#line 184 "g0gram.y"
    { (yyval.t) = P(Class-Body1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 41:
#line 187 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 42:
#line 188 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 43:
#line 191 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 44:
#line 192 "g0gram.y"
    { (yyval.t) = P(ClassBody-Decl2, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 45:
#line 195 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 46:
#line 196 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 47:
#line 199 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 48:
#line 200 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 49:
#line 203 "g0gram.y"
    { (yyval.t) = P(Field-Decl1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 50:
#line 206 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 51:
#line 207 "g0gram.y"
    { (yyval.t) = P(Variable-Decs2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 52:
#line 210 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 53:
#line 211 "g0gram.y"
    { (yyval.t) = P(Variable-Decl2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 54:
#line 214 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 55:
#line 215 "g0gram.y"
    { (yyval.t) = P(VariableDec-Id2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 56:
#line 218 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 57:
#line 219 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 58:
#line 222 "g0gram.y"
    { (yyval.t) = P(Method-Decl1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 59:
#line 225 "g0gram.y"
    { (yyval.t) = P(Method-Head1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 60:
#line 226 "g0gram.y"
    { (yyval.t) = P(Method-Head2, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 61:
#line 229 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 62:
#line 230 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 63:
#line 233 "g0gram.y"
    { (yyval.t) = P(MethodDec-er1, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].t)); ;}
    break;

  case 64:
#line 234 "g0gram.y"
    { (yyval.t) = P(MethodDec-er2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 65:
#line 237 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 66:
#line 238 "g0gram.y"
    { (yyval.t) = P(FormalParam-List2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 67:
#line 241 "g0gram.y"
    { (yyval.t) = P(Formal-Para1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 68:
#line 244 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 69:
#line 248 "g0gram.y"
    { (yyval.t) = P(Constructer-Deln1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 70:
#line 251 "g0gram.y"
    { (yyval.t) = P(Constructer-Decl1, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].t)); ;}
    break;

  case 71:
#line 254 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 72:
#line 255 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 73:
#line 257 "g0gram.y"
    { (yyval.t) = P(Constructer-Body1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 74:
#line 260 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 75:
#line 261 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 76:
#line 264 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 77:
#line 265 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 78:
#line 268 "g0gram.y"
    { (yyval.t) = P(Array-Init1, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].t)); ;}
    break;

  case 79:
#line 271 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 80:
#line 272 "g0gram.y"
    { (yyval.t) = P(VariableInit-zers2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 81:
#line 275 "g0gram.y"
    { (yyval.t) = P(Block1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 82:
#line 278 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 83:
#line 279 "g0gram.y"
    { (yyval.t) = P(Block-Stmt2, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 84:
#line 282 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 85:
#line 283 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 86:
#line 286 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 87:
#line 287 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 88:
#line 290 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 89:
#line 293 "g0gram.y"
    { (yyval.t) = P(LocVar-Decl1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 90:
#line 296 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 91:
#line 297 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 92:
#line 298 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 93:
#line 299 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 94:
#line 300 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 95:
#line 301 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 96:
#line 304 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 97:
#line 305 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 98:
#line 306 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 99:
#line 307 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 100:
#line 308 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 101:
#line 311 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 102:
#line 312 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 103:
#line 313 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 104:
#line 314 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 105:
#line 317 "g0gram.y"
    { (yyval.t) = P(Labeled-Stmt1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 106:
#line 320 "g0gram.y"
    { (yyval.t) = P(LabeledStmtNoSrt-If1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 107:
#line 323 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 108:
#line 326 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 109:
#line 327 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 110:
#line 330 "g0gram.y"
    { (yyval.t) = P(IfThen-Stmt1, 4, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].t), (yyvsp[(4) - (5)].t)); ;}
    break;

  case 111:
#line 333 "g0gram.y"
    { (yyval.t) = P(IfThenElse-Stmt1, 7, (yyvsp[(1) - (7)].t), (yyvsp[(2) - (7)].t), (yyvsp[(3) - (7)].t), (yyvsp[(4) - (7)].t), (yyvsp[(5) - (7)].t), (yyvsp[(6) - (7)].t), (yyvsp[(7) - (7)].t)); ;}
    break;

  case 112:
#line 337 "g0gram.y"
    { (yyval.t) = P(IfThenElseNoSrt-If1, 7, (yyvsp[(1) - (7)].t), (yyvsp[(2) - (7)].t), (yyvsp[(3) - (7)].t), (yyvsp[(4) - (7)].t), (yyvsp[(5) - (7)].t), (yyvsp[(6) - (7)].t), (yyvsp[(7) - (7)].t)); ;}
    break;

  case 113:
#line 340 "g0gram.y"
    { (yyval.t) = P(While-Stmt1, 4, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].t), (yyvsp[(4) - (5)].t)); ;}
    break;

  case 114:
#line 343 "g0gram.y"
    { (yyval.t) = P(WhileNoSrt-If1, 5, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].t), (yyvsp[(4) - (5)].t), (yyvsp[(5) - (5)].t)); ;}
    break;

  case 115:
#line 346 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 116:
#line 347 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 117:
#line 350 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 118:
#line 351 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 119:
#line 354 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 120:
#line 355 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 121:
#line 358 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 122:
#line 359 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 123:
#line 362 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 124:
#line 366 "g0gram.y"
    { (yyval.t) = P(For-Stmt1, 9, (yyvsp[(1) - (9)].t), (yyvsp[(2) - (9)].t), (yyvsp[(3) - (9)].t), (yyvsp[(4) - (9)].t), (yyvsp[(5) - (9)].t), (yyvsp[(6) - (9)].t), (yyvsp[(7) - (9)].t), (yyvsp[(8) - (9)].t), (yyvsp[(9) - (9)].t)); ;}
    break;

  case 125:
#line 370 "g0gram.y"
    { (yyval.t) = P(ForStmtNoShort-If1, 9, (yyvsp[(1) - (9)].t), (yyvsp[(2) - (9)].t), (yyvsp[(3) - (9)].t), (yyvsp[(4) - (9)].t), (yyvsp[(5) - (9)].t), (yyvsp[(6) - (9)].t), (yyvsp[(7) - (9)].t), (yyvsp[(8) - (9)].t), (yyvsp[(9) - (9)].t)); ;}
    break;

  case 126:
#line 373 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 127:
#line 374 "g0gram.y"
    { (yyval.t) = P(StatementExpression-List2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 128:
#line 377 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 129:
#line 378 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 130:
#line 381 "g0gram.y"
    { (yyval.t) = P(Break-Stmt1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 131:
#line 384 "g0gram.y"
    { (yyval.t) = P(Return-Stmt1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 132:
#line 387 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 133:
#line 388 "g0gram.y"
    { (yyval.t) = P(Primary3, 2, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t)); ;}
    break;

  case 134:
#line 389 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 135:
#line 390 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 136:
#line 391 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 137:
#line 394 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 138:
#line 395 "g0gram.y"
    { (yyval.t) = P(Args-List2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 139:
#line 398 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 140:
#line 399 "g0gram.y"
    { (yyval.t) = NULL; ;}
    break;

  case 141:
#line 402 "g0gram.y"
    { (yyval.t) = P(Dims1, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 142:
#line 403 "g0gram.y"
    { (yyval.t) = P(Dims2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 143:
#line 406 "g0gram.y"
    { (yyval.t) = P(Field-Accs1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 144:
#line 409 "g0gram.y"
    { (yyval.t) = P(Method-Invo1, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].t)); ;}
    break;

  case 145:
#line 410 "g0gram.y"
    { (yyval.t) = P(Method-Invo2, 5, (yyvsp[(1) - (6)].t), (yyvsp[(2) - (6)].t), (yyvsp[(3) - (6)].t), (yyvsp[(4) - (6)].t), (yyvsp[(5) - (6)].t)); ;}
    break;

  case 146:
#line 411 "g0gram.y"
    { (yyval.t) = P(Method-Invo4, 3, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t)); ;}
    break;

  case 147:
#line 412 "g0gram.y"
    { (yyval.t) = P(Method-Invo5, 5, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].t), (yyvsp[(4) - (5)].t), (yyvsp[(5) - (5)].t)); ;}
    break;

  case 148:
#line 415 "g0gram.y"
    { (yyval.t) = P(Array-Accs1, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].t)); ;}
    break;

  case 149:
#line 416 "g0gram.y"
    { (yyval.t) = P(Array-Accs2, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].t)); ;}
    break;

  case 150:
#line 417 "g0gram.y"
    { (yyval.t) = P(Array-Accs3, 4, (yyvsp[(1) - (6)].t), (yyvsp[(2) - (6)].t), (yyvsp[(3) - (6)].t), (yyvsp[(4) - (6)].t)); ;}
    break;

  case 151:
#line 418 "g0gram.y"
    { (yyval.t) = P(Array-Accs4, 4, (yyvsp[(1) - (6)].t), (yyvsp[(2) - (6)].t), (yyvsp[(3) - (6)].t), (yyvsp[(4) - (6)].t)); ;}
    break;

  case 152:
#line 421 "g0gram.y"
    { (yyval.t) = P(Unary-Expr2, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 153:
#line 422 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 154:
#line 425 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 155:
#line 426 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 156:
#line 427 "g0gram.y"
    { (yyval.t) = P(UnaryExprNotPlus-Min3, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 157:
#line 428 "g0gram.y"
    { (yyval.t) = P(UnaryExprNotPlus-Min4, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 158:
#line 429 "g0gram.y"
    { (yyval.t) = P(UnaryExprNotPlus-Min5, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 159:
#line 430 "g0gram.y"
    { (yyval.t) = P(UnaryExprNotPlus-Min6, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 160:
#line 431 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 161:
#line 434 "g0gram.y"
    { (yyval.t) = P(Cast-Expr1, 5, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].t), (yyvsp[(4) - (5)].t), (yyvsp[(5) - (5)].t)); ;}
    break;

  case 162:
#line 435 "g0gram.y"
    { (yyval.t) = P(Cast-Expr2, 4, (yyvsp[(1) - (4)].t), (yyvsp[(2) - (4)].t), (yyvsp[(3) - (4)].t), (yyvsp[(4) - (4)].t)); ;}
    break;

  case 163:
#line 436 "g0gram.y"
    { (yyval.t) = P(Cast-Expr3, 5, (yyvsp[(1) - (5)].t), (yyvsp[(2) - (5)].t), (yyvsp[(3) - (5)].t), (yyvsp[(4) - (5)].t), (yyvsp[(5) - (5)].t)); ;}
    break;

  case 164:
#line 439 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 165:
#line 440 "g0gram.y"
    { (yyval.t) = P(Mult-Expr2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 166:
#line 441 "g0gram.y"
    { (yyval.t) = P(Mult-Expr3, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 167:
#line 442 "g0gram.y"
    { (yyval.t) = P(Mult-Expr4, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 168:
#line 445 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 169:
#line 446 "g0gram.y"
    { (yyval.t) = P(Add-Expr2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 170:
#line 447 "g0gram.y"
    { (yyval.t) = P(Add-Expr3, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 171:
#line 448 "g0gram.y"
    { (yyval.t) = P(Add-Expr4, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 172:
#line 449 "g0gram.y"
    { (yyval.t) = P(Add-Expr5, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 173:
#line 452 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 174:
#line 453 "g0gram.y"
    { (yyval.t) = P(Relational-Expr2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 175:
#line 454 "g0gram.y"
    { (yyval.t) = P(Relational-Expr3, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 176:
#line 455 "g0gram.y"
    { (yyval.t) = P(Relational-Expr4, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 177:
#line 456 "g0gram.y"
    { (yyval.t) = P(Relational-Expr5, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 178:
#line 459 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 179:
#line 460 "g0gram.y"
    { (yyval.t) = P(Equality-Expr2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 180:
#line 461 "g0gram.y"
    { (yyval.t) = P(Equality-Expr3, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 181:
#line 464 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 182:
#line 465 "g0gram.y"
    { (yyval.t) = P(And-Expr2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 183:
#line 468 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 184:
#line 471 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 185:
#line 472 "g0gram.y"
    { (yyval.t) = P(InclusiveOr-Expr2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 186:
#line 475 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 187:
#line 476 "g0gram.y"
    { (yyval.t) = P(ConditionalAnd-Expr2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 188:
#line 479 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 189:
#line 480 "g0gram.y"
    { (yyval.t) = P(ConditionalOr-Expr2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 190:
#line 483 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 191:
#line 486 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 192:
#line 487 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 193:
#line 488 "g0gram.y"
    { (yyval.t) = P(Assign-Expr3, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 194:
#line 489 "g0gram.y"
    { (yyval.t) = P(Assign-Expr4, 2, (yyvsp[(1) - (2)].t), (yyvsp[(2) - (2)].t)); ;}
    break;

  case 195:
#line 490 "g0gram.y"
    { (yyval.t) = P(Assign-Expr5, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 196:
#line 493 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 197:
#line 494 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 198:
#line 495 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 199:
#line 496 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 200:
#line 497 "g0gram.y"
    { (yyval.t) = P(List-Fill5, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 201:
#line 500 "g0gram.y"
    { (yyval.t) = P(Assignment1, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 202:
#line 501 "g0gram.y"
    { (yyval.t) = P(Assignment2, 3, (yyvsp[(1) - (3)].t), (yyvsp[(2) - (3)].t), (yyvsp[(3) - (3)].t)); ;}
    break;

  case 203:
#line 504 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 204:
#line 505 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 205:
#line 506 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 206:
#line 509 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 207:
#line 510 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 208:
#line 511 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 209:
#line 514 "g0gram.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2921 "g0gram.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 517 "g0gram.y"

/*
 * Prints relevant information for syntax errors and exits returning 2
 * per assignment requirements.
 */
void yyerror(const char *s)
{
	fprintf(stderr, "Syntax error: file %s, line %d, token %s: %s\n",
			(const char *)list_peek(filenames), yylineno, yytext, s);
	exit(2);
}

