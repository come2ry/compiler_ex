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
extern int yylineno;
extern char *yytext;

Scope flag = GLOBAL_VAR;

#line 17 "parser.y"
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
#line 45 "y.tab.c"

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
    0,    1,    2,    2,    5,    5,    6,    3,    3,    8,
    8,    9,   10,   11,   12,   13,   13,    4,    4,    4,
    4,    4,    4,    4,    4,    4,   23,   25,   14,   15,
   27,   27,   16,   28,   29,   17,   18,   31,   30,   20,
   21,   22,   19,   26,   26,   26,   26,   26,   26,   24,
   24,   24,   24,   24,   32,   32,   32,   33,   33,   33,
   34,   35,   35,    7,    7,
};
static const short yylen[] = {                            2,
    5,    3,    0,    2,    3,    1,    2,    2,    0,    3,
    1,    1,    4,    1,    2,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    0,    0,    5,    5,
    2,    0,    4,    0,    0,   10,    1,    0,    2,    3,
    4,    4,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    2,    3,    3,    1,    3,    3,    1,    1,    3,
    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   64,
    0,    1,    0,    0,    0,   11,   12,    0,    0,   14,
    0,    0,    0,    0,    0,    0,    0,    0,    2,   18,
   19,   20,   21,   22,   23,   24,   25,   26,   37,    0,
    5,   65,    0,   17,    0,   34,    0,    0,    0,   59,
   61,    0,    0,    0,   55,   58,    0,    0,    0,   27,
   39,   10,    0,   13,   40,    0,   35,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   28,   15,   16,    0,   60,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   56,   57,
   41,   33,   42,    0,    0,    0,   30,    0,    0,   31,
    0,    0,    0,   36,
};
static const short yydgoto[] = {                          2,
    6,    7,   14,   29,    8,    9,   11,   15,   16,   17,
   21,   64,   45,   30,   31,   32,   33,   34,   35,   36,
   37,   38,   85,   52,  104,   53,  107,   67,   88,   39,
   61,   54,   55,   56,    0,
};
static const short yysindex[] = {                      -265,
 -289,    0, -280, -250, -248, -251, -210, -219,    0,    0,
 -220,    0, -213, -163, -185,    0,    0, -250, -184,    0,
 -182, -163, -175, -197, -156, -197, -153, -154,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -210,
    0,    0, -250,    0, -236,    0, -176, -176, -197,    0,
    0,  -21, -115, -188,    0,    0, -122,  -82, -197,    0,
    0,    0, -163,    0,    0, -163,    0, -188, -188, -231,
 -176, -176, -197, -197, -197, -197, -197, -197, -163, -176,
 -176, -105, -163, -126,    0,    0,    0, -112,    0, -188,
 -188, -162, -162, -162, -162, -162, -162,  -74,    0,    0,
    0,    0,    0, -197, -197, -163,    0, -162,  -62,    0,
 -197, -194, -163,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -246,    0,    0, -201,    0,    0,    0,
  -90,    0,    0,  -92,    0,    0,    0, -255,    0,    0,
    0, -226,    0,    0,    0,    0,    0, -237,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -189,
    0,    0, -172,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -145,    0,    0,    0,    0,    0,    0,
    0,    0, -182,    0,    0, -226,    0, -118,  -91,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -139,    0,
    0,    0, -139,    0,    0,    0,    0,    0,    0,  -64,
  -37, -254, -221,  -93,  -87,  -84,  -66, -253,    0,    0,
    0,    0,    0,    0,    0, -139,    0, -134,    0,    0,
    0,    0, -139,    0,
};
static const short yygindex[] = {                         0,
    0,  158,    0,  -22,    0,  185,    0,    0,  166,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -46,    0,  182,    0,    0,    0,    0,
    0,    2,   64,    0,    0,
};
#define YYTABLESIZE 261
static const short yytable[] = {                         44,
    1,    4,   70,   44,    3,    4,   32,    4,    4,    4,
    3,    4,   84,   44,    3,    4,    4,    3,    3,    5,
    3,   38,   38,   65,    3,    3,   92,   93,   94,   95,
   96,   97,    4,   43,   32,    4,   45,   32,    4,   12,
   86,   71,   72,   87,    3,   10,   45,    3,   68,   69,
   38,   66,   89,   38,   13,    9,   98,  108,  109,    9,
  102,   43,    9,  113,  112,    9,   19,    8,   18,    9,
    9,    8,   90,   91,    8,   47,   48,    8,   71,   72,
   20,    8,    8,  110,    3,   49,   80,   81,    3,    9,
  114,    3,    9,   22,    3,   50,   51,   23,    3,    3,
   24,    8,   40,   25,    8,   43,   49,   26,   27,   42,
   71,   72,   50,   50,   50,    3,   50,   51,   46,   43,
   43,    3,   50,   50,   29,   29,   57,   50,   50,   59,
   28,   50,   50,   50,   50,   50,   50,   60,   50,   51,
   51,   51,   50,   99,  100,   50,   71,   72,   43,   51,
   51,   43,   79,   29,   51,   51,   29,  103,   51,   51,
   51,   51,   51,   51,   47,   51,   52,   52,   52,   51,
   46,   82,   51,   49,   47,   83,   52,   52,  101,  105,
   46,   52,   52,   49,  106,   52,   52,   52,   52,   52,
   52,   48,   52,   53,   53,   53,   52,    7,   43,   52,
   63,   48,   41,   53,   53,   62,  111,   58,   53,   53,
   71,   72,   53,   53,   53,   53,   53,   53,    0,   53,
   54,   54,   54,   53,    0,    0,   53,    0,    0,    0,
   54,   54,    0,    0,    0,   54,   54,    0,    0,   54,
   54,   54,   54,   54,   54,    0,   54,    0,    0,    0,
   54,   71,   72,   54,    0,   73,   74,   75,   76,   77,
   78,
};
static const short yycheck[] = {                         22,
  266,  257,   49,  258,  294,  261,  260,  288,  264,  265,
  257,  267,   59,  268,  261,  271,  272,  264,  265,  270,
  267,  259,  260,  260,  271,  272,   73,   74,   75,   76,
   77,   78,  288,  260,  288,  291,  258,  291,  294,  291,
   63,  273,  274,   66,  291,  294,  268,  294,   47,   48,
  288,  288,  284,  291,  265,  257,   79,  104,  105,  261,
   83,  288,  264,  258,  111,  267,  287,  257,  288,  271,
  272,  261,   71,   72,  264,  273,  274,  267,  273,  274,
  294,  271,  272,  106,  257,  283,  275,  276,  261,  291,
  113,  264,  294,  257,  267,  293,  294,  261,  271,  272,
  264,  291,  288,  267,  294,  288,  283,  271,  272,  294,
  273,  274,  258,  259,  260,  288,  293,  294,  294,  259,
  260,  294,  268,  269,  259,  260,  283,  273,  274,  283,
  294,  277,  278,  279,  280,  281,  282,  292,  284,  258,
  259,  260,  288,   80,   81,  291,  273,  274,  288,  268,
  269,  291,  268,  288,  273,  274,  291,  284,  277,  278,
  279,  280,  281,  282,  258,  284,  258,  259,  260,  288,
  258,  294,  291,  258,  268,  258,  268,  269,  284,  292,
  268,  273,  274,  268,  259,  277,  278,  279,  280,  281,
  282,  258,  284,  258,  259,  260,  288,  288,  291,  291,
   43,  268,   18,  268,  269,   40,  269,   26,  273,  274,
  273,  274,  277,  278,  279,  280,  281,  282,   -1,  284,
  258,  259,  260,  288,   -1,   -1,  291,   -1,   -1,   -1,
  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,  277,
  278,  279,  280,  281,  282,   -1,  284,   -1,   -1,   -1,
  288,  273,  274,  291,   -1,  277,  278,  279,  280,  281,
  282,
};
#define YYFINAL 2
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
"program : PROGRAM IDENT SEMICOLON outblock PERIOD",
"outblock : var_decl_part subprog_decl_part statement",
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
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
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
"$$1 :",
"$$2 :",
"assignment_statement : IDENT ASSIGN $$1 $$2 expression",
"if_statement : IF condition THEN statement else_statement",
"else_statement : ELSE statement",
"else_statement :",
"while_statement : WHILE condition DO statement",
"$$3 :",
"$$4 :",
"for_statement : FOR IDENT $$3 $$4 ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
"$$5 :",
"proc_call_name : IDENT $$5",
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
"arg_list : expression",
"arg_list : arg_list COMMA expression",
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
#line 194 "parser.y"
yyerror(char *s)
{
	fprintf(stderr, "%s in line %d: token '%s'\n", s, yylineno, yytext);
}
#line 377 "y.tab.c"

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
case 4:
#line 49 "parser.y"
	{flag = LOCAL_VAR;}
break;
case 13:
#line 76 "parser.y"
	{delete(LOCAL_VAR);}
break;
case 14:
#line 80 "parser.y"
	{insert(yystack.l_mark[0].ident, PROC_NAME);}
break;
case 27:
#line 105 "parser.y"
	{printf("assignment_statement %s %d\n", yystack.l_mark[-1].ident, flag);}
break;
case 28:
#line 105 "parser.y"
	{lookup(yystack.l_mark[-2].ident, flag);}
break;
case 34:
#line 122 "parser.y"
	{printf("for_statement %s %d\n", yystack.l_mark[0].ident, flag);}
break;
case 35:
#line 122 "parser.y"
	{lookup(yystack.l_mark[-1].ident, flag);}
break;
case 38:
#line 130 "parser.y"
	{printf("proc_call_name %s %d\n", yystack.l_mark[0].ident, flag);}
break;
case 39:
#line 130 "parser.y"
	{lookup(yystack.l_mark[-1].ident, flag);}
break;
case 40:
#line 134 "parser.y"
	{flag = GLOBAL_VAR; delete(LOCAL_VAR);}
break;
case 41:
#line 138 "parser.y"
	{printf("read_statement %s %d\n", yystack.l_mark[-1].ident, flag); lookup(yystack.l_mark[-1].ident, flag);}
break;
case 61:
#line 179 "parser.y"
	{printf("var_name %s %d\n", yystack.l_mark[0].ident, flag); lookup(yystack.l_mark[0].ident, flag);}
break;
case 64:
#line 188 "parser.y"
	{insert(yystack.l_mark[0].ident, flag);}
break;
case 65:
#line 189 "parser.y"
	{insert(yystack.l_mark[0].ident, flag);}
break;
#line 639 "y.tab.c"
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
