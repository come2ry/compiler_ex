#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
#include "symbol_table.h"
#include "code_generator.h"

extern int yylineno;
extern char *yytext;
extern int yylex(void);
void yyerror(char *s);
extern int cntr;

Scope flag = GLOBAL_VAR;
char *fname = "result.ll";
FILE *fp;

#line 24 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int num;
	char ident[MAXLENGTH+1];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 52 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SBEGIN 257
#define DO 258
#define ELSE 259
#define SEND 260
#define FOR 261
#define FORWARD 262
#define FUNCTION 263
#define IF 264
#define PROCEDURE 265
#define PROGRAM 266
#define READ 267
#define THEN 268
#define TO 269
#define VAR 270
#define WHILE 271
#define WRITE 272
#define PLUS 273
#define MINUS 274
#define MULT 275
#define DIV 276
#define EQ 277
#define NEQ 278
#define LE 279
#define LT 280
#define GE 281
#define GT 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define COMMA 287
#define SEMICOLON 288
#define COLON 289
#define INTERVAL 290
#define PERIOD 291
#define ASSIGN 292
#define NUMBER 293
#define IDENT 294
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    1,    0,    6,    2,    3,    3,    7,    7,    8,    4,
    4,   10,   10,   11,   15,   12,   13,   14,   16,   16,
    5,    5,    5,    5,    5,    5,    5,    5,    5,   17,
   28,   29,   18,   31,   30,   30,   32,   33,   34,   19,
   35,   20,   21,   36,   23,   24,   25,   22,   27,   27,
   27,   27,   27,   27,   26,   26,   26,   26,   26,   37,
   37,   37,   38,   38,   38,   39,    9,    9,
};
static const short yylen[] = {                            2,
    0,    6,    0,    4,    0,    2,    3,    1,    2,    2,
    0,    3,    1,    1,    0,    5,    1,    2,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    0,    0,    7,    0,    3,    0,    0,    0,    0,    7,
    0,    9,    1,    1,    3,    4,    4,    0,    3,    3,
    3,    3,    3,    3,    1,    2,    2,    3,    3,    1,
    3,    3,    1,    1,    3,    1,    1,    3,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
   67,    0,    2,    0,    3,    0,   13,   14,    0,    0,
   17,    0,    0,    0,    7,   68,   15,    0,    0,    0,
    0,   37,    0,    0,    4,   21,   22,   23,   24,   25,
   26,   27,   28,   29,   43,   12,    0,   20,    0,   41,
    0,    0,    0,   64,   66,    0,   31,    0,   60,   63,
    0,    0,    0,    0,    0,   16,   45,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   38,    0,    0,   18,   19,    0,
   65,    0,    0,    0,    0,    0,    0,    0,    0,   32,
   61,   62,   46,    0,   47,    0,    0,   39,    0,    0,
    0,    0,   33,    0,   40,    0,    0,   42,   35,
};
static const short yydgoto[] = {                          1,
    2,    7,    8,   15,   35,   23,    9,   10,   12,   16,
   17,   18,   22,   66,   47,   49,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   56,   57,   81,  107,  113,
  114,   62,  104,  111,   69,   45,   58,   59,   60,
};
static const short yysindex[] = {                         0,
    0, -234, -241, -227, -223, -229, -220, -185, -203,    0,
    0, -219,    0, -196,    0, -149,    0,    0, -223, -173,
    0, -148, -153, -185,    0,    0,    0, -153, -161, -158,
 -192,    0, -139, -147,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -223,    0, -247,    0,
 -274, -274, -158,    0,    0,   -7,    0, -199,    0,    0,
 -142, -158, -158, -158, -153,    0,    0, -153, -120, -199,
 -199, -211, -274, -274, -158, -158, -158, -158, -158, -158,
 -105, -274, -274,  -99,    0, -167, -107,    0,    0, -158,
    0, -199, -199, -107, -107, -107, -107, -107, -107,    0,
    0,    0,    0,  -79,    0, -259, -153,    0, -158,    0,
 -153, -252,    0,  -73,    0, -153, -153,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -213,    0,    0, -197,    0,    0,
    0,  -98,    0,    0,    0,    0,    0,    0, -222,    0,
    0,    0, -103, -171,    0,    0,    0, -242,    0,    0,
    0,    0,    0, -257,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -162,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -131,    0,    0,
    0,    0,    0,    0,  -95,    0,    0, -242,    0, -104,
  -77,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -255,    0,    0,    0,
    0,  -50,  -23, -176, -155, -146, -134, -100,  -97,    0,
    0,    0,    0,    0,    0,    0, -204,    0,    0, -129,
 -204,    0,    0,    0,    0, -204, -204,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  142,    0,  -28,    0,    0,  175,    0,    0,
  171,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -52,  136,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -44,  -66,    0,
};
#define YYTABLESIZE 275
static const short yytable[] = {                         48,
   72,   44,   44,   30,   30,  116,   70,   71,   53,  109,
   86,   87,   67,   73,   74,  101,  102,   48,   54,   55,
   73,   74,   94,   95,   96,   97,   98,   99,   92,   93,
   44,    3,   30,   44,    6,   30,   88,  106,    6,   89,
   68,    6,    6,    5,    6,   48,    6,    5,    6,    6,
    5,    5,    4,    5,   48,   48,  112,    5,    5,   11,
    5,   73,   74,   11,   11,    6,   11,   20,    6,   11,
   13,    6,   91,   11,   11,   82,   83,    5,  110,   14,
    5,   49,  115,   48,   19,   10,   48,  118,  119,   10,
   61,   49,   10,   11,    5,   10,   11,   21,    5,   10,
   10,    5,   50,   28,    5,   73,   74,   29,    5,    5,
   30,   52,   50,   31,   51,   52,  105,   32,   33,   10,
   26,   52,   10,   51,   53,    5,   55,   55,   55,   34,
   36,    5,   50,   51,   54,   55,   55,   55,   24,   27,
   34,   55,   55,   63,   64,   55,   55,   55,   55,   55,
   55,   84,   55,   56,   56,   56,   55,   54,   36,   55,
   53,   36,  100,   56,   56,   73,   74,   54,   56,   56,
   53,   90,   56,   56,   56,   56,   56,   56,  108,   56,
   57,   57,   57,   56,  103,  117,   56,   48,   65,    9,
   57,   57,   48,   25,   46,   57,   57,   85,    0,   57,
   57,   57,   57,   57,   57,    0,   57,   58,   58,   58,
   57,    0,    0,   57,    0,    0,    0,   58,   58,    0,
    0,    0,   58,   58,    0,    0,   58,   58,   58,   58,
   58,   58,    0,   58,   59,   59,   59,   58,    0,    0,
   58,    0,    0,    0,   59,   59,    0,    0,    0,   59,
   59,    0,    0,   59,   59,   59,   59,   59,   59,    0,
   59,    0,    0,    0,   59,   73,   74,   59,    0,   75,
   76,   77,   78,   79,   80,
};
static const short yycheck[] = {                         28,
   53,  259,  260,  259,  260,  258,   51,   52,  283,  269,
   63,   64,  260,  273,  274,   82,   83,  260,  293,  294,
  273,  274,   75,   76,   77,   78,   79,   80,   73,   74,
  288,  266,  288,  291,  257,  291,   65,   90,  261,   68,
  288,  264,  265,  257,  267,  288,  270,  261,  271,  272,
  264,  265,  294,  267,  259,  260,  109,  271,  272,  257,
  288,  273,  274,  261,  294,  288,  264,  287,  291,  267,
  291,  294,  284,  271,  272,  275,  276,  291,  107,  265,
  294,  258,  111,  288,  288,  257,  291,  116,  117,  261,
  283,  268,  264,  291,  257,  267,  294,  294,  261,  271,
  272,  264,  258,  257,  267,  273,  274,  261,  271,  272,
  264,  258,  268,  267,  273,  274,  284,  271,  272,  291,
  294,  268,  294,  258,  283,  288,  258,  259,  260,  259,
  260,  294,  294,  268,  293,  294,  268,  269,  288,  288,
  294,  273,  274,  283,  292,  277,  278,  279,  280,  281,
  282,  294,  284,  258,  259,  260,  288,  258,  288,  291,
  258,  291,  268,  268,  269,  273,  274,  268,  273,  274,
  268,  292,  277,  278,  279,  280,  281,  282,  258,  284,
  258,  259,  260,  288,  284,  259,  291,  291,   47,  288,
  268,  269,  288,   19,   24,  273,  274,   62,   -1,  277,
  278,  279,  280,  281,  282,   -1,  284,  258,  259,  260,
  288,   -1,   -1,  291,   -1,   -1,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,
  291,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,
  274,   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,
  284,   -1,   -1,   -1,  288,  273,  274,  291,   -1,  277,
  278,  279,  280,  281,  282,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SBEGIN","DO","ELSE","SEND","FOR",
"FORWARD","FUNCTION","IF","PROCEDURE","PROGRAM","READ","THEN","TO","VAR",
"WHILE","WRITE","PLUS","MINUS","MULT","DIV","EQ","NEQ","LE","LT","GE","GT",
"LPAREN","RPAREN","LBRACKET","RBRACKET","COMMA","SEMICOLON","COLON","INTERVAL",
"PERIOD","ASSIGN","NUMBER","IDENT",
};
static const char *yyrule[] = {
"$accept : program",
"$$1 :",
"program : $$1 PROGRAM IDENT SEMICOLON outblock PERIOD",
"$$2 :",
"outblock : var_decl_part subprog_decl_part $$2 statement",
"var_decl_part :",
"var_decl_part : var_decl_list SEMICOLON",
"var_decl_list : var_decl_list SEMICOLON var_decl",
"var_decl_list : var_decl",
"var_decl : VAR id_list",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_part :",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"$$3 :",
"proc_decl : PROCEDURE proc_name SEMICOLON $$3 inblock",
"proc_name : IDENT",
"inblock : var_decl_part statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"statement : if_statement",
"statement : while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"assignment_statement : IDENT ASSIGN expression",
"$$4 :",
"$$5 :",
"if_statement : IF condition $$4 THEN $$5 statement else_statement",
"$$6 :",
"else_statement : $$6 ELSE statement",
"else_statement :",
"$$7 :",
"$$8 :",
"$$9 :",
"while_statement : WHILE $$7 condition $$8 DO $$9 statement",
"$$10 :",
"for_statement : FOR IDENT $$10 ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN IDENT RPAREN",
"write_statement : WRITE LPAREN expression RPAREN",
"null_statement :",
"condition : expression EQ expression",
"condition : expression NEQ expression",
"condition : expression LT expression",
"condition : expression LE expression",
"condition : expression GT expression",
"condition : expression GE expression",
"expression : term",
"expression : PLUS term",
"expression : MINUS term",
"expression : expression PLUS term",
"expression : expression MINUS term",
"term : factor",
"term : term MULT factor",
"term : term DIV factor",
"factor : var_name",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"var_name : IDENT",
"id_list : IDENT",
"id_list : id_list COMMA IDENT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 381 "parser.y"
void yyerror(char *s)
{
	fprintf(stderr, "%s in line %d: token '%s'\n", s, yylineno, yytext);
}
#line 389 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 48 "parser.y"
	{
			fp = fopen(fname, "w");
			if (fp == NULL) {
				printf("ERROR cannot open\n");
				exit(1);
			}
			printf("[program start]\n");
			printf("------------------\n");
		}
break;
case 2:
#line 58 "parser.y"
	{
			printf("[program end.]\n");
			print_all();
			displayLlvmfundecl(declhd);
		}
break;
case 3:
#line 67 "parser.y"
	{
			/* printf("[outblock]\n");*/
			insertDecl("main", 0, NULL);
			init_fstack();
			Factor f;
			f.type = CONSTANT;
			f.val = 0;
			factorpush(f);
			generateCode(Alloca);
			generateCode(Store);
        }
break;
case 4:
#line 79 "parser.y"
	{
			Factor f;
			f.type = CONSTANT;
			f.val = 0;
			factorpush(f);
			generateCode(Ret);
		}
break;
case 6:
#line 91 "parser.y"
	{
			displayGlobalVar();
		}
break;
case 15:
#line 121 "parser.y"
	{
			flag = LOCAL_VAR;
		}
break;
case 16:
#line 125 "parser.y"
	{
			/* printf("[proc_decl]\n");*/
			delete();
			flag = GLOBAL_VAR;
		}
break;
case 17:
#line 134 "parser.y"
	{
			insert(yystack.l_mark[0].ident, PROC_NAME);
			insertDecl(yystack.l_mark[0].ident, 0, NULL);
		}
break;
case 30:
#line 163 "parser.y"
	{
			/* printf("[assignment_statement %s %d]\n", $1, flag);*/

			factorpush(generateFactor(yystack.l_mark[-2].ident));
			generateCode(Store);
		}
break;
case 31:
#line 173 "parser.y"
	{
			generateCode(BrCond);
		}
break;
case 32:
#line 177 "parser.y"
	{
			labelpush(cntr);
			generateCode(Label);
		}
break;
case 33:
#line 182 "parser.y"
	{
			generateCode(Label);
		}
break;
case 34:
#line 188 "parser.y"
	{
			generateCode(BrCond);
			generateCode(Label);
		}
break;
case 37:
#line 198 "parser.y"
	{
			generateCode(BrUncond); /* Bru0作成*/
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; /* Bru0完成*/
			labelpush(cntr); /* WHILEのスタートラベルをpush*/
			generateCode(Label); /* WHILEのスタートラベル*/
		}
break;
case 38:
#line 206 "parser.y"
	{
			generateCode(BrCond); /* Br1作成*/
			printf("%d\n", codetl->command);
			LLVMcode *tmp = brpop();
			(tmp->args).brcond.arg2 = cntr; /* Br1 True時即埋め*/
			brpush(tmp); /* Br1 Fasle時 push*/
		}
break;
case 39:
#line 214 "parser.y"
	{
			generateCode(Label); /* 真ラベル作成*/
		}
break;
case 40:
#line 218 "parser.y"
	{
			generateCode(BrUncond); /* スタートに戻るためのBru1作成*/
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = labelpop(); /* WHILEのスタートラベルをpopしてBru1即埋め*/
			tmp = brpop();
			(tmp->args).brcond.arg3 = cntr; /* Br1 Fasle時popして偽ラベル埋める*/
			generateCode(Label); /* 偽ラベル作成*/
		}
break;
case 41:
#line 230 "parser.y"
	{
			/* printf("[for_statement %s %d]\n", $2, flag);*/
			lookup(yystack.l_mark[0].ident);
		}
break;
case 44:
#line 242 "parser.y"
	{
			/* printf("[proc_call_name %s %d]\n", $1, flag);*/
			lookup(yystack.l_mark[0].ident);
		}
break;
case 46:
#line 254 "parser.y"
	{
			/* printf("[read_statement %s %d]\n", $3, flag);*/
			lookup(yystack.l_mark[-1].ident);
		}
break;
case 49:
#line 270 "parser.y"
	{
			generateIcmp(EQUAL);
        }
break;
case 50:
#line 274 "parser.y"
	{
			generateIcmp(NE);
		}
break;
case 51:
#line 278 "parser.y"
	{
			generateIcmp(SLT);
		}
break;
case 52:
#line 282 "parser.y"
	{
			generateIcmp(SLE);
		}
break;
case 53:
#line 286 "parser.y"
	{
			generateIcmp(SGT);
		}
break;
case 54:
#line 290 "parser.y"
	{
			generateIcmp(SGE);
		}
break;
case 57:
#line 299 "parser.y"
	{
			Factor f;
			f = factorpop();
			f.val = -f.val;
			factorpush(f);
		}
break;
case 58:
#line 306 "parser.y"
	{
			/* printf("[ex PLUS term]\n");*/
			generateCode(Add);
        }
break;
case 59:
#line 311 "parser.y"
	{
			/* printf("[ex Sub term]\n");*/
			generateCode(Sub);
        }
break;
case 61:
#line 321 "parser.y"
	{
			/* printf("[term Mult factor]\n");*/
			generateCode(Mult);
		}
break;
case 62:
#line 326 "parser.y"
	{
			/* printf("[term Div factor]\n");*/
			generateCode(Div);
		}
break;
case 64:
#line 335 "parser.y"
	{
			Factor f;
			f.type = CONSTANT;
			f.val = yystack.l_mark[0].num;
			factorpush(f);
		}
break;
case 66:
#line 346 "parser.y"
	{
			/* printf("[var_name %s %d]\n", $1, flag);*/

			Factor f = generateFactor(yystack.l_mark[0].ident);
			factorpush(f);
			generateCode(Load);
		}
break;
case 67:
#line 362 "parser.y"
	{
			/* printf("[id_list]\n");*/
			insert(yystack.l_mark[0].ident, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			}
		}
break;
case 68:
#line 370 "parser.y"
	{
			/* printf("[id_list]\n");*/
			insert(yystack.l_mark[0].ident, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			}
		}
break;
#line 871 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
