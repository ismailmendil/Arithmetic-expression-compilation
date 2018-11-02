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
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char* s);    

struct item{
    int value;
    struct item* next;

};

struct LinkedList{
    struct item* first;
    struct item* last;
};

struct tuple4{
   int op;
   int first_arg;
   int second_arg;
   int target;

};

struct entry {
    struct tuple4* content;
    struct entry* next;
};

struct tupleList{
    struct entry* first;
    struct entry* last;
};


int yylex (void);
double compute(int f_name, struct LinkedList *list);
struct LinkedList* createLinkedList();
void addItem(struct LinkedList* ll, double val);
void concatLL(struct LinkedList *ll1, struct LinkedList *ll2);
struct LinkedList* addItemInFront(int val, struct LinkedList *ll);
int ll_len(struct item* ll);

/*API for IR 4-tuple*/
struct tupleList* createTupleList();
struct entry* createEntry(int op, int first_arg, int second_arg, int target);
void addEntry(struct tupleList* list, struct entry *itm);
void displayTuples(struct tupleList *tlist);


/*Functions that are supported*/
double sum(struct item *itm);
double mean(struct item *itm);
double var(struct item *itm);
double product(struct item *itm);
 
 
 /*Produce RI*/
int produce_function(int f_name, struct LinkedList* ll);
int produce_mean(struct item * itm);
int produce_sum(struct item * itm);
int produce_sqrt(int number);
int produce_var(struct item * itm);
int produce_deviation(struct item * itm);
int produce_min(struct item * itm);
int produce_max(struct item * itm);


int line_nb = 0;
int temp = 300;
int address = 0;
struct tupleList* tlist = NULL;
const char * path = "ri_output";
FILE * output_file = NULL;




#line 148 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    PLUS = 259,
    MINUS = 260,
    TIMES = 261,
    DIV = 262,
    SIGN = 263,
    OPENING_PARENTHESIS = 264,
    CLOSING_PARENTHESIS = 265,
    STOP = 266,
    COMMA = 267,
    ERROR = 268,
    SUM = 269,
    MEAN = 270,
    VAR = 271,
    PRODUCT = 272,
    SQRT = 273,
    MIN = 274,
    MAX = 275,
    DEVIATION = 276,
    IDENT = 277
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 83 "parser.y" /* yacc.c:355  */

    struct LinkedList* ll; 
    double d;
    int n;
    char c;

#line 218 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 235 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  70

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   105,   105,   106,   109,   117,   120,   127,   131,   134,
     135,   136,   137,   140,   147,   152,   154,   155,   156,   157,
     158,   159,   162,   163,   169,   170,   171,   172,   174,   175,
     177,   178,   182,   183,   184,   185,   188,   189,   190,   191,
     192,   193,   195,   196
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "PLUS", "MINUS", "TIMES",
  "DIV", "SIGN", "OPENING_PARENTHESIS", "CLOSING_PARENTHESIS", "STOP",
  "COMMA", "ERROR", "SUM", "MEAN", "VAR", "PRODUCT", "SQRT", "MIN", "MAX",
  "DEVIATION", "IDENT", "$accept", "INPUT", "Z", "E", "T", "F", "func",
  "func_name", "arg_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277
};
# endif

#define YYPACT_NINF -38

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-38)))

#define YYTABLE_NINF -35

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    81,   -38,    36,    36,    58,    15,   -38,   -38,   -38,
      19,   -38,   -38,   -38,   -38,    32,     5,    42,   212,   -38,
     -38,     4,    80,    80,    80,   -38,    39,   -38,   -38,    81,
       7,    80,   -38,   -38,   102,   124,   -38,   -38,   146,   168,
      80,   190,   -38,   -38,   252,    24,   -38,    60,    81,   224,
      81,    62,    39,   236,    39,   248,    34,   103,    28,    80,
     -38,   -38,   -38,   -38,   -38,   -38,    49,   -38,   -38,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    25,     0,     0,     0,     5,    36,    37,    38,
       0,    39,    40,    41,    27,     0,     0,     0,     0,    15,
      26,     0,     0,     0,     0,    28,     0,    24,    23,    29,
       0,     0,     1,     3,     0,     0,     4,    12,     0,     0,
       0,     0,    19,    21,    43,     0,    22,     0,    10,     0,
      11,     7,    18,     0,    20,     0,     0,     0,     0,     0,
      35,    31,     9,    16,    17,    32,    28,    33,    30,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,    50,   -38,     2,     8,    -3,   -38,   -38,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    16,    44,    18,    19,    20,    21,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    28,    17,    56,    58,    40,     1,    30,     2,     3,
       4,    34,    35,    41,     5,    -2,     6,    46,    17,     7,
       8,     9,    69,    10,    11,    12,    13,    14,    31,    67,
      42,    43,    32,    47,    60,    53,    55,    26,    68,     2,
       3,     4,    49,    51,    65,     5,    34,    35,    24,    25,
       7,     8,     9,    36,    10,    11,    12,    13,    14,    29,
     -34,     2,     3,     4,    34,    35,    33,     5,    38,    39,
      61,     0,     7,     8,     9,     0,    10,    11,    12,    13,
      14,     1,     0,     2,     3,     4,     0,    22,    23,     5,
      24,    25,     0,     0,     7,     8,     9,     0,    10,    11,
      12,    13,    14,    48,     0,     2,     3,     4,     0,    22,
      23,     5,    24,    66,     0,     0,     7,     8,     9,     0,
      10,    11,    12,    13,    14,    50,     0,     2,     3,     4,
       0,     0,     0,     5,     0,     0,     0,     0,     7,     8,
       9,     0,    10,    11,    12,    13,    14,    52,     0,     2,
       3,     4,     0,     0,     0,     5,     0,     0,     0,     0,
       7,     8,     9,     0,    10,    11,    12,    13,    14,    54,
       0,     2,     3,     4,     0,     0,     0,     5,     0,     0,
       0,     0,     7,     8,     9,     0,    10,    11,    12,    13,
      14,    57,     0,     2,     3,     4,     0,     0,     0,     5,
       0,     0,     0,     0,     7,     8,     9,     0,    10,    11,
      12,    13,    14,    37,     0,     0,    -8,    -8,    38,    39,
       0,     0,    -8,    -8,    -8,    62,     0,     0,    -6,    -6,
      38,    39,     0,     0,    -6,    -6,    -6,    63,     0,     0,
     -13,   -13,   -13,   -13,     0,     0,   -13,   -13,   -13,    64,
       0,     0,   -14,   -14,   -14,   -14,    34,    35,   -14,   -14,
     -14,     0,     0,     0,    59
};

static const yytype_int8 yycheck[] =
{
       3,     4,     0,    40,    41,     1,     1,     5,     3,     4,
       5,     4,     5,     9,     9,     0,    11,    10,    16,    14,
      15,    16,    59,    18,    19,    20,    21,    22,     9,     1,
      22,    23,     0,    31,    10,    38,    39,     1,    10,     3,
       4,     5,    34,    35,    10,     9,     4,     5,     9,    10,
      14,    15,    16,    11,    18,    19,    20,    21,    22,     1,
      11,     3,     4,     5,     4,     5,    16,     9,     6,     7,
      10,    -1,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,     1,    -1,     3,     4,     5,    -1,     6,     7,     9,
       9,    10,    -1,    -1,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,     1,    -1,     3,     4,     5,    -1,     6,
       7,     9,     9,    10,    -1,    -1,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,     1,    -1,     3,     4,     5,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,     1,    -1,     3,
       4,     5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,     1,
      -1,     3,     4,     5,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,     1,    -1,     3,     4,     5,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,     1,    -1,    -1,     4,     5,     6,     7,
      -1,    -1,    10,    11,    12,     1,    -1,    -1,     4,     5,
       6,     7,    -1,    -1,    10,    11,    12,     1,    -1,    -1,
       4,     5,     6,     7,    -1,    -1,    10,    11,    12,     1,
      -1,    -1,     4,     5,     6,     7,     4,     5,    10,    11,
      12,    -1,    -1,    -1,    12
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     9,    11,    14,    15,    16,
      18,    19,    20,    21,    22,    24,    25,    26,    27,    28,
      29,    30,     6,     7,     9,    10,     1,    28,    28,     1,
      26,     9,     0,    24,     4,     5,    11,     1,     6,     7,
       1,     9,    27,    27,    26,    31,    10,    26,     1,    27,
       1,    27,     1,    28,     1,    28,    31,     1,    31,    12,
      10,    10,     1,     1,     1,    10,    10,     1,    10,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    23,    24,    24,    25,    25,    26,    26,    26,    26,
      26,    26,    26,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    28,    28,    28,    28,    28,    28,    28,    28,
      29,    29,    29,    29,    29,    29,    30,    30,    30,    30,
      30,    30,    31,    31
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     3,     3,     1,     4,
       3,     3,     2,     3,     3,     1,     4,     4,     3,     3,
       3,     3,     3,     2,     2,     1,     1,     1,     2,     2,
       4,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     3,     1
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
#line 105 "parser.y" /* yacc.c:1646  */
    {printf("%2d - Input: ", line_nb++);}
#line 1389 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "parser.y" /* yacc.c:1646  */
    {
                fprintf(output_file, "%2d - The Intermidiate Representation of the input is:\n", line_nb++);
                displayTuples(tlist);
                tlist = createTupleList();
                temp = 300;
                printf("\n\n");
                fprintf(stdout, "%2d - Input: ", line_nb++);
         }
#line 1402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 117 "parser.y" /* yacc.c:1646  */
    {(yyval.n) = STOP;}
#line 1408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 120 "parser.y" /* yacc.c:1646  */
    {   
                    struct entry* entry = createEntry('+', (yyvsp[-2].n), (yyvsp[0].n), temp++);                 
                    addEntry(tlist, entry);
 		    (yyval.n) = temp - 1; 

                                 
                }
#line 1420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 127 "parser.y" /* yacc.c:1646  */
    {   (yyval.n) = temp; 
                    struct entry* entry = createEntry('-', (yyvsp[-2].n), (yyvsp[0].n), temp++);
                    addEntry(tlist, entry);
                }
#line 1429 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 134 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing operand."); }
#line 1435 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing operand.");}
#line 1441 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 136 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing operand.");}
#line 1447 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 137 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing operator."); }
#line 1453 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 140 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.n) = temp; 
                    
                    struct entry* entry = createEntry('*', (yyvsp[-2].n), (yyvsp[0].n), temp++ );
                    addEntry(tlist, entry);
                    
              }
#line 1465 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 147 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.n) = temp; 
                    struct entry* entry = createEntry('/', (yyvsp[-2].n), (yyvsp[0].n), temp++);
                    addEntry(tlist, entry);
              }
#line 1475 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 152 "parser.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);}
#line 1481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 154 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing operand."); }
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 155 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing operand."); }
#line 1493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 156 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing operand."); }
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 157 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing operand."); }
#line 1505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 158 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing operand."); }
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 159 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing operand."); }
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[-1].n); }
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 163 "parser.y" /* yacc.c:1646  */
    {
			
				struct entry* entry = createEntry('I', (yyvsp[0].n), '_', temp++);
                    		addEntry(tlist, entry);
				(yyval.n) = temp - 1;
			 }
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 169 "parser.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n); }
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 170 "parser.y" /* yacc.c:1646  */
    {(yyval.n) = yylval.d;}
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.n) = (yyvsp[0].n);}
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.n) = yylval.c;}
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 174 "parser.y" /* yacc.c:1646  */
    { yyerror("Unbalanced number of parentheses.");  }
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 175 "parser.y" /* yacc.c:1646  */
    { yyerror("Unbalanced number of parentheses.");  }
#line 1570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.n) = produce_function((yyvsp[-3].n), (yyvsp[-1].ll));}
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.n) = produce_sqrt((int)(yyvsp[-1].n));}
#line 1582 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 182 "parser.y" /* yacc.c:1646  */
    { yyerror("Unbalanced number of parentheses.");}
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 183 "parser.y" /* yacc.c:1646  */
    { yyerror("Unbalanced number of parentheses.");}
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 184 "parser.y" /* yacc.c:1646  */
    { yyerror("Missing separator.");}
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 185 "parser.y" /* yacc.c:1646  */
    { yyerror("Function does not exist.");}
#line 1606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.n) = SUM; }
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.n) = MEAN;}
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.n) = VAR;}
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.n) = MIN;}
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.n) = MAX;}
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.n) = DEVIATION;}
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.ll) = addItemInFront((yyvsp[-2].n), (yyvsp[0].ll));}
#line 1648 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 196 "parser.y" /* yacc.c:1646  */
    {  (yyval.ll) = createLinkedList((yyvsp[0].n)); }
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1658 "parser.tab.c" /* yacc.c:1646  */
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
#line 198 "parser.y" /* yacc.c:1906  */


void yyerror(char* s) 
{ 
    if(strcmp(s, "syntax error"))
    { 
        printf("%d - Syntax Error: %s\n", line_nb++,s);
        yyclearin; /* discard lookahead */
        
        //printf("%2d - Input: ", line_nb++);
    }   
};
/*
double compute(int f_name, struct LinkedList *list)
{   
    struct item* itm = (struct item *)list->first;

    switch(f_name)
    {
        case SUM     : return sum(itm);
        case MEAN    : return mean(itm);
        case VAR     : return var(itm);
        case PRODUCT : return product(itm);
    }
}
*/
int produce_function(int f_name, struct LinkedList *list)
{   
    struct item* itm = (struct item *)list->first;

    switch(f_name)
    {
      case MEAN    : return produce_mean(itm);
      case SUM	   : return produce_sum(itm);
      case VAR     : return produce_var(itm);
      case MIN     : return produce_min(itm);
      case MAX     : return produce_max(itm);
      case DEVIATION : return produce_deviation(itm);
    }
}

/*
double sum(struct item *itm)
{
    double result = 0;
    while(itm != NULL) {result += itm->value; itm = itm->next;}
    return result;
}
double product(struct item * itm)
{
    double result = 1;
    while(itm != NULL) {result *= itm->value; itm = itm->next;}
    return result;
}
double mean(struct item * itm)
{
    double result = 0;
    int count = 0;

    while(itm != NULL) {result += itm->value; count++; itm = itm->next;}
    return result /= count;
}

double var(struct item * itm)
{
    double inter1 = 0;
    double inter2 = 0; 
    int count = 0;

    while(itm != NULL)
    {
        inter1 += itm->value; 
        inter2 += (itm->value) * (itm->value);
        count++;
        itm = itm->next;
    }
    inter1 /= count;
    inter1 *= inter1;
    inter2 /= count;
    return inter2 - inter1;
}
*/
int produce_mean(struct item * itm)
{

    struct entry* entry = NULL;
    temp ++;
    temp ++;
        
    entry = createEntry('M', '0', '_', temp - 2);
    addEntry(tlist, entry);

    entry = createEntry('M',  '0', '_', temp - 1);  
    addEntry(tlist, entry);
    while(itm != NULL) { 
        
          entry = createEntry('+', itm->value, temp - 1, temp - 1);
          addEntry(tlist, entry);

          entry = createEntry('+',  temp - 2, '1', temp - 2);  
          addEntry(tlist, entry);
          itm = itm->next;
          
         
    }
   
      entry = createEntry('/', temp - 2, temp - 1, temp - 2);      
      addEntry(tlist, entry);   
    return temp - 2;
}

int produce_sum(struct item * itm)
{

    struct entry* entry = NULL;
    temp ++;
    entry = createEntry('M', '0', '_', temp - 1);
    addEntry(tlist, entry);
    while(itm != NULL) { 
        
          entry = createEntry('+', itm->value, temp - 1, temp - 1);
          addEntry(tlist, entry);

          itm = itm->next;
          
         
    }
    return temp - 1;
}

int produce_var(struct item * itm)
{

    struct entry* entry = NULL;
    temp ++;
    temp ++;
    temp ++;
    temp++;
           
    entry = createEntry('M', '0', '_', temp - 4);
    addEntry(tlist, entry);           
    entry = createEntry('M', '0', '_', temp - 3);
    addEntry(tlist, entry);   
    entry = createEntry('M', '0', '_', temp - 2);
    addEntry(tlist, entry);
    entry = createEntry('M',  '0', '_', temp - 1);  
    addEntry(tlist, entry);

    while(itm != NULL) { 
       
          entry = createEntry('*', itm->value, itm->value, temp - 4);
          addEntry(tlist, entry);

          entry = createEntry('+',  temp - 3, temp - 4, temp - 3);  
          addEntry(tlist, entry);

          entry = createEntry('+',  temp - 2, itm->value, temp - 2);  
          addEntry(tlist, entry);
          
  	  entry = createEntry('+',  temp - 1, '1', temp-1);  
          addEntry(tlist, entry);
          itm = itm->next;
          
          
         
    }
   
      entry = createEntry('*', temp - 2, temp - 2, temp - 2);      
      addEntry(tlist, entry);   
      entry = createEntry('/', temp - 2, temp - 1, temp - 2);      
      addEntry(tlist, entry); 
      entry = createEntry('/', temp - 3, temp - 1, temp - 3);      
      addEntry(tlist, entry); 
      entry = createEntry('-', temp - 3, temp - 2, temp - 2);      
      addEntry(tlist, entry);     
    return temp - 2;
}


int produce_sqrt(int number)
{	
    struct entry* entry = NULL;

    // will need 3 temps to compute to sqrt of 'number'. Will use the Heron algorithm, in fact we get quickly a very good apporoximation of 	  sqrt.
    temp++;
    temp++;
    temp++;
    // intialize Un and Un+1 represented respectively by (temp-3) and (temp-2) 
    entry = createEntry('M', '1', '_', temp - 3);
    addEntry(tlist, entry);
    entry = createEntry('M', '1', '_', temp - 2);
    addEntry(tlist, entry);
    entry = createEntry('M', '1', '_', temp - 1);
    addEntry(tlist, entry);
    entry = createEntry('C', temp - 1, '6', '_');
    addEntry(tlist, entry);
          entry = createEntry('G',  '_', '_', address + 7);  
    addEntry(tlist, entry);
    
    	
	entry = createEntry('/', number, temp - 3, temp - 2);
    	addEntry(tlist, entry);
    	entry = createEntry('+', temp - 3, temp - 2, temp - 2);
    	addEntry(tlist, entry);	
    	entry = createEntry('/', temp - 2, '2', temp - 2);
    	addEntry(tlist, entry);	
    	entry = createEntry('M', temp - 2, '_', temp - 3);
	addEntry(tlist, entry);
	entry = createEntry('+', temp - 1, '1', temp - 1);
	addEntry(tlist, entry);
          entry = createEntry('J',  '_', '_', address -7);  
	addEntry(tlist, entry);
    	
    return temp - 3;
}


int produce_min(struct item * itm)
{
    struct entry* entry = NULL;
    temp++;
           
    if(itm)
    {
	entry = createEntry('M',  itm->value, '_', temp - 1);  
    	addEntry(tlist, entry);
        itm = itm->next;
    } 


    while(itm != NULL) { 
       
          entry = createEntry('C', temp - 1, itm->value, '_');
          addEntry(tlist, entry);

          entry = createEntry('L',  '_', '_', address + 2);  
          addEntry(tlist, entry);

          entry = createEntry('M',  itm->value,  '_', temp - 1);  
          addEntry(tlist, entry);

          itm = itm->next;
          
          
         
    }
       
    return temp - 1;
}

int produce_max(struct item * itm)
{
    struct entry* entry = NULL;
    temp++;
           
    if(itm)
    {
	entry = createEntry('M',  itm->value, '_', temp - 1);  
    	addEntry(tlist, entry);
        itm = itm->next;
    } 


    while(itm != NULL) { 
       
          entry = createEntry('C', temp - 1, itm->value, '_');
          addEntry(tlist, entry);

          entry = createEntry('G',  '_', '_', address + 2);  
          addEntry(tlist, entry);

          entry = createEntry('M',  itm->value,  '_', temp - 1);  
          addEntry(tlist, entry);

          itm = itm->next;
          
          
         
    }
       
    return temp - 1;
}
int produce_deviation(struct item * itm)
{
  return produce_sqrt(produce_var(itm));   
		
}



struct LinkedList* createLinkedList(int val)
{

    struct LinkedList* ll = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    struct item* itm = malloc(sizeof(struct item));
    itm->value = val;
    itm->next = NULL;
    ll->first = itm;
    ll->last = itm;
    return ll;
}


struct LinkedList* addItemInFront(int val, struct LinkedList *ll)
{

    struct item* itm = (struct item *)  malloc(sizeof(struct item));
    itm->value = val;
    itm->next = ll->first;
    
    ll->first = itm;
    return ll;

}
int ll_len(struct item* itm)
{
 int count = 0;

 while(itm != NULL)
 {
 	count++;
	itm = itm->next;
 }
 return count;
}

struct tupleList* createTupleList()
{
    struct tupleList* tlist = (struct tupleList*)malloc(sizeof(struct tupleList));
    tlist->first = NULL;
    tlist->last =NULL;
    return tlist;
}
struct entry* createEntry(int op, int first_arg, int second_arg, int target)
{
    struct entry* itm = (struct entry*)malloc(sizeof(struct entry));
    itm->content = (struct tuple4*) malloc(sizeof(struct tuple4));
    (itm->content)->op         = op;
    (itm->content)->first_arg  = first_arg;
    (itm->content)->second_arg = second_arg;
    (itm->content)->target     = target;
    itm->next = NULL;
    
    return itm;
}
void addEntry(struct tupleList* list, struct entry *itm)
{
     if(list->first == NULL)
     {
         list->first = itm;
         list->last = itm;
     } else
     {
         (list->last)->next = itm;
         list->last = itm;
     }
     address++;
}

void displayTuples(struct tupleList *tlist)
{

    int local_address = 0;
    struct entry* itm = NULL;
    struct tuple4* tuple = (struct tuple4*) malloc(sizeof(struct tuple4));
    itm = tlist->first;
    


    while(itm)
    {
        
        tuple = itm->content;
        fprintf(output_file,"\n");
        fprintf(output_file, "\t------------------------------------");
        fprintf(output_file, "\n\t%2d : %c ", local_address++,tuple->op);
        if(tuple->first_arg < 300)
        {
   	   fprintf(output_file, "%7c ", tuple->first_arg);

        } else 
        {
            fprintf(output_file, "   tmp%d ", tuple->first_arg%300);
        }

         if(tuple->second_arg < 300)
        {
            fprintf(output_file, "%7c ", tuple->second_arg);
        } else 
        {
            fprintf(output_file, "    tmp%d ", tuple->second_arg%300);
        }

         if(tuple->target < 300)
        {
           if(tuple->op != 'J' && tuple->op != 'G' && tuple->op != 'L' && tuple->op != 'Z')
	   {
 	     fprintf(output_file, "%7c ",tuple->target);
	   }else 
	   {
             fprintf(output_file, "%7d ", tuple->target%300);
	   }
        } else 
        {
            fprintf(output_file, "    tmp%d ", tuple->target%300);
            
        }
        itm = itm->next;
    }
    address = 0;
    if(output_file != stdout)
    {
	    fclose(output_file);
    }	
}


int main(void)
{
    output_file = stdout;//fopen(path, "w");   
    tlist = createTupleList();
    printf("%2d - Input: ", line_nb++);
    yyparse();
    return 0;
}
