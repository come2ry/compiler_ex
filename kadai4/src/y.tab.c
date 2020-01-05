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
    0,    5,    1,    2,    2,    6,    6,    7,    3,    3,
    9,    9,   10,   14,   11,   12,   13,   15,   15,    4,
    4,    4,    4,    4,    4,    4,    4,    4,   16,   17,
   27,   27,   18,   28,   19,   20,   29,   22,   23,   24,
   21,   26,   26,   26,   26,   26,   26,   25,   25,   25,
   25,   25,   30,   30,   30,   31,   31,   31,   32,   33,
   33,    8,    8,
};
static const short yylen[] = {                            2,
    5,    0,    4,    0,    2,    3,    1,    2,    2,    0,
    3,    1,    1,    0,    5,    1,    2,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    3,    5,
    2,    0,    4,    0,    9,    1,    1,    3,    4,    4,
    0,    3,    3,    3,    3,    3,    3,    1,    2,    2,
    3,    3,    1,    3,    3,    1,    1,    3,    1,    1,
    3,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    7,   62,
    0,    1,    0,    2,    0,   12,   13,    0,    0,   16,
    0,    0,    0,    6,   63,   14,    0,    0,    0,    0,
    0,    0,    0,    3,   20,   21,   22,   23,   24,   25,
   26,   27,   28,   36,   11,    0,   19,    0,   34,    0,
    0,    0,   57,   59,    0,    0,    0,   53,   56,    0,
    0,    0,    0,    0,   15,   38,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   17,   18,    0,   58,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   54,
   55,   39,   33,   40,    0,    0,   30,    0,   31,    0,
    0,   35,
};
static const short yydgoto[] = {                          2,
    6,    7,   14,   34,   22,    8,    9,   11,   15,   16,
   17,   21,   65,   46,   48,   35,   36,   37,   38,   39,
   40,   41,   42,   43,   55,   56,  107,   68,   44,   57,
   58,   59,    0,
};
static const short yysindex[] = {                      -262,
 -271,    0, -258, -218, -240, -245, -204, -220,    0,    0,
 -184,    0, -183,    0, -174,    0,    0, -218, -159,    0,
 -135, -163, -204,    0,    0,    0, -163, -152, -168, -121,
 -168, -105, -112,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -218,    0, -257,    0, -223,
 -223, -168,    0,    0,  -17,  -85, -146,    0,    0, -109,
  -74, -168, -168, -163,    0,    0, -163, -104, -146, -146,
 -267, -223, -223, -168, -168, -168, -168, -168, -168, -163,
 -223, -223,  -95, -163, -150, -117,    0,    0, -168,    0,
 -146, -146, -117, -117, -117, -117, -117, -117,  -63,    0,
    0,    0,    0,    0, -192, -163,    0, -168,    0, -186,
 -163,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0, -216,    0,    0, -198,    0,    0,    0,
  -86,    0,    0,    0,    0,    0,    0, -256,    0,    0,
    0,  -88, -181,    0,    0,    0, -246,    0,    0,    0,
    0,    0, -241,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -172,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -141,    0,    0,    0,
    0,    0,    0,  -83,    0,    0, -246,    0, -114,  -87,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -226,
    0,    0,    0, -226,    0, -139,    0,    0,    0,    0,
  -60,  -33, -248, -161, -156, -110, -107,  -89, -224,    0,
    0,    0,    0,    0,    0, -226,    0,    0,    0,    0,
 -226,    0,
};
static const short yygindex[] = {                         0,
    0,  160,    0,  -27,    0,    0,  189,    0,    0,  187,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -50,  180,    0,    0,    0,  -29,
   94,    0,    0,
};
#define YYTABLESIZE 265
static const short yytable[] = {                         47,
    5,   71,   66,    1,    5,   72,   73,    5,    5,   42,
    5,   85,   86,   41,    5,    5,   90,   37,   37,   42,
   69,   70,    3,   93,   94,   95,   96,   97,   98,    4,
   67,    5,   41,   41,    5,   32,   87,    5,  105,   88,
    4,   41,   91,   92,    4,   12,   37,    4,    4,   37,
    4,    5,   99,   10,    4,    4,  103,  110,   10,   52,
   13,   41,   10,   32,   41,   10,   32,   18,   10,   53,
   54,  111,   10,   10,    4,    9,  108,    4,  109,    9,
   72,   73,    9,  112,    4,    9,   72,   73,    4,    9,
    9,    4,   10,   27,    4,   10,   43,   28,    4,    4,
   29,   45,   19,   30,   50,   51,   43,   31,   32,    9,
   20,   45,    9,   23,   52,    4,   48,   48,   48,   29,
   29,    4,   72,   73,   53,   54,   48,   48,   81,   82,
   33,   48,   48,  104,   25,   48,   48,   48,   48,   48,
   48,   49,   48,   49,   49,   49,   48,   44,   29,   48,
   47,   29,   26,   49,   49,   72,   73,   44,   49,   49,
   47,   60,   49,   49,   49,   49,   49,   49,   46,   49,
   50,   50,   50,   49,  100,  101,   49,   62,   46,   63,
   50,   50,   80,   84,   83,   50,   50,   89,  102,   50,
   50,   50,   50,   50,   50,  106,   50,   51,   51,   51,
   50,    8,   41,   50,   41,   64,   24,   51,   51,   45,
   61,    0,   51,   51,    0,    0,   51,   51,   51,   51,
   51,   51,    0,   51,   52,   52,   52,   51,    0,    0,
   51,    0,    0,    0,   52,   52,    0,    0,    0,   52,
   52,    0,    0,   52,   52,   52,   52,   52,   52,    0,
   52,    0,    0,    0,   52,   72,   73,   52,    0,   74,
   75,   76,   77,   78,   79,
};
static const short yycheck[] = {                         27,
  257,   52,  260,  266,  261,  273,  274,  264,  265,  258,
  267,   62,   63,  260,  271,  272,  284,  259,  260,  268,
   50,   51,  294,   74,   75,   76,   77,   78,   79,  288,
  288,  288,  259,  260,  291,  260,   64,  294,   89,   67,
  257,  288,   72,   73,  261,  291,  288,  264,  265,  291,
  267,  270,   80,  294,  271,  272,   84,  108,  257,  283,
  265,  288,  261,  288,  291,  264,  291,  288,  267,  293,
  294,  258,  271,  272,  291,  257,  269,  294,  106,  261,
  273,  274,  264,  111,  257,  267,  273,  274,  261,  271,
  272,  264,  291,  257,  267,  294,  258,  261,  271,  272,
  264,  258,  287,  267,  273,  274,  268,  271,  272,  291,
  294,  268,  294,  288,  283,  288,  258,  259,  260,  259,
  260,  294,  273,  274,  293,  294,  268,  269,  275,  276,
  294,  273,  274,  284,  294,  277,  278,  279,  280,  281,
  282,  294,  284,  258,  259,  260,  288,  258,  288,  291,
  258,  291,  288,  268,  269,  273,  274,  268,  273,  274,
  268,  283,  277,  278,  279,  280,  281,  282,  258,  284,
  258,  259,  260,  288,   81,   82,  291,  283,  268,  292,
  268,  269,  268,  258,  294,  273,  274,  292,  284,  277,
  278,  279,  280,  281,  282,  259,  284,  258,  259,  260,
  288,  288,  291,  291,  288,   46,   18,  268,  269,   23,
   31,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,
  291,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,
  274,   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,
  284,   -1,   -1,   -1,  288,  273,  274,  291,   -1,  277,
  278,  279,  280,  281,  282,
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
"$$1 :",
"outblock : var_decl_part subprog_decl_part $$1 statement",
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
"$$2 :",
"proc_decl : PROCEDURE proc_name SEMICOLON $$2 inblock",
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
#line 274 "parser.y"
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
case 1:
#line 43 "parser.y"
	{
			/* printf("[program end.]\n");*/
			/* // print_all();*/
			/* displayLlvmfundecl(declhd);*/
		}
break;
case 2:
#line 52 "parser.y"
	{
			insertDecl("main", 0, NULL);
			Factor temp_f = {CONSTANT, NULL, 0};
			factorpush(temp_f);
			insertCode(Alloca);
			insertCode(Store);
        }
break;
case 14:
#line 91 "parser.y"
	{
			flag = LOCAL_VAR;
		}
break;
case 15:
#line 95 "parser.y"
	{
			printf("[proc_decl]\n");
			delete();
			flag = GLOBAL_VAR;
		}
break;
case 16:
#line 104 "parser.y"
	{
			insert(yystack.l_mark[0].ident, PROC_NAME);
			insertDecl(yystack.l_mark[0].ident, 0, NULL);
		}
break;
case 29:
#line 133 "parser.y"
	{
			printf("[assignment_statement %s %d]\n", yystack.l_mark[-2].ident, flag);
			Factor f = generateFactor(yystack.l_mark[-2].ident);
			factorpush(f);
			insertCode(Store);
		}
break;
case 34:
#line 156 "parser.y"
	{
			printf("[for_statement %s %d]\n", yystack.l_mark[0].ident, flag);
			lookup(yystack.l_mark[0].ident);
		}
break;
case 37:
#line 168 "parser.y"
	{
			printf("[proc_call_name %s %d]\n", yystack.l_mark[0].ident, flag);
			lookup(yystack.l_mark[0].ident);
		}
break;
case 39:
#line 180 "parser.y"
	{
			printf("[read_statement %s %d]\n", yystack.l_mark[-1].ident, flag);
			lookup(yystack.l_mark[-1].ident);
		}
break;
case 50:
#line 207 "parser.y"
	{
			Factor f = factorpop();
			f.val = -f.val;
			factorpush(f);
		}
break;
case 51:
#line 213 "parser.y"
	{
			insertCode(Add);
        }
break;
case 52:
#line 217 "parser.y"
	{
			insertCode(Sub);
        }
break;
case 57:
#line 232 "parser.y"
	{
			Factor f = {CONSTANT, NULL, yystack.l_mark[0].num};
			factorpush(f);
		}
break;
case 59:
#line 241 "parser.y"
	{
			printf("[var_name %s %d]\n", yystack.l_mark[0].ident, flag);

			Factor f = generateFactor(yystack.l_mark[0].ident);
			factorpush(f);
			insertCode(Load);
		}
break;
case 62:
#line 257 "parser.y"
	{
			insert(yystack.l_mark[0].ident, flag);
			if (flag == LOCAL_VAR) {
				insert_code(Alloca);
			};
		}
break;
case 63:
#line 264 "parser.y"
	{
			insert(yystack.l_mark[0].ident, flag);
			if (flag == LOCAL_VAR) {
				insert_code(Alloca);
			};
		}
break;
#line 707 "y.tab.c"
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
