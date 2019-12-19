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

Scope flag = GLOBAL_VAR;

#line 19 "parser.y"
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
#line 47 "y.tab.c"

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
    2,    0,    1,    3,    3,    6,    6,    7,    4,    4,
    9,    9,   10,   11,   12,   13,   14,   14,    5,    5,
    5,    5,    5,    5,    5,    5,    5,   25,   15,   16,
   27,   27,   17,   28,   18,   19,   29,   21,   22,   23,
   20,   26,   26,   26,   26,   26,   26,   24,   24,   24,
   24,   24,   30,   30,   30,   31,   31,   31,   32,   33,
   33,    8,    8,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    2,    0,
    3,    1,    1,    4,    1,    2,    3,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    0,    4,    5,
    2,    0,    4,    0,    9,    1,    1,    3,    4,    4,
    0,    3,    3,    3,    3,    3,    3,    1,    2,    2,
    3,    3,    1,    3,    3,    1,    1,    3,    1,    1,
    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    1,    0,    0,    0,    0,    0,    7,
   62,    0,    2,    0,    0,    0,   12,   13,    0,    0,
   15,    0,    0,    0,    0,    0,    0,    0,    0,    3,
   19,   20,   21,   22,   23,   24,   25,   26,   27,   36,
    0,    6,   63,    0,   18,    0,   34,    0,    0,    0,
   57,   59,    0,    0,    0,   53,   56,    0,    0,    0,
   28,   11,    0,   14,   38,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   16,   17,    0,   58,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   54,   55,
   39,   33,   40,    0,    0,    0,   30,    0,   31,    0,
    0,   35,
};
static const short yydgoto[] = {                          2,
    7,    5,    8,   15,   30,    9,   10,   12,   16,   17,
   18,   22,   64,   46,   31,   32,   33,   34,   35,   36,
   37,   38,   39,   53,   85,   54,  107,   67,   40,   55,
   56,   57,    0,
};
static const short yysindex[] = {                      -259,
 -284,    0, -269,    0, -239, -244, -233, -201, -222,    0,
    0, -218,    0, -219, -249, -208,    0,    0, -239, -209,
    0, -181, -249, -189,  -46, -153,  -46, -140, -155,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -201,    0,    0, -239,    0, -251,    0, -277, -277,  -46,
    0,    0,  -22, -122, -262,    0,    0, -137, -110,  -46,
    0,    0, -249,    0,    0, -249, -121, -262, -262, -183,
 -277, -277,  -46,  -46,  -46,  -46,  -46,  -46, -249, -277,
 -277, -109, -249, -163,  -46,    0,    0,  -46,    0, -262,
 -262, -221, -221, -221, -221, -221, -221,  -81,    0,    0,
    0,    0,    0, -221,  -72, -249,    0,  -46,    0, -253,
 -249,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -210,    0,    0, -194,    0,    0,
    0, -104,    0,    0, -112,    0,    0,    0, -223,    0,
    0,    0, -214,    0,    0,    0,    0,    0, -256,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -185,    0,    0, -168,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -146,    0,    0,    0,    0,    0,
    0,    0, -208,    0,    0, -214,    0, -119,  -92,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -144,    0,
    0,    0, -144,    0,    0,    0,    0,    0,    0,  -65,
  -38, -166, -160, -139,  -94,  -88,  -85, -258,    0,    0,
    0,    0,    0, -135,    0, -144,    0,    0,    0,    0,
 -144,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  147,    0,  -23,    0,  179,    0,    0,  159,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -49,    0,  178,    0,    0,    0,   46,
   71,    0,    0,
};
#define YYTABLESIZE 260
static const short yytable[] = {                         45,
   70,   32,   37,   37,  111,   50,    1,   23,   65,    3,
   84,   24,   80,   81,   25,   51,   52,   26,    4,   71,
   72,   27,   28,   92,   93,   94,   95,   96,   97,   32,
    6,   37,   32,    5,   37,  104,   66,    5,  105,   86,
    5,    5,   87,    5,   29,   41,    4,    5,    5,   11,
    4,   71,   72,    4,    4,   98,    4,   13,  110,  102,
    4,    4,   10,   14,    5,   19,   10,    5,   20,   10,
    5,    9,   10,   41,   21,    9,   10,   10,    9,   41,
    4,    9,  109,    4,   43,    9,    9,  112,    4,   71,
   72,   42,    4,   68,   69,    4,   10,   43,    4,   10,
   89,   42,    4,    4,   47,    9,   44,   43,    9,   71,
   72,   48,   48,   48,   41,   41,   90,   91,   45,    4,
  103,   48,   48,   29,   29,    4,   48,   48,   45,   58,
   48,   48,   48,   48,   48,   48,   61,   48,   49,   49,
   49,   48,   60,   41,   48,   79,   41,   83,   49,   49,
   99,  100,   29,   49,   49,   29,   82,   49,   49,   49,
   49,   49,   49,   44,   49,   50,   50,   50,   49,   47,
   88,   49,   46,   44,  101,   50,   50,  106,   41,   47,
   50,   50,   46,    8,   50,   50,   50,   50,   50,   50,
   63,   50,   51,   51,   51,   50,  108,   42,   50,   62,
   71,   72,   51,   51,   59,    0,    0,   51,   51,    0,
    0,   51,   51,   51,   51,   51,   51,    0,   51,   52,
   52,   52,   51,    0,    0,   51,   48,   49,    0,   52,
   52,    0,    0,    0,   52,   52,   50,    0,   52,   52,
   52,   52,   52,   52,    0,   52,   51,   52,    0,   52,
   71,   72,   52,    0,   73,   74,   75,   76,   77,   78,
};
static const short yycheck[] = {                         23,
   50,  260,  259,  260,  258,  283,  266,  257,  260,  294,
   60,  261,  275,  276,  264,  293,  294,  267,  288,  273,
  274,  271,  272,   73,   74,   75,   76,   77,   78,  288,
  270,  288,  291,  257,  291,   85,  288,  261,   88,   63,
  264,  265,   66,  267,  294,  260,  257,  271,  272,  294,
  261,  273,  274,  264,  265,   79,  267,  291,  108,   83,
  271,  272,  257,  265,  288,  288,  261,  291,  287,  264,
  294,  257,  267,  288,  294,  261,  271,  272,  264,  288,
  291,  267,  106,  294,  294,  271,  272,  111,  257,  273,
  274,  258,  261,   48,   49,  264,  291,  258,  267,  294,
  284,  268,  271,  272,  294,  291,  288,  268,  294,  273,
  274,  258,  259,  260,  259,  260,   71,   72,  258,  288,
  284,  268,  269,  259,  260,  294,  273,  274,  268,  283,
  277,  278,  279,  280,  281,  282,  292,  284,  258,  259,
  260,  288,  283,  288,  291,  268,  291,  258,  268,  269,
   80,   81,  288,  273,  274,  291,  294,  277,  278,  279,
  280,  281,  282,  258,  284,  258,  259,  260,  288,  258,
  292,  291,  258,  268,  284,  268,  269,  259,  291,  268,
  273,  274,  268,  288,  277,  278,  279,  280,  281,  282,
   44,  284,  258,  259,  260,  288,  269,   19,  291,   41,
  273,  274,  268,  269,   27,   -1,   -1,  273,  274,   -1,
   -1,  277,  278,  279,  280,  281,  282,   -1,  284,  258,
  259,  260,  288,   -1,   -1,  291,  273,  274,   -1,  268,
  269,   -1,   -1,   -1,  273,  274,  283,   -1,  277,  278,
  279,  280,  281,  282,   -1,  284,  293,  294,   -1,  288,
  273,  274,  291,   -1,  277,  278,  279,  280,  281,  282,
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
"$$1 :",
"program : PROGRAM IDENT SEMICOLON $$1 outblock PERIOD",
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
"$$2 :",
"assignment_statement : IDENT ASSIGN $$2 expression",
"if_statement : IF condition THEN statement else_statement",
"else_statement : ELSE statement",
"else_statement :",
"while_statement : WHILE condition DO statement",
"$$3 :",
"for_statement : FOR IDENT $$3 ASSIGN expression TO expression DO statement",
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
#line 261 "parser.y"
yyerror(char *s)
{
	fprintf(stderr, "%s in line %d: token '%s'\n", s, yylineno, yytext);
}
#line 375 "y.tab.c"

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
#line 43 "parser.y"
	{
			init_fstack();
		}
break;
case 2:
#line 47 "parser.y"
	{
			printf("[program end.]\n");
			print_all();
		}
break;
case 5:
#line 60 "parser.y"
	{
			flag = LOCAL_VAR;
		}
break;
case 14:
#line 90 "parser.y"
	{
			printf("[proc_decl]\n");
			delete();
			flag = GLOBAL_VAR;
		}
break;
case 15:
#line 99 "parser.y"
	{
			insert(yystack.l_mark[0].ident, PROC_NAME);
		}
break;
case 28:
#line 127 "parser.y"
	{
			printf("[assignment_statement %s %d]\n", yystack.l_mark[-1].ident, flag);
			lookup(yystack.l_mark[-1].ident);
		}
break;
case 34:
#line 148 "parser.y"
	{
			printf("[for_statement %s %d]\n", yystack.l_mark[0].ident, flag);
			lookup(yystack.l_mark[0].ident);
		}
break;
case 37:
#line 160 "parser.y"
	{
			printf("[proc_call_name %s %d]\n", yystack.l_mark[0].ident, flag);
			lookup(yystack.l_mark[0].ident);
		}
break;
case 39:
#line 172 "parser.y"
	{
			printf("[read_statement %s %d]\n", yystack.l_mark[-1].ident, flag);
			lookup(yystack.l_mark[-1].ident);
		}
break;
case 49:
#line 198 "parser.y"
	{
			generateLlvm(Add);
        }
break;
case 50:
#line 202 "parser.y"
	{
			generateLlvm(Sub);
        }
break;
case 51:
#line 206 "parser.y"
	{
			generateLlvm(Add);
        }
break;
case 52:
#line 210 "parser.y"
	{
			generateLlvm(Sub);
        }
break;
case 59:
#line 230 "parser.y"
	{
			printf("[var_name %s %d]\n", yystack.l_mark[0].ident, flag);
			lookup(yystack.l_mark[0].ident);
		}
break;
case 62:
#line 243 "parser.y"
	{
			insert(yystack.l_mark[0].ident, flag);
			Factor arg, retval;
			retval.type = flag;
			strcpy(retval.vname, yystack.l_mark[0].ident);
			arg.type = flag;
			arg.val = 0;
			factorpush(arg);
			factorpush(retval);
		}
break;
case 63:
#line 254 "parser.y"
	{
			insert(yystack.l_mark[0].ident, flag);
		}
break;
#line 692 "y.tab.c"
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
