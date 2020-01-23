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
    1,    0,    5,    7,    2,    3,    3,    8,    8,    9,
    4,    4,   11,   11,   12,   16,   13,   14,   15,   17,
   17,    6,    6,    6,    6,    6,    6,    6,    6,    6,
   18,   29,   30,   32,   19,   33,   31,   31,   34,   35,
   36,   20,   37,   21,   22,   38,   24,   25,   26,   23,
   28,   28,   28,   28,   28,   28,   27,   27,   27,   27,
   27,   39,   39,   39,   40,   40,   40,   41,   10,   10,
};
static const short yylen[] = {                            2,
    0,    6,    0,    0,    5,    0,    2,    3,    1,    2,
    2,    0,    3,    1,    1,    0,    5,    1,    2,    3,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    0,    0,    0,    8,    0,    3,    0,    0,    0,
    0,    7,    0,    9,    1,    1,    3,    4,    4,    0,
    3,    3,    3,    3,    3,    3,    1,    2,    2,    3,
    3,    1,    3,    3,    1,    1,    3,    1,    1,    3,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    3,    0,    9,
   69,    0,    2,    0,    0,    0,    0,    4,    0,   14,
   15,    8,   70,   18,    0,    0,    0,   16,    0,    0,
    0,    0,   39,    0,    0,    5,   22,   23,   24,   25,
   26,   27,   28,   29,   30,   45,   13,    0,   21,    0,
   43,    0,    0,    0,   66,   68,    0,   32,    0,   62,
   65,    0,    0,    0,    0,    0,   17,   47,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   40,    0,    0,   19,   20,
    0,   67,    0,    0,    0,    0,    0,    0,    0,    0,
   33,   63,   64,   48,    0,   49,    0,    0,   41,    0,
   34,    0,    0,    0,   42,    0,   36,   35,   44,    0,
   37,
};
static const short yydgoto[] = {                          1,
    2,    7,    8,   18,   14,   36,   26,    9,   10,   12,
   19,   20,   21,   25,   67,   48,   50,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   57,   58,   82,  108,
  118,  114,  120,   63,  105,  112,   70,   46,   59,   60,
   61,
};
static const short yysindex[] = {                         0,
    0, -234, -238, -241, -202, -223, -214,    0, -208,    0,
    0, -199,    0, -183, -202, -210, -191,    0, -192,    0,
    0,    0,    0,    0, -179, -147, -183,    0, -147, -176,
 -167, -168,    0, -162, -181,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -202,    0, -247,
    0, -274, -274, -167,    0,    0,   -4,    0, -133,    0,
    0, -171, -167, -167, -167, -147,    0,    0, -147, -164,
 -133, -133, -140, -274, -274, -167, -167, -167, -167, -167,
 -167, -132, -274, -274, -145,    0, -136, -104,    0,    0,
 -167,    0, -133, -133, -104, -104, -104, -104, -104, -104,
    0,    0,    0,    0,  -96,    0, -259, -147,    0, -167,
    0, -147, -252,  -93,    0, -147,    0,    0,    0, -147,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -213,    0,    0,    0,    0,    0,
    0, -113,    0, -197, -222,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -109, -172,    0, -242,    0,
    0,    0,    0,    0, -257,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -159,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -128,    0,
    0,    0,    0,    0,    0, -100,    0,    0, -242,    0,
 -101,  -74,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -255,    0,    0,
    0,    0,  -47,  -20, -205, -203, -182, -103,  -97,  -94,
    0,    0,    0,    0,    0,    0,    0, -198,    0,    0,
    0, -198,    0, -187,    0, -198,    0,    0,    0, -198,
    0,
};
static const short yygindex[] = {                         0,
    0,    0,  141,    0,    0,  -29,    0,    0,  176,    0,
    0,  165,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -53,  130,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -45,  -67,
    0,
};
#define YYTABLESIZE 278
static const short yytable[] = {                         49,
   73,   46,   46,   31,   31,  116,   71,   72,   54,  110,
   87,   88,   68,   74,   75,  102,  103,   50,   55,   56,
   74,   75,   95,   96,   97,   98,   99,  100,   93,   94,
   46,    3,   31,   46,    7,   31,   89,  107,    7,   90,
   69,    7,    7,    6,    7,   50,    5,    6,    7,    7,
    6,    6,   51,    6,   52,    4,  113,    6,    6,   12,
   50,   50,   51,   12,   52,    7,   12,    6,    7,   12,
   11,    7,   38,   12,   12,   54,   13,    6,  111,   15,
    6,   17,  115,   23,   11,   54,  119,   16,   11,   50,
  121,   11,   50,   12,   11,   27,   12,    6,   11,   11,
   38,    6,   24,   38,    6,   52,   53,    6,   28,   29,
   65,    6,    6,   30,   62,   54,   31,   51,   11,   32,
   64,   11,   85,   33,   34,   55,   56,   91,    6,   57,
   57,   57,   74,   75,    6,  101,   74,   75,  104,   57,
   57,   83,   84,   92,   57,   57,   35,  106,   57,   57,
   57,   57,   57,   57,   53,   57,   58,   58,   58,   57,
   56,  109,   57,   55,   53,  117,   58,   58,   74,   75,
   56,   58,   58,   55,   10,   58,   58,   58,   58,   58,
   58,   50,   58,   59,   59,   59,   58,   50,   66,   58,
   22,   47,   86,   59,   59,    0,    0,    0,   59,   59,
    0,    0,   59,   59,   59,   59,   59,   59,    0,   59,
   60,   60,   60,   59,    0,    0,   59,    0,    0,    0,
   60,   60,    0,    0,    0,   60,   60,    0,    0,   60,
   60,   60,   60,   60,   60,    0,   60,   61,   61,   61,
   60,    0,    0,   60,    0,    0,    0,   61,   61,    0,
    0,    0,   61,   61,    0,    0,   61,   61,   61,   61,
   61,   61,    0,   61,    0,    0,    0,   61,   74,   75,
   61,    0,   76,   77,   78,   79,   80,   81,
};
static const short yycheck[] = {                         29,
   54,  259,  260,  259,  260,  258,   52,   53,  283,  269,
   64,   65,  260,  273,  274,   83,   84,  260,  293,  294,
  273,  274,   76,   77,   78,   79,   80,   81,   74,   75,
  288,  266,  288,  291,  257,  291,   66,   91,  261,   69,
  288,  264,  265,  257,  267,  288,  288,  261,  271,  272,
  264,  265,  258,  267,  258,  294,  110,  271,  272,  257,
  259,  260,  268,  261,  268,  288,  264,  270,  291,  267,
  294,  294,  260,  271,  272,  258,  291,  291,  108,  288,
  294,  265,  112,  294,  257,  268,  116,  287,  261,  288,
  120,  264,  291,  291,  267,  288,  294,  257,  271,  272,
  288,  261,  294,  291,  264,  273,  274,  267,  288,  257,
  292,  271,  272,  261,  283,  283,  264,  294,  291,  267,
  283,  294,  294,  271,  272,  293,  294,  292,  288,  258,
  259,  260,  273,  274,  294,  268,  273,  274,  284,  268,
  269,  275,  276,  284,  273,  274,  294,  284,  277,  278,
  279,  280,  281,  282,  258,  284,  258,  259,  260,  288,
  258,  258,  291,  258,  268,  259,  268,  269,  273,  274,
  268,  273,  274,  268,  288,  277,  278,  279,  280,  281,
  282,  291,  284,  258,  259,  260,  288,  288,   48,  291,
   15,   27,   63,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
  258,  259,  260,  288,   -1,   -1,  291,   -1,   -1,   -1,
  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,  277,
  278,  279,  280,  281,  282,   -1,  284,  258,  259,  260,
  288,   -1,   -1,  291,   -1,   -1,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,   -1,   -1,   -1,  288,  273,  274,
  291,   -1,  277,  278,  279,  280,  281,  282,
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
"$$3 :",
"outblock : var_decl_part $$2 subprog_decl_part $$3 statement",
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
"$$4 :",
"proc_decl : PROCEDURE proc_name SEMICOLON $$4 inblock",
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
"$$5 :",
"$$6 :",
"$$7 :",
"if_statement : IF condition $$5 THEN $$6 statement $$7 else_statement",
"$$8 :",
"else_statement : ELSE $$8 statement",
"else_statement :",
"$$9 :",
"$$10 :",
"$$11 :",
"while_statement : WHILE $$9 condition $$10 DO $$11 statement",
"$$12 :",
"for_statement : FOR IDENT $$12 ASSIGN expression TO expression DO statement",
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
#line 435 "parser.y"
void yyerror(char *s)
{
	fprintf(stderr, "%s in line %d: token '%s'\n", s, yylineno, yytext);
}
#line 396 "y.tab.c"

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
			fprintf(fp, "declare dso_local i32 @scanf(i8*, ...)\n");
    		fprintf(fp, "declare dso_local i32 @printf(i8*, ...)\n");
		}
break;
case 3:
#line 69 "parser.y"
	{
			displayGlobalVar();
		}
break;
case 4:
#line 73 "parser.y"
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
case 5:
#line 85 "parser.y"
	{
			Factor f;
			strcpy(f.vname, "I32");
			f.type = CONSTANT;
			f.val = 0;
			factorpush(f);
			generateCode(Ret);
		}
break;
case 16:
#line 125 "parser.y"
	{
			flag = LOCAL_VAR;
		}
break;
case 17:
#line 129 "parser.y"
	{
			/* printf("[proc_decl]\n");*/
			delete();
			flag = GLOBAL_VAR;

			Factor f;
			strcpy(f.vname, "VOID");
			factorpush(f);
			generateCode(Ret);
		}
break;
case 18:
#line 143 "parser.y"
	{
			insert(yystack.l_mark[0].ident, PROC_NAME);
			insertDecl(yystack.l_mark[0].ident, 0, NULL);
		}
break;
case 31:
#line 172 "parser.y"
	{
			/* printf("[assignment_statement %s %d]\n", $1, flag);*/

			factorpush(generateFactor(yystack.l_mark[-2].ident));
			generateCode(Store);
		}
break;
case 32:
#line 182 "parser.y"
	{
			
			generateCode(BrCond); /* Br1 arg1埋め*/
			LLVMcode *tmp = brpop();
			(tmp->args).brcond.arg2 = cntr; /* Br1 arg2即埋め*/
			brpush(tmp);
		}
break;
case 33:
#line 190 "parser.y"
	{
			generateCode(Label); /* 真ラベル作成*/
		}
break;
case 34:
#line 194 "parser.y"
	{
			generateCode(BrUncond); /* Bru2作成*/
		}
break;
case 35:
#line 198 "parser.y"
	{
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; /* Bru2 arg1埋め*/
			generateCode(Label); /* retラベル作成*/
		}
break;
case 36:
#line 207 "parser.y"
	{
			LLVMcode *tmp1 = brpop();
			LLVMcode *tmp2 = brpop();
			brpush(tmp1);
			(tmp2->args).brcond.arg3 = cntr; /* Br1 arg3埋め*/
			generateCode(Label); /* 偽ラベル作成*/
		}
break;
case 37:
#line 215 "parser.y"
	{
			generateCode(BrUncond);
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; /* Br3 arg1即埋め*/
		}
break;
case 38:
#line 221 "parser.y"
	{
			LLVMcode *tmp1 = brpop();
			LLVMcode *tmp2 = brpop();
			brpush(tmp1);
			(tmp2->args).brcond.arg3 = cntr; /* Br1 arg3埋め*/
		}
break;
case 39:
#line 231 "parser.y"
	{
			generateCode(BrUncond); /* Bru0作成*/
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; /* Bru0完成*/
			labelpush(cntr); /* WHILEのスタートラベルをpush*/
			generateCode(Label); /* WHILEのスタートラベル*/
		}
break;
case 40:
#line 239 "parser.y"
	{
			generateCode(BrCond); /* Br1作成*/
			LLVMcode *tmp = brpop();
			(tmp->args).brcond.arg2 = cntr; /* Br1 True時即埋め*/
			brpush(tmp); /* Br1 Fasle時 push*/
		}
break;
case 41:
#line 246 "parser.y"
	{
			generateCode(Label); /* 真ラベル作成*/
		}
break;
case 42:
#line 250 "parser.y"
	{
			generateCode(BrUncond); /* スタートに戻るためのBru1作成*/
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = labelpop(); /* WHILEのスタートラベルをpopしてBru1即埋め*/
			tmp = brpop();
			(tmp->args).brcond.arg3 = cntr; /* Br1 Fasle時popして偽ラベル埋める*/
			generateCode(Label); /* 偽ラベル作成*/
		}
break;
case 43:
#line 262 "parser.y"
	{
			/* printf("[for_statement %s %d]\n", $2, flag);*/
			lookup(yystack.l_mark[0].ident);
		}
break;
case 46:
#line 274 "parser.y"
	{
			/* printf("[proc_call_name %s %d]\n", $1, flag);*/
			/* lookup($1);*/
			Factor fname;
			fname.type = PROC_NAME;
			strcpy(fname.vname, yystack.l_mark[0].ident);
			fname.val = 0;
			Factor args[10] = {};
			generateCall(VOID, fname, args);
		}
break;
case 48:
#line 292 "parser.y"
	{
			/* %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* @x)*/
			/* lookup($3);*/
			Factor fname;
			fname.type = PROC_NAME;
			strcpy(fname.vname, "scanf");
			fname.val = 1;
			Factor f = generateFactor(yystack.l_mark[-1].ident);
			Factor args[10] = {f};
			generateCall(I32, fname, args);
		}
break;
case 49:
#line 307 "parser.y"
	{
			Factor fname;
			fname.type = PROC_NAME;
			strcpy(fname.vname, "printf");
			fname.val = 1;
			Factor f = factorpop();
			Factor args[10] = {f};
			generateCall(I32, fname, args);
		}
break;
case 51:
#line 324 "parser.y"
	{
			generateIcmp(EQUAL);
        }
break;
case 52:
#line 328 "parser.y"
	{
			generateIcmp(NE);
		}
break;
case 53:
#line 332 "parser.y"
	{
			generateIcmp(SLT);
		}
break;
case 54:
#line 336 "parser.y"
	{
			generateIcmp(SLE);
		}
break;
case 55:
#line 340 "parser.y"
	{
			generateIcmp(SGT);
		}
break;
case 56:
#line 344 "parser.y"
	{
			generateIcmp(SGE);
		}
break;
case 59:
#line 353 "parser.y"
	{
			Factor f;
			f = factorpop();
			f.val = -f.val;
			factorpush(f);
		}
break;
case 60:
#line 360 "parser.y"
	{
			/* printf("[ex PLUS term]\n");*/
			generateCode(Add);
        }
break;
case 61:
#line 365 "parser.y"
	{
			/* printf("[ex Sub term]\n");*/
			generateCode(Sub);
        }
break;
case 63:
#line 375 "parser.y"
	{
			/* printf("[term Mult factor]\n");*/
			generateCode(Mult);
		}
break;
case 64:
#line 380 "parser.y"
	{
			/* printf("[term Div factor]\n");*/
			generateCode(Div);
		}
break;
case 66:
#line 389 "parser.y"
	{
			Factor f;
			f.type = CONSTANT;
			f.val = yystack.l_mark[0].num;
			factorpush(f);
		}
break;
case 68:
#line 400 "parser.y"
	{
			/* printf("[var_name %s %d]\n", $1, flag);*/

			Factor f = generateFactor(yystack.l_mark[0].ident);
			factorpush(f);
			generateCode(Load);
		}
break;
case 69:
#line 416 "parser.y"
	{
			/* printf("[id_list]\n");*/
			insert(yystack.l_mark[0].ident, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			}
		}
break;
case 70:
#line 424 "parser.y"
	{
			/* printf("[id_list]\n");*/
			insert(yystack.l_mark[0].ident, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			}
		}
break;
#line 941 "y.tab.c"
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
