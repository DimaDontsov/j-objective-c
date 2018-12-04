/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "objectivec.y"

    /*
    ТУТ ПОДКЛЮЧЕНИЕ БИБЛИОТЕК, 
    ПРОТОТИПЫ ФУНКЦИЙ НА СИ
    ОБЪЯВЛЕНИЕ ПЕРЕМЕННЫХ
    */
    #include <stdio.h>
	#include "tree_structs.h"

   /* #define YYSTYPE */

    void yyerror( const char *s) {
        fprintf (stderr, "%s\n", s);
    }
	
	extern int yylex(void);
	struct Program_st* root;


/* Line 371 of yacc.c  */
#line 88 "objectivec.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "objectivec.tab.h".  */
#ifndef YY_YY_OBJECTIVEC_TAB_H_INCLUDED
# define YY_YY_OBJECTIVEC_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_CONST = 258,
     FLOAT_CONST = 259,
     CHAR_CONST = 260,
     BOOL_CONST = 261,
     STRING_CONST = 262,
     ID = 263,
     WHILE = 264,
     DO = 265,
     IF = 266,
     ELSE = 267,
     END = 268,
     EXTERN = 269,
     IMPLEMENTATION = 270,
     INTERFACE = 271,
     PUBLIC = 272,
     PROTECTED = 273,
     PRIVATE = 274,
     RETURN = 275,
     ENUM = 276,
     INT = 277,
     FLOAT = 278,
     STRING = 279,
     CHAR = 280,
     BOOL = 281,
     VOID = 282,
     OR = 283,
     AND = 284,
     NOT_EQUAL = 285,
     EQUAL = 286,
     GREATER_OR_EQUAL = 287,
     LESS_OR_EQUAL = 288,
     POINTER = 289,
     UPLUS = 290,
     UMINUS = 291,
     ARROW = 292
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 21 "objectivec.y"

    int int_const;
    double float_const;
    char char_const;
	char bool_const; 
    char* string_const;
    char* id;
    
	struct Statements_List_st *_stmt_list;
	struct Statement_st *_stmt;
	struct Expression_st *_expr;
	struct Type_st *_type;
	struct Array_type_st *_array_type;
	struct Enum_declaration_st *_enum_decl;
	struct Enumerator_list_st *_enum_list;
	struct Enumerator_st *_enumerator;

	enum Field_access_en field_access_en;
	struct Class_method_param_declaration_st* class_method_param_declaration_st;
	struct Class_method_param_declaration_list_st* class_method_param_declaration_list_st;
	enum Method_type_en method_type_en;
	struct Class_method_declaration_st* class_method_declaration_st;
	struct Class_methods_declaration_list_st* class_methods_declaration_list_st;
	struct Class_methods_declaration_block_st* class_methods_declaration_block_st;
	struct Class_methods_declaration_block_list_st* class_methods_declaration_block_list_st;
	struct Class_invariant_declaration_st* class_invariant_declaration_st;
	struct Class_invariants_declaration_list_st* class_invariants_declaration_list_st;
	struct Class_invariants_declaration_block_st* class_invariants_declaration_block_st;
	struct Class_invariants_declaration_block_list_st* class_invariants_declaration_block_list_st;
	struct Class_declaration_st* class_declaration_st;
	struct Class_method_impl_st* class_method_impl_st;
	struct Class_method_impl_list_st* class_method_impl_list_st;
	struct Class_impl_st* class_impl_st;

	struct Invariant_call_st* invariant_call_st;

	struct Method_call_arg_st* method_call_arg_st;
	struct Method_call_arg_list_st* method_call_arg_list_st;
	struct Method_call_st* method_call_st;

	struct Expr_list_st* expr_list_st;

	struct Func_arg_st* func_arg_st;
	struct Func_arg_list_st* func_arg_list_st;
	struct Func_declaration_st* func_declaration_st;
	struct Func_impl_st* func_impl_st;
	struct Func_call_st* func_call_st;

	struct Array_elem_call_st* array_elem_call_st;

	struct Extern_code_st* extern_code_st;
	struct Program_st* program_st;


/* Line 387 of yacc.c  */
#line 223 "objectivec.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_OBJECTIVEC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 251 "objectivec.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   571

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNRULES -- Number of states.  */
#define YYNSTATES  263

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,    42,     2,     2,
      55,    50,    40,    39,    28,    38,    47,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    52,
      34,    29,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    51,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    30,    31,    32,    33,    36,    37,    44,
      45,    46,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    18,
      20,    23,    25,    27,    28,    32,    35,    38,    40,    42,
      44,    46,    48,    52,    58,    66,    72,    78,    82,    89,
     100,   103,   106,   108,   110,   112,   114,   116,   118,   120,
     122,   124,   128,   132,   136,   139,   143,   147,   151,   157,
     161,   165,   169,   173,   177,   181,   185,   189,   192,   195,
     198,   202,   204,   206,   208,   210,   212,   214,   220,   225,
     230,   234,   239,   243,   249,   253,   255,   257,   261,   263,
     265,   267,   271,   273,   276,   279,   281,   283,   286,   289,
     293,   298,   305,   312,   321,   323,   326,   328,   331,   334,
     336,   338,   339,   347,   355,   361,   367,   370,   372,   375,
     378,   380,   382,   385,   387,   388,   396,   402,   409,   414,
     417,   419,   422,   424,   425,   430,   433,   437,   439,   442,
     444,   447,   450,   452,   454,   458,   460,   461,   464,   469,
     471,   475,   477,   478,   484,   487
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,   110,    -1,   111,    -1,    94,    -1,    98,
      -1,    73,    -1,    58,    -1,    59,    58,    -1,    59,    -1,
      61,    63,    -1,    63,    -1,    61,    -1,    -1,    20,    72,
      52,    -1,    20,    52,    -1,    72,    52,    -1,    66,    -1,
      65,    -1,    67,    -1,    64,    -1,    52,    -1,    53,    62,
      54,    -1,    11,    55,    72,    50,    63,    -1,    11,    55,
      72,    50,    63,    12,    63,    -1,     9,    55,    72,    50,
      63,    -1,    70,     8,    29,    72,    52,    -1,    70,     8,
      52,    -1,    70,     8,    49,     3,    51,    52,    -1,    70,
       8,    49,     3,    51,    29,    53,   105,    54,    52,    -1,
       8,    40,    -1,    21,     8,    -1,    71,    -1,    68,    -1,
      69,    -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,
      26,    -1,    27,    -1,    72,    39,    72,    -1,    72,    38,
      72,    -1,    72,    40,    72,    -1,    68,    72,    -1,    72,
      41,    72,    -1,    72,    42,    72,    -1,    72,    29,    72,
      -1,    72,    29,    53,   105,    54,    -1,    72,    34,    72,
      -1,    72,    37,    72,    -1,    72,    35,    72,    -1,    72,
      36,    72,    -1,    72,    33,    72,    -1,    72,    32,    72,
      -1,    72,    31,    72,    -1,    72,    30,    72,    -1,    43,
      72,    -1,    39,    72,    -1,    38,    72,    -1,    55,    72,
      50,    -1,     8,    -1,     3,    -1,     4,    -1,     6,    -1,
       5,    -1,     7,    -1,    49,    72,     8,   103,    51,    -1,
      49,    72,     8,    51,    -1,    72,    49,    72,    51,    -1,
      72,    48,     8,    -1,     8,    55,   104,    50,    -1,     8,
      55,    50,    -1,    69,    53,    74,    54,    52,    -1,    74,
      28,    75,    -1,    75,    -1,     8,    -1,     8,    29,     3,
      -1,    17,    -1,    18,    -1,    19,    -1,    70,     8,    52,
      -1,    77,    -1,    78,    77,    -1,    76,    78,    -1,    78,
      -1,    79,    -1,    80,    79,    -1,    53,    54,    -1,    53,
      80,    54,    -1,    55,    70,    50,     8,    -1,    55,    70,
      49,    51,    50,     8,    -1,     8,    56,    55,    70,    50,
       8,    -1,     8,    56,    55,    70,    49,    51,    50,     8,
      -1,    83,    -1,    84,    83,    -1,    82,    -1,    85,    82,
      -1,    82,    84,    -1,    85,    -1,    86,    -1,    -1,    38,
      55,    70,    50,     8,    56,    87,    -1,    39,    55,    70,
      50,     8,    56,    87,    -1,    38,    55,    70,    50,     8,
      -1,    39,    55,    70,    50,     8,    -1,    88,    52,    -1,
      89,    -1,    90,    89,    -1,    76,    90,    -1,    90,    -1,
      91,    -1,    92,    91,    -1,    92,    -1,    -1,    16,     8,
      56,     8,    81,    93,    13,    -1,    16,     8,    81,    93,
      13,    -1,    16,     8,    56,     8,    93,    13,    -1,    16,
       8,    93,    13,    -1,    88,    64,    -1,    95,    -1,    96,
      95,    -1,    96,    -1,    -1,    15,     8,    97,    13,    -1,
      56,    72,    -1,     8,    56,    72,    -1,    99,    -1,   101,
      99,    -1,   100,    -1,   102,   100,    -1,    99,   102,    -1,
     101,    -1,    72,    -1,   104,    28,    72,    -1,   104,    -1,
      -1,    70,     8,    -1,    70,     8,    49,    51,    -1,   106,
      -1,   107,    28,   106,    -1,   107,    -1,    -1,    70,     8,
      55,   108,    50,    -1,   109,    52,    -1,   109,    64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   186,   187,   188,   189,   192,   193,   196,
     198,   199,   202,   203,   206,   207,   208,   209,   210,   211,
     212,   213,   216,   219,   220,   223,   226,   227,   228,   229,
     232,   236,   239,   240,   241,   244,   245,   246,   247,   248,
     249,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   286,   289,   290,   293,   294,   320,   321,
     322,   325,   328,   329,   333,   337,   338,   339,   342,   343,
     346,   347,   354,   355,   358,   359,   362,   363,   367,   368,
     372,   373,   384,   385,   386,   387,   390,   395,   396,   401,
     405,   406,   407,   410,   411,   414,   415,   416,   417,   421,
     425,   426,   429,   430,   433,   438,   441,   444,   445,   448,
     449,   453,   454,   459,   460,   465,   466,   471,   472,   475,
     476,   479,   480,   483,   486,   489
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_CONST", "FLOAT_CONST", "CHAR_CONST",
  "BOOL_CONST", "STRING_CONST", "ID", "WHILE", "DO", "IF", "ELSE", "END",
  "EXTERN", "IMPLEMENTATION", "INTERFACE", "PUBLIC", "PROTECTED",
  "PRIVATE", "RETURN", "ENUM", "INT", "FLOAT", "STRING", "CHAR", "BOOL",
  "VOID", "','", "'='", "OR", "AND", "NOT_EQUAL", "EQUAL", "'<'", "'>'",
  "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "'-'", "'+'", "'*'", "'/'", "'%'",
  "'!'", "POINTER", "UPLUS", "UMINUS", "'.'", "ARROW", "'['", "')'", "']'",
  "';'", "'{'", "'}'", "'('", "':'", "$accept", "extern_code", "prog",
  "prog_full", "stmt_list", "stmt_list_or_empty", "stmt", "compound_stmt",
  "if_stmt", "while_stmt", "var_decl", "pointer_custom_type", "enum_type",
  "type", "default_type", "expr", "enum_declaration", "enumerator_list",
  "enumerator", "class_fields_access", "class_invariant_declaration",
  "class_invariants_declarations",
  "class_invariant_declaration_with_access",
  "class_invariant_declaration_with_access_list",
  "class_invariants_declaration", "class_method_first_param",
  "class_method_other_param_named", "class_method_other_params_named",
  "class_method_params_nonamed", "class_method_all_params",
  "class_method_params", "class_method", "class_method_declaration",
  "class_methods_declaration", "class_methods_declaration_with_access",
  "class_methods_declaration_with_access_list",
  "class_methods_declaration_or_empty", "class_declaration",
  "class_method_implementation", "class_methods_implementation",
  "class_methods_implementation_or_empty", "class_implementation",
  "method_call_noname_arg", "method_call_name_arg",
  "method_call_noname_args", "method_call_name_args", "method_call_args",
  "expr_list", "array_elems_or_empty", "func_arg", "func_args",
  "func_args_or_empty", "func_header", "func_declaration",
  "func_implementation", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    44,    61,
     283,   284,   285,   286,    60,    62,   287,   288,    45,    43,
      42,    47,    37,    33,   289,   290,   291,    46,   292,    91,
      41,    93,    59,   123,   125,    40,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    65,    65,    66,    67,    67,    67,    67,
      68,    69,    70,    70,    70,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    74,    74,    75,    75,    76,    76,
      76,    77,    78,    78,    79,    80,    80,    80,    81,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      87,    87,    88,    88,    88,    88,    89,    90,    90,    91,
      92,    92,    92,    93,    93,    94,    94,    94,    94,    95,
      96,    96,    97,    97,    98,    99,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   110,   111
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     0,     3,     2,     2,     1,     1,     1,
       1,     1,     3,     5,     7,     5,     5,     3,     6,    10,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     2,     3,     3,     3,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     5,     4,     4,
       3,     4,     3,     5,     3,     1,     1,     3,     1,     1,
       1,     3,     1,     2,     2,     1,     1,     2,     2,     3,
       4,     6,     6,     8,     1,     2,     1,     2,     2,     1,
       1,     0,     7,     7,     5,     5,     2,     1,     2,     2,
       1,     1,     2,     1,     0,     7,     5,     6,     4,     2,
       1,     2,     1,     0,     4,     2,     3,     1,     2,     1,
       2,     2,     1,     1,     3,     1,     0,     2,     4,     1,
       3,     1,     0,     5,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    35,    36,    37,    38,    39,
      40,     7,     9,     0,    33,    34,     0,    32,     6,     4,
       5,     0,     2,     3,    30,   123,   114,    31,     8,     1,
       0,     0,   144,    13,   145,     0,     0,     0,   120,   122,
       0,    78,    79,    80,     0,     0,     0,   114,     0,   107,
     110,   111,   113,     0,    76,     0,    75,   142,    62,    63,
      65,    64,    66,    61,     0,     0,     0,     0,     0,     0,
       0,    21,     0,    12,     0,    11,    20,    18,    17,    19,
       0,    34,     0,     0,     0,     0,   119,   121,   124,    88,
       0,     0,    82,    85,    86,     0,   114,   109,     0,   106,
     108,   112,   118,     0,     0,     0,     0,   139,   141,     0,
       0,     0,     0,    15,     0,     0,    59,    58,    57,     0,
       0,    10,    22,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,     0,    84,    83,    89,    87,   114,
       0,   116,    77,    74,    73,   137,     0,   143,    72,   133,
       0,     0,     0,    14,     0,    60,     0,     0,    27,   136,
      47,    56,    55,    54,    53,    49,    51,    52,    50,    42,
      41,    43,    45,    46,    70,     0,     0,     0,    81,     0,
     117,     0,   140,     0,    71,     0,     0,    68,     0,   127,
     132,     0,     0,     0,   135,     0,    69,   104,   105,   115,
     138,   134,    25,    23,   125,     0,   129,   131,   128,    67,
      26,     0,    48,   101,   101,     0,     0,   130,     0,    28,
       0,    96,    99,   100,   102,   103,    24,   126,   136,     0,
       0,    94,    98,    97,     0,     0,     0,     0,    95,     0,
       0,    90,     0,    29,     0,     0,    91,     0,     0,     0,
      92,     0,    93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    73,    74,    75,    76,    77,    78,
      79,   114,    81,    82,    17,    83,    18,    55,    56,    46,
      92,    93,    94,    95,    47,   231,   241,   242,   232,   233,
     234,    48,    49,    50,    51,    52,    53,    19,    38,    39,
      40,    20,   199,   216,   200,   217,   201,   204,   205,   107,
     108,   109,    21,    22,    23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -92
static const yytype_int16 yypact[] =
{
     176,   -29,    40,    43,    53,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   176,    72,   -92,    22,    73,   -92,   -92,   -92,
     -92,     6,   -92,   -92,   -92,    51,   231,   -92,   -92,   -92,
      84,    42,   -92,   236,   -92,    54,    80,    87,   -92,    51,
      82,   -92,   -92,   -92,     2,   129,    51,    60,    92,   -92,
      51,   -92,    83,   139,   124,   -14,   -92,   486,   -92,   -92,
     -92,   -92,   -92,    27,    99,   100,    31,   174,   174,   174,
     174,   -92,   174,   236,   106,   -92,   -92,   -92,   -92,   -92,
     174,   -92,   153,   284,   486,   486,   -92,   -92,   -92,   -92,
     156,   486,   -92,   486,   -92,   -11,   289,    51,   154,   -92,
     -92,   -92,   -92,   163,    84,   123,   168,   -92,   155,   135,
     108,   174,   174,   -92,   174,   314,    56,    56,    56,   263,
     385,   -92,   -92,   451,    -7,   166,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   178,
     174,   -92,   137,   138,   141,   486,   -92,   -92,   -92,    60,
     177,   -92,   -92,   -92,   -92,   157,   486,   -92,   -92,   451,
      21,   407,   429,   -92,   -38,   -92,   174,   204,   -92,   174,
     451,   483,   501,   517,   517,   522,   522,   522,   522,   101,
     101,    56,    56,    56,   -92,   362,   200,   202,   -92,   198,
     -92,   165,   -92,   174,   -92,   236,   236,   -92,   174,   206,
     162,   169,   338,   173,   199,   172,   -92,   175,   179,   -92,
     -92,   451,   -92,   216,   451,   180,   -92,   206,   -92,   -92,
     -92,   -20,   -92,   182,   182,   236,   174,   -92,   185,   -92,
     486,   224,   182,   -92,   -92,   -92,   -92,   451,   174,    68,
     190,   -92,   224,   -92,   197,   203,   245,   209,   -92,   213,
     217,   -92,   486,   -92,   258,    70,   -92,   221,   260,   223,
     -92,   268,   -92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   265,   -92,   -92,   -92,   -92,   -57,     9,   -92,   -92,
     -92,     0,    41,     3,   -92,    -4,   -92,   -92,   186,   -40,
     -91,   187,   188,   -92,   184,    49,    44,   -92,   -92,   -92,
      58,    -8,   -45,   264,   257,   -92,   -46,   -92,   290,   -92,
     -92,   -92,   130,   114,   -92,   -92,   -92,   225,    96,   181,
     -92,   -92,   -92,   -92,   -92
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      14,    98,   146,    16,    91,   100,    41,    42,    43,   228,
       1,    24,    14,   197,   104,    16,   121,    37,   198,    41,
      42,    43,   166,     4,     5,     6,     7,     8,     9,    10,
      34,    37,   229,    80,    58,    59,    60,    61,    62,    63,
     105,    15,   167,   147,    14,   168,    86,    90,    25,   193,
     150,    26,   100,    15,   146,    91,    89,    14,    32,    33,
     106,    27,   115,   116,   117,   118,   119,    24,   120,    67,
      68,   194,    29,    80,    69,    30,   123,    41,    42,    43,
      70,    31,   110,   113,    14,    14,    72,   142,   143,    35,
      36,    14,    54,    14,    90,    88,    90,    57,    35,    36,
      41,    42,    43,   189,   139,   140,   159,   161,   162,    84,
     123,    58,    59,    60,    61,    62,    63,   245,   246,   257,
     258,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    85,   185,    96,   212,   213,
      33,   136,   137,   138,    99,    14,    67,    68,    90,   139,
     140,    69,   102,   103,   111,   112,    14,    70,   158,   106,
     122,   124,   202,    72,   144,   159,   152,   151,   236,    58,
      59,    60,    61,    62,    63,   154,   155,    58,    59,    60,
      61,    62,    63,   156,     1,   157,   184,   186,   187,   211,
     190,     2,     3,   188,   214,    80,    80,     4,     5,     6,
       7,     8,     9,    10,    67,    68,   191,   203,   207,    69,
     208,   209,    67,    68,   215,    70,   210,    69,   198,   169,
     219,    72,   237,    70,   221,    80,   222,   193,   225,    72,
      14,   223,   240,   239,   159,   224,   226,   230,   238,    58,
      59,    60,    61,    62,    63,    64,   247,    65,    41,    42,
      43,   249,    14,   251,   250,   255,    66,     4,     5,     6,
       7,     8,     9,    10,   252,   253,   256,   254,   260,    35,
      36,   164,   259,   261,    67,    68,   262,    28,   145,    69,
     149,   243,   235,   148,    44,    70,   248,    45,    71,    33,
     153,    72,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    41,    42,    43,   101,
      97,   139,   140,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    35,    36,    87,
     218,   227,   139,   140,   244,   160,   141,   192,     0,     0,
       0,     0,    44,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,   139,   140,     0,     0,   163,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     0,     0,     0,     0,     0,   139,   140,     0,     0,
     220,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     0,     0,     0,     0,     0,
     139,   140,     0,   206,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,   139,   140,   165,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,     0,     0,   139,   140,   195,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,     0,     0,     0,     0,     0,   139,   140,   196,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     1,     0,     0,     0,     0,   139,
     140,     0,     0,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,     0,
       0,   139,   140,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,   139,
     140,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
     139,   140
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    47,    93,     0,    44,    50,    17,    18,    19,    29,
       8,    40,    12,    51,    28,    12,    73,    25,    56,    17,
      18,    19,    29,    21,    22,    23,    24,    25,    26,    27,
      21,    39,    52,    33,     3,     4,     5,     6,     7,     8,
      54,     0,    49,    54,    44,    52,    37,    44,     8,    28,
      96,     8,    97,    12,   145,    95,    54,    57,    52,    53,
      57,     8,    66,    67,    68,    69,    70,    40,    72,    38,
      39,    50,     0,    73,    43,    53,    80,    17,    18,    19,
      49,     8,    55,    52,    84,    85,    55,    84,    85,    38,
      39,    91,     8,    93,    91,    13,    93,    55,    38,    39,
      17,    18,    19,   149,    48,    49,   110,   111,   112,    55,
     114,     3,     4,     5,     6,     7,     8,    49,    50,    49,
      50,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,    55,   140,     8,   195,   196,
      53,    40,    41,    42,    52,   145,    38,    39,   145,    48,
      49,    43,    13,    29,    55,    55,   156,    49,    50,   156,
      54,     8,   166,    55,     8,   169,     3,    13,   225,     3,
       4,     5,     6,     7,     8,    52,     8,     3,     4,     5,
       6,     7,     8,    28,     8,    50,     8,    50,    50,   193,
      13,    15,    16,    52,   198,   195,   196,    21,    22,    23,
      24,    25,    26,    27,    38,    39,    49,     3,     8,    43,
       8,    13,    38,    39,     8,    49,    51,    43,    56,    53,
      51,    55,   226,    49,    51,   225,    54,    28,    12,    55,
     230,    56,     8,   230,   238,    56,    56,    55,    53,     3,
       4,     5,     6,     7,     8,     9,    56,    11,    17,    18,
      19,    54,   252,     8,    51,   252,    20,    21,    22,    23,
      24,    25,    26,    27,    55,    52,     8,    50,     8,    38,
      39,     8,    51,    50,    38,    39,     8,    12,    91,    43,
      96,   232,   224,    95,    53,    49,   242,    56,    52,    53,
     104,    55,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    17,    18,    19,    52,
      46,    48,    49,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    38,    39,    39,
     200,   217,    48,    49,   238,   110,    52,   156,    -1,    -1,
      -1,    -1,    53,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    -1,    52,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      52,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    -1,    51,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     8,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      38,    39,    40,    41,    42,    48,    49,    -1,    -1,    -1,
      48,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    15,    16,    21,    22,    23,    24,    25,    26,
      27,    58,    59,    60,    68,    69,    70,    71,    73,    94,
      98,   109,   110,   111,    40,     8,     8,     8,    58,     0,
      53,     8,    52,    53,    64,    38,    39,    88,    95,    96,
      97,    17,    18,    19,    53,    56,    76,    81,    88,    89,
      90,    91,    92,    93,     8,    74,    75,    55,     3,     4,
       5,     6,     7,     8,     9,    11,    20,    38,    39,    43,
      49,    52,    55,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    72,    55,    55,    64,    95,    13,    54,
      70,    76,    77,    78,    79,    80,     8,    90,    93,    52,
      89,    91,    13,    29,    28,    54,    70,   106,   107,   108,
      55,    55,    55,    52,    68,    72,    72,    72,    72,    72,
      72,    63,    54,    72,     8,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    48,
      49,    52,    70,    70,     8,    78,    77,    54,    79,    81,
      93,    13,     3,    75,    52,     8,    28,    50,    50,    72,
     104,    72,    72,    52,     8,    50,    29,    49,    52,    53,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,     8,    72,    50,    50,    52,    93,
      13,    49,   106,    28,    50,    50,    50,    51,    56,    99,
     101,   103,    72,     3,   104,   105,    51,     8,     8,    13,
      51,    72,    63,    63,    72,     8,   100,   102,    99,    51,
      52,    51,    54,    56,    56,    12,    56,   100,    29,    52,
      55,    82,    85,    86,    87,    87,    63,    72,    53,    70,
       8,    83,    84,    82,   105,    49,    50,    56,    83,    54,
      51,     8,    55,    52,    50,    70,     8,    49,    50,    51,
       8,    50,     8
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
/* Line 1792 of yacc.c  */
#line 185 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode((yyvsp[(1) - (1)].func_declaration_st), NULL, NULL, NULL, NULL);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 186 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, (yyvsp[(1) - (1)].func_impl_st), NULL, NULL, NULL);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 187 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, (yyvsp[(1) - (1)].class_declaration_st), NULL, NULL);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 188 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, NULL, (yyvsp[(1) - (1)].class_impl_st), NULL);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 189 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, NULL, NULL, (yyvsp[(1) - (1)]._enum_decl));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 192 "objectivec.y"
    { (yyval.program_st) = createProgram((yyvsp[(1) - (1)].extern_code_st));}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 193 "objectivec.y"
    { (yyval.program_st) = addToProgram((yyvsp[(1) - (2)].program_st), (yyvsp[(2) - (2)].extern_code_st));}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 196 "objectivec.y"
    { root = (yyvsp[(1) - (1)].program_st); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 198 "objectivec.y"
    { (yyval._stmt_list) = AppendStatementToList((yyvsp[(1) - (2)]._stmt_list), (yyvsp[(2) - (2)]._stmt)); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 199 "objectivec.y"
    { (yyval._stmt_list) = CreateStatementList((yyvsp[(1) - (1)]._stmt)); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 202 "objectivec.y"
    { (yyval._stmt_list) = (yyvsp[(1) - (1)]._stmt_list); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 203 "objectivec.y"
    { (yyval._stmt_list) = NULL; }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 206 "objectivec.y"
    { (yyval._stmt) = CreateReturnStatement((yyvsp[(2) - (3)]._expr));}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 207 "objectivec.y"
    { (yyval._stmt) = CreateReturnStatement(NULL);}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 208 "objectivec.y"
    { (yyval._stmt) = CreateExpressionStatement((yyvsp[(1) - (2)]._expr)); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 209 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(1) - (1)]._stmt); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 210 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(1) - (1)]._stmt); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 211 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(1) - (1)]._stmt); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 212 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(1) - (1)]._stmt); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 213 "objectivec.y"
    { }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 216 "objectivec.y"
    { (yyval._stmt) = CreateCompoundStatement((yyvsp[(2) - (3)]._stmt_list)); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 219 "objectivec.y"
    { (yyval._stmt) = CreateIfStatement((yyvsp[(3) - (5)]._expr), (yyvsp[(5) - (5)]._stmt), NULL); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 220 "objectivec.y"
    { (yyval._stmt) = CreateIfStatement((yyvsp[(3) - (7)]._expr), (yyvsp[(5) - (7)]._stmt), (yyvsp[(7) - (7)]._stmt)); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 223 "objectivec.y"
    { (yyval._stmt) = CreateWhileStatement((yyvsp[(3) - (5)]._expr), (yyvsp[(5) - (5)]._stmt)); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 226 "objectivec.y"
    { (yyval._stmt) = CreateVarDeclWithInit((yyvsp[(1) - (5)]._type), (yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)]._expr)); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 227 "objectivec.y"
    { (yyval._stmt) = CreateVarDeclWithInit((yyvsp[(1) - (3)]._type), (yyvsp[(2) - (3)].id), NULL); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 228 "objectivec.y"
    { (yyval._stmt) = CreateArrayDeclWithInit((yyvsp[(1) - (6)]._type), (yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].int_const), NULL);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 229 "objectivec.y"
    { (yyval._stmt) = CreateArrayDeclWithInit((yyvsp[(1) - (10)]._type), (yyvsp[(2) - (10)].id), (yyvsp[(4) - (10)].int_const), (yyvsp[(8) - (10)].expr_list_st));}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 232 "objectivec.y"
    { (yyval._type) = createType(TYPE_POINTER, NULL, createType(TYPE_CUSTOM, (yyvsp[(1) - (2)].id), NULL)); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 236 "objectivec.y"
    { (yyval._type) = createType(TYPE_CUSTOM, (yyvsp[(2) - (2)].id), NULL); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 239 "objectivec.y"
    { (yyval._type) = (yyvsp[(1) - (1)]._type); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 240 "objectivec.y"
    { (yyval._type) = (yyvsp[(1) - (1)]._type); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 241 "objectivec.y"
    { (yyval._type) = (yyvsp[(1) - (1)]._type); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 244 "objectivec.y"
    { (yyval._type) = createType(TYPE_INT, NULL, NULL);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 245 "objectivec.y"
    { (yyval._type) = createType(TYPE_FLOAT, NULL, NULL);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 246 "objectivec.y"
    { (yyval._type) = createType(TYPE_STRING, NULL, NULL);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 247 "objectivec.y"
    { (yyval._type) = createType(TYPE_CHAR, NULL, NULL);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 248 "objectivec.y"
    { (yyval._type) = createType(TYPE_BOOL, NULL, NULL);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 249 "objectivec.y"
    { (yyval._type) = createType(TYPE_VOID, NULL, NULL);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 252 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_ADD, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 253 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_SUB, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 254 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_MUL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 255 "objectivec.y"
    { (yyval._expr) = CreateMulFromPointer( (yyvsp[(1) - (2)]._type), (yyvsp[(2) - (2)]._expr)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 256 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_DIV, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 257 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_MOD, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 258 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_ASSIGN, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 259 "objectivec.y"
    { (yyval._expr) = CreateArrayInitExpr((yyvsp[(1) - (5)]._expr), (yyvsp[(4) - (5)].expr_list_st));}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 260 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LESS, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 261 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LESS_OR_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 262 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_GREATER, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 263 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_GREATER_OR_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 264 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 265 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_NOT_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 266 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_AND, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 267 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_OR, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 268 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LOGICAL_NOT, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 269 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_UPLUS, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 270 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_UMINUS, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 271 "objectivec.y"
    { (yyval._expr) = (yyvsp[(2) - (3)]._expr); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 272 "objectivec.y"
    { (yyval._expr) = CreateIDExpression((yyvsp[(1) - (1)].id)); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 273 "objectivec.y"
    { (yyval._expr) = CreateIntValueExpression((yyvsp[(1) - (1)].int_const)); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 274 "objectivec.y"
    { (yyval._expr) = CreateFloatValueExpression((yyvsp[(1) - (1)].float_const)); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 275 "objectivec.y"
    { (yyval._expr) = CreateBoolValueExpression((yyvsp[(1) - (1)].bool_const)); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 276 "objectivec.y"
    { (yyval._expr) = CreateCharValueExpression((yyvsp[(1) - (1)].char_const)); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 277 "objectivec.y"
    { (yyval._expr) = CreateStringValueExpression((yyvsp[(1) - (1)].string_const)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 278 "objectivec.y"
    { (yyval._expr) = createMethodCall((yyvsp[(2) - (5)]._expr), (yyvsp[(3) - (5)].id), (yyvsp[(4) - (5)].method_call_arg_list_st)); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 279 "objectivec.y"
    { (yyval._expr) = createMethodCall((yyvsp[(2) - (4)]._expr), (yyvsp[(3) - (4)].id), NULL); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 280 "objectivec.y"
    { (yyval._expr) = createArrayElemCall((yyvsp[(1) - (4)]._expr), (yyvsp[(3) - (4)]._expr)); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 281 "objectivec.y"
    { (yyval._expr) = createInvariantCall((yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)].id)); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 282 "objectivec.y"
    { (yyval._expr) = createFuncCall((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].expr_list_st)); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 283 "objectivec.y"
    { (yyval._expr) = createFuncCall((yyvsp[(1) - (3)].id), NULL); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 286 "objectivec.y"
    { (yyval._enum_decl) = CreateEnumDeclaration((yyvsp[(1) - (5)]._type)->name, (yyvsp[(3) - (5)]._enum_list)); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 289 "objectivec.y"
    { (yyval._enum_list) = AppendEnumeratorToList((yyvsp[(1) - (3)]._enum_list), (yyvsp[(3) - (3)]._enumerator)); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 290 "objectivec.y"
    { (yyval._enum_list) = CreateEnumeratorList((yyvsp[(1) - (1)]._enumerator)); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 293 "objectivec.y"
    { (yyval._enumerator) = CreateEnumerator((yyvsp[(1) - (1)].id)); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 294 "objectivec.y"
    { (yyval._enumerator) = CreateEnumeratorWithVal((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].int_const)); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 320 "objectivec.y"
    { (yyval.field_access_en) = A_PUBLIC; }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 321 "objectivec.y"
    { (yyval.field_access_en) = A_PROTECTED; }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 322 "objectivec.y"
    { (yyval.field_access_en) = A_PRIVATE; }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 325 "objectivec.y"
    { (yyval.class_invariant_declaration_st) = createClassInvariantDeclaration((yyvsp[(1) - (3)]._type), (yyvsp[(2) - (3)].id)); }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 328 "objectivec.y"
    { (yyval.class_invariants_declaration_list_st) = createClassInvariantsDeclarationList((yyvsp[(1) - (1)].class_invariant_declaration_st)); }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 329 "objectivec.y"
    { (yyval.class_invariants_declaration_list_st) = addToClassInvariantsDeclarationList((yyvsp[(1) - (2)].class_invariants_declaration_list_st), (yyvsp[(2) - (2)].class_invariant_declaration_st)); }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 333 "objectivec.y"
    { (yyval.class_invariants_declaration_block_st) = createClassInvariantsDeclarationBlock((yyvsp[(1) - (2)].field_access_en), (yyvsp[(2) - (2)].class_invariants_declaration_list_st)); }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 337 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = createClassInvariantsDeclarationBlockList( createClassInvariantsDeclarationBlock(A_NOT_SET, (yyvsp[(1) - (1)].class_invariants_declaration_list_st))); }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 338 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = createClassInvariantsDeclarationBlockList((yyvsp[(1) - (1)].class_invariants_declaration_block_st)); }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 339 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = addToClassInvariantsDeclarationBlockList((yyvsp[(1) - (2)].class_invariants_declaration_block_list_st), (yyvsp[(2) - (2)].class_invariants_declaration_block_st)); }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 342 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = NULL; }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 343 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = (yyvsp[(2) - (3)].class_invariants_declaration_block_list_st); }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 346 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration( NULL, (yyvsp[(2) - (4)]._type), (yyvsp[(4) - (4)].id) ); }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 347 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration( NULL, createType(TYPE_ARRAY, NULL, (yyvsp[(2) - (6)]._type)), (yyvsp[(6) - (6)].id) ); }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 354 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration((yyvsp[(1) - (6)].id), (yyvsp[(4) - (6)]._type), (yyvsp[(6) - (6)].id)); }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 355 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration((yyvsp[(1) - (8)].id), createType(TYPE_ARRAY, NULL, (yyvsp[(4) - (8)]._type)), (yyvsp[(8) - (8)].id)); }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 358 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = createClassMethodParamDeclarationList((yyvsp[(1) - (1)].class_method_param_declaration_st)); }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 359 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToClassMethodParamDeclarationList((yyvsp[(1) - (2)].class_method_param_declaration_list_st), (yyvsp[(2) - (2)].class_method_param_declaration_st)); }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 362 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = createClassMethodParamDeclarationList((yyvsp[(1) - (1)].class_method_param_declaration_st)); }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 363 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToClassMethodParamDeclarationList((yyvsp[(1) - (2)].class_method_param_declaration_list_st), (yyvsp[(2) - (2)].class_method_param_declaration_st)); }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 367 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToFrontClassMethodParamDeclarationList((yyvsp[(2) - (2)].class_method_param_declaration_list_st), (yyvsp[(1) - (2)].class_method_param_declaration_st)); }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 368 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = (yyvsp[(1) - (1)].class_method_param_declaration_list_st); }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 372 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = (yyvsp[(1) - (1)].class_method_param_declaration_list_st); }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 373 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = NULL; }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 384 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, (yyvsp[(3) - (7)]._type), (yyvsp[(5) - (7)].id), (yyvsp[(7) - (7)].class_method_param_declaration_list_st)); }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 385 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, (yyvsp[(3) - (7)]._type), (yyvsp[(5) - (7)].id), (yyvsp[(7) - (7)].class_method_param_declaration_list_st)); }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 386 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, (yyvsp[(3) - (5)]._type), (yyvsp[(5) - (5)].id), NULL); }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 387 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, (yyvsp[(3) - (5)]._type), (yyvsp[(5) - (5)].id), NULL); }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 390 "objectivec.y"
    { (yyval.class_method_declaration_st) = (yyvsp[(1) - (2)].class_method_declaration_st); }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 395 "objectivec.y"
    { (yyval.class_methods_declaration_list_st) = createMethodsDeclarationList( (yyvsp[(1) - (1)].class_method_declaration_st)); }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 396 "objectivec.y"
    { (yyval.class_methods_declaration_list_st) = addToMethodsDeclarationList( (yyvsp[(1) - (2)].class_methods_declaration_list_st), (yyvsp[(2) - (2)].class_method_declaration_st)); }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 401 "objectivec.y"
    { (yyval.class_methods_declaration_block_st) = createClassMethodsDeclarationBlock( (yyvsp[(1) - (2)].field_access_en), (yyvsp[(2) - (2)].class_methods_declaration_list_st)); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 405 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = createClassMethodsDeclarationBlockList(createClassMethodsDeclarationBlock(A_NOT_SET, (yyvsp[(1) - (1)].class_methods_declaration_list_st))); }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 406 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = createClassMethodsDeclarationBlockList( (yyvsp[(1) - (1)].class_methods_declaration_block_st)); }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 407 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = addToClassMethodsDeclarationBlockList( (yyvsp[(1) - (2)].class_methods_declaration_block_list_st), (yyvsp[(2) - (2)].class_methods_declaration_block_st)); }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 410 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = (yyvsp[(1) - (1)].class_methods_declaration_block_list_st); }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 411 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = NULL; }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 414 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (7)].id), (yyvsp[(4) - (7)].id), (yyvsp[(5) - (7)].class_invariants_declaration_block_list_st), (yyvsp[(6) - (7)].class_methods_declaration_block_list_st)); }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 415 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (5)].id), NULL, (yyvsp[(3) - (5)].class_invariants_declaration_block_list_st), (yyvsp[(4) - (5)].class_methods_declaration_block_list_st)); }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 416 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].id), NULL, (yyvsp[(5) - (6)].class_methods_declaration_block_list_st)); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 417 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (4)].id), NULL, NULL, (yyvsp[(3) - (4)].class_methods_declaration_block_list_st)); }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 421 "objectivec.y"
    { (yyval.class_method_impl_st) = createClassMethodImpl((yyvsp[(1) - (2)].class_method_declaration_st), (yyvsp[(2) - (2)]._stmt)); }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 425 "objectivec.y"
    { (yyval.class_method_impl_list_st) = createClassMethodImplList((yyvsp[(1) - (1)].class_method_impl_st)); }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 426 "objectivec.y"
    { (yyval.class_method_impl_list_st) = addToClassMethodImplList((yyvsp[(1) - (2)].class_method_impl_list_st), (yyvsp[(2) - (2)].class_method_impl_st)); }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 429 "objectivec.y"
    { (yyval.class_method_impl_list_st) = (yyvsp[(1) - (1)].class_method_impl_list_st); }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 430 "objectivec.y"
    {(yyval.class_method_impl_list_st) = NULL; }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 433 "objectivec.y"
    { (yyval.class_impl_st) = createClassImpl((yyvsp[(2) - (4)].id), (yyvsp[(3) - (4)].class_method_impl_list_st)); }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 438 "objectivec.y"
    { (yyval.method_call_arg_st) = createMethodCallArg(NULL, (yyvsp[(2) - (2)]._expr)); }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 441 "objectivec.y"
    { (yyval.method_call_arg_st) = createMethodCallArg((yyvsp[(1) - (3)].id),(yyvsp[(3) - (3)]._expr)); }
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 444 "objectivec.y"
    { (yyval.method_call_arg_list_st) = createMethodCallArgList((yyvsp[(1) - (1)].method_call_arg_st)); }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 445 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToMethodCallArgList((yyvsp[(1) - (2)].method_call_arg_list_st), (yyvsp[(2) - (2)].method_call_arg_st)); }
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 448 "objectivec.y"
    { (yyval.method_call_arg_list_st) = createMethodCallArgList((yyvsp[(1) - (1)].method_call_arg_st)); }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 449 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToMethodCallArgList((yyvsp[(1) - (2)].method_call_arg_list_st), (yyvsp[(2) - (2)].method_call_arg_st)); }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 453 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToFrontMethodCallArgList((yyvsp[(2) - (2)].method_call_arg_list_st), (yyvsp[(1) - (2)].method_call_arg_st)); }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 454 "objectivec.y"
    { (yyval.method_call_arg_list_st) = (yyvsp[(1) - (1)].method_call_arg_list_st); }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 459 "objectivec.y"
    { (yyval.expr_list_st) = createExprList((yyvsp[(1) - (1)]._expr)); }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 460 "objectivec.y"
    { (yyval.expr_list_st) = addToExprList((yyvsp[(1) - (3)].expr_list_st), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 465 "objectivec.y"
    { (yyval.expr_list_st) = (yyvsp[(1) - (1)].expr_list_st); }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 466 "objectivec.y"
    { (yyval.expr_list_st) = NULL; }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 471 "objectivec.y"
    { (yyval.func_arg_st) =  createFuncArg((yyvsp[(1) - (2)]._type), (yyvsp[(2) - (2)].id)); }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 472 "objectivec.y"
    { (yyval.func_arg_st) =  createFuncArg(createType(TYPE_ARRAY, NULL, (yyvsp[(1) - (4)]._type)), (yyvsp[(2) - (4)].id)); }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 475 "objectivec.y"
    { (yyval.func_arg_list_st) = createFuncArgList((yyvsp[(1) - (1)].func_arg_st)); }
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 476 "objectivec.y"
    { (yyval.func_arg_list_st) = addToFuncArgList((yyvsp[(1) - (3)].func_arg_list_st), (yyvsp[(3) - (3)].func_arg_st)); }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 479 "objectivec.y"
    { (yyval.func_arg_list_st) = (yyvsp[(1) - (1)].func_arg_list_st); }
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 480 "objectivec.y"
    { (yyval.func_arg_list_st) = NULL; }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 483 "objectivec.y"
    { (yyval.func_declaration_st) = createFuncDeclaration((yyvsp[(1) - (5)]._type), (yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].func_arg_list_st)); }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 486 "objectivec.y"
    { (yyval.func_declaration_st) = (yyvsp[(1) - (2)].func_declaration_st); }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 489 "objectivec.y"
    { (yyval.func_impl_st) = createFuncImpl((yyvsp[(1) - (2)].func_declaration_st), (yyvsp[(2) - (2)]._stmt)); }
    break;


/* Line 1792 of yacc.c  */
#line 2632 "objectivec.tab.c"
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


/* Line 2055 of yacc.c  */
#line 492 "objectivec.y"

