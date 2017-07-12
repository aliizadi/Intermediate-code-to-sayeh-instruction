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
#line 1 "grammer.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=1; //count for number of temporary variables
char* code[1000];
int next_inst=1;
char fill_label[10];
char* case_inst[20][2];  // used in switch case 
int no_of_cases=0;       // no of cases in switch case
int no_of_defaults=0;       // no of defaults in switch case , error if more than 1
char* identifiers[100];
int no_of_identifiers=0;

struct list
{
	int inst_no;
	struct list *next;
};


struct list * makelist(int next_inst);
struct list * merge(struct list * l1,struct list * l2);
void backpatch(struct list* l,int target_inst);
char* new_temp();
void print_code();
void declare(char* id);
int isdeclared(char* id);


#line 97 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    MUL_ASSIGN = 258,
    DIV_ASSIGN = 259,
    PLUS_ASSIGN = 260,
    MINUS_ASSIGN = 261,
    LOGICAL_OR = 262,
    LOGICAL_AND = 263,
    EQUAL = 264,
    NOT_EQUAL = 265,
    GREATER_OR_EQUAL = 266,
    LESS_OR_EQUAL = 267,
    UMINUS = 268,
    IDENTIFER = 269,
    INTEGER = 270,
    IDENTIFIER = 271,
    WHILE = 272,
    IF = 273,
    ELSE = 274,
    TRUE = 275,
    FALSE = 276,
    MAIN = 277,
    SWITCH = 278,
    CASE = 279,
    DEFAULT = 280,
    BREAK = 281,
    INT = 282
  };
#endif
/* Tokens.  */
#define MUL_ASSIGN 258
#define DIV_ASSIGN 259
#define PLUS_ASSIGN 260
#define MINUS_ASSIGN 261
#define LOGICAL_OR 262
#define LOGICAL_AND 263
#define EQUAL 264
#define NOT_EQUAL 265
#define GREATER_OR_EQUAL 266
#define LESS_OR_EQUAL 267
#define UMINUS 268
#define IDENTIFER 269
#define INTEGER 270
#define IDENTIFIER 271
#define WHILE 272
#define IF 273
#define ELSE 274
#define TRUE 275
#define FALSE 276
#define MAIN 277
#define SWITCH 278
#define CASE 279
#define DEFAULT 280
#define BREAK 281
#define INT 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "grammer.y" /* yacc.c:355  */

	union 
	{
	
		int inst;
		char* addr;
		struct list* nextlist;	
		struct
		{
			struct list* truelist;
			struct list* falselist;
		};
	}
	info;

#line 207 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   344

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,     2,     2,    24,    13,     2,
      29,    30,    22,    20,     3,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    47,
      18,     8,    16,     2,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    12,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    11,    46,    26,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,     9,    10,    14,    15,    17,    19,    27,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    82,    88,    97,   113,   146,   151,   156,
     161,   169,   178,   183,   189,   194,   199,   210,   228,   239,
     246,   254,   261,   268,   274,   280,   297,   316,   335,   351,
     368,   386,   396,   409,   415,   425,   438,   449,   460,   472,
     487,   496,   505,   514,   524,   535,   544,   554,   564,   574,
     580,   589,   598,   603
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "','", "MUL_ASSIGN", "DIV_ASSIGN",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "'='", "LOGICAL_OR", "LOGICAL_AND", "'|'",
  "'^'", "'&'", "EQUAL", "NOT_EQUAL", "'>'", "GREATER_OR_EQUAL", "'<'",
  "LESS_OR_EQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'",
  "UMINUS", "'@'", "'('", "')'", "IDENTIFER", "INTEGER", "IDENTIFIER",
  "WHILE", "IF", "ELSE", "TRUE", "FALSE", "MAIN", "SWITCH", "CASE",
  "DEFAULT", "BREAK", "INT", "'{'", "'}'", "';'", "':'", "$accept",
  "start", "S", "list", "cases", "L", "B", "M", "N", "assignment", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    44,   258,   259,   260,   261,    61,   262,
     263,   124,    94,    38,   264,   265,    62,   266,    60,   267,
      43,    45,    42,    47,    37,    33,   126,   268,    64,    40,
      41,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   123,   125,    59,    58
};
# endif

#define YYPACT_NINF -55

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -37,   120,     7,   139,   -55,   -21,    -8,   -27,    -6,   290,
     -55,   -55,   -55,   311,   311,   311,   311,   311,    -1,   277,
     311,   -55,    26,    -2,   -55,   -55,     0,   -55,   311,   311,
     311,   -55,   -55,   128,   146,   160,   174,   188,   277,   277,
     277,   -55,   -55,     5,   259,   202,   311,     6,   -55,   -55,
     120,    12,    12,   239,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   -55,   -55,   -55,   -55,   -55,     8,   -55,
      13,   225,   -55,   -55,   -55,   311,   311,   311,   311,   311,
     311,   -55,   273,    36,   -55,   -55,    74,   298,     9,    85,
      85,    12,    12,    12,    12,   -55,   -55,   277,   277,   120,
     273,   273,   273,   273,   273,   273,     2,   311,   120,    38,
     -55,    23,    19,   273,   -55,   -55,   311,    87,   -55,    57,
     311,     1,   -55,   120,   -55,   114,   -55,   -55,   -55,   120,
     -55,   120,   -55,   120,   -55,   -55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    33,     0,     0,     0,     0,     0,
      33,     9,     1,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    13,     0,     8,    20,    33,     2,     0,     0,
       0,    52,    53,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,    11,     7,
       0,    51,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,    36,    37,    35,     0,    23,
       0,     0,    33,    33,    33,     0,     0,     0,     0,     0,
       0,    34,    15,    12,    19,    49,    48,    47,    46,    40,
      41,    42,    43,    44,    45,    33,    24,     0,     0,     0,
      25,    26,    30,    27,    29,    28,     0,     0,     0,    21,
      22,     3,     0,    14,     5,    34,     0,     0,    33,     0,
       0,     0,    33,     0,    33,     0,    33,     6,     4,     0,
      33,     0,    18,     0,    17,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,    -9,   -55,   -55,   -55,   -34,    -7,   -54,   -55,
      -4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    10,    23,   117,    26,    43,    18,   106,    11,
      44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    47,     1,    27,    68,    69,    70,    12,    19,    33,
      34,    35,    36,    37,    72,    73,    45,    72,    73,    50,
      21,    20,    72,    73,    51,    52,    53,    22,    38,    57,
      58,    59,    60,    61,    46,    74,    71,    62,    95,    83,
      62,    84,    82,    96,   107,    48,    49,   112,    73,   126,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   115,
     116,   118,     0,   109,   110,    97,    98,    99,    54,    55,
      56,   100,   101,   102,   103,   104,   105,    57,    58,    59,
      60,    61,     0,     0,     0,    62,    55,    56,   108,     0,
     111,     0,     0,     0,    57,    58,    59,    60,    61,   114,
       0,     0,    62,   113,     0,   124,     0,    59,    60,    61,
       0,   123,   119,    62,   128,   127,   125,   129,     0,   131,
     132,     0,   134,   133,   135,    54,    55,    56,   120,   121,
       0,     0,     0,   122,    57,    58,    59,    60,    61,    54,
      55,    56,    62,    13,    14,    15,    16,    17,    57,    58,
      59,    60,    61,     3,     4,     5,    62,    54,    55,    56,
       6,     0,   130,     7,     8,     9,    57,    58,    59,    60,
      61,    54,    55,    56,    62,    63,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    54,    55,    56,    62,     0,
       0,     0,     0,    64,    57,    58,    59,    60,    61,    54,
      55,    56,    62,     0,     0,     0,     0,    65,    57,    58,
      59,    60,    61,    54,    55,    56,    62,     0,     0,     0,
       0,    66,    57,    58,    59,    60,    61,     0,     0,     0,
      62,     0,    81,     0,     0,    67,    54,    55,    56,    75,
      76,    77,    78,    79,    80,    57,    58,    59,    60,    61,
      54,    55,    56,    62,     0,    85,     0,     0,     0,    57,
      58,    59,    60,    61,     0,     0,     0,    62,     0,    85,
      54,    55,    56,    75,    76,    77,    78,    79,    80,    57,
      58,    59,    60,    61,    54,    55,    56,    62,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    28,     0,
       0,    62,    39,    29,     0,     0,    40,     0,     0,    31,
      32,    56,     0,     0,    41,    42,     0,     0,    57,    58,
      59,    60,    61,     3,     4,     5,    62,     0,     0,     0,
       6,     0,    28,     7,     8,     9,    24,    29,     0,     0,
      30,     0,     0,    31,    32
};

static const yytype_int16 yycheck[] =
{
       9,     3,    39,    10,    38,    39,    40,     0,    29,    13,
      14,    15,    16,    17,     9,    10,    20,     9,    10,    26,
      47,    29,     9,    10,    28,    29,    30,    33,    29,    20,
      21,    22,    23,    24,     8,    30,    40,    28,    30,    33,
      28,    50,    46,    30,     8,    47,    46,    45,    10,    48,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    36,
      41,   115,    -1,    97,    98,    72,    73,    74,    11,    12,
      13,    75,    76,    77,    78,    79,    80,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    12,    13,    95,    -1,
      99,    -1,    -1,    -1,    20,    21,    22,    23,    24,   108,
      -1,    -1,    28,   107,    -1,    48,    -1,    22,    23,    24,
      -1,   118,   116,    28,   123,   122,   120,   124,    -1,   126,
     129,    -1,   131,   130,   133,    11,    12,    13,    41,    42,
      -1,    -1,    -1,    46,    20,    21,    22,    23,    24,    11,
      12,    13,    28,     4,     5,     6,     7,     8,    20,    21,
      22,    23,    24,    33,    34,    35,    28,    11,    12,    13,
      40,    -1,    48,    43,    44,    45,    20,    21,    22,    23,
      24,    11,    12,    13,    28,    47,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    11,    12,    13,    28,    -1,
      -1,    -1,    -1,    47,    20,    21,    22,    23,    24,    11,
      12,    13,    28,    -1,    -1,    -1,    -1,    47,    20,    21,
      22,    23,    24,    11,    12,    13,    28,    -1,    -1,    -1,
      -1,    47,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      28,    -1,    30,    -1,    -1,    47,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      11,    12,    13,    28,    -1,    30,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    11,    12,    13,    28,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    21,    -1,
      -1,    28,    25,    26,    -1,    -1,    29,    -1,    -1,    32,
      33,    13,    -1,    -1,    37,    38,    -1,    -1,    20,    21,
      22,    23,    24,    33,    34,    35,    28,    -1,    -1,    -1,
      40,    -1,    21,    43,    44,    45,    46,    26,    -1,    -1,
      29,    -1,    -1,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    50,    33,    34,    35,    40,    43,    44,    45,
      51,    58,     0,     4,     5,     6,     7,     8,    56,    29,
      29,    47,    33,    52,    46,    51,    54,    56,    21,    26,
      29,    32,    33,    59,    59,    59,    59,    59,    29,    25,
      29,    37,    38,    55,    59,    59,     8,     3,    47,    46,
      56,    59,    59,    59,    11,    12,    13,    20,    21,    22,
      23,    24,    28,    47,    47,    47,    47,    47,    55,    55,
      55,    59,     9,    10,    30,    14,    15,    16,    17,    18,
      19,    30,    59,    33,    51,    30,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    30,    30,    56,    56,    56,
      59,    59,    59,    59,    59,    59,    57,     8,    56,    55,
      55,    51,    45,    59,    51,    36,    41,    53,    57,    59,
      41,    42,    46,    56,    48,    59,    48,    56,    51,    56,
      48,    56,    51,    56,    51,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     6,    10,     7,     9,     3,     2,     1,
       2,     3,     3,     1,     5,     3,     6,     5,     5,     3,
       1,     4,     4,     2,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     0,     0,     4,     4,     4,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1
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
#line 75 "grammer.y" /* yacc.c:1646  */
    {
				backpatch((yyvsp[-1].info).nextlist,(yyvsp[0].info).inst);
				print_code();
			}
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 83 "grammer.y" /* yacc.c:1646  */
    {
				backpatch((yyvsp[-3].info).truelist,(yyvsp[-1].info).inst);
				(yyval.info).nextlist=merge((yyvsp[-3].info).falselist,(yyvsp[0].info).nextlist);
			}
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "grammer.y" /* yacc.c:1646  */
    {
				backpatch((yyvsp[-7].info).truelist,(yyvsp[-5].info).inst);
				backpatch((yyvsp[-7].info).falselist,(yyvsp[-1].info).inst);
				struct list * temp = merge((yyvsp[-2].info).nextlist,(yyvsp[0].info).nextlist);
				(yyval.info).nextlist=merge(temp,(yyvsp[-4].info).nextlist);
			}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 98 "grammer.y" /* yacc.c:1646  */
    {
				backpatch((yyvsp[0].info).nextlist,(yyvsp[-5].info).inst);
				backpatch((yyvsp[-3].info).truelist,(yyvsp[-1].info).inst);
				
				(yyval.info).nextlist=(yyvsp[-3].info).falselist;
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
	
				sprintf(fill_label,"%d",(yyvsp[-5].info).inst);
				strcat(code[next_inst],fill_label);
				
				next_inst++;
			}
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 114 "grammer.y" /* yacc.c:1646  */
    {
			
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			
				backpatch((yyvsp[-4].info).nextlist,next_inst);
			
			
				int i;
				for(i=1;i<=no_of_cases;i++)
				{
					code[next_inst]=(char*)malloc(50);
					if(i!=no_of_cases||case_inst[i][0]!=NULL)
					sprintf(code[next_inst],"%s%s%s%s%s%s","if ",(yyvsp[-6].info).addr,"==",case_inst[i][0]," goto ",case_inst[i][1]);
					
					else
					sprintf(code[next_inst],"%s%s","goto ",case_inst[i][1]);
					
					next_inst++;
				}
				
				backpatch((yyvsp[-2].info).nextlist,next_inst);
	
				sprintf(fill_label,"%d",next_inst);
				strcat(code[(yyvsp[0].info).inst],fill_label);
				no_of_cases=0;
				no_of_defaults=0;
				(yyval.info).nextlist=NULL;
			}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 147 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).nextlist=(yyvsp[-1].info).nextlist;
			}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 152 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).nextlist=NULL;
			}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 157 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).nextlist=NULL;
			}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 162 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).nextlist=makelist(next_inst);
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 170 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).nextlist=NULL;
			}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 179 "grammer.y" /* yacc.c:1646  */
    {
			declare((yyvsp[0].info).addr);
			}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 184 "grammer.y" /* yacc.c:1646  */
    {
			declare((yyvsp[0].info).addr);
			}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 190 "grammer.y" /* yacc.c:1646  */
    {
			declare((yyvsp[-2].info).addr);
			}
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 195 "grammer.y" /* yacc.c:1646  */
    {
			declare((yyvsp[-2].info).addr);
		}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 200 "grammer.y" /* yacc.c:1646  */
    {
				no_of_cases++;
				case_inst[no_of_cases][0]=(yyvsp[-3].info).addr;
				sprintf(fill_label,"%d",(yyvsp[-1].info).inst);
				case_inst[no_of_cases][1]=(char*)malloc(5);
				strcpy(case_inst[no_of_cases][1],fill_label);
				(yyval.info).nextlist=merge((yyvsp[-5].info).nextlist,(yyvsp[0].info).nextlist);
	
			}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 211 "grammer.y" /* yacc.c:1646  */
    {
				no_of_cases++;
				no_of_defaults++;
				
				if(no_of_defaults==2)
				{
					printf("\nerror more than 1 defaults \n");
					exit(1);
				}
				
				case_inst[no_of_cases][0]=NULL;
				sprintf(fill_label,"%d",(yyvsp[-1].info).inst);
				case_inst[no_of_cases][1]=(char*)malloc(5);
				strcpy(case_inst[no_of_cases][1],fill_label);
				(yyval.info).nextlist=merge((yyvsp[-4].info).nextlist,(yyvsp[0].info).nextlist);
			}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 229 "grammer.y" /* yacc.c:1646  */
    {
				no_of_cases++;
				case_inst[no_of_cases][0]=(yyvsp[-3].info).addr;
				sprintf(fill_label,"%d",(yyvsp[-1].info).inst);
				case_inst[no_of_cases][1]=(char*)malloc(5);
				strcpy(case_inst[no_of_cases][1],fill_label);
				(yyval.info).nextlist=(yyvsp[0].info).nextlist;
			}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 240 "grammer.y" /* yacc.c:1646  */
    {	
				backpatch((yyvsp[-2].info).nextlist,(yyvsp[-1].info).inst);
				(yyval.info).nextlist=(yyvsp[0].info).nextlist;
				
			}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 247 "grammer.y" /* yacc.c:1646  */
    {	
				(yyval.info).nextlist=(yyvsp[0].info).nextlist;
				
			}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 255 "grammer.y" /* yacc.c:1646  */
    {
				backpatch((yyvsp[-3].info).falselist,(yyvsp[-1].info).inst);
				(yyval.info).truelist=merge((yyvsp[-3].info).truelist,(yyvsp[0].info).truelist);
				(yyval.info).falselist=(yyvsp[0].info).falselist;
			}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 262 "grammer.y" /* yacc.c:1646  */
    {
				backpatch((yyvsp[-3].info).truelist,(yyvsp[-1].info).inst);
				(yyval.info).falselist=merge((yyvsp[-3].info).falselist,(yyvsp[0].info).falselist);
				(yyval.info).truelist=(yyvsp[0].info).truelist;
			}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 269 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).truelist = (yyvsp[0].info).falselist;
				(yyval.info).falselist = (yyvsp[0].info).truelist;
			}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 275 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).truelist = (yyvsp[-1].info).truelist;
				(yyval.info).falselist = (yyvsp[-1].info).falselist;
			}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 281 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[-2].info).addr,"==",(yyvsp[0].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 298 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[-2].info).addr,"!=",(yyvsp[0].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 317 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[-2].info).addr,">=",(yyvsp[0].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 336 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[-2].info).addr,"<=",(yyvsp[0].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 352 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[-2].info).addr,"<",(yyvsp[0].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 369 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).truelist=makelist(next_inst);
				(yyval.info).falselist=makelist(next_inst+1);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%s%s%s%s","if ",(yyvsp[-2].info).addr,">",(yyvsp[0].info).addr," goto ");
				next_inst++;	
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;					
			}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 387 "grammer.y" /* yacc.c:1646  */
    {	
				(yyval.info).truelist=makelist(next_inst);
				code[next_inst]=(char*)malloc(50);
				

				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 397 "grammer.y" /* yacc.c:1646  */
    {	
				(yyval.info).falselist=makelist(next_inst);
				

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 409 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).inst=next_inst;
			}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 415 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).nextlist=makelist(next_inst);
				code[next_inst]=(char*)malloc(50);
				

				sprintf(code[next_inst],"%s","goto ");
				next_inst++;
			}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 426 "grammer.y" /* yacc.c:1646  */
    {
				if(!isdeclared((yyvsp[-3].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[-3].info).addr);
				}
				
				code[next_inst]=(char*)malloc(50);				

				sprintf(code[next_inst],"%s%c%s",(yyvsp[-3].info).addr,'=',(yyvsp[-1].info).addr);
				next_inst++;
			}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 439 "grammer.y" /* yacc.c:1646  */
    {
				if(!isdeclared((yyvsp[-3].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[-3].info).addr);
				}
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyvsp[-3].info).addr,'=',(yyvsp[-3].info).addr,'+',(yyvsp[-1].info).addr);
				next_inst++;
			}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 450 "grammer.y" /* yacc.c:1646  */
    {
				if(!isdeclared((yyvsp[-3].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[-3].info).addr);
				}
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyvsp[-3].info).addr,'=',(yyvsp[-3].info).addr,'-',(yyvsp[-1].info).addr);
				next_inst++;
			}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 461 "grammer.y" /* yacc.c:1646  */
    {
				if(!isdeclared((yyvsp[-3].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[-3].info).addr);
				}
				
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyvsp[-3].info).addr,'=',(yyvsp[-3].info).addr,'*',(yyvsp[-1].info).addr);
				next_inst++;
			}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 473 "grammer.y" /* yacc.c:1646  */
    {
				if(!isdeclared((yyvsp[-3].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[-3].info).addr);
				}
				
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyvsp[-3].info).addr,'=',(yyvsp[-3].info).addr,'/',(yyvsp[-1].info).addr);
				next_inst++;
			}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 488 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[-2].info).addr,'+',(yyvsp[0].info).addr);
				next_inst++;
			}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 497 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[-2].info).addr,'-',(yyvsp[0].info).addr);
				next_inst++;
			}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 506 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[-2].info).addr,'*',(yyvsp[0].info).addr);
				next_inst++;
			}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 515 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[-2].info).addr,'/',(yyvsp[0].info).addr);
				next_inst++;
			}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 525 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[-2].info).addr,'%',(yyvsp[0].info).addr);
				next_inst++;
			}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 536 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[-2].info).addr,'@',(yyvsp[0].info).addr);
				next_inst++;
			}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 545 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[-2].info).addr,'&',(yyvsp[0].info).addr);
				next_inst++;
			}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 555 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());

				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[-2].info).addr,'^',(yyvsp[0].info).addr);
				next_inst++;
			}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 565 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%s%c%s",(yyval.info).addr,'=',(yyvsp[-2].info).addr,'|',(yyvsp[0].info).addr);
				next_inst++;
			}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 575 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,(yyvsp[-1].info).addr);
			}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 581 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%c%s",(yyval.info).addr,'=','~',(yyvsp[0].info).addr);
				next_inst++;
			}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 590 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,new_temp());
				code[next_inst]=(char*)malloc(50);
				sprintf(code[next_inst],"%s%c%c%s",(yyval.info).addr,'=','-',(yyvsp[0].info).addr);
				next_inst++;
			}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 599 "grammer.y" /* yacc.c:1646  */
    {
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,(yyvsp[0].info).addr);
			}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 604 "grammer.y" /* yacc.c:1646  */
    {
				if(!isdeclared((yyvsp[0].info).addr))
				{
					printf("\n%s not declared\n",(yyvsp[0].info).addr);
				}
				
				(yyval.info).addr=malloc(5);
				strcpy((yyval.info).addr,(yyvsp[0].info).addr);
			}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2092 "y.tab.c" /* yacc.c:1646  */
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
#line 615 "grammer.y" /* yacc.c:1906  */

#include "lex.yy.c"

int main(int argc,char** argv)
{
	if(argc==2)
	yyin=fopen(argv[1],"r");

	else
	yyin=fopen("input.cpp","r");
	
	yyparse();
	
}

struct list * makelist(int next_inst)
{
	struct list * new=malloc(sizeof(struct list));
	new->inst_no=next_inst;
	new->next=NULL;
	return new;
}

struct list * merge(struct list * l1,struct list * l2)
{
	if(l1!=NULL)
	{
		struct list * new=l1;
		while(l1->next!=NULL)
		l1=l1->next;
		l1->next=l2;
		return new;
	}
	
	else return l2; 

}

void backpatch(struct list* l,int target_inst)
{
	while(l!=NULL)
	{
		sprintf(fill_label,"%d",target_inst);
		strcat(code[l->inst_no],fill_label);
		l=l->next;
	}
}

char* new_temp()
{
	char *temp;
	temp=malloc(5);
	sprintf(temp,"%c%d",'t',count++);
	return temp;
}


void print_code()
{
	printf("\nFinal intermediate code is --- \n");
	int i;
	for(i=1;i<next_inst;i++)
	{
		if(i<100) printf(" ");
		if(i<10) printf(" ");
		printf("%d : %s\n",i,code[i]);
	}
}


void declare(char* id)
{
	identifiers[no_of_identifiers++]=id;
}

int isdeclared(char* id)
{
	int i;
	
	for(i=0;i<no_of_identifiers;i++)
	if(strcmp(identifiers[i],id)==0)
	return 1;
	
	return 0;
	
}
