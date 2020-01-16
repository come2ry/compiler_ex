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

Scope flag = GLOBAL_VAR;
char *fname = "result.ll";
FILE *fp;

#line 23 "parser.y"
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
#line 51 "y.tab.c"

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
   28,   18,   30,   29,   29,   19,   31,   20,   21,   32,
   23,   24,   25,   22,   27,   27,   27,   27,   27,   27,
   26,   26,   26,   26,   26,   33,   33,   33,   34,   34,
   34,   35,    9,    9,
};
static const short yylen[] = {                            2,
    0,    6,    0,    4,    0,    2,    3,    1,    2,    2,
    0,    3,    1,    1,    0,    5,    1,    2,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    0,    6,    0,    3,    0,    4,    0,    9,    1,    1,
    3,    4,    4,    0,    3,    3,    3,    3,    3,    3,
    1,    2,    2,    3,    3,    1,    3,    3,    1,    1,
    3,    1,    1,    3,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
   63,    0,    2,    0,    3,    0,   13,   14,    0,    0,
   17,    0,    0,    0,    7,   64,   15,    0,    0,    0,
    0,    0,    0,    0,    4,   21,   22,   23,   24,   25,
   26,   27,   28,   29,   39,   12,    0,   20,    0,   37,
    0,    0,    0,   60,   62,    0,   31,    0,   56,   59,
    0,    0,    0,    0,    0,   16,   41,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   18,   19,    0,
   61,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   57,   58,   42,   36,   43,    0,    0,    0,   32,    0,
    0,    0,    0,   34,   38,
};
static const short yydgoto[] = {                          1,
    2,    7,    8,   15,   35,   23,    9,   10,   12,   16,
   17,   18,   22,   66,   47,   49,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   56,   57,   81,  109,  110,
   69,   45,   58,   59,   60,
};
static const short yysindex[] = {                         0,
    0, -251, -277, -256, -229, -236, -225, -187, -208,    0,
    0, -200,    0, -188,    0, -180,    0,    0, -229, -183,
    0, -165, -143, -187,    0,    0,    0, -143, -168,  -25,
 -151,  -25, -144, -147,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -229,    0, -253,    0,
 -233, -233,  -25,    0,    0,   -1,    0, -266,    0,    0,
 -148, -111,  -25,  -25, -143,    0,    0, -143, -142, -266,
 -266, -177, -233, -233,  -25,  -25,  -25,  -25,  -25,  -25,
 -110, -233, -233, -120, -143, -174, -136,    0,    0,  -25,
    0, -266, -266, -136, -136, -136, -136, -136, -136, -143,
    0,    0,    0,    0,    0, -210,    0,  -25,    0,  -94,
 -252, -143, -143,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -190,    0,    0, -178,    0,    0,
    0, -121,    0,    0,    0,    0,    0,    0, -218,    0,
    0,    0, -123, -169,    0,    0,    0, -244,    0,    0,
    0,    0,    0, -257,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -152,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -125,    0,    0,
    0,    0,    0,    0, -119,    0,    0, -244,    0,  -98,
  -71,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -255,    0, -246,    0,    0,    0,
    0,  -44,  -17, -250, -206, -203, -141, -128, -127, -255,
    0,    0,    0,    0,    0,    0, -240,    0,    0,    0,
    0, -255, -255,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  125,    0,  -28,    0,    0,  154,    0,    0,
  150,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -52,  145,    0,    0,    0,
    0,    0,   17,  -53,    0,
};
#define YYTABLESIZE 281
static const short yytable[] = {                         48,
   72,   40,   40,   44,   44,  113,   67,   45,   82,   83,
   86,   87,   30,   30,    3,   44,    4,   45,   33,   35,
   73,   74,   94,   95,   96,   97,   98,   99,  101,  102,
   40,    5,   44,   40,   68,   44,   88,  106,    6,   89,
    6,   30,    6,   44,   30,    6,    6,   35,    6,   53,
   35,   46,    6,    6,   48,  111,  104,   11,  108,   54,
   55,   46,   73,   74,   48,   13,    5,   70,   71,    6,
    5,  107,    6,    5,    5,    6,    5,   14,   11,   19,
    5,    5,   11,  114,  115,   11,   20,   10,   11,   92,
   93,   10,   11,   11,   10,   73,   74,   10,   73,   74,
    5,   10,   10,    5,    5,   21,   91,   24,    5,  105,
   26,    5,   11,   28,    5,   11,   47,   29,    5,    5,
   30,   10,   27,   31,   10,   50,   47,   32,   33,   50,
   49,   61,   51,   51,   51,    5,   73,   74,   63,   50,
   49,    5,   51,   51,   64,   84,   85,   51,   51,   90,
   34,   51,   51,   51,   51,   51,   51,  100,   51,   52,
   52,   52,   51,  103,  112,   51,    9,   44,   44,   52,
   52,   65,   25,   46,   52,   52,   62,    0,   52,   52,
   52,   52,   52,   52,    0,   52,   53,   53,   53,   52,
    0,    0,   52,    0,    0,    0,   53,   53,    0,    0,
    0,   53,   53,    0,    0,   53,   53,   53,   53,   53,
   53,    0,   53,   54,   54,   54,   53,    0,    0,   53,
    0,    0,    0,   54,   54,    0,    0,    0,   54,   54,
    0,    0,   54,   54,   54,   54,   54,   54,    0,   54,
   55,   55,   55,   54,    0,    0,   54,   51,   52,    0,
   55,   55,    0,    0,    0,   55,   55,   53,    0,   55,
   55,   55,   55,   55,   55,    0,   55,   54,   55,    0,
   55,   73,   74,   55,    0,   75,   76,   77,   78,   79,
   80,
};
static const short yycheck[] = {                         28,
   53,  259,  260,  259,  260,  258,  260,  258,  275,  276,
   63,   64,  259,  260,  266,  260,  294,  268,  259,  260,
  273,  274,   75,   76,   77,   78,   79,   80,   82,   83,
  288,  288,  288,  291,  288,  291,   65,   90,  257,   68,
  270,  288,  261,  288,  291,  264,  265,  288,  267,  283,
  291,  258,  271,  272,  258,  108,   85,  294,  269,  293,
  294,  268,  273,  274,  268,  291,  257,   51,   52,  288,
  261,  100,  291,  264,  265,  294,  267,  265,  257,  288,
  271,  272,  261,  112,  113,  264,  287,  257,  267,   73,
   74,  261,  271,  272,  264,  273,  274,  267,  273,  274,
  291,  271,  272,  294,  257,  294,  284,  288,  261,  284,
  294,  264,  291,  257,  267,  294,  258,  261,  271,  272,
  264,  291,  288,  267,  294,  294,  268,  271,  272,  258,
  258,  283,  258,  259,  260,  288,  273,  274,  283,  268,
  268,  294,  268,  269,  292,  294,  258,  273,  274,  292,
  294,  277,  278,  279,  280,  281,  282,  268,  284,  258,
  259,  260,  288,  284,  259,  291,  288,  291,  288,  268,
  269,   47,   19,   24,  273,  274,   32,   -1,  277,  278,
  279,  280,  281,  282,   -1,  284,  258,  259,  260,  288,
   -1,   -1,  291,   -1,   -1,   -1,  268,  269,   -1,   -1,
   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,  281,
  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,
   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
  258,  259,  260,  288,   -1,   -1,  291,  273,  274,   -1,
  268,  269,   -1,   -1,   -1,  273,  274,  283,   -1,  277,
  278,  279,  280,  281,  282,   -1,  284,  293,  294,   -1,
  288,  273,  274,  291,   -1,  277,  278,  279,  280,  281,
  282,
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
"if_statement : IF condition $$4 THEN statement else_statement",
"$$5 :",
"else_statement : $$5 ELSE statement",
"else_statement :",
"while_statement : WHILE condition DO statement",
"$$6 :",
"for_statement : FOR IDENT $$6 ASSIGN expression TO expression DO statement",
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
#line 349 "parser.y"
void yyerror(char *s)
{
	fprintf(stderr, "%s in line %d: token '%s'\n", s, yylineno, yytext);
}
#line 386 "y.tab.c"

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
#line 47 "parser.y"
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
#line 57 "parser.y"
	{
			printf("[program end.]\n");
			print_all();
			displayLlvmfundecl(declhd);
		}
break;
case 3:
#line 66 "parser.y"
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
#line 78 "parser.y"
	{
			Factor f;
			f.type = CONSTANT;
			f.val = 0;
			factorpush(f);
			generateCode(Ret);
		}
break;
case 6:
#line 90 "parser.y"
	{
			displayGlobalVar();
		}
break;
case 15:
#line 120 "parser.y"
	{
			flag = LOCAL_VAR;
		}
break;
case 16:
#line 124 "parser.y"
	{
			/* printf("[proc_decl]\n");*/
			delete();
			flag = GLOBAL_VAR;
		}
break;
case 17:
#line 133 "parser.y"
	{
			insert(yystack.l_mark[0].ident, PROC_NAME);
			insertDecl(yystack.l_mark[0].ident, 0, NULL);
		}
break;
case 30:
#line 162 "parser.y"
	{
			/* printf("[assignment_statement %s %d]\n", $1, flag);*/

			factorpush(generateFactor(yystack.l_mark[-2].ident));
			generateCode(Store);
		}
break;
case 31:
#line 172 "parser.y"
	{
			generateCode(BrCond);
		}
break;
case 32:
#line 176 "parser.y"
	{
			generateCode(Label);
			backpatch();
		}
break;
case 33:
#line 183 "parser.y"
	{
			generateCode(BrCond);
			generateCode(Label);
		}
break;
case 37:
#line 197 "parser.y"
	{
			/* printf("[for_statement %s %d]\n", $2, flag);*/
			lookup(yystack.l_mark[0].ident);
		}
break;
case 40:
#line 209 "parser.y"
	{
			/* printf("[proc_call_name %s %d]\n", $1, flag);*/
			lookup(yystack.l_mark[0].ident);
		}
break;
case 42:
#line 221 "parser.y"
	{
			/* printf("[read_statement %s %d]\n", $3, flag);*/
			lookup(yystack.l_mark[-1].ident);
		}
break;
case 45:
#line 237 "parser.y"
	{
			generateIcmp(EQ);
        }
break;
case 46:
#line 241 "parser.y"
	{
			generateIcmp(NEQ);
		}
break;
case 47:
#line 245 "parser.y"
	{
			generateIcmp(LT);
		}
break;
case 48:
#line 249 "parser.y"
	{
			generateIcmp(LE);
		}
break;
case 49:
#line 253 "parser.y"
	{
			generateIcmp(GT);
		}
break;
case 50:
#line 257 "parser.y"
	{
			generateIcmp(GE);
		}
break;
case 53:
#line 266 "parser.y"
	{
			Factor f;
			f = factorpop();
			f.val = -f.val;
			factorpush(f);
		}
break;
case 54:
#line 273 "parser.y"
	{
			/* printf("[ex PLUS term]\n");*/
			generateCode(Add);
        }
break;
case 55:
#line 278 "parser.y"
	{
			/* printf("[ex Sub term]\n");*/
			generateCode(Sub);
        }
break;
case 57:
#line 288 "parser.y"
	{
			/* printf("[term Mult factor]\n");*/
			generateCode(Mult);
		}
break;
case 58:
#line 293 "parser.y"
	{
			/* printf("[term Div factor]\n");*/
			generateCode(Div);
		}
break;
case 60:
#line 302 "parser.y"
	{
			/* printf("[factor]\n");*/
			Factor f;
			f.type = CONSTANT;
			f.val = yystack.l_mark[0].num;
			factorpush(f);
		}
break;
case 62:
#line 314 "parser.y"
	{
			/* printf("[var_name %s %d]\n", $1, flag);*/

			Factor f = generateFactor(yystack.l_mark[0].ident);
			factorpush(f);
			generateCode(Load);
		}
break;
case 63:
#line 330 "parser.y"
	{
			/* printf("[id_list]\n");*/
			insert(yystack.l_mark[0].ident, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			}
		}
break;
case 64:
#line 338 "parser.y"
	{
			/* printf("[id_list]\n");*/
			insert(yystack.l_mark[0].ident, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			};
		}
break;
#line 826 "y.tab.c"
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
