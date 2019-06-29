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
#line 1 "s8t1.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "s8t1.h"
#include "s8t1.c"
FILE *yyin,*fp;
#define YYSTYPE tnode*
int yylex();

#line 77 "y.tab.c" /* yacc.c:339  */

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
    NUM = 258,
    ID = 259,
    BEG = 260,
    END = 261,
    READ = 262,
    WRITE = 263,
    IF = 264,
    THEN = 265,
    ELSE = 266,
    ENDIF = 267,
    WHILE = 268,
    DO = 269,
    ENDWHILE = 270,
    L = 271,
    G = 272,
    LE = 273,
    GE = 274,
    NE = 275,
    EE = 276,
    REPEAT = 277,
    UNTIL = 278,
    BREAK = 279,
    CONTINUE = 280,
    DECL = 281,
    ENDDECL = 282,
    INT = 283,
    STR = 284,
    STRVAL = 285,
    MAIN = 286,
    RETURN = 287,
    TYPE = 288,
    ENDTYPE = 289,
    NUL = 290,
    ALLOC = 291,
    DEALLOC = 292,
    BOOLEAN = 293,
    VOID = 294,
    INIT = 295,
    CLASS = 296,
    ENDCLASS = 297,
    SELF = 298,
    NEW = 299,
    DELETE = 300,
    EXTENDS = 301
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define BEG 260
#define END 261
#define READ 262
#define WRITE 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDWHILE 270
#define L 271
#define G 272
#define LE 273
#define GE 274
#define NE 275
#define EE 276
#define REPEAT 277
#define UNTIL 278
#define BREAK 279
#define CONTINUE 280
#define DECL 281
#define ENDDECL 282
#define INT 283
#define STR 284
#define STRVAL 285
#define MAIN 286
#define RETURN 287
#define TYPE 288
#define ENDTYPE 289
#define NUL 290
#define ALLOC 291
#define DEALLOC 292
#define BOOLEAN 293
#define VOID 294
#define INIT 295
#define CLASS 296
#define ENDCLASS 297
#define SELF 298
#define NEW 299
#define DELETE 300
#define EXTENDS 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 220 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   567

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  297

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    51,     2,     2,
      56,    57,    49,    47,    59,    48,    58,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
       2,    52,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    19,    19,    20,    21,    24,    25,    27,    28,    30,
      32,    33,    39,    40,    42,    43,    45,    46,    50,    51,
      53,    54,    57,    58,    61,   101,   108,   144,   222,   266,
     287,   337,   376,   376,   377,   377,   378,   382,   386,   386,
     387,   389,   390,   393,   393,   394,   394,   395,   396,   396,
     397,   398,   399,   401,   402,   403,   407,   408,   409,   411,
     411,   412,   441,   509,   509,   509,   510,   514,   515,   517,
     517,   518,   519,   525,   533,   550,   578,   584,   588,   610,
     616,   618,   619,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   633,   636,   639,   642,   698,   712,   713,
     715,   718,   721,   726,   727,   728,   729,   730,   731,   732,
     736,   740,   741,   742,   743,   744,   745,   746,   747,   748,
     749,   751,   768,   770,   773,   775,   778,   810,   834
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "BEG", "END", "READ",
  "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "L",
  "G", "LE", "GE", "NE", "EE", "REPEAT", "UNTIL", "BREAK", "CONTINUE",
  "DECL", "ENDDECL", "INT", "STR", "STRVAL", "MAIN", "RETURN", "TYPE",
  "ENDTYPE", "NUL", "ALLOC", "DEALLOC", "BOOLEAN", "VOID", "INIT", "CLASS",
  "ENDCLASS", "SELF", "NEW", "DELETE", "EXTENDS", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'='", "'{'", "'}'", "';'", "'('", "')'", "'.'", "','",
  "'['", "']'", "$accept", "Program", "ClassDefBlock", "ClassDefList",
  "ClassDef", "Cname", "Fieldlists", "FId", "Typef", "MethodDecl", "MDecl",
  "MethodDefns", "Stmt", "FieldFunction", "TDeclBlock", "TDeclList", "TId",
  "TDecl", "TDe", "TDec", "Tidlist", "GDeclBlock", "GDeclList", "GDecl",
  "GidList", "Gid", "Type", "PType", "FDefBlock", "FDef", "Fdef",
  "ParamList", "Param", "LdeclBlock", "LDecList", "LDecl", "IdList",
  "expr", "ArgList", "MainBlock", "Body", "Slist", "InputStmt",
  "OutputStmt", "AsgStmt", "IfStmt", "DoWhile", "RepUntil", "WhileStmt",
  "E", "arr_expr", "Field", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,    43,    45,    42,
      47,    37,    61,   123,   125,    59,    40,    41,    46,    44,
      91,    93
};
# endif

#define YYPACT_NINF -151

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-151)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,     8,    29,    -7,   -14,  -151,    11,    89,  -151,  -151,
      88,    87,  -151,  -151,  -151,  -151,  -151,  -151,     4,  -151,
      93,    31,    19,  -151,    80,    92,   109,   145,  -151,  -151,
    -151,  -151,   -11,   144,  -151,  -151,   132,  -151,    96,  -151,
     178,   141,   109,   203,   145,  -151,   164,  -151,  -151,   221,
    -151,  -151,  -151,  -151,    15,    44,  -151,   131,   177,  -151,
    -151,   210,  -151,   156,   231,   237,  -151,   178,   195,   231,
     108,   239,   248,  -151,  -151,  -151,   253,   135,  -151,  -151,
    -151,  -151,   258,   -39,  -151,   215,  -151,   210,    73,  -151,
     276,   187,  -151,   282,   230,    -1,    27,   289,    89,   293,
    -151,  -151,  -151,   231,  -151,   239,  -151,  -151,    72,  -151,
    -151,   101,  -151,   249,   259,   260,   261,   482,   482,   243,
     265,   191,   268,   277,   278,   250,   281,  -151,   322,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,   269,   274,  -151,  -151,
     231,  -151,   231,   287,    18,  -151,   299,  -151,   306,  -151,
     341,   352,   191,    55,   191,   191,   191,   522,   362,  -151,
    -151,  -151,   205,  -151,   303,   191,  -151,   302,  -151,   305,
     307,   191,   311,   368,     9,  -151,  -151,   168,   369,   143,
     163,  -151,  -151,  -151,  -151,  -151,   262,   317,   291,   252,
     320,   326,   339,   340,    13,   396,   397,   331,   191,   191,
     191,   191,   191,  -151,   399,  -151,   371,  -151,  -151,   346,
      47,   353,   356,   342,  -151,   358,   359,  -151,   370,   380,
     191,   191,   191,   191,   183,   202,   413,   422,   191,   191,
    -151,   382,   184,   381,   384,  -151,   126,   126,  -151,  -151,
    -151,   385,   388,   389,  -151,   444,  -151,  -151,  -151,  -151,
    -151,   382,   382,   382,   382,  -151,   382,  -151,   382,   482,
     482,   395,   400,  -151,   191,    86,    98,   153,  -151,  -151,
     401,   242,   402,    -5,   398,   382,  -151,   218,  -151,   224,
    -151,   235,   404,   482,   405,   406,  -151,  -151,  -151,  -151,
    -151,  -151,   442,  -151,  -151,   407,  -151
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,     0,    33,     0,     0,    35,     1,
       0,     0,    36,    32,    34,    55,    53,    54,     0,    39,
       0,    10,     0,     8,     0,     0,     0,     0,     4,    37,
      38,    42,     0,     0,     5,     7,     0,    44,     0,    46,
       0,     0,    53,     0,     0,    60,     0,     3,    40,     0,
      11,    13,    43,    45,    50,     0,    49,     0,     0,    59,
       2,     0,    41,     0,    65,     0,    47,     0,     0,    65,
       0,     0,     0,    16,    17,    12,     0,     0,    19,    58,
      56,    57,     0,     0,    64,     0,    48,     0,     0,    68,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
      18,    66,    52,     0,    51,     0,    62,    73,     0,    67,
      69,   121,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,    83,
      84,    85,    86,    88,    89,    87,     0,   125,    61,    15,
      65,    14,    65,     0,     0,    23,     0,    63,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,   117,   121,   118,     0,     0,   120,     0,   119,   125,
       0,     0,     0,     0,     0,    79,    81,     0,     0,     0,
       0,     9,    22,    78,    72,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,   123,     0,   124,   126,     0,
       0,     0,     0,     0,   127,     0,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    77,     0,   128,   126,   116,   111,   112,   113,   114,
     115,   127,     0,     0,    97,     0,    96,    21,    20,    94,
      95,   103,   104,   105,   106,   109,   107,   110,   108,     0,
       0,     0,     0,    75,     0,     0,     0,     0,    93,    25,
       0,     0,     0,     0,     0,    76,    30,     0,    29,     0,
      31,     0,     0,     0,     0,     0,   100,   101,    27,    26,
      28,    24,     0,    99,   102,     0,    98
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,  -151,  -151,   441,  -151,  -151,  -151,   391,  -151,
     392,  -151,  -127,  -151,  -151,  -151,  -151,   459,  -151,   452,
    -151,  -151,  -151,   433,  -151,   408,     3,  -151,  -151,   -30,
    -151,   -66,   373,   386,  -151,   390,  -151,  -114,   -37,    -8,
     367,  -113,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -150,
     -91,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,    22,    23,    24,    63,    75,    76,    77,
      78,   144,   127,   166,     3,     6,     7,     8,    18,    19,
      32,    27,    38,    39,    55,    56,    43,    82,    44,    45,
      46,    83,    84,    71,    91,    92,   108,   189,   232,    28,
      94,   128,   129,   130,   131,   132,   133,   134,   135,   190,
     168,   169
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     137,   176,   136,    88,   157,   158,   191,   167,    15,   260,
      20,     1,     4,   209,    59,     4,   161,   162,   102,    47,
     103,    20,    15,    21,   137,   137,   136,   136,    40,     9,
     176,   176,    16,    17,    10,   137,    60,   136,   186,    12,
     188,    40,     5,   163,    48,    13,    16,    17,    49,   122,
     286,   197,   125,   124,   139,   140,   164,   206,    29,   111,
     137,    34,   187,   213,   137,   137,   136,   136,   145,   165,
     230,    64,   181,    90,   179,    65,   180,    33,   261,   262,
     231,   210,   141,   142,   236,   237,   238,   239,   240,   161,
     162,   122,    21,    15,    90,   124,    15,    31,   125,    66,
      15,   161,   162,    67,   243,   178,   251,   252,   253,   254,
     256,   258,    15,    25,   182,    26,   163,    16,    17,    37,
      16,    17,   122,    52,    16,    17,   124,   149,   163,   164,
     106,   150,   103,    36,   122,    89,    16,    17,   124,    97,
      41,   164,   165,   276,   176,   176,   271,   272,    50,    15,
     275,   231,   231,   231,   165,   278,   161,   162,    51,   151,
      72,   152,    98,    73,    74,   176,   137,   137,   136,   136,
     292,   161,   162,    42,    17,   200,   201,   202,   137,   137,
     136,   136,    54,   163,    73,    74,   161,   162,    68,   122,
     137,    15,   136,   124,   161,   162,   164,    57,   163,   137,
     215,   136,   103,   211,   122,   161,   162,    58,   124,   165,
     280,   164,   212,   163,   109,    16,    17,    61,   255,   122,
     216,   163,   103,   124,   165,    62,   164,   122,   277,   279,
     281,   124,   163,    69,   164,    79,    70,   257,   122,   165,
      85,   263,   124,   264,    93,   164,   111,   165,    87,   113,
     114,   115,    95,   283,   284,   116,   117,    96,   165,    80,
      81,   194,   101,   195,   118,   152,   119,   120,   220,   221,
     222,   223,   224,   225,   121,   288,   104,   264,   122,   123,
     107,   289,   124,   264,   138,   125,   111,   126,   112,   113,
     114,   115,   290,   143,   264,   116,   117,   146,   159,   198,
     199,   200,   201,   202,   118,   153,   119,   120,   173,   198,
     199,   200,   201,   202,   121,   154,   155,   156,   122,   123,
     160,   177,   124,   217,   170,   125,   111,   126,   175,   113,
     114,   115,   178,   171,   172,   116,   117,   174,   198,   199,
     200,   201,   202,   140,   118,   184,   119,   120,   219,   198,
     199,   200,   201,   202,   121,   142,   185,   203,   122,   123,
     183,   196,   124,   204,   205,   125,   111,   126,   207,   113,
     114,   115,   208,   214,   218,   116,   117,   226,   198,   199,
     200,   201,   202,   227,   118,   193,   119,   120,   235,   198,
     199,   200,   201,   202,   121,   228,   229,   246,   122,   123,
     233,   234,   124,   241,   151,   125,   111,   126,   244,   113,
     114,   115,   245,   247,   248,   116,   117,   285,   198,   199,
     200,   201,   202,   259,   118,   249,   119,   120,   242,   198,
     199,   200,   201,   202,   121,   250,   260,   265,   122,   123,
     266,   267,   124,   268,   269,   125,   111,   126,   270,   113,
     114,   115,   273,   287,   295,   116,   117,   274,   282,   291,
     293,   294,   296,    35,   118,    14,   119,   120,    99,   100,
      30,    53,   148,   105,   121,    86,   147,     0,   122,   123,
       0,   110,   124,     0,     0,   125,   111,   126,     0,   113,
     114,   115,     0,     0,     0,   116,   117,     0,     0,     0,
       0,     0,     0,     0,   118,     0,   119,   120,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,   123,
       0,     0,   124,     0,     0,   125,   111,   126,     0,   113,
     114,   115,     0,     0,     0,   192,   117,     0,     0,     0,
       0,     0,     0,     0,   118,     0,   119,   120,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,   123,
       0,     0,   124,     0,     0,   125,     0,   126
};

static const yytype_int16 yycheck[] =
{
      93,   128,    93,    69,   117,   118,   156,   121,     4,    14,
       7,    33,     4,     4,    44,     4,     3,     4,    57,    27,
      59,    18,     4,     4,   117,   118,   117,   118,    25,     0,
     157,   158,    28,    29,    41,   128,    44,   128,   152,    53,
     154,    38,    34,    30,    55,    34,    28,    29,    59,    36,
      55,   165,    43,    40,    55,    56,    43,   171,    54,     4,
     153,    42,   153,   177,   157,   158,   157,   158,    98,    56,
      57,    56,    54,    70,   140,    60,   142,    46,   228,   229,
     194,   174,    55,    56,   198,   199,   200,   201,   202,     3,
       4,    36,     4,     4,    91,    40,     4,     4,    43,    55,
       4,     3,     4,    59,    57,    58,   220,   221,   222,   223,
     224,   225,     4,    26,   144,    28,    30,    28,    29,    27,
      28,    29,    36,    27,    28,    29,    40,    55,    30,    43,
      57,    59,    59,    53,    36,    27,    28,    29,    40,     4,
      31,    43,    56,    57,   271,   272,   259,   260,     4,     4,
     264,   265,   266,   267,    56,    57,     3,     4,    26,    58,
       4,    60,    27,    28,    29,   292,   259,   260,   259,   260,
     283,     3,     4,    28,    29,    49,    50,    51,   271,   272,
     271,   272,     4,    30,    28,    29,     3,     4,    57,    36,
     283,     4,   283,    40,     3,     4,    43,    56,    30,   292,
      57,   292,    59,    35,    36,     3,     4,     4,    40,    56,
      57,    43,    44,    30,    27,    28,    29,    53,    35,    36,
      57,    30,    59,    40,    56,     4,    43,    36,   265,   266,
     267,    40,    30,    56,    43,     4,    26,    35,    36,    56,
       3,    57,    40,    59,     5,    43,     4,    56,    53,     7,
       8,     9,     4,    11,    12,    13,    14,     4,    56,    28,
      29,    56,     4,    58,    22,    60,    24,    25,    16,    17,
      18,    19,    20,    21,    32,    57,    61,    59,    36,    37,
       4,    57,    40,    59,    54,    43,     4,    45,     6,     7,
       8,     9,    57,     4,    59,    13,    14,     4,    55,    47,
      48,    49,    50,    51,    22,    56,    24,    25,    58,    47,
      48,    49,    50,    51,    32,    56,    56,    56,    36,    37,
      55,    52,    40,    61,    56,    43,     4,    45,     6,     7,
       8,     9,    58,    56,    56,    13,    14,    56,    47,    48,
      49,    50,    51,    56,    22,     4,    24,    25,    57,    47,
      48,    49,    50,    51,    32,    56,     4,    55,    36,    37,
      54,    58,    40,    58,    57,    43,     4,    45,    57,     7,
       8,     9,     4,     4,    57,    13,    14,    57,    47,    48,
      49,    50,    51,    57,    22,    23,    24,    25,    57,    47,
      48,    49,    50,    51,    32,    56,    56,    55,    36,    37,
       4,     4,    40,     4,    58,    43,     4,    45,    55,     7,
       8,     9,    56,    55,    55,    13,    14,    15,    47,    48,
      49,    50,    51,    10,    22,    55,    24,    25,    57,    47,
      48,    49,    50,    51,    32,    55,    14,    56,    36,    37,
      56,    56,    40,    55,    55,    43,     4,    45,     4,     7,
       8,     9,    57,    55,    12,    13,    14,    57,    57,    55,
      55,    55,    55,    22,    22,     6,    24,    25,    77,    77,
      18,    38,   105,    87,    32,    67,   103,    -1,    36,    37,
      -1,    91,    40,    -1,    -1,    43,     4,    45,    -1,     7,
       8,     9,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,
      -1,    -1,    40,    -1,    -1,    43,     4,    45,    -1,     7,
       8,     9,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,
      -1,    -1,    40,    -1,    -1,    43,    -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    63,    76,     4,    34,    77,    78,    79,     0,
      41,    64,    53,    34,    79,     4,    28,    29,    80,    81,
      88,     4,    65,    66,    67,    26,    28,    83,   101,    54,
      81,     4,    82,    46,    42,    66,    53,    27,    84,    85,
      88,    31,    28,    88,    90,    91,    92,   101,    55,    59,
       4,    26,    27,    85,     4,    86,    87,    56,     4,    91,
     101,    53,     4,    68,    56,    60,    55,    59,    57,    56,
      26,    95,     4,    28,    29,    69,    70,    71,    72,     4,
      28,    29,    89,    93,    94,     3,    87,    53,    93,    27,
      88,    96,    97,     5,   102,     4,     4,     4,    27,    70,
      72,     4,    57,    59,    61,    95,    57,     4,    98,    27,
      97,     4,     6,     7,     8,     9,    13,    14,    22,    24,
      25,    32,    36,    37,    40,    43,    45,    74,   103,   104,
     105,   106,   107,   108,   109,   110,   112,   113,    54,    55,
      56,    55,    56,     4,    73,    91,     4,    94,   102,    55,
      59,    58,    60,    56,    56,    56,    56,   103,   103,    55,
      55,     3,     4,    30,    43,    56,    75,    99,   112,   113,
      56,    56,    56,    58,    56,     6,    74,    52,    58,    93,
      93,    54,    91,    54,     4,     4,    99,   112,    99,    99,
     111,   111,    13,    23,    56,    58,    58,    99,    47,    48,
      49,    50,    51,    55,    58,    57,    99,    57,     4,     4,
     113,    35,    44,    99,     4,    57,    57,    61,    57,    57,
      16,    17,    18,    19,    20,    21,    57,    57,    56,    56,
      57,    99,   100,     4,     4,    57,    99,    99,    99,    99,
      99,     4,    57,    57,    55,    56,    55,    55,    55,    55,
      55,    99,    99,    99,    99,    35,    99,    35,    99,    10,
      14,   111,   111,    57,    59,    56,    56,    56,    55,    55,
       4,   103,   103,    57,    57,    99,    57,   100,    57,   100,
      57,   100,    57,    11,    12,    15,    55,    55,    57,    57,
      57,    55,   103,    55,    55,    12,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    63,    64,    64,    65,    65,    66,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    75,    76,    76,    77,    77,    78,    79,    80,    80,
      81,    82,    82,    83,    83,    84,    84,    85,    86,    86,
      87,    87,    87,    88,    88,    88,    89,    89,    89,    90,
      90,    91,    92,    93,    93,    93,    94,    95,    95,    96,
      96,    97,    98,    98,    99,    99,   100,   100,   101,   102,
     102,   103,   103,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,   104,   105,   106,   106,   107,   107,
     108,   109,   110,   111,   111,   111,   111,   111,   111,   111,
     111,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,   112,   112,   112,   112,   112,   113,   113,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     2,     1,     8,
       1,     3,     2,     0,     3,     3,     1,     1,     2,     1,
       6,     6,     2,     1,     7,     5,     6,     6,     6,     5,
       5,     5,     3,     2,     2,     1,     2,     3,     2,     1,
       3,     3,     1,     3,     2,     2,     1,     3,     3,     1,
       1,     4,     4,     1,     1,     1,     1,     1,     1,     2,
       1,     5,     5,     3,     1,     0,     2,     3,     2,     2,
       1,     3,     3,     1,     3,     4,     3,     1,     8,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     5,     5,     5,     4,     4,    10,     8,
       7,     7,     8,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     4,     3,     3,     1,     3,     3,     3
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
#line 19 "s8t1.y" /* yacc.c:1646  */
    {print_gtab(head);printf("\n");print_ltab(l1);printf("\n");print_classtable(c1);exit(1);}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 20 "s8t1.y" /* yacc.c:1646  */
    {print_gtab(head);printf("\n");print_ltab(l1);printf("\n");print_classtable(c1);exit(1);}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 21 "s8t1.y" /* yacc.c:1646  */
    {/*print_ltab(l1);printf("\n");*/exit(1);}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 30 "s8t1.y" /* yacc.c:1646  */
    {Cptr->fieldcount=fc;Cptr->methodcount=mc;bind=bind+8;/*print_classtable(Cptr);*/}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 32 "s8t1.y" /* yacc.c:1646  */
    {Cptr=CInstall((yyvsp[0])->varname,NULL);fc=0;mc=0;}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 33 "s8t1.y" /* yacc.c:1646  */
    {Cptr=CInstall((yyvsp[-2])->varname,(yyvsp[0])->varname);
			int i;
			for(i=0;i<8;i++)
				mcheck[i]=0;
			}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 42 "s8t1.y" /* yacc.c:1646  */
    {Class_FInstall(Cptr,typ,(yyvsp[-1])->varname);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 43 "s8t1.y" /* yacc.c:1646  */
    {Class_FInstall(Cptr,(yyvsp[-2])->varname,(yyvsp[-1])->varname);}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 45 "s8t1.y" /* yacc.c:1646  */
    {char *ch="int";typ=strdup(ch);}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 46 "s8t1.y" /* yacc.c:1646  */
    {char *ch="str";typ=strdup(ch);}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 53 "s8t1.y" /* yacc.c:1646  */
    {++fl;Class_MInstall(Cptr,(yyvsp[-4])->varname,typ,h1);mc++;h1=NULL;}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 54 "s8t1.y" /* yacc.c:1646  */
    {++fl;Class_MInstall(Cptr,(yyvsp[-4])->varname,(yyvsp[-5])->varname,h1);mc++;h1=NULL;}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 61 "s8t1.y" /* yacc.c:1646  */
    {
					/*$1->Lentry=LLookup($1->varname);
					if($1->Lentry!=NULL)
						{
						$1->ctype=$1->Lentry->ctype;
						$1->type=$1->Lentry->type;
						}
					else
						{
						$1->Gentry=GLookup($1->varname);
						if($1->Gentry!=NULL)
							{
							$1->ctype=$1->Gentry->ctype;
							$1->type=$1->Gentry->type;
							}
						}
					*/
						//printf("siva %s %s siva\n",$1->ctype->name,$5->varname);
					if((yyvsp[-6])->ctype==NULL)
						{
						
						printf("Types %s %s not matched to create new\n",(yyvsp[-6])->ctype->name,(yyvsp[-2])->varname);
						exit(1); 
						}
					if(strcmp((yyvsp[-6])->ctype->name,(yyvsp[-2])->varname)!=0)
						{
						struct Classtable *cc1=CLookup((yyvsp[-2])->varname);
						
						while(cc1!=NULL && strcmp(cc1->name,(yyvsp[-6])->ctype->name)!=0)
							cc1=cc1->parentptr;
						if(cc1==NULL)
							{
							printf("Types %s %s not matched to create new\n",(yyvsp[-6])->ctype->name,(yyvsp[-2])->varname);
							exit(1);
							}
						}
					char *c="new",*c2="int",*c3="=";
					(yyvsp[-4])=makeOperatorNode(c,-1,29,TLookup(c2),(yyvsp[-2]),NULL,NULL);
					(yyval)=makeOperatorNode(c3,-1,36,NULL,(yyvsp[-6]),NULL,(yyvsp[-4]));
				    }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 101 "s8t1.y" /* yacc.c:1646  */
    {
					char *c="dealloc",*c2="int";
					(yyval)=makeOperatorNode(c,-1,30,TLookup(c2),(yyvsp[-2]),NULL,NULL);
				      }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 108 "s8t1.y" /* yacc.c:1646  */
    {
						char *c="self";
					   	(yyval)=makeOperatorNode(c,-1,33,NULL,(yyvsp[-3]),NULL,NULL);
			
						(yyvsp[-3])->left=(yyvsp[-1]);
						//$$->type=$3->type;
						
						struct Memberfunclist *temp=Class_MLookup(Cptr,(yyvsp[-3])->varname);
						if(temp==NULL)
							{
							printf("Method %s not declared in class %s\n",(yyvsp[-3])->varname,Cptr->name);
							exit(1);
							}
						(yyval)->type=temp->type;					    
						struct Paramstruct *t2=temp->paramlist;
						struct tnode *t1=(yyvsp[-1]);
						while(t1!=NULL && t2!=NULL)
							{
							if(strcmp(t1->type->name,t2->type->name)!=0)
								{
								printf("Incorrect type of attributes %s %s for %s while calling\n",t1->type->name,t2->type->name,(yyvsp[-5])->varname);
								exit(1);
								}
							t1=t1->mid;		
							t2=t2->next;
							}		
						if(t1!=NULL || t2!=NULL)
							{
							printf("Incorrect no of attributes for %s while calling\n",(yyvsp[-5])->varname);
							exit(1);
							}
							
					    
					    }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 144 "s8t1.y" /* yacc.c:1646  */
    {
					    	(yyval)=(yyvsp[-5]);
						(yyval)->nodetype=34;
						(yyval)->left=(yyvsp[-3]);
							(yyvsp[-3])->left=(yyvsp[-1]);
						//$$->type=$3->type;
						struct Classtable *tt;
						//$1->Lentry=LLookup($1->varname);
						//if($1->Lentry!=NULL)
						//	$1->ctype=$1->Lentry->ctype;
						//else
						//	{
							(yyvsp[-5])->Gentry=GLookup((yyvsp[-5])->varname);
							if((yyvsp[-5])->Gentry!=NULL)
								(yyvsp[-5])->ctype=(yyvsp[-5])->Gentry->ctype;
							else
								{
								printf("Variable %s not declared \n",(yyvsp[-5])->varname);
								exit(1);
								}
						//	}
						tt=(yyvsp[-5])->ctype;		
						struct Memberfunclist *temp=Class_MLookup(tt,(yyvsp[-3])->varname);
						if(temp==NULL)
							{
							printf("Method %s not declared in class %s\n",(yyvsp[-3])->varname,tt->name);
							exit(1);
							}
						(yyval)->type=temp->type;					    
						struct Paramstruct *t2=temp->paramlist;
						struct tnode *t1=(yyvsp[-1]);
						//int ccc=0;
						//printf("vard\n");
						//	if(strcmp($1->varname,"second")==0)
						//		{
						//		printf("%s \n",t1->varname);
								
						//		}
						//	printf("vard\n");
							
						//	t1=$5;
						while(t1!=NULL && t2!=NULL)
							{
							if(strcmp(t1->type->name,t2->type->name)!=0)
								{
								printf("Incorrect type of attributes %s %s for %s while calling\n",t1->type->name,t2->type->name,(yyvsp[-5])->varname);				
								
								exit(1);
								}
							//if(strcmp($1->varname,"second")==0)
							//printf("\nCompared %s %s %d\n",t1->type->name,t2->type->name,++ccc);
							t1=t1->mid;		
							t2=t2->next;
							}		
						if(t1!=NULL || t2!=NULL)
							{
							printf("Incorrect no of attributes for %s while calling\n",(yyvsp[-5])->varname);
							//printf("vvvvvvvvvvvvvvvvvvv\n");
							//prefix($5);
							//	printf("SSSSSSSSSSSS\n");
							//	print_par(temp->paramlist);
							//	printf("\n\n");
							//printf("vardhan\n");
							//prefix(t1);
							//printf("siva\n");
							//print_par(t2);
							exit(1);
							}

						struct Classtable *cc1=GLookup((yyvsp[-5])->varname)->ctype;
						if(Class_MLookup(cc1,(yyvsp[-3])->varname)==NULL)
							{
							printf("Compilation error due to function %s not declared in parent section %s\n",(yyvsp[-3])->varname,cc1->name);
							exit(1);
							}
					     }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 222 "s8t1.y" /* yacc.c:1646  */
    {
						   	(yyval)=(yyvsp[-5]);
							(yyval)->nodetype=35;
							
							struct tnode *tt1=(yyvsp[-5]);
							if(tt1->left->left!=NULL)
								{
								printf("Members cannot be accessed\n");
								exit(1);
								}
							//while(tt1->left!=NULL)
							//	tt1=tt1->left;
							tt1->left->left=(yyvsp[-3]);
							(yyvsp[-3])->left=(yyvsp[-1]);
							//$$->type=$3->type;
							struct Classtable *tt=CLookup(tt1->varname);	
							struct Memberfunclist *temp=Class_MLookup((yyval)->ctype,(yyvsp[-3])->varname);
							if(temp==NULL)
								{
								printf("Method %s not declared in class %s\n",(yyvsp[-3])->varname,tt->name);
								exit(1);
								}
							(yyval)->type=temp->type;					    
							struct Paramstruct *t2=temp->paramlist;
							struct tnode *t1=(yyvsp[-1]);
							
							while(t1!=NULL && t2!=NULL)
								{
								if(strcmp(t1->type->name,t2->type->name)!=0)
									{
									printf("Incorrect type of attributes %s %s for %s while calling\n",t1->type->name,t2->type->name,(yyvsp[-5])->varname);
									exit(1);
									}
								t1=t1->mid;		
								t2=t2->next;
								}		
							if(t1!=NULL || t2!=NULL)
								{
								printf("Incorrect no of attributes for %s while calling\n",(yyvsp[-5])->varname);
								exit(1);
								}


						}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 266 "s8t1.y" /* yacc.c:1646  */
    {
						char *c="self";
					   	(yyval)=makeOperatorNode(c,-1,33,NULL,(yyvsp[-2]),NULL,NULL);
						(yyvsp[-2])->left=NULL;
						//$$->type=$3->type;
						
						struct Memberfunclist *temp=Class_MLookup(Cptr,(yyvsp[-2])->varname);
						if(temp==NULL)
							{
							printf("Method %s not declared in class %s\n",(yyvsp[-2])->varname,Cptr->name);
							exit(1);
							}
						(yyval)->type=temp->type;					    
						struct Paramstruct *t2=temp->paramlist;
						if(t2!=NULL)
							{
							printf("Incorrect no of attributes for %s while calling\n",(yyvsp[-4])->varname);
							exit(1);
							}

					}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 287 "s8t1.y" /* yacc.c:1646  */
    {
		
						(yyval)=(yyvsp[-4]);
						(yyval)->nodetype=34;
						(yyval)->left=(yyvsp[-2]);
							(yyvsp[-2])->left=NULL;
						//$$->type=$3->type;
						
						struct Classtable *tt;
						//$1->Lentry=LLookup($1->varname);
						//if($1->Lentry!=NULL)
						//	$1->ctype=$1->Lentry->ctype;
						//else
						//	{
							(yyvsp[-4])->Gentry=GLookup((yyvsp[-4])->varname);
							if((yyvsp[-4])->Gentry!=NULL)
								(yyvsp[-4])->ctype=(yyvsp[-4])->Gentry->ctype;
							else
								{
								printf("Variable %s not declared \n",(yyvsp[-4])->varname);
								exit(1);
								}
						//	}
						tt=(yyvsp[-4])->ctype;		
						struct Memberfunclist *temp=Class_MLookup(tt,(yyvsp[-2])->varname);
						if(temp==NULL)
							{
							printf("Method %s not declared in class %s\n",(yyvsp[-2])->varname,tt->name);
							exit(1);
							}
							
						(yyval)->type=temp->type;					    
						struct Paramstruct *t2=temp->paramlist;

				
						if(t2!=NULL)
							{
							printf("Incorrect no of attributes for %s while calling\n",(yyvsp[-4])->varname);
							exit(1);
							}
						struct Classtable *cc1=GLookup((yyvsp[-4])->varname)->ctype;
						if(Class_MLookup(cc1,(yyvsp[-2])->varname)==NULL)
							{
							printf("Compilation error due to function %s not declared in parent section %s\n",(yyvsp[-2])->varname,cc1->name);
							exit(1);
							}


					}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 337 "s8t1.y" /* yacc.c:1646  */
    {
					   	(yyval)=(yyvsp[-4]);
						(yyval)->nodetype=35;

						struct tnode *tt1=(yyvsp[-4]);
						if(tt1->left->left!=NULL)
								{
								printf("Members cannot be accessed\n");
								exit(1);
								}
						//while(tt1->left!=NULL)
						//	tt1=tt1->left;
						tt1->left->left=(yyvsp[-2]);
						(yyvsp[-2])->left=NULL;
						//$$->type=$3->type;
						struct Classtable *tt=CLookup(tt1->varname);	
						struct Memberfunclist *temp=Class_MLookup(tt,(yyvsp[-2])->varname);
						if(temp==NULL)
							{
							printf("Method %s not declared in class %s\n",(yyvsp[-2])->varname,tt->name);
							exit(1);
							}
						(yyval)->type=temp->type;					    
						struct Paramstruct *t2=temp->paramlist;
				
						if(t2!=NULL)
							{
							printf("Incorrect no of attributes for %s while calling\n",(yyvsp[-4])->varname);
							exit(1);
							}
	

					}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 378 "s8t1.y" /* yacc.c:1646  */
    {type=TInstall((yyvsp[-1])->varname,0,NULL);//$$=$1;
//print_t(T1);
	}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 382 "s8t1.y" /* yacc.c:1646  */
    {//struct Typetable *t1=TLookup(type);
		type->fields=f1;type->size=ind;f1=NULL;ind=0;/*print_t(T1);*/}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 389 "s8t1.y" /* yacc.c:1646  */
    {FInstall((yyvsp[0])->varname,++ind,typ);/*print_f(f1);*/}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 390 "s8t1.y" /* yacc.c:1646  */
    {FInstall((yyvsp[0])->varname,++ind,typ);/*print_f(f1);*/}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 397 "s8t1.y" /* yacc.c:1646  */
    {GInstall((yyvsp[0])->varname,typ,size,NULL,-1);}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 398 "s8t1.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3])->varname,typ,(yyvsp[-1])->val,NULL,-1);}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 399 "s8t1.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3])->varname,typ,0,h1,++fl);h1=NULL;}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 401 "s8t1.y" /* yacc.c:1646  */
    {char *ch="int";typ=strdup(ch);type=TLookup(ch);size=1;ctype=CLookup(ch);}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 402 "s8t1.y" /* yacc.c:1646  */
    {char *ch="str";typ=strdup(ch);type=TLookup(ch);size=1;ctype=CLookup(ch);}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 403 "s8t1.y" /* yacc.c:1646  */
    {char *ch=strdup((yyvsp[0])->varname);typ=strdup(ch);type=TLookup(ch);
		if(type!=NULL) size=type->size;ctype=CLookup(ch);}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 407 "s8t1.y" /* yacc.c:1646  */
    {char *ch="int";ptype=TLookup(ch);size=1;}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 408 "s8t1.y" /* yacc.c:1646  */
    {char *ch="str";ptype=TLookup(ch);size=1;}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 409 "s8t1.y" /* yacc.c:1646  */
    {char *ch=strdup((yyvsp[0])->varname);ptype=TLookup(ch);if(ptype!=NULL)size=ptype->size;}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 412 "s8t1.y" /* yacc.c:1646  */
    {//print_ltab(l1);printf("\n");
	struct Lsymbol *t1=l1;
	//print_ltab(t1);
	//printf("i=%d\n",i);

if(i>1 && t1!=NULL)
	while(t1!=NULL && i!=(t1->binding))
		{
		//printf("\ni=%d Name : %s binding=%d\n",i,t1->name,t1->binding);
		t1=t1->next;
			}
			//printf("SIVY\n");
	if(l1!=NULL)	
	while(t1!=NULL)
		{
		if(strcmp(t1->name,"self")!=0)
			fprintf(fp,"PUSH R0\n");
		t1=t1->next;
		}
		//printf("ISVN\n");
	i=1;
//exit(1);
	gencode((yyvsp[-1]));
					print_ltab(l1);
	//exit(1); 
	 l1=NULL;

	}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 441 "s8t1.y" /* yacc.c:1646  */
    {

	fnret=type;

	struct Gsymbol *temp=GLookup((yyvsp[-3])->varname);
	struct Memberfunclist *f1=NULL;
	if(temp==NULL)
		f1=Class_MLookup(Cptr,(yyvsp[-3])->varname);

	if(temp==NULL && f1==NULL)
		{
		printf("%s not declared\n",(yyvsp[-3])->varname);
		exit(1);
		}
	if(temp!=NULL)
		fprintf(fp,"F%d:\n",temp->flabel);
	else 
		fprintf(fp,"F%d:\n",f1->flabel);
	fprintf(fp,"PUSH BP\nMOV BP,SP\n");
	
	
		
	struct Paramstruct *t1=h1,*t2;
	if(temp!=NULL)
		t2=temp->paramlist;
	else
		t2=f1->paramlist;
	h1=NULL;
	i=1;
	int p,q;
	p=getReg();
	q=getReg();
	
	s1=0;
	while(t1!=NULL && t2!=NULL)
		{
		if(strcmp(t1->name,t2->name)!=0 || strcmp(t1->type->name,t2->type->name)!=0)
			{
			printf("Arguments of %s not matching\n",(yyvsp[-3])->varname);
			exit(1);
			}
		LInstall(t1->name,t1->type->name);
		fprintf(fp,"MOV R%d,BP\n",p);
		fprintf(fp,"MOV R%d,%d\n",q,i+2);
		fprintf(fp,"SUB R%d, R%d\n",p,q);
		fprintf(fp,"MOV R0,[R%d]\n",p);
		i++;
		fprintf(fp,"PUSH R0\n");
		t1=t1->next;
		t2=t2->next;
		s1++;
		}
	//if(l1!=NULL)
	//	l1->self=s1+2;
	char *s="self";
	char *st="int";
	LInstall(s,st);
	freeReg();
	freeReg();		
	if(t1!=NULL || t2!=NULL)
		{
		printf("Arguments of %s not matching\n",(yyvsp[-3])->varname);
		exit(1);
		}


	}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 510 "s8t1.y" /* yacc.c:1646  */
    {PInstall((yyvsp[0])->varname,ptype);
			//printf("VVVVVVVVVVVVVVVV %s AAAAAAAAAAAAAAA",ptype->name);
		}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 514 "s8t1.y" /* yacc.c:1646  */
    {bin=0;}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 515 "s8t1.y" /* yacc.c:1646  */
    {bin=0;}
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 519 "s8t1.y" /* yacc.c:1646  */
    {if(type==NULL)	
			{
			printf("The field %s cannot be installed locally\n",(yyvsp[0])->varname);
			exit(1);
			}
			LInstall((yyvsp[0])->varname,type->name);}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 525 "s8t1.y" /* yacc.c:1646  */
    {if(type==NULL)	
			{
			printf("The field %s cannot be installed locally\n",(yyvsp[0])->varname);
			exit(1);
			}
			LInstall((yyvsp[0])->varname,type->name);}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 533 "s8t1.y" /* yacc.c:1646  */
    {
		struct Gsymbol *temp=GLookup((yyvsp[-2])->varname);
		if(temp==NULL)
			{
			printf("%s not declared\n",(yyvsp[-2])->varname);
			exit(1);
			}
		if(temp->paramlist!=NULL)
			{printf("Incorrect no of attributes for %s while calling\n",(yyvsp[-2])->varname);
			exit(1);
			} 
		temp=GLookup((yyvsp[-2])->varname);
		(yyval)=makeOperatorNode((yyvsp[-2])->varname,-1,25,temp->type,NULL,NULL,NULL);
			
		}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 550 "s8t1.y" /* yacc.c:1646  */
    {//printf("\n\n\n");prefix($1);printf("\n\n");prefix($3);printf("\n\n\n");
	 			struct Gsymbol *temp=GLookup((yyvsp[-3])->varname);
				if(temp==NULL)
					{	
					printf("%s not declared\n",(yyvsp[-3])->varname);
					exit(1);
					}
				struct Paramstruct *t2=temp->paramlist;
				struct tnode *t1=(yyvsp[-1]);
				while(t1!=NULL && t2!=NULL)
					{
					if(strcmp(t1->type->name,t2->type->name)!=0)
						{
						printf("Incorrect type of attributes %s %s for %s while calling\n",t1->type->name,t2->type->name,(yyvsp[-3])->varname);
						exit(1);
						}
					t1=t1->mid;		
					t2=t2->next;
					}		
				if(t1!=NULL || t2!=NULL)
					{
					printf("Incorrect no of attributes for %s while calling\n",(yyvsp[-3])->varname);
					exit(1);
					}
				temp=GLookup((yyvsp[-3])->varname);
				(yyval)=makeOperatorNode((yyvsp[-3])->varname,-1,25,temp->type,(yyvsp[-1]),NULL,NULL);
			
	 			}
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 578 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]);
			while((yyvsp[-2])->mid!=NULL)
				(yyvsp[-2])=(yyvsp[-2])->mid;
			(yyvsp[-2])->mid=(yyvsp[0]);

			}
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 584 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 589 "s8t1.y" /* yacc.c:1646  */
    {

	fprintf(fp,"M1:\n");
	fprintf(fp,"MOV SP, %d\nMOV BP, %d\n",bind,bind);
	fill_class(c1);
	struct Lsymbol *t1=l1;
	int p=getReg();
	while(t1!=NULL){
		fprintf(fp,"PUSH R%d\n",p);
		t1=t1->next;
		}
	freeReg();
//exit(1);
	gencode((yyvsp[-1]));
//exit(1);
	//print_ltab(l1);printf("\n");
	// printf("SSSSSSSSSSSSSSSSSSSSSSS           fn_name : %s   self : %d      dddddddddddddddddddddddd\n",l1->
	 l1=NULL;

	}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 610 "s8t1.y" /* yacc.c:1646  */
    {printf("\n");prefix((yyvsp[-1]));printf("\n");//evaluator($3);
	(yyval)=(yyvsp[-1]);
	
	//gencode($2);
	//l1=NULL;
	}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 618 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(NULL,-1,4,NULL,(yyvsp[-1]),NULL,(yyvsp[0]));}
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 619 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 621 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 622 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 623 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 624 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 625 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 626 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 627 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 628 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 629 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 630 "s8t1.y" /* yacc.c:1646  */
    {if(strcmp(fnret->name,(yyvsp[-1])->type->name)!=0) {printf("Return type Error");exit(1);} 
				char *c="return";
				(yyval)=makeOperatorNode(c,-1,24,(yyvsp[-1])->type,(yyvsp[-1]),NULL,NULL);}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 633 "s8t1.y" /* yacc.c:1646  */
    {char *c="dealloc",*c2="int";(yyval)=makeOperatorNode(c,-1,30,TLookup(c2),(yyvsp[-2]),NULL,NULL);}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 636 "s8t1.y" /* yacc.c:1646  */
    {char *c="read";
				(yyval)=makeOperatorNode(c,-1,1,NULL,(yyvsp[-2]),NULL,NULL);}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 639 "s8t1.y" /* yacc.c:1646  */
    {char *c="write";
				(yyval)=makeOperatorNode(c,-1,2,NULL,(yyvsp[-2]),NULL,NULL);}
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 642 "s8t1.y" /* yacc.c:1646  */
    {
				char *c="=";
				if((yyvsp[-1])->ctype!=NULL && (yyvsp[-1])->ctype->name!=NULL && (yyvsp[-1])->left==NULL && (yyvsp[-1])->right==NULL && (yyvsp[-1])->mid==NULL && CLookup((yyvsp[-1])->ctype->name)!=NULL)
					{

					if(GLookup((yyvsp[-3])->varname)==NULL || GLookup((yyvsp[-1])->varname)==NULL)
						{
						printf("ID = ID is not valid for %s, %s\n",(yyvsp[-3])->varname,(yyvsp[-1])->varname);
						exit(1);
						}
					(yyvsp[-3])->ctype=GLookup((yyvsp[-3])->varname)->ctype;
					(yyvsp[-1])->ctype=GLookup((yyvsp[-1])->varname)->ctype;
					if((yyvsp[-3])->ctype==NULL || (yyvsp[-1])->ctype==NULL)
						{
						printf("ID = ID is not valid for types %s, %s\n",(yyvsp[-3])->varname,(yyvsp[-1])->varname);
						exit(1);
						}
					if(strcmp((yyvsp[-3])->ctype->name,(yyvsp[-1])->ctype->name)!=0 && (yyvsp[-1])->ctype->parentptr==NULL)
						{
						printf("ID = ID is not valid for %s, %s with types %s %s\n",(yyvsp[-3])->varname,(yyvsp[-1])->varname,(yyvsp[-3])->ctype->name,(yyvsp[-1])->ctype->name);
						exit(1);
						}
					struct Classtable *tt1=(yyvsp[-1])->ctype->parentptr;
					while(tt1!=NULL)
						{
						if(strcmp((yyvsp[-3])->ctype->name,tt1->name)==0)
							break;
						tt1=tt1->parentptr;
						}
					if(strcmp((yyvsp[-3])->ctype->name,(yyvsp[-1])->ctype->name)==0 || tt1!=NULL)
						{
						(yyval)=makeOperatorNode(c,-1,37,NULL,(yyvsp[-3]),NULL,(yyvsp[-1]));
						}
					else
						{
						printf("ID = ID is invalid operation for %s, %s\n",(yyvsp[-3])->varname,(yyvsp[-1])->varname);
						exit(1);
						}
					
					}
				else
					{
					if((yyvsp[-1])->nodetype!=29 && ((yyvsp[-3])->type==NULL || (yyvsp[-1])->type==NULL || strcmp((yyvsp[-3])->type->name,(yyvsp[-1])->type->name)!=0)) 						{
						printf("Type conflict for %s = %d\n",(yyvsp[-3])->varname,(yyvsp[-1])->val);
						exit(1);
						}
					(yyval)=makeOperatorNode(c,-1,3,NULL,(yyvsp[-3]),NULL,(yyvsp[-1]));
					if((yyvsp[-3])->type->size>8) 
						{
						printf("Too many member fields for %s\n",(yyvsp[-3])->varname);
						exit(1);
						}
					if((yyvsp[-1])->nodetype==29)
						(yyval)->nodetype=27;
					}
				}
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 698 "s8t1.y" /* yacc.c:1646  */
    {
				char *c="=";
				//printf("RRRRRRRRRRRRRRR %s %s EEEEEEEEEEEEEEEEEE",$1->type->name,$3->type->name);
				//if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) 
				 char *ch1="int",*ch2="str",*ch3="boolean",*ch4=(yyvsp[-3])->type->name;
				if(strcmp(ch4,ch1)==0 || strcmp(ch4,ch2)==0 || strcmp(ch4,ch3)==0)
					{
					printf("NULL not be defined in this way\n");
					exit(1);
					}
				(yyval)=makeOperatorNode(c,-1,3,NULL,(yyvsp[-3]),NULL,(yyvsp[-1]));
				}
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 712 "s8t1.y" /* yacc.c:1646  */
    {char *c="if";(yyval)=makeOperatorNode(c,-1,10,NULL,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 713 "s8t1.y" /* yacc.c:1646  */
    {char *c="if";(yyval)=makeOperatorNode(c,-1,10,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 715 "s8t1.y" /* yacc.c:1646  */
    { char *c="dowhile";
(yyval)=makeOperatorNode(c,-1,19,NULL,(yyvsp[-2]),NULL,(yyvsp[-5]));}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 718 "s8t1.y" /* yacc.c:1646  */
    {char *c="dowhile";
(yyval)=makeOperatorNode(c,-1,20,NULL,(yyvsp[-2]),NULL,(yyvsp[-5]));}
#line 2499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 721 "s8t1.y" /* yacc.c:1646  */
    {char *c="while";
(yyval)=makeOperatorNode(c,-1,11,NULL,(yyvsp[-5]),NULL,(yyvsp[-2]));}
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 726 "s8t1.y" /* yacc.c:1646  */
    {char *c="<";if((yyvsp[-2])->type==NULL || (yyvsp[0])->type==NULL || strcmp((yyvsp[-2])->type->name,(yyvsp[0])->type->name)!=0) {printf("Type conflict <\n");exit(1);}(yyval)=makeOperatorNode(c,-1,12,NULL,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 727 "s8t1.y" /* yacc.c:1646  */
    {char *c=">";if((yyvsp[-2])->type==NULL || (yyvsp[0])->type==NULL || strcmp((yyvsp[-2])->type->name,(yyvsp[0])->type->name)!=0) {printf("Type conflict >\n");exit(1);}(yyval)=makeOperatorNode(c,-1,13,NULL,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 728 "s8t1.y" /* yacc.c:1646  */
    {char *c="<=";if((yyvsp[-2])->type==NULL || (yyvsp[0])->type==NULL || strcmp((yyvsp[-2])->type->name,(yyvsp[0])->type->name)!=0) {printf("Type conflict <=\n");exit(1);}(yyval)=makeOperatorNode(c,-1,14,NULL,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 729 "s8t1.y" /* yacc.c:1646  */
    {char *c=">=";if((yyvsp[-2])->type==NULL || (yyvsp[0])->type==NULL || strcmp((yyvsp[-2])->type->name,(yyvsp[0])->type->name)!=0) {printf("Type conflict >=\n");exit(1);}(yyval)=makeOperatorNode(c,-1,15,NULL,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 730 "s8t1.y" /* yacc.c:1646  */
    {char *c="!=";if((yyvsp[-2])->type==NULL || (yyvsp[0])->type==NULL || strcmp((yyvsp[-2])->type->name,(yyvsp[0])->type->name)!=0) {printf("Type conflict !=\n");exit(1);}(yyval)=makeOperatorNode(c,-1,16,NULL,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 731 "s8t1.y" /* yacc.c:1646  */
    {char *c="==";if((yyvsp[-2])->type==NULL || (yyvsp[0])->type==NULL || strcmp((yyvsp[-2])->type->name,(yyvsp[0])->type->name)!=0) {printf("Type conflict ==\n");exit(1);}(yyval)=makeOperatorNode(c,-1,17,NULL,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 732 "s8t1.y" /* yacc.c:1646  */
    {char *c="!=";//if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) 
			char *ch1="int",*ch2="str",*ch3="boolean",*ch4=(yyvsp[-2])->type->name;
				if(strcmp(ch4,ch1)==0 || strcmp(ch4,ch2)==0 || strcmp(ch4,ch3)==0)
			{printf("Type conflict !=null\n");exit(1);}(yyval)=makeOperatorNode(c,-1,16,NULL,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 736 "s8t1.y" /* yacc.c:1646  */
    {char *c="==";//if($1->type==NULL || $3->type==NULL || strcmp($1->type->name,$3->type->name)!=0) 
			char *ch1="int",*ch2="str",*ch3="boolean",*ch4=(yyvsp[-2])->type->name;
				if(strcmp(ch4,ch1)==0 || strcmp(ch4,ch2)==0 || strcmp(ch4,ch3)==0){printf("Type conflict ==null\n");exit(1);}(yyval)=makeOperatorNode(c,-1,17,NULL,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 740 "s8t1.y" /* yacc.c:1646  */
    {char *c="+";if((yyvsp[-2])->type==NULL || (yyvsp[0])->type==NULL || strcmp((yyvsp[-2])->type->name,(yyvsp[0])->type->name)!=0) {printf("Type conflict +\n");exit(1);}(yyval)=makeOperatorNode(c,-1,5,(yyvsp[-2])->type,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 741 "s8t1.y" /* yacc.c:1646  */
    {char *c="-";if((yyvsp[-2])->type==NULL || (yyvsp[0])->type==NULL || strcmp((yyvsp[-2])->type->name,(yyvsp[0])->type->name)!=0) {printf("Type conflict -\n");exit(1);}(yyval)=makeOperatorNode(c,-1,6,(yyvsp[-2])->type,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 742 "s8t1.y" /* yacc.c:1646  */
    {char *c="*";if((yyvsp[-2])->type==NULL || (yyvsp[0])->type==NULL || strcmp((yyvsp[-2])->type->name,(yyvsp[0])->type->name)!=0) {printf("Type conflict *\n");exit(1);}(yyval)=makeOperatorNode(c,-1,7,(yyvsp[-2])->type,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 743 "s8t1.y" /* yacc.c:1646  */
    {char *c="/";if((yyvsp[-2])->type==NULL || (yyvsp[0])->type==NULL || strcmp((yyvsp[-2])->type->name,(yyvsp[0])->type->name)!=0) {printf("Type conflict /\n");exit(1);}(yyval)=makeOperatorNode(c,-1,8,(yyvsp[-2])->type,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 744 "s8t1.y" /* yacc.c:1646  */
    {char *c="%";if((yyvsp[-2])->type==NULL || (yyvsp[0])->type==NULL || strcmp((yyvsp[-2])->type->name,(yyvsp[0])->type->name)!=0) {printf("Type conflict \"%\"\n");exit(1);}(yyval)=makeOperatorNode(c,-1,9,(yyvsp[-2])->type,(yyvsp[-2]),NULL,(yyvsp[0]));}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 745 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 746 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 747 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 748 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 749 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 751 "s8t1.y" /* yacc.c:1646  */
    {
	if((yyvsp[0])->Lentry!=NULL)
		{ 
		(yyvsp[0])->type=(yyvsp[0])->Lentry->type;
		//$1->ctype=$1->Lentry->ctype;
		}
	else if((yyvsp[0])->Gentry!=NULL)
		{
		(yyvsp[0])->type=(yyvsp[0])->Gentry->type;
		(yyvsp[0])->ctype=(yyvsp[0])->Gentry->ctype;
		//if($1->ctype!=NULL && $1->ctype->name!=NULL && $1->left==NULL && $1->right==NULL && $1->mid==NULL && CLookup($1->ctype->name)!=NULL)
			//set=1;
		}
	else
		{printf("%s not declared\n",(yyvsp[0])->varname);
		exit(1);}			
	(yyval)=(yyvsp[0]);}
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 768 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=makeOperatorNode(NULL,-1,22,(yyvsp[-3])->Gentry->type,(yyvsp[-3]),NULL,(yyvsp[-1]));
			}
#line 2648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 770 "s8t1.y" /* yacc.c:1646  */
    {char *c="alloc",*c2="int";(yyval)=makeOperatorNode(c,-1,29,TLookup(c2),NULL,NULL,NULL);
		//printf("RRRRRRRRRR ");//$$=makeOperatorNode(c3,-1,3,0,$1,NULL,$2);prefix($$);printf("DDDDDDDDDDD\n");
				}
#line 2656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 773 "s8t1.y" /* yacc.c:1646  */
    {char *c="initialize",*c2="int";(yyval)=makeOperatorNode(c,-1,31,TLookup(c2),NULL,NULL,NULL);}
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 775 "s8t1.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 778 "s8t1.y" /* yacc.c:1646  */
    {
			(yyvsp[0])->left=NULL;
			(yyvsp[0])->mid=NULL;
			(yyvsp[0])->right=NULL;
			char *c="self";
			(yyval)=makeOperatorNode(c,-1,32,NULL,(yyvsp[0]),NULL,NULL);
		
		/*	$3->Gentry=GLookup($1->varname);
			$3->Lentry=LLookup($1->varname);
			
			if($1->Lentry!=NULL)			
				$1->type=$1->Lentry->type;
			else if($1->Gentry!=NULL)
				$1->type=$1->Gentry->type;
			else
				{
				printf("variable not declared\n");
				exit(1);
				}

			*/
			struct Fieldlist *ft=Class_FLookup(Cptr,(yyvsp[0])->varname);
			if(ft==NULL)
				{
				printf("Variable %s not declared in class %s\n",(yyvsp[0])->varname,Cptr->name);
				exit(1);
				}
			(yyval)->ctype=ft->ctype;
			(yyval)->type=ft->type;
			//if(ft->ctype!=NULL)
			//printf("Vardhan %s Vardhan\n",ft->ctype->name);
       		    }
#line 2705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 810 "s8t1.y" /* yacc.c:1646  */
    {
			char *c=(yyvsp[-2])->type->name,*c1="int",*c2="str",*c3="boolean";
			if((yyvsp[-2])->nodetype==32 && (strcmp(c,c1)==0 || strcmp(c,c2)==0 || strcmp(c,c3)==0))
				{
				printf("Members cannot be accessed\n");
				exit(1);
				}
			(yyval)=(yyvsp[-2]);
			
			(yyvsp[-2])=(yyval);
			while((yyvsp[-2])->left!=NULL)
				(yyvsp[-2])=(yyvsp[-2])->left;
			(yyvsp[-2])->left=(yyvsp[0]);
			
			if((yyvsp[-2])->type!=NULL)
				(yyval)->type=(FLookup((yyvsp[-2])->type,(yyvsp[0])->varname))->type;
			/*else if($1->ctype!=NULL)
				{
				$$->ctype=(Class_FLookup($1->ctype,$3->varname))->ctype;
				$$->type=(Class_FLookup($1->ctype,$3->varname))->type;
				}
		     */
		     }
#line 2733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 834 "s8t1.y" /* yacc.c:1646  */
    {
		
			(yyval)=(yyvsp[-2]);
			(yyval)->nodetype=28;
			(yyval)->left=(yyvsp[0]);
		(yyvsp[0])->left=NULL;
		(yyvsp[0])->mid=NULL;
		(yyvsp[0])->right=NULL;
			(yyvsp[-2])->Gentry=GLookup((yyvsp[-2])->varname);
			(yyvsp[-2])->Lentry=LLookup((yyvsp[-2])->varname);
			
			if((yyvsp[-2])->Lentry!=NULL)
				{			
				(yyvsp[-2])->type=(yyvsp[-2])->Lentry->type;
				//$1->ctype=$1->Lentry->ctype;
				}
			else if((yyvsp[-2])->Gentry!=NULL)
				{
				(yyvsp[-2])->type=(yyvsp[-2])->Gentry->type;
				(yyvsp[-2])->ctype=(yyvsp[-2])->Gentry->ctype;
				}
			else
				{
				printf("variable not declared\n");
				exit(1);
				}

			
			struct Fieldlist *ft=FLookup((yyvsp[-2])->type,(yyvsp[0])->varname);

			if(ft==NULL)
				{
				ft=Class_FLookup((yyvsp[-2])->ctype,(yyvsp[0])->varname);
				if(ft==NULL)
					{
					printf("Variable %s cannot be accessed\n",(yyvsp[0])->varname);
					exit(1);
					}
				else
					{
					(yyval)->ctype=ft->ctype;
					(yyval)->type=ft->type;
					}
				}
			else	
				{
				(yyval)->type=ft->type;
				(yyval)->ctype=ft->ctype;
				}

			

	
			}
#line 2792 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2796 "y.tab.c" /* yacc.c:1646  */
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
#line 890 "s8t1.y" /* yacc.c:1906  */

int yyerror(char *s)
{
printf("yyerror %s",s);
}
int main(int argc,char *argv[])
{
if(argc>2)
{
yyin=fopen(argv[1],"r");
fp=fopen(argv[2],"w");
fprintf(fp,"0\nM1\n0\n0\n0\n0\n0\n0\n");
TypeTableCreate();
yyparse();
fclose(fp);
}
return 1;
}

