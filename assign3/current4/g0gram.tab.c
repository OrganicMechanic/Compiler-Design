/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 8 "g0gram.y" /* yacc.c:339  */

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

#line 84 "g0gram.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "g0gram.tab.h".  */
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
#line 29 "g0gram.y" /* yacc.c:355  */

   struct tree *t;
   

#line 188 "g0gram.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_G0GRAM_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 205 "g0gram.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  349

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   111,   112,   113,   114,   115,   118,   119,
     122,   123,   124,   127,   128,   131,   134,   137,   138,   139,
     140,   143,   144,   147,   148,   149,   152,   153,   154,   157,
     158,   161,   164,   167,   168,   169,   172,   173,   176,   179,
     182,   185,   186,   189,   190,   193,   194,   197,   198,   201,
     204,   205,   208,   209,   212,   213,   216,   217,   220,   223,
     224,   227,   228,   231,   232,   235,   236,   239,   242,   245,
     249,   252,   253,   255,   258,   259,   262,   263,   266,   269,
     270,   273,   276,   277,   280,   281,   284,   285,   288,   291,
     294,   295,   296,   297,   298,   299,   302,   303,   304,   305,
     306,   309,   310,   311,   312,   315,   318,   321,   324,   325,
     328,   331,   334,   338,   341,   344,   345,   348,   349,   352,
     353,   356,   357,   360,   363,   367,   371,   372,   375,   376,
     379,   382,   385,   386,   387,   388,   389,   392,   393,   396,
     397,   400,   401,   404,   407,   408,   409,   410,   413,   414,
     415,   416,   419,   420,   423,   424,   425,   426,   427,   428,
     429,   432,   433,   434,   437,   438,   439,   440,   443,   444,
     445,   446,   447,   450,   451,   452,   453,   454,   457,   458,
     459,   462,   463,   466,   469,   470,   473,   474,   477,   478,
     481,   484,   485,   486,   487,   488,   491,   492,   493,   494,
     495,   498,   499,   502,   503,   504,   507,   508,   509,   512
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "AssignmentOperator", "Expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -305

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-305)))

#define YYTABLE_NINF -206

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 108 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(program, 1, (yyvsp[0].t)); yyprogram = (yyval.t); }
#line 1644 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 111 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1650 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 112 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1656 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 113 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1662 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 114 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1668 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 115 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1674 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1680 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1686 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1692 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 123 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1698 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1704 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1710 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1716 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 131 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1722 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 134 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1728 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 137 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1734 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 138 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1740 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 139 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1746 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 140 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1752 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 143 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1758 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 144 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(List-Type2, 4, (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1764 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 147 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1770 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 148 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Table-Type2, 4, (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1776 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 149 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Table-Type2, 6, (yyvsp[-5].t), (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1782 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Array-Type1, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1788 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 153 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Array-Type2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1794 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 154 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Array-Type3, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1800 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 157 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1806 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 158 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1812 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 161 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1818 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 164 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Qualified-Name1, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1824 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 167 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Compil-Unit1, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1830 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 168 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Compil-Unit2, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1836 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 169 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Compil-Unit3, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1842 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 172 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1848 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 173 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 1854 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 176 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1860 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 179 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Class-Decl1, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1866 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 182 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Class-Body1, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1872 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 185 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1878 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 186 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 1884 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 189 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1890 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 190 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(ClassBody-Decl2, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1896 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 193 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1902 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 194 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1908 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 197 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1914 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 198 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1920 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 201 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Field-Decl1, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1926 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 204 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1932 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 205 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Variable-Decs2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1938 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 208 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1944 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 209 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Variable-Decl2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1950 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 212 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1956 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 213 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(VariableDec-Id2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1962 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 216 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1968 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 217 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1974 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 220 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Method-Decl1, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1980 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 223 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Method-Head1, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1986 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 224 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Method-Head2, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1992 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 227 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 1998 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 228 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 2004 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 231 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(MethodDec-er1, 4, (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2010 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 232 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(MethodDec-er2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2016 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 235 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2022 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 236 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(FormalParam-List2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2028 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 239 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Formal-Para1, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2034 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 242 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2040 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 246 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Constructer-Deln1, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2046 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 249 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Constructer-Decl1, 4, (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2052 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 252 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2058 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 253 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 2064 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 255 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Constructer-Body1, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2070 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 258 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2076 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 259 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 2082 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 262 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 2088 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 263 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 2094 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 266 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Array-Init1, 4, (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2100 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 269 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2106 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 270 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(VariableInit-zers2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2112 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 273 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Block1, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2118 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 276 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2124 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 277 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Block-Stmt2, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2130 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 280 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2136 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 281 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2142 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 284 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2148 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 285 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 2154 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 288 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2160 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 291 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(LocVar-Decl1, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2166 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 294 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2172 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 295 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2178 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 296 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2184 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 297 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2190 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 298 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2196 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 299 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2202 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 302 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2208 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 303 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2214 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 304 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2220 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 305 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2226 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 306 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2232 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 309 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2238 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 310 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2244 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 311 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2250 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 312 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2256 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 315 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Labeled-Stmt1, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2262 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 318 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(LabeledStmtNoSrt-If1, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2268 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 321 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2274 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 324 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2280 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 325 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2286 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 328 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(IfThen-Stmt1, 4, (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t)); }
#line 2292 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 331 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(IfThenElse-Stmt1, 7, (yyvsp[-6].t), (yyvsp[-5].t), (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2298 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 335 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(IfThenElseNoSrt-If1, 7, (yyvsp[-6].t), (yyvsp[-5].t), (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2304 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 338 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(While-Stmt1, 4, (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t)); }
#line 2310 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 341 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(WhileNoSrt-If1, 5, (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2316 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 344 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2322 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 345 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 2328 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 348 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2334 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 349 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 2340 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 352 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2346 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 353 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2352 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 356 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2358 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 357 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 2364 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 360 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2370 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 364 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(For-Stmt1, 9, (yyvsp[-8].t), (yyvsp[-7].t), (yyvsp[-6].t), (yyvsp[-5].t), (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2376 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 368 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(ForStmtNoShort-If1, 9, (yyvsp[-8].t), (yyvsp[-7].t), (yyvsp[-6].t), (yyvsp[-5].t), (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2382 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 371 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2388 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 372 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(StatementExpression-List2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2394 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 375 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2400 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 376 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 2406 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 379 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Break-Stmt1, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2412 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 382 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Return-Stmt1, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2418 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 385 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2424 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 386 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Primary3, 2, (yyvsp[-2].t), (yyvsp[-1].t)); }
#line 2430 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 387 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2436 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 388 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2442 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 389 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2448 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 392 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2454 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 393 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Args-List2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2460 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 396 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2466 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 397 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = NULL; }
#line 2472 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 400 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Dims1, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2478 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 401 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Dims2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2484 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 404 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Field-Accs1, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2490 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 407 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Method-Invo1, 4, (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2496 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 408 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Method-Invo2, 5, (yyvsp[-5].t), (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t)); }
#line 2502 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 409 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Method-Invo4, 3, (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t)); }
#line 2508 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 410 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Method-Invo5, 5, (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2514 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 413 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Array-Accs1, 4, (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2520 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 414 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Array-Accs2, 4, (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2526 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 415 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Array-Accs3, 4, (yyvsp[-5].t), (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t)); }
#line 2532 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 416 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Array-Accs4, 4, (yyvsp[-5].t), (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t)); }
#line 2538 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 419 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Unary-Expr2, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2544 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 420 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2550 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 423 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2556 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 424 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2562 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 425 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(UnaryExprNotPlus-Min3, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2568 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 426 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(UnaryExprNotPlus-Min4, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2574 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 427 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(UnaryExprNotPlus-Min5, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2580 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 428 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(UnaryExprNotPlus-Min6, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2586 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 429 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2592 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 432 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Cast-Expr1, 5, (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2598 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 433 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Cast-Expr2, 4, (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2604 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 434 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Cast-Expr3, 5, (yyvsp[-4].t), (yyvsp[-3].t), (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2610 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 437 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2616 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 438 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Mult-Expr2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2622 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 439 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Mult-Expr3, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2628 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 440 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Mult-Expr4, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2634 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 443 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2640 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 444 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Add-Expr2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2646 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 445 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Add-Expr3, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2652 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 446 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Add-Expr4, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2658 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 447 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Add-Expr5, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2664 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 450 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2670 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 451 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Relational-Expr2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2676 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 452 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Relational-Expr3, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2682 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 453 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Relational-Expr4, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2688 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 454 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Relational-Expr5, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2694 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 457 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2700 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 458 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Equality-Expr2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2706 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 459 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Equality-Expr3, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2712 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 462 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2718 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 463 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(And-Expr2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2724 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 466 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2730 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 469 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2736 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 470 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(InclusiveOr-Expr2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2742 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 473 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2748 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 474 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(ConditionalAnd-Expr2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2754 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 477 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2760 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 478 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(ConditionalOr-Expr2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2766 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 481 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2772 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 484 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2778 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 485 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2784 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 486 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Assign-Expr3, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2790 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 487 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Assign-Expr4, 2, (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2796 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 488 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Assign-Expr5, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2802 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 491 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2808 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 492 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2814 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 493 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2820 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 494 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2826 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 495 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(List-Fill5, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2832 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 498 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Assignment1, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2838 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 499 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = P(Assignment2, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 2844 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 502 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2850 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 503 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2856 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 504 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2862 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 507 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2868 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 508 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2874 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 509 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2880 "g0gram.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 512 "g0gram.y" /* yacc.c:1646  */
    { (yyval.t) = (yyvsp[0].t); }
#line 2886 "g0gram.tab.c" /* yacc.c:1646  */
    break;


#line 2890 "g0gram.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 515 "g0gram.y" /* yacc.c:1906  */

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
