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
#line 1 "lenguajeP.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h> 
	#include <limits.h> 

	// ASIGNACIONES A POSICIONES DE LISTA
	// !!!!!!!!!!!!!!!!!!!!!!!!RECURSIVIDAD Y RETURNS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// stuff from flex that bison needs to know about:
	extern int yylex();
	extern int yyparse();
	extern int numlin;
	extern FILE *yyin;

	void yyerror(const char *s);

	char* removeQuotes(char* s);

	struct symbol{
		int type;
		int memDir;
		int size;
		char* name;
		int* values;
		int scope;
	};

	struct Stack { 
		int top; 
		unsigned capacity; 
		struct symbol* array; 
	};
	
	struct Stack* stack;
	struct Stack* funcStack;

	FILE* fp;
	
	int currentScope = 0;
	int memoryDir = 73728;
	int localOffset = 0;
	int nextLabel = 1;
	int nextStatBlock = 1;
	int emptyStringDir;
	int currentReg = -1;
	int currentFloatReg = 0;
	int inFor = 0;
	int listPosition;
	int spillMode = 0;
	int spillRegs = 0;
	int lastRegSpilled = -1;
	int spilled[5] = {1, 1, 1, 1, 1};	
	int floatSpillMode = 0;
	int floatSpillRegs = 0;
	int lastFloatRegSpilled = -1;
	int floatSpilled[4] = {1, 1, 1, 1};
	int inFunc = 0;
	int funcParams = 0;
	int funcOffset = 0;
	int funcAssignedParams = 0;

	void advanceRegister();
	void reduceRegister();
	void advanceFloatRegister();
	void reduceLastRegSpilled();
	void reduceFloatRegister();
	void reduceLastFloatRegSpilled();
	void intSpill(int r1, int r2);
	void floatSpill(int r1, int r2);

	void initQFile();
	int getStringLength(char* string);
	void printStringQ(int memDir); 
	void loadRegisterOperatorQ(int reg);

	int isNotVar(int type);
	int varIsInt(int type);
	int varIsFloat(int type);
	int varIsString(int type);
	int varIsList(int type);
	int varIsFunc(int type);

	void resetRegs();
	int doExpr(int r1, int r2, char* op);	
	void initNumVarQ(char* varName, int reg);
	void initTextVarQ(char* varName, int reg);
	void initListPositionQ(int reg);
	int getStringRegQ(char* string);
	int getVarnameRegQ(char* varName);
	void printFromReg(int reg);
	void processCondition(int r1, int r2, char* comp);
	void initFromQ(int r1, int r2);
	void endFromQ(int label);
	void initForeachQ(char* varName, int cod);
	void endForeachQ(int label);
	void assignRegToVar(char* varName, int reg);
	int accessListQ(char* varName, int reg);
	int initFunctionQ(char* funcName);
	void initFuncParamQ(char* varName);
	void symbolFunctionQ(char* funcName, int funcLabel);
	void endFunctionQ(int funcLabel);
	int callFunctionQ(char* funcName);	
	void leaveFunctionQ(int label);
	void assignParamQ(int reg);

	void changeSymbolType(char* varName, int type);
	char* intToString(int number);
	char* floatToString(float number);
	struct symbol getSymbol(char* varName);
	struct symbol getFuncSymbol(char* varName);
	struct Stack* createStack(unsigned capacity);
	void push(struct Stack* stack, struct symbol item);
	int isEmpty(struct Stack* stack); 
	void pop(struct Stack* stack); 
	void removeScope(struct Stack* stack);


#line 185 "lenguajeP.tab.c" /* yacc.c:339  */

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
   by #include "lenguajeP.tab.h".  */
#ifndef YY_YY_LENGUAJEP_TAB_H_INCLUDED
# define YY_YY_LENGUAJEP_TAB_H_INCLUDED
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
    TEXT = 258,
    NUM = 259,
    LIST = 260,
    PLUS = 261,
    MINUS = 262,
    TIMES = 263,
    DIVIDED_BY = 264,
    MOD = 265,
    INT = 266,
    FLOAT = 267,
    VARNAME = 268,
    STRING = 269,
    IS = 270,
    IF = 271,
    THEN = 272,
    FROM = 273,
    TO = 274,
    DO = 275,
    DONE = 276,
    ENDFUNC = 277,
    SHOW = 278,
    TAB = 279,
    NOT = 280,
    GREATER = 281,
    LOWER = 282,
    GEQUALS = 283,
    LEQUALS = 284,
    EQUALS = 285,
    NOT_EQUALS = 286,
    AND = 287,
    OR = 288,
    FOREACH = 289,
    IN = 290,
    FUNC = 291,
    RETURN = 292,
    OPEN_BRACKET = 293,
    CLOSE_BRACKET = 294,
    OPEN_PAREN = 295,
    CLOSE_PAREN = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 120 "lenguajeP.y" /* yacc.c:355  */
int entero; float real; char* string;

#line 270 "lenguajeP.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LENGUAJEP_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 287 "lenguajeP.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
       2,     2,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   147,   147,   148,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   162,   163,   164,   167,   169,   172,   173,
     176,   176,   178,   178,   179,   182,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   199,   200,
     203,   203,   206,   207,   209,   210,   211,   212,   213,   214,
     215,   218,   218,   218,   221,   221,   221,   224,   227,   227,
     227,   227,   229,   229,   230,   233,   233,   233,   235,   235,
     236,   239
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TEXT", "NUM", "LIST", "PLUS", "MINUS",
  "TIMES", "DIVIDED_BY", "MOD", "INT", "FLOAT", "VARNAME", "STRING", "IS",
  "IF", "THEN", "FROM", "TO", "DO", "DONE", "ENDFUNC", "SHOW", "TAB",
  "NOT", "GREATER", "LOWER", "GEQUALS", "LEQUALS", "EQUALS", "NOT_EQUALS",
  "AND", "OR", "FOREACH", "IN", "FUNC", "RETURN", "OPEN_BRACKET",
  "CLOSE_BRACKET", "OPEN_PAREN", "CLOSE_PAREN", "'='", "','", "\",\"",
  "$accept", "lenguajeP", "line", "init", "initNum", "initText",
  "asignator", "initList", "@1", "numList", "$@2", "assign", "expr",
  "show", "ifClause", "@3", "negation", "comparator", "fromClause", "@4",
  "$@5", "foreachClause", "@6", "$@7", "listAccess", "initFunction", "@8",
  "$@9", "$@10", "funcParam", "$@11", "function", "@12", "$@13",
  "assignParams", "$@14", "returnClause", YY_NULLPTR
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
     295,   296,    61,    44,   297
};
# endif

#define YYPACT_NINF -23

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-23)))

#define YYTABLE_NINF -71

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,    56,   -23,    -9,    -8,    10,    58,    51,    51,    51,
      12,    24,    51,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,    15,    15,    25,   -23,
     -23,   -23,    51,   -23,   -23,    28,   -23,    51,   126,   -23,
     -23,   131,   169,     4,   -23,   169,    51,    51,   -23,    51,
     169,    51,     3,    51,    51,    51,    51,    51,   -23,   128,
      51,    51,     2,   169,   169,    15,    26,   -23,    14,   -23,
      19,    19,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,    51,   169,   169,    45,    51,    27,    29,   -23,
     154,    55,    57,    37,    39,   -23,     9,   -23,   -23,   -23,
     -23,   -23,    38,   -23,    40,   -23,   108,   108,    45,   -23,
      51,    81,    61,    66,   -23,   108,   -23,   -23,   -23,   -23,
      67,   -23
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,     0,     0,     0,    39,
       0,     0,     0,     2,     4,    13,    14,    15,     5,     6,
       7,     8,    10,     9,    12,    11,     0,     0,     0,    18,
      65,    19,     0,    34,    35,    33,    36,     0,    43,    32,
      37,     0,    38,     0,    58,    71,     0,     0,    20,     0,
      25,     0,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,     0,    17,    16,     0,    68,    66,     0,    31,
      26,    27,    28,    29,    30,    46,    44,    45,    47,    48,
      49,    50,     0,    51,    54,     0,     0,     0,     0,    57,
       0,     0,     0,    62,     0,    21,    24,    69,    67,    40,
       3,     3,     0,    59,     0,     3,    52,    55,     0,     3,
       0,     0,     0,     0,    63,    60,    23,    41,    53,    56,
       0,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -23,    65,   -23,   -23,   -23,   -23,   -19,   -23,   -23,   -22,
     -23,   -23,    -6,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -13,
     -23,    -1,   -23,   -23,   -23,   -23,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    13,    14,    15,    16,    32,    17,    65,    95,
     104,    18,    96,    19,    20,   105,    59,    82,    21,    91,
     112,    22,    92,   113,    39,    23,    62,   109,   120,    94,
     102,    40,    49,    88,    67,    87,    25
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,    38,    41,    42,    26,    27,    45,    46,    47,    53,
      54,    55,    56,    57,    28,    53,    54,    55,    56,    57,
      53,    54,    55,    56,    57,    43,    50,    55,    56,    57,
      29,    52,    53,    54,    55,    56,    57,    44,    48,    61,
      63,    64,    85,    66,    69,    68,    86,    70,    71,    72,
      73,    74,   -22,    89,    83,    84,     2,    31,    93,     3,
       4,     5,    33,    34,    35,    36,    51,   -70,    30,     6,
      98,    97,     7,    29,     8,   100,    90,   101,   -64,     9,
     103,   108,   118,   110,     3,     4,     5,   119,   116,   121,
      10,    37,    11,    12,     6,   114,     0,     7,    30,     8,
      31,     0,   117,     0,     9,    24,    24,     0,     0,     0,
      24,     3,     4,     5,    24,    10,     0,    11,    12,     0,
       0,     6,     0,     0,     7,     0,     8,     0,     0,     0,
       0,     9,    53,    54,    55,    56,    57,    53,    54,    55,
      56,    57,    10,    75,    11,    12,     0,     0,     0,     0,
      60,    58,     0,     0,    76,    77,    78,    79,    80,    81,
      53,    54,    55,    56,    57,   106,   107,     0,     0,     0,
     111,    99,     0,     0,   115,    53,    54,    55,    56,    57
};

static const yytype_int8 yycheck[] =
{
       1,     7,     8,     9,    13,    13,    12,    26,    27,     6,
       7,     8,     9,    10,     4,     6,     7,     8,     9,    10,
       6,     7,     8,     9,    10,    13,    32,     8,     9,    10,
      15,    37,     6,     7,     8,     9,    10,    13,    13,    35,
      46,    47,    40,    49,    41,    51,    65,    53,    54,    55,
      56,    57,    43,    39,    60,    61,     0,    42,    13,     3,
       4,     5,    11,    12,    13,    14,    38,    41,    40,    13,
      41,    44,    16,    15,    18,    20,    82,    20,    41,    23,
      41,    43,    21,    43,     3,     4,     5,    21,   110,    22,
      34,    40,    36,    37,    13,   108,    -1,    16,    40,    18,
      42,    -1,    21,    -1,    23,   106,   107,    -1,    -1,    -1,
     111,     3,     4,     5,   115,    34,    -1,    36,    37,    -1,
      -1,    13,    -1,    -1,    16,    -1,    18,    -1,    -1,    -1,
      -1,    23,     6,     7,     8,     9,    10,     6,     7,     8,
       9,    10,    34,    15,    36,    37,    -1,    -1,    -1,    -1,
      19,    25,    -1,    -1,    26,    27,    28,    29,    30,    31,
       6,     7,     8,     9,    10,   100,   101,    -1,    -1,    -1,
     105,    17,    -1,    -1,   109,     6,     7,     8,     9,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,     0,     3,     4,     5,    13,    16,    18,    23,
      34,    36,    37,    47,    48,    49,    50,    52,    56,    58,
      59,    63,    66,    70,    76,    81,    13,    13,     4,    15,
      40,    42,    51,    11,    12,    13,    14,    40,    57,    69,
      76,    57,    57,    13,    13,    57,    51,    51,    13,    77,
      57,    38,    57,     6,     7,     8,     9,    10,    25,    61,
      19,    35,    71,    57,    57,    53,    57,    79,    57,    41,
      57,    57,    57,    57,    57,    15,    26,    27,    28,    29,
      30,    31,    62,    57,    57,    40,    51,    80,    78,    39,
      57,    64,    67,    13,    74,    54,    57,    44,    41,    17,
      20,    20,    75,    41,    55,    60,    46,    46,    43,    72,
      43,    46,    65,    68,    74,    46,    54,    21,    21,    21,
      73,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    48,    48,    48,    49,    50,    51,    51,
      53,    52,    55,    54,    54,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      60,    59,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    64,    65,    63,    67,    68,    66,    69,    71,    72,
      73,    70,    75,    74,    74,    77,    78,    76,    80,    79,
      79,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     1,     1,
       0,     6,     0,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     9,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     0,     0,     9,     0,     0,     9,     4,     0,     0,
       0,    10,     0,     4,     1,     0,     0,     6,     0,     3,
       1,     2
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
        case 16:
#line 167 "lenguajeP.y" /* yacc.c:1646  */
    {initNumVarQ((yyvsp[-2].string), (yyvsp[0].entero));}
#line 1467 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 169 "lenguajeP.y" /* yacc.c:1646  */
    {initTextVarQ((yyvsp[-2].string), (yyvsp[0].entero));}
#line 1473 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 176 "lenguajeP.y" /* yacc.c:1646  */
    {struct symbol s; if (inFunc) s = getFuncSymbol((yyvsp[0].string)); else s = getSymbol((yyvsp[0].string)); if (s.type != -1) yyerror("La variable ya ha sido inicializada"); else {if (inFunc) (yyval.entero) = funcOffset; else (yyval.entero) = localOffset; listPosition = 0;}}
#line 1479 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 176 "lenguajeP.y" /* yacc.c:1646  */
    {struct symbol s; s.memDir = (yyvsp[-2].entero); s.type = 3; s.name = (yyvsp[-3].string); s.scope = currentScope; s.size = listPosition; if (inFunc) {funcOffset += listPosition * 4; push(funcStack, s);} else {localOffset += listPosition * 4; push(stack, s);} listPosition = 0; resetRegs();}
#line 1485 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "lenguajeP.y" /* yacc.c:1646  */
    {initListPositionQ((yyvsp[0].entero));}
#line 1491 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 179 "lenguajeP.y" /* yacc.c:1646  */
    {initListPositionQ((yyvsp[0].entero)); (yyval.entero) = 100 + listPosition; }
#line 1497 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 182 "lenguajeP.y" /* yacc.c:1646  */
    {assignRegToVar((yyvsp[-2].string), (yyvsp[0].entero)); resetRegs();}
#line 1503 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 185 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = doExpr((yyvsp[-2].entero), (yyvsp[0].entero), "+");}
#line 1509 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 186 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = doExpr((yyvsp[-2].entero), (yyvsp[0].entero), "-");}
#line 1515 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 187 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = doExpr((yyvsp[-2].entero), (yyvsp[0].entero), "*");}
#line 1521 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 188 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = doExpr((yyvsp[-2].entero), (yyvsp[0].entero), "/");}
#line 1527 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 189 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = doExpr((yyvsp[-2].entero), (yyvsp[0].entero), "%");}
#line 1533 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 190 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[-1].entero);}
#line 1539 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 191 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[0].entero);}
#line 1545 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 192 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = getVarnameRegQ((yyvsp[0].string));}
#line 1551 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 193 "lenguajeP.y" /* yacc.c:1646  */
    {advanceRegister(); fprintf(fp, "\tR%i=%i;\n", currentReg, (yyvsp[0].entero)); (yyval.entero) = currentReg;}
#line 1557 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 194 "lenguajeP.y" /* yacc.c:1646  */
    {advanceFloatRegister(); fprintf(fp, "\tRR%i=%f;\n", currentFloatReg, (yyvsp[0].real)); (yyval.entero) = currentFloatReg + 10; }
#line 1563 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 195 "lenguajeP.y" /* yacc.c:1646  */
    {advanceRegister(); (yyval.entero) = getStringRegQ(removeQuotes((yyvsp[0].string))); }
#line 1569 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 196 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[0].entero);}
#line 1575 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 199 "lenguajeP.y" /* yacc.c:1646  */
    {printFromReg((yyvsp[0].entero)); resetRegs();}
#line 1581 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 200 "lenguajeP.y" /* yacc.c:1646  */
    {printStringQ(emptyStringDir);}
#line 1587 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 203 "lenguajeP.y" /* yacc.c:1646  */
    {processCondition((yyvsp[-4].entero), (yyvsp[-1].entero), (yyvsp[-2].string)); (yyval.entero) = nextLabel++; fprintf(fp, "\n\tIF(%sR0) GT(%i);\n", (yyvsp[-3].string), (yyval.entero)); resetRegs(); currentScope++;}
#line 1593 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 203 "lenguajeP.y" /* yacc.c:1646  */
    {fprintf(fp, "L %i:\n", (yyvsp[-2].entero)); if (inFunc) removeScope(funcStack); else removeScope(stack); resetRegs();}
#line 1599 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 206 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.string) = "";}
#line 1605 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 207 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.string) = "!";}
#line 1611 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 209 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.string) = ">";}
#line 1617 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 210 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.string) = "<";}
#line 1623 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 211 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.string) = "==";}
#line 1629 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 212 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.string) = ">=";}
#line 1635 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 213 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.string) = "<=";}
#line 1641 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 214 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.string) = "==";}
#line 1647 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 215 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.string) = "!=";}
#line 1653 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 218 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = nextLabel; initFromQ((yyvsp[-2].entero), (yyvsp[0].entero));}
#line 1659 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 218 "lenguajeP.y" /* yacc.c:1646  */
    {endFromQ((yyvsp[-2].entero));}
#line 1665 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 221 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = nextLabel; initForeachQ((yyvsp[-2].string), (yyvsp[0].entero));}
#line 1671 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 221 "lenguajeP.y" /* yacc.c:1646  */
    {endForeachQ((yyvsp[-2].entero));}
#line 1677 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 224 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = accessListQ((yyvsp[-3].string), (yyvsp[-1].entero));}
#line 1683 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 227 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = initFunctionQ((yyvsp[0].string));}
#line 1689 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 227 "lenguajeP.y" /* yacc.c:1646  */
    {symbolFunctionQ((yyvsp[-4].string), (yyvsp[-3].entero));}
#line 1695 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 227 "lenguajeP.y" /* yacc.c:1646  */
    {endFunctionQ((yyvsp[-5].entero));}
#line 1701 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 229 "lenguajeP.y" /* yacc.c:1646  */
    {initFuncParamQ((yyvsp[0].string));}
#line 1707 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 230 "lenguajeP.y" /* yacc.c:1646  */
    {initFuncParamQ((yyvsp[0].string));}
#line 1713 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 233 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = callFunctionQ((yyvsp[-1].string));}
#line 1719 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 233 "lenguajeP.y" /* yacc.c:1646  */
    {leaveFunctionQ((yyvsp[-1].entero));}
#line 1725 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 233 "lenguajeP.y" /* yacc.c:1646  */
    {(yyval.entero) = 0;}
#line 1731 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 235 "lenguajeP.y" /* yacc.c:1646  */
    {assignParamQ((yyvsp[0].entero));}
#line 1737 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 236 "lenguajeP.y" /* yacc.c:1646  */
    {assignParamQ((yyvsp[0].entero));}
#line 1743 "lenguajeP.tab.c" /* yacc.c:1646  */
    break;


#line 1747 "lenguajeP.tab.c" /* yacc.c:1646  */
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
#line 241 "lenguajeP.y" /* yacc.c:1906  */


int main(int argc, char** argv) {
	
	stack = createStack(100);
	fp = fopen("compiled.q.c", "w");
	initQFile();

	if (argc > 1) yyin = fopen(argv[1], "r");
	else yyin = stdin;	
	yyparse();

	fprintf(fp, "\tGT(-2);\nEND"); //Fin del programa, se le añadiría un código de salida a R0
	fclose(fp);

	return 0;
	
}

void advanceRegister(){
	if (currentReg == 4) {
		currentReg = 0;
		if (spillMode) spillRegs++;
		spillMode = 1;
		if (inFunc) {
			funcOffset += 4;
			if (spilled[0] != 0) fprintf(fp, "\tI(R7-%i)=R0;\n", funcOffset);
		} else {			
			localOffset += 4;
			if (spilled[0] != 0) fprintf(fp, "\tI(R7-%i)=R0;\n", localOffset);
		}
	}
	else {
		currentReg++;
		if (spillMode) {
			if (spilled[currentReg] != 0){				
				spillRegs++;
				if (inFunc) {
					funcOffset += 4;
					fprintf(fp, "\tI(R7-%i)=R%i;\n", funcOffset, currentReg);
				} else {					
					localOffset += 4;
					fprintf(fp, "\tI(R7-%i)=R%i;\n", localOffset, currentReg);
				}
			}
			spilled[currentReg] = 1;	
		}
	}
}

void reduceRegister(){
	if (currentReg == 0) currentReg = 4;
	else currentReg--;
}

void reduceLastRegSpilled(){
	if (lastRegSpilled == 0) lastRegSpilled = 4;
	else lastRegSpilled--;
}

void advanceFloatRegister(){
	if (currentFloatReg == 3) {
		currentFloatReg = 0;
		if (floatSpillMode) floatSpillRegs++;
		floatSpillMode = 1;
		if (inFunc){
			funcOffset += 4;
			if (floatSpilled[0] != 0) fprintf(fp, "\tF(R7-%i)=RR0;\n", funcOffset);
		} else {
			localOffset += 4;
			if (floatSpilled[0] != 0) fprintf(fp, "\tF(R7-%i)=RR0;\n", localOffset);
		}
	}
	else {
		currentFloatReg++;
		if (floatSpillMode) {
			if (floatSpilled[currentFloatReg] != 0){				
				floatSpillRegs++;
				if (inFunc) {
					funcOffset += 4;
					fprintf(fp, "\tF(R7-%i)=RR%i;\n", funcOffset, currentFloatReg);
				} else {
					localOffset += 4;
					fprintf(fp, "\tF(R7-%i)=RR%i;\n", localOffset, currentFloatReg);
				}
			}
			floatSpilled[currentFloatReg] = 1;	
		}
	}
}

void reduceFloatRegister(){
	if (currentFloatReg == 0) currentFloatReg = 3;
	else currentFloatReg--;
}

void reduceLastFloatRegSpilled(){
	if (lastFloatRegSpilled == 0) lastFloatRegSpilled = 3;
	else lastFloatRegSpilled--;
}

int isNotVar(int type){
	return (type == -1);
}

int varIsInt(int type){
	return (type == 0);
}

int varIsFloat(int type){
	return (type == 1);
}

int varIsString(int type){
	return (type == 2);
}

int varIsList(int type){
	return (type == 3);
}

int varIsFunc(int type){
	return (type == 4);
}

void floatSpill(int r1, int r2){
	if (floatSpillMode){		
		if (lastFloatRegSpilled == -1) lastFloatRegSpilled = r2;
		else if (r1 == lastFloatRegSpilled){
			if (inFunc){
				fprintf(fp, "\tRR%i=F(R7-%i);\n", r1, funcOffset);
				funcOffset -= 4;
			} else {
				fprintf(fp, "\tRR%i=F(R7-%i);\n", r1, localOffset);
				localOffset -= 4;
			}						
			if (floatSpillRegs > 0) {floatSpillRegs--; reduceLastFloatRegSpilled();}
			else {
				lastFloatRegSpilled = -1;
				floatSpillMode = 0;
			}
		}
		floatSpilled[r2] = 0;
	}
}

void intSpill(int r1, int r2){
	if (spillMode){		
		if (lastRegSpilled == -1) lastRegSpilled = r2;
		else if (r1 == lastRegSpilled){
			if (inFunc){
				fprintf(fp, "\tR%i=I(R7-%i);\n", r1, funcOffset);
				funcOffset -= 4;
			} else {
				fprintf(fp, "\tR%i=I(R7-%i);\n", r1, localOffset);
				localOffset -= 4;
			}						
			if (spillRegs > 0) {spillRegs--; reduceLastRegSpilled();}
			else {
				lastRegSpilled = -1;
				spillMode = 0;
			}
		}
		spilled[r2] = 0;
	}
}

int doExpr(int r1, int r2, char* op){
	if (r1 > 100 || r2 > 100) yyerror("No se puede operar con una lista. Pruebe a operar un elemento."); // 100 indica que hay una posición de lista base en R0 y cada número que sume es el tamaño de dicha lista (p. ej 105 indica una lista tamaño 5)
	else if (r1 < -9 || r2 < -9) yyerror("No se puede operar con una variable texto.");
	else if (r1 > 9 && r2 > 9) {
		floatSpill(r1-10, r2-10);
		fprintf(fp, "\tRR%i=RR%i%sRR%i;\n", r1-10, r1-10, op, r2-10); 
		reduceFloatRegister();
	} else if (r1 > 9) {		
		int r_aux = r2 - 1;
		if (r_aux == -1) r_aux = 4;
		intSpill(r2, r2);
		fprintf(fp, "\tRR%i=RR%i%sR%i;\n", r1-10, r1-10, op, r2);
	} else if (r2 > 9) {		
		int r_aux = r1 - 1;
		if (r_aux == -1) r_aux = 4;
		intSpill(r1, r1);
		fprintf(fp, "\tRR%i=R%i%sRR%i;\n", r2-10, r1, op, r2-10);
		return r2;
	} else {
		intSpill(r1, r2);
		fprintf(fp, "\tR%i=R%i%sR%i;\n", r1, r1, op, r2); 
		reduceRegister();
	}
	return r1;
}	

void initQFile(){	
	fprintf(fp, "#include \"Q.h\"\n\nBEGIN\nL 0:\nSTAT(0)\n");
	fprintf(fp, "\tSTR(%i, \"\\n\");\n", memoryDir -= 4);
	fprintf(fp, "\tSTR(%i, \"%%i\");\n", memoryDir -= 4);
	fprintf(fp, "\tSTR(%i, \"%%f\");\n", memoryDir -= 4);
	fprintf(fp, "\tSTR(%i, \"\");\n", memoryDir -= 4);
	emptyStringDir = memoryDir;
	fprintf(fp, "CODE(0)\n");
}

void resetRegs(){
	currentReg = -1;
	currentFloatReg = -1;
	spillMode = 0;
	floatSpillMode = 0;
	int i = 0;
	for (i; i < 5; i++){
		spilled[i] = 1;
		if (i < 4) floatSpilled[i] = 1;	
	}
}

void initNumVarQ(char* varName, int reg){
	if (inFunc) {
		struct symbol s = getFuncSymbol(varName);
		if (!isNotVar(s.type)) yyerror("La variable ya existe.");
		if (reg < -9) yyerror("Una variable numérica no puede inicializarse con una String");
		if (reg > 9) {
			reg -= 10;
			s.type = 1;
			s.name = varName;
			funcOffset += 4;
			s.memDir = funcOffset;
			s.scope = currentScope;
			fprintf(fp, "\tF(R7-%i)=RR%i;\n", s.memDir, reg);
			push(funcStack, s);
			resetRegs();
		} else {
			s.type = 0;
			s.name = varName;
			funcOffset += 4;
			s.memDir = funcOffset;
			s.scope = currentScope;
			fprintf(fp, "\tI(R7-%i)=R%i;\n", s.memDir, reg);
			push(funcStack, s);
			resetRegs();
		}
	} else {
		struct symbol s = getSymbol(varName);
		if (!isNotVar(s.type)) yyerror("La variable ya existe.");
		if (reg < -9) yyerror("Una variable numérica no puede inicializarse con una String"); // es string
		if (reg > 9) {
			reg -= 10;
			s.type = 1;
			s.name = varName;
			localOffset += 4;
			s.memDir = localOffset;
			s.scope = currentScope;
			fprintf(fp, "\tF(R7-%i)=RR%i;\n", s.memDir, reg);
			push(stack, s);
			resetRegs();
		} else {
			s.type = 0;
			s.name = varName;
			localOffset += 4;
			s.memDir = localOffset;
			s.scope = currentScope;
			fprintf(fp, "\tI(R7-%i)=R%i;\n", s.memDir, reg);
			push(stack, s);
			resetRegs();
		}
	}
}

int getStringLength(char* string){
	int length = strlen(string);
	if (length == 0) return 4;	
	else if (length % 4 != 0){
		return (length / 4 + 1) * 4;
	}
	return length;
}

void initTextVarQ(char* varName, int reg){
	if (inFunc) {
		struct symbol s = getFuncSymbol(varName);
		if (!isNotVar(s.type)) yyerror("La variable ya existe.");
		if (reg >= 0) yyerror("Una variable tipo texto no se puede inicializar con un número.");
		else {
			reg += 10;
			s.type = 2;
			s.name = varName;
			funcOffset += 4;
			s.memDir = funcOffset;
			s.scope = currentScope;
			fprintf(fp, "\tI(R7-%i)=R%i;\n", s.memDir, reg);
			push(funcStack, s);
			resetRegs();
		}
	} else {
		struct symbol s = getSymbol(varName);
		if (!isNotVar(s.type)) yyerror("La variable ya existe.");
		if (reg >= 0) yyerror("Una variable tipo texto no se puede inicializar con un número.");
		else {
			reg += 10;
			s.type = 2;
			s.name = varName;
			localOffset += 4;
			s.memDir = localOffset;
			s.scope = currentScope;
			fprintf(fp, "\tI(R7-%i)=R%i;\n", s.memDir, reg);
			push(stack, s);
			resetRegs();
		}
	}
}

void initListPositionQ(int reg){
	if (reg < 0) yyerror("La lista solo admite valores numéricos.");
	else {
		listPosition += 1;
		if (inFunc) {
			if (reg > 9) fprintf(fp, "\tF(R7-%i)=RR%i;\n", funcOffset + listPosition*4, reg-10);
			else {
				fprintf(fp, "\tF(R7-%i)=R%i;\n", funcOffset + listPosition*4, reg);
			}
		} else {
			if (reg > 9) fprintf(fp, "\tF(R7-%i)=RR%i;\n", localOffset + listPosition*4, reg-10);
			else {
				fprintf(fp, "\tF(R7-%i)=R%i;\n", localOffset + listPosition*4, reg);
			}
		}
		
	}
	resetRegs();
}

int getStringRegQ(char* string){
	int length = getStringLength(string);
	fprintf(fp, "STAT(%i)\n", nextStatBlock);
	fprintf(fp, "\tSTR(%i, \"%s\");\n", memoryDir -= length, string);
	fprintf(fp, "CODE(%i)\n", nextStatBlock++);
	fprintf(fp, "\tR%i=%i;\n", currentReg, memoryDir);
	return currentReg-10;
}

int getVarnameRegQ(char* varName){
	if (inFunc) {
		struct symbol s = getFuncSymbol(varName);
		if (isNotVar(s.type)) yyerror("La variable no existe.");
		else if (varIsInt(s.type)){
			advanceRegister();
			fprintf(fp, "\tR%i=I(R7-%i);\n", currentReg, s.memDir);
			int reg = currentReg;
			return reg;
		} else if (varIsFloat(s.type)){
			advanceFloatRegister();
			fprintf(fp, "\tRR%i=F(R7-%i);\n", currentFloatReg, s.memDir);
			int reg = currentFloatReg + 10;
			return reg;
		} else if (varIsString(s.type)){
			advanceRegister();
			fprintf(fp, "\tR%i=I(R7-%i);\n", currentReg, s.memDir);
			int reg = currentReg - 10;
			return reg;
		} else if (varIsList(s.type)){
			fprintf(fp, "\tR0=%i;\n", s.memDir);
			return 100 + s.size;
		}
	} else {
		struct symbol s = getSymbol(varName);
		if (isNotVar(s.type)) yyerror("La variable no existe.");
		else if (varIsInt(s.type)){
			advanceRegister();
			fprintf(fp, "\tR%i=I(R7-%i);\n", currentReg, s.memDir);
			int reg = currentReg;
			return reg;
		} else if (varIsFloat(s.type)){
			advanceFloatRegister();
			fprintf(fp, "\tRR%i=F(R7-%i);\n", currentFloatReg, s.memDir);
			int reg = currentFloatReg + 10;
			return reg;
		} else if (varIsString(s.type)){
			advanceRegister();
			fprintf(fp, "\tR%i=I(R7-%i);\n", currentReg, s.memDir);
			int reg = currentReg - 10;
			return reg;
		} else if (varIsList(s.type)){
			fprintf(fp, "\tR0=%i;\n", s.memDir);
			return 100 + s.size;
		}
	}
}

void printFromReg(int reg){
	if (reg > 100) yyerror("No se puede mostrar una lista."); //quizás podemos hacer un método para imprimir una lista, no creo que sea muy difícil.
	else if (reg < 0){
		fprintf(fp, "\tR1=R%i;\n", reg+10);
		fprintf(fp, "\tR0=%i;\n", nextLabel);
		fprintf(fp, "\tGT(putf_);\n");
		fprintf(fp, "L %i:\n", nextLabel++);
	} else if (reg > 9){
		fprintf(fp, "\tRR1=RR%i;\n", reg-10);
		fprintf(fp, "\tR0=%i;\n", nextLabel);
		fprintf(fp, "\tGT(printfloat_);\n");
		fprintf(fp, "L %i:\n", nextLabel++);
	} else {
		fprintf(fp, "\tR1=R%i;\n", reg);
		fprintf(fp, "\tR0=%i;\n", nextLabel);
		fprintf(fp, "\tGT(printint_);\n");
		fprintf(fp, "L %i:\n", nextLabel++);
	}
}

void processCondition(int r1, int r2, char* comp){
	fprintf(fp, "\tR0=");
	loadRegisterOperatorQ(r1);
	fprintf(fp, "%s", comp);
	loadRegisterOperatorQ(r2);
	fprintf(fp, ";");
}

void loadRegisterOperatorQ(int reg){
	if (reg < 0) yyerror("No se puede comparar una variable texto.");
	else if (reg > 9) fprintf(fp, "RR%i", reg - 10);
	else fprintf(fp, "R%i", reg);
}

void initFromQ(int r1, int r2){
	if (inFor == 1) yyerror("Ya se encuentra en un bucle FROM. Este lenguaje no permite bucles FROM anidados.");
	else if (r1 < 0 || r1 > 9 || r2 < 0 || r2 > 9) yyerror("Solo se puede iterar entre variables enteras.");
	else {
		inFor = 1; 
		currentScope++;
		struct symbol s, t; 
		s.name = "iter";
		s.type = 0; 
		if (inFunc){
			funcOffset += 4; 
			s.memDir = funcOffset;
			funcOffset += 4;
			t.memDir = funcOffset;		 
			fprintf(fp, "\tI(R7-%i)=R%i;\n\tI(R7-%i)=R%i;\nL %i:\n", s.memDir, r1, t.memDir, r2, nextLabel); //init variables iter y final (limites locales) 
			s.scope = currentScope;
			t.scope = currentScope; 
			push(funcStack, s);
			push(funcStack, t);
		} else {			
			localOffset += 4; 
			s.memDir = localOffset;
			localOffset += 4;
			t.memDir = localOffset;		 
			fprintf(fp, "\tI(R7-%i)=R%i;\n\tI(R7-%i)=R%i;\nL %i:\n", s.memDir, r1, t.memDir, r2, nextLabel); //init variables iter y final (limites locales) 
			s.scope = currentScope;
			t.scope = currentScope; 
			push(stack, s);
			push(stack, t);
		}
		fprintf(fp, "\tR0=I(R7-%i);\n\tR1=I(R7-%i);\n\tIF(R0>R1) GT(%i);\n", s.memDir, t.memDir, nextLabel+1); //cargo y comparo				
		nextLabel += 2;
	}	
}

void endFromQ(int label){
	int memDir;
	if (inFunc) memDir = getFuncSymbol("iter").memDir;
	else memDir = getSymbol("iter").memDir;
	fprintf(fp, "\tR0=I(R7-%i);\n", memDir);
	fprintf(fp, "\tR0=R0+1;\n");
	fprintf(fp, "\tI(R7-%i)=R0;\n", memDir);
	fprintf(fp, "\tGT(%i);\n", label);
	fprintf(fp, "L %i:\n", label+1);
	inFor = 0; 
	if (inFunc) removeScope(funcStack);
	else removeScope(stack);
	resetRegs();
}

void initForeachQ(char* varName, int cod){
	//printf("%i", cod);
	if (cod < 100) yyerror("Solo se puede iterar sobre una variable tipo lista.");
	else {
		currentScope++;
		int size = cod - 100;
		struct symbol l, i, s;

		if (inFunc) {
			funcOffset += 4;
			l.memDir = funcOffset;
			l.scope = currentScope;
			fprintf(fp, "\tR0=R7-R0;\n\tI(R7-%i)=R0;\n", l.memDir); //en R0 está la offset base del array

			funcOffset += 4;
			i.memDir = funcOffset;
			i.name = "foreach";
			fprintf(fp, "\tI(R7-%i)=0;\nL %i:\n", i.memDir, nextLabel);
			i.scope = currentScope;
			push(funcStack, i);

			fprintf(fp, "\tR0=I(R7-%i);\n\tR1=%i;\n\tIF(R0>=R1) GT(%i);\n", i.memDir, size, nextLabel+1);
			s.name = varName;
			s.type = 1;
			s.scope = currentScope;
			funcOffset += 4;
			s.memDir = funcOffset;
			fprintf(fp, "\tR0=I(R7-%i);\n\tR0=R0+1;\n\tR0=R0*4;\n", i.memDir); //cojo el índice + 1 para acceder al array en memoria
			fprintf(fp, "\tR1=I(R7-%i);\n\tR0=R1-R0;\n\tRR0=F(R0);\n\tF(R7-%i)=RR0;\n", l.memDir, s.memDir); //recupero la posición base y le resto el offset del array para recuperar el valor de la posición correspondiente
			push(funcStack, s);
			nextLabel += 2;

		} else {
			localOffset += 4;
			l.memDir = localOffset;
			l.scope = currentScope;
			fprintf(fp, "\tR0=R7-R0;\n\tI(R7-%i)=R0;\n", l.memDir); //en R0 está la offset base del array

			localOffset += 4;
			i.memDir = localOffset;
			i.name = "foreach";
			fprintf(fp, "\tI(R7-%i)=0;\nL %i:\n", i.memDir, nextLabel);
			i.scope = currentScope;
			push(stack, i);

			fprintf(fp, "\tR0=I(R7-%i);\n\tR1=%i;\n\tIF(R0>=R1) GT(%i);\n", i.memDir, size, nextLabel+1);
			s.name = varName;
			s.type = 1;
			s.scope = currentScope;
			localOffset += 4;
			s.memDir = localOffset;
			fprintf(fp, "\tR0=I(R7-%i);\n\tR0=R0+1;\n\tR0=R0*4;\n", i.memDir); //cojo el índice + 1 para acceder al array en memoria
			fprintf(fp, "\tR1=I(R7-%i);\n\tR0=R1-R0;\n\tRR0=F(R0);\n\tF(R7-%i)=RR0;\n", l.memDir, s.memDir); //recupero la posición base y le resto el offset del array para recuperar el valor de la posición correspondiente
			push(stack, s);
			nextLabel += 2;
		}
	}
}

void endForeachQ(int label){
	int memDir; 
	if (inFunc) memDir = getFuncSymbol("foreach").memDir;
	else memDir = getSymbol("foreach").memDir;	
	fprintf(fp, "\tR0=I(R7-%i);\n", memDir);
	fprintf(fp, "\tR0=R0+1;\n");
	fprintf(fp, "\tI(R7-%i)=R0;\n", memDir);
	fprintf(fp, "\tGT(%i);\n", label);
	fprintf(fp, "L %i:\n", label+1);
	//inFor = 0; 
	if (inFunc) removeScope(funcStack);
	else removeScope(stack);
	resetRegs();
}

void changeSymbolType(char* varName, int type){
	int i;
	if (inFunc) {
		for (i = 0; i <= funcStack->top; i++){
			if (strcmp(varName, funcStack->array[i].name) == 0){
				funcStack->array[i].type = type;
			}
		}
	}
	else {		
		for (i = 0; i <= stack->top; i++){
			if (strcmp(varName, stack->array[i].name) == 0){
				stack->array[i].type = type;
			}
		}
	}
}

void assignRegToVar(char* varName, int reg){
	struct symbol s;
	if (inFunc) s = getFuncSymbol(varName);
	else s = getSymbol(varName);
	if (isNotVar(s.type)) yyerror("La variable no existe.");
	else if (varIsInt(s.type)) {
		if (reg > 100 || reg < -9) yyerror("Los tipos son incompatibles.");
		else if (reg > 9) {
			changeSymbolType(varName, 1);
			fprintf(fp, "\tF(R7-%i)=RR%i;\n", s.memDir, reg-10);
		} else fprintf(fp, "\tI(R7-%i)=R%i;\n", s.memDir, reg);
	} else if (varIsFloat(s.type)){
		if (reg > 100 || reg < -9) yyerror("Los tipos son incompatibles.");
		else if (reg < 9) {
			changeSymbolType(varName, 0);
			fprintf(fp, "\tI(R7-%i)=R%i;\n", s.memDir, reg);
		} else fprintf(fp, "\tF(R7-%i)=RR%i;\n", s.memDir, reg-10);
	} else if (varIsString(s.type)){
		if (reg > -1) yyerror("Los tipos son incompatibles.");
		fprintf(fp, "\tI(R7-%i)=R%i;\n", s.memDir, reg+10);
	} else if (varIsList(s.type)) yyerror("No se puede asignar una lista. Pruebe a asignar elementos.");
}

int accessListQ(char* varName, int reg){
	struct symbol l;
	if (inFunc) l = getFuncSymbol(varName);
	else l = getSymbol(varName);
	if (!varIsList(l.type)) yyerror("Solo se puede acceder a posiciones de listas.");	
	else {
		if (reg < 0 || reg > 9) yyerror("Solo se puede acceder a una posición entera de una lista.");
		else {
			advanceFloatRegister();
			int aux1 = reg + 1;
			if (aux1 == 5) aux1 = 0;
			if (inFunc){
				funcOffset += 4;
				fprintf(fp, "\tI(R7-%i)=R%i;\n", funcOffset, aux1);			
				int aux2 = aux1 + 1;
				if (aux2 == 5) aux2 = 0;
				funcOffset += 4;
				fprintf(fp, "\tI(R7-%i)=R%i;\n", funcOffset, aux2);
				fprintf(fp, "\tR%i=%i;\n", aux1, l.size);
				fprintf(fp, "\tR%i=R%i;\n", aux2, reg);
				fprintf(fp, "\tIF(R%i<0) GT(-2);\n", aux2);
				fprintf(fp, "\tIF(R%i>=R%i) GT(-2);\n", aux2, aux1); //Se sale del límite del array
				fprintf(fp, "\tR%i=4*R%i;\n", aux1, aux2);
				fprintf(fp, "\tR%i=R%i+4;\n", aux1, aux1);
				fprintf(fp, "\tR%i=%i+R%i;\n", aux1, l.memDir, aux1);
				fprintf(fp, "\tRR%i=F(R7-R%i);\n", currentFloatReg, aux1);
				fprintf(fp, "\tR%i=I(R7-%i);\n", aux2, funcOffset);
				funcOffset -= 4;
				fprintf(fp, "\tR%i=I(R7-%i);\n", aux1, funcOffset);
				funcOffset -= 4;
			} else {
				localOffset += 4;
				fprintf(fp, "\tI(R7-%i)=R%i;\n", localOffset, aux1);			
				int aux2 = aux1 + 1;
				if (aux2 == 5) aux2 = 0;
				localOffset += 4;
				fprintf(fp, "\tI(R7-%i)=R%i;\n", localOffset, aux2);
				fprintf(fp, "\tR%i=%i;\n", aux1, l.size);
				fprintf(fp, "\tR%i=R%i;\n", aux2, reg);
				fprintf(fp, "\tIF(R%i<0) GT(-2);\n", aux2);
				fprintf(fp, "\tIF(R%i>=R%i) GT(-2);\n", aux2, aux1); //Se sale del límite del array
				fprintf(fp, "\tR%i=4*R%i;\n", aux1, aux2);
				fprintf(fp, "\tR%i=R%i+4;\n", aux1, aux1);
				fprintf(fp, "\tR%i=%i+R%i;\n", aux1, l.memDir, aux1);
				fprintf(fp, "\tRR%i=F(R7-R%i);\n", currentFloatReg, aux1);
				fprintf(fp, "\tR%i=I(R7-%i);\n", aux2, localOffset);
				localOffset -= 4;
				fprintf(fp, "\tR%i=I(R7-%i);\n", aux1, localOffset);
				localOffset -= 4;
			}
			
			
			if (spillMode) reduceRegister();
			else currentReg--;
		}
	}
	return currentFloatReg+10;
}

int initFunctionQ(char* funcName){
	funcStack = createStack(100);
	struct symbol s = getSymbol(funcName);
	if (s.type != -1) yyerror("Ya existe una variable o función con este nombre.");
	else if (currentScope > 0) yyerror("Solo se puede definir una función en el ámbito global.");
	else {
		inFunc = 1;
		int funcLabel = nextLabel;
		nextLabel++;
		fprintf(fp, "\tGT(%i);\n", nextLabel);
		fprintf(fp, "L %i:\n", funcLabel);
		funcOffset += 4;
		nextLabel++;
		return funcLabel;
	}
}

void initFuncParamQ(char* varName){
	struct symbol s = getFuncSymbol(varName);
	if (s.type != -1) yyerror("No se pueden tener dos parámetros con el mismo nombre.");
	else {
		s.name = varName;
		s.type = 0;
		s.scope = currentScope;
		funcOffset += 4;
		s.memDir = funcOffset;
		funcParams++;
		push(funcStack, s);	
	}
}

void symbolFunctionQ(char* funcName, int funcLabel){
	struct symbol s;
	s.name = funcName;
	s.memDir = funcLabel;
	s.size = funcParams;
	s.type = 4;
	push(stack, s);
}

void endFunctionQ(int funcLabel){
	inFunc = 0;
	funcParams = 0;
	funcOffset = 0;
	fprintf(fp, "\tR0=I(R7-4);\n");
	fprintf(fp, "\tGT(R0);\n");
	fprintf(fp, "L %i:\n", funcLabel + 1);
}

void saveRegs(){
	if (inFunc) {
		//funcOffset += 4;
		fprintf(fp, "\tI(R7-%i)=R0;\n", funcOffset += 4);
		fprintf(fp, "\tI(R7-%i)=R1;\n", funcOffset += 4);
		fprintf(fp, "\tI(R7-%i)=R2;\n", funcOffset += 4);
		fprintf(fp, "\tI(R7-%i)=R3;\n", funcOffset += 4);
		fprintf(fp, "\tI(R7-%i)=R4;\n", funcOffset += 4);
		fprintf(fp, "\tF(R7-%i)=RR0;\n", funcOffset += 4);
		fprintf(fp, "\tF(R7-%i)=RR1;\n", funcOffset += 4);
		fprintf(fp, "\tF(R7-%i)=RR2;\n", funcOffset += 4);
		fprintf(fp, "\tF(R7-%i)=RR3;\n", funcOffset += 4);
	} else {
		//localOffset += 4;
		fprintf(fp, "\tI(R7-%i)=R0;\n", localOffset += 4);
		fprintf(fp, "\tI(R7-%i)=R1;\n", localOffset += 4);
		fprintf(fp, "\tI(R7-%i)=R2;\n", localOffset += 4);
		fprintf(fp, "\tI(R7-%i)=R3;\n", localOffset += 4);
		fprintf(fp, "\tI(R7-%i)=R4;\n", localOffset += 4);
		fprintf(fp, "\tF(R7-%i)=RR0;\n", localOffset += 4);
		fprintf(fp, "\tF(R7-%i)=RR1;\n", localOffset += 4);
		fprintf(fp, "\tF(R7-%i)=RR2;\n", localOffset += 4);
		fprintf(fp, "\tF(R7-%i)=RR3;\n", localOffset += 4);
	}
}

void loadRegs(){
	if (inFunc) {
		fprintf(fp, "\tRR3=F(R7-%i);\n", funcOffset);
		fprintf(fp, "\tRR2=F(R7-%i);\n", funcOffset -= 4);
		fprintf(fp, "\tRR1=F(R7-%i);\n", funcOffset -= 4);
		fprintf(fp, "\tRR0=F(R7-%i);\n", funcOffset -= 4);
		fprintf(fp, "\tR4=I(R7-%i);\n", funcOffset -= 4);
		fprintf(fp, "\tR3=I(R7-%i);\n", funcOffset -= 4);
		fprintf(fp, "\tR2=I(R7-%i);\n", funcOffset -= 4);
		fprintf(fp, "\tR1=I(R7-%i);\n", funcOffset -= 4);
		fprintf(fp, "\tR0=I(R7-%i);\n", funcOffset -= 4);
		//funcOffset -= 4;
	} else {
		fprintf(fp, "\tRR3=F(R7-%i);\n", localOffset);
		fprintf(fp, "\tRR2=F(R7-%i);\n", localOffset -= 4);
		fprintf(fp, "\tRR1=F(R7-%i);\n", localOffset -= 4);
		fprintf(fp, "\tRR0=F(R7-%i);\n", localOffset -= 4);
		fprintf(fp, "\tR4=I(R7-%i);\n", localOffset -= 4);
		fprintf(fp, "\tR3=I(R7-%i);\n", localOffset -= 4);
		fprintf(fp, "\tR2=I(R7-%i);\n", localOffset -= 4);
		fprintf(fp, "\tR1=I(R7-%i);\n", localOffset -= 4);
		fprintf(fp, "\tR0=I(R7-%i);\n", localOffset -= 4);
		//funcOffset -= 4;
	}	
}

int callFunctionQ(char* funcName){
	struct symbol f = getSymbol(funcName);
	if (isNotVar(f.type)) yyerror("Esta función no ha sido definida previamente.");
	if (!varIsFunc(f.type)) yyerror("No se puede llamar a una variable que no sea función.");
	else {
		if (1 != f.size) yyerror("El número de parámetros no coincide con el de la función.");
		saveRegs();
		return f.memDir;
	}
}

void leaveFunctionQ(int label){
	fprintf(fp, "\tI(R7-4)=%i;\n", nextLabel);
	fprintf(fp, "\tGT(%i);\n", label);
	fprintf(fp, "L %i:\n", nextLabel++);
	if (inFunc) fprintf(fp, "\tR7=R7+%i;\n", funcOffset);	
	else fprintf(fp, "\tR7=R7+%i;\n", localOffset);
	loadRegs();
	funcAssignedParams = 0;
}

void assignParamQ(int reg){
	if (reg < 0 || reg > 100) yyerror("Solo se puede asignar a funciones valores numéricos.");
	else if (reg > 9){			
		if (inFunc) fprintf(fp, "\tR7=R7-%i;\n", funcOffset);
		else fprintf(fp, "\tR7=R7-%i;\n", localOffset);		
		funcAssignedParams++;
		int mem = 4 + funcAssignedParams*4;
		reg -= 10;
		fprintf(fp, "\tF(R7-%i)=RR%i;\n", mem, reg);
	} else {			
		if (inFunc) fprintf(fp, "\tR7=R7-%i;\n", funcOffset);
		else fprintf(fp, "\tR7=R7-%i;\n", localOffset);		
		funcAssignedParams++;
		int mem = 4 + funcAssignedParams*4;
		fprintf(fp, "\tI(R7-%i)=R%i;\n", mem, reg);
	}
}

void printStringQ(int memDir){
	fprintf(fp, "\tR1=I(R7-%i);\n", memDir);
	fprintf(fp, "\tR0=%i;\n", nextLabel);
	fprintf(fp, "\tGT(putf_);\n");
	fprintf(fp, "L %i:\n", nextLabel++);
} 

//para el return guardar codigo de salida en algun registro y cuando entra a función hay que guardar los registros en memoria por si las moscas.


char* removeQuotes(char* s){
	char* res = s; 	
	res++;
	res[strlen(res)-1] = 0;
	return res;
}

void yyerror(const char* mens){
	printf("Error sintáctico en linea %i: %s\n", numlin, mens); // hay que corregir el número de línea cuando se llame a yyerror desde el final de una sentencia.
	exit(-1);
}

struct symbol getSymbol(char* varName){
	int i;
	for (i = 0; i <= stack->top; i++){
		if (strcmp(varName, stack->array[i].name) == 0){
			return stack->array[i];
		}
	}
	struct symbol a;
	a.type = -1;
	return a;
}

struct symbol getFuncSymbol(char* varName){
	int i;
	for (i = 0; i <= funcStack->top; i++){
		if (strcmp(varName, funcStack->array[i].name) == 0){
			return funcStack->array[i];
		}
	}
	struct symbol a;
	a.type = -1;
	return a;
}
  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity) { 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (struct symbol*) malloc(stack->capacity * sizeof(struct symbol)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
/*int isFull(struct Stack* stack) 
{   return stack->top == stack->capacity - 1; } 
  */
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{   return stack->top == -1;  } 

// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, struct symbol item) 
{ 
    /*if (isFull(stack)) 
        return; */
    stack->array[++stack->top] = item; 
    //printf("%s, %i, %s pushed to stack\n", item.name, item.type, item.value); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
void pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)){		
    	stack->top--; 
	}
}

void removeScope(struct Stack* stack){
	while(currentScope==stack->array[stack->top].scope){
		stack->top--;
		if (inFunc) funcOffset -= 4;
		else localOffset -= 4;
	}
	currentScope--;
} 

