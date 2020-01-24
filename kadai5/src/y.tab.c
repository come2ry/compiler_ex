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
   36,   20,   37,   38,   39,   40,   21,   22,   41,   24,
   25,   26,   23,   28,   28,   28,   28,   28,   28,   27,
   27,   27,   27,   27,   42,   42,   42,   43,   43,   43,
   44,   10,   10,
};
static const short yylen[] = {                            2,
    0,    6,    0,    0,    5,    0,    2,    3,    1,    2,
    2,    0,    3,    1,    1,    0,    5,    1,    2,    3,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    0,    0,    0,    8,    0,    3,    0,    0,    0,
    0,    7,    0,    0,    0,    0,   12,    1,    1,    3,
    4,    4,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    2,    3,    3,    1,    3,    3,    1,    1,    3,
    1,    1,    3,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    3,    0,    9,
   72,    0,    2,    0,    0,    0,    0,    4,    0,   14,
   15,    8,   73,   18,    0,    0,    0,   16,    0,    0,
    0,    0,   39,    0,    0,    5,   22,   23,   24,   25,
   26,   27,   28,   29,   30,   48,   13,    0,   21,    0,
    0,    0,    0,    0,   69,   71,    0,   32,    0,   65,
   68,    0,    0,    0,    0,    0,   17,   50,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   40,    0,    0,   19,   20,
    0,   70,    0,    0,    0,    0,    0,    0,    0,    0,
   33,   66,   67,   51,    0,   52,    0,    0,   41,   44,
   34,    0,    0,    0,   42,    0,   36,   35,    0,    0,
   46,   37,    0,   47,
};
static const short yydgoto[] = {                          1,
    2,    7,    8,   18,   14,   36,   26,    9,   10,   12,
   19,   20,   21,   25,   67,   48,   50,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   57,   58,   82,  108,
  118,  114,  120,   63,  105,  112,  107,  113,  119,  123,
   46,   59,   60,   61,
};
static const short yysindex[] = {                         0,
    0, -256, -265, -246, -222, -250, -237,    0, -227,    0,
    0, -223,    0, -195, -222, -218, -188,    0, -221,    0,
    0,    0,    0,    0, -216, -160, -195,    0, -160, -185,
  -42, -168,    0, -131, -151,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -222,    0, -258,
 -137, -280, -280,  -42,    0,    0,  -18,    0, -260,    0,
    0, -146,  -42,  -42,  -42, -160,    0,    0, -160,  -42,
 -260, -260, -266, -280, -280,  -42,  -42,  -42,  -42,  -42,
  -42, -112, -280, -280, -124,    0, -123, -184,    0,    0,
 -184,    0, -260, -260, -184, -184, -184, -184, -184, -184,
    0,    0,    0,    0,  -90,    0,  -95, -160,    0,    0,
    0, -160,  -42,  -84,    0, -184,    0,    0,  -81, -160,
    0,    0, -160,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -214,    0,    0,    0,    0,    0,
    0, -110,    0, -198, -226,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -109, -186,    0, -254,    0,
    0,    0,    0,    0, -255,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -169,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -142,    0,
    0,    0,    0,    0,    0, -105,    0,    0, -254,    0,
 -115,  -88,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -239,    0,    0,
  -85,    0,  -61,  -34, -249, -236, -144, -138, -135, -111,
    0,    0,    0,    0,    0,    0,    0, -204,    0,    0,
    0, -204,    0, -178,    0,  -79,    0,    0,    0, -204,
    0,    0, -204,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  139,    0,    0,  -29,    0,    0,  173,    0,
    0,  168,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -53,  138,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   47,   45,    0,
};
#define YYTABLESIZE 264
static const short yytable[] = {                         49,
   73,   68,   54,   49,   49,   53,   74,   75,   54,    3,
   87,   88,   55,   56,   83,   84,   91,   92,   54,   31,
   31,   55,   95,   96,   97,   98,   99,  100,    4,   69,
    7,   55,   49,   53,    7,   49,   89,    7,    7,   90,
    7,    5,    6,   11,    7,    7,    6,    6,   31,    6,
    6,   31,    6,   13,   53,   53,    6,    6,   12,  116,
   15,    7,   12,   16,    7,   12,   27,    7,   12,   17,
   11,   28,   12,   12,   11,   23,    6,   11,  111,    6,
   11,   38,  115,   53,   11,   11,   53,    6,   74,   75,
  122,    6,   12,  124,    6,   12,   29,    6,   71,   72,
   30,    6,    6,   31,   11,   24,   32,   11,   51,   38,
   33,   34,   38,   57,   62,   60,   60,   60,    6,   56,
   93,   94,   59,   57,    6,   60,   60,  102,  103,   56,
   60,   60,   59,   35,   60,   60,   60,   60,   60,   60,
   65,   60,   61,   61,   61,   60,   58,   85,   60,   74,
   75,   64,   61,   61,   70,  101,   58,   61,   61,  104,
  106,   61,   61,   61,   61,   61,   61,  109,   61,   62,
   62,   62,   61,  110,  117,   61,  121,   10,   45,   62,
   62,   53,   53,   43,   62,   62,   66,   22,   62,   62,
   62,   62,   62,   62,   47,   62,   63,   63,   63,   62,
   86,    0,   62,    0,    0,    0,   63,   63,    0,    0,
    0,   63,   63,    0,    0,   63,   63,   63,   63,   63,
   63,    0,   63,   64,   64,   64,   63,    0,    0,   63,
   52,   53,    0,   64,   64,    0,    0,    0,   64,   64,
   54,    0,   64,   64,   64,   64,   64,   64,    0,   64,
   55,   56,    0,   64,   74,   75,   64,    0,   76,   77,
   78,   79,   80,   81,
};
static const short yycheck[] = {                         29,
   54,  260,  283,  259,  260,  260,  273,  274,  258,  266,
   64,   65,  293,  294,  275,  276,   70,  284,  268,  259,
  260,  258,   76,   77,   78,   79,   80,   81,  294,  288,
  257,  268,  288,  288,  261,  291,   66,  264,  265,   69,
  267,  288,  257,  294,  271,  272,  261,  270,  288,  264,
  265,  291,  267,  291,  259,  260,  271,  272,  257,  113,
  288,  288,  261,  287,  291,  264,  288,  294,  267,  265,
  257,  288,  271,  272,  261,  294,  291,  264,  108,  294,
  267,  260,  112,  288,  271,  272,  291,  257,  273,  274,
  120,  261,  291,  123,  264,  294,  257,  267,   52,   53,
  261,  271,  272,  264,  291,  294,  267,  294,  294,  288,
  271,  272,  291,  258,  283,  258,  259,  260,  288,  258,
   74,   75,  258,  268,  294,  268,  269,   83,   84,  268,
  273,  274,  268,  294,  277,  278,  279,  280,  281,  282,
  292,  284,  258,  259,  260,  288,  258,  294,  291,  273,
  274,  283,  268,  269,  292,  268,  268,  273,  274,  284,
  284,  277,  278,  279,  280,  281,  282,  258,  284,  258,
  259,  260,  288,  269,  259,  291,  258,  288,  258,  268,
  269,  291,  288,  269,  273,  274,   48,   15,  277,  278,
  279,  280,  281,  282,   27,  284,  258,  259,  260,  288,
   63,   -1,  291,   -1,   -1,   -1,  268,  269,   -1,   -1,
   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,  281,
  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,
  273,  274,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
  283,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
  293,  294,   -1,  288,  273,  274,  291,   -1,  277,  278,
  279,  280,  281,  282,
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
"$$13 :",
"$$14 :",
"$$15 :",
"for_statement : FOR IDENT ASSIGN expression $$12 TO $$13 expression $$14 DO $$15 statement",
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
#line 480 "parser.y"
void yyerror(char *s)
{
	fprintf(stderr, "%s in line %d: token '%s'\n", s, yylineno, yytext);
}
#line 399 "y.tab.c"

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
			factorpush(generateFactor(yystack.l_mark[-2].ident));
			generateCode(Store);
		}
break;
case 32:
#line 180 "parser.y"
	{

			generateCode(BrCond); /* Br1 arg1埋め*/
			LLVMcode *tmp = brpop();
			(tmp->args).brcond.arg2 = cntr; /* Br1 arg2即埋め*/
			brpush(tmp);
		}
break;
case 33:
#line 188 "parser.y"
	{
			generateCode(Label); /* 真ラベル作成*/
		}
break;
case 34:
#line 192 "parser.y"
	{
			generateCode(BrUncond); /* Bru2作成*/
		}
break;
case 35:
#line 196 "parser.y"
	{
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; /* Bru2 arg1埋め*/
			generateCode(Label); /* retラベル作成*/
		}
break;
case 36:
#line 205 "parser.y"
	{
			LLVMcode *tmp1 = brpop();
			LLVMcode *tmp2 = brpop();
			brpush(tmp1);
			(tmp2->args).brcond.arg3 = cntr; /* Br1 arg3埋め*/
			generateCode(Label); /* 偽ラベル作成*/
		}
break;
case 37:
#line 213 "parser.y"
	{
			generateCode(BrUncond);
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; /* Br3 arg1即埋め*/
		}
break;
case 38:
#line 219 "parser.y"
	{
			LLVMcode *tmp1 = brpop();
			LLVMcode *tmp2 = brpop();
			brpush(tmp1);
			(tmp2->args).brcond.arg3 = cntr; /* Br1 arg3埋め*/
		}
break;
case 39:
#line 229 "parser.y"
	{
			generateCode(BrUncond); /* Bru0作成*/
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; /* Bru0完成*/
			labelpush(cntr); /* WHILEのスタートラベルをpush*/
			generateCode(Label); /* WHILEのスタートラベル*/
		}
break;
case 40:
#line 237 "parser.y"
	{
			generateCode(BrCond); /* Br1作成*/
			LLVMcode *tmp = brpop();
			(tmp->args).brcond.arg2 = cntr; /* Br1 True時即埋め*/
			brpush(tmp); /* Br1 Fasle時 push*/
		}
break;
case 41:
#line 244 "parser.y"
	{
			generateCode(Label); /* 真ラベル作成*/
		}
break;
case 42:
#line 248 "parser.y"
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
#line 261 "parser.y"
	{
			/* あとでIDENTを使いたいのでassignment_stateは使わない*/
			factorpush(generateFactor(yystack.l_mark[-2].ident));
			generateCode(Store);
			generateCode(BrUncond); /* forを開始するBru1*/
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; /* Bru1 arg1即埋め*/
			labelpush(cntr); /* 戻り用ラベルpush*/
			generateCode(Label); /* 真ラベル作成*/
		}
break;
case 44:
#line 272 "parser.y"
	{
			factorpush(generateFactor(yystack.l_mark[-4].ident));
			generateCode(Load);
		}
break;
case 45:
#line 277 "parser.y"
	{
			generateIcmp(SLE);
			generateCode(BrCond); /* Br2作成*/
			LLVMcode *tmp = brpop();
			(tmp->args).brcond.arg2 = cntr; /* Br2 True時即埋め*/
			brpush(tmp); /* Br2 Fasle時 push*/
		}
break;
case 46:
#line 285 "parser.y"
	{
			generateCode(Label);
		}
break;
case 47:
#line 289 "parser.y"
	{
			generateCode(BrUncond);
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; /* Bru3 arg1即埋め 次へ*/

			generateCode(Label); /* i++ラベル作成*/
			factorpush(generateFactor(yystack.l_mark[-10].ident));
			generateCode(Load);
			Factor f;
			f.type = CONSTANT;
			f.val = 1;
			factorpush(f);
			generateCode(Add);
			generateCode(Store);
			generateCode(BrUncond);
			tmp = brpop();
			(tmp->args).bruncond.arg1 = labelpop(); /* Bru4 arg1埋め 戻る*/

			tmp = brpop();
			(tmp->args).brcond.arg3 = cntr; /* Bru1 False埋め*/
			generateCode(Label); /* for外ラベル作成*/
		}
break;
case 49:
#line 319 "parser.y"
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
case 51:
#line 337 "parser.y"
	{
			/* %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32* @x)*/
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
case 52:
#line 352 "parser.y"
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
case 54:
#line 369 "parser.y"
	{
			generateIcmp(EQUAL);
        }
break;
case 55:
#line 373 "parser.y"
	{
			generateIcmp(NE);
		}
break;
case 56:
#line 377 "parser.y"
	{
			generateIcmp(SLT);
		}
break;
case 57:
#line 381 "parser.y"
	{
			generateIcmp(SLE);
		}
break;
case 58:
#line 385 "parser.y"
	{
			generateIcmp(SGT);
		}
break;
case 59:
#line 389 "parser.y"
	{
			generateIcmp(SGE);
		}
break;
case 62:
#line 398 "parser.y"
	{
			Factor f;
			f = factorpop();
			f.val = -f.val;
			factorpush(f);
		}
break;
case 63:
#line 405 "parser.y"
	{
			/* printf("[ex PLUS term]\n");*/
			generateCode(Add);
        }
break;
case 64:
#line 410 "parser.y"
	{
			/* printf("[ex Sub term]\n");*/
			generateCode(Sub);
        }
break;
case 66:
#line 420 "parser.y"
	{
			/* printf("[term Mult factor]\n");*/
			generateCode(Mult);
		}
break;
case 67:
#line 425 "parser.y"
	{
			/* printf("[term Div factor]\n");*/
			generateCode(Div);
		}
break;
case 69:
#line 434 "parser.y"
	{
			Factor f;
			f.type = CONSTANT;
			f.val = yystack.l_mark[0].num;
			factorpush(f);
		}
break;
case 71:
#line 445 "parser.y"
	{
			/* printf("[var_name %s %d]\n", $1, flag);*/

			Factor f = generateFactor(yystack.l_mark[0].ident);
			factorpush(f);
			generateCode(Load);
		}
break;
case 72:
#line 461 "parser.y"
	{
			/* printf("[id_list]\n");*/
			insert(yystack.l_mark[0].ident, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			}
		}
break;
case 73:
#line 469 "parser.y"
	{
			/* printf("[id_list]\n");*/
			insert(yystack.l_mark[0].ident, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			}
		}
break;
#line 996 "y.tab.c"
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
