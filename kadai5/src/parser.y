%{
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

%}

%union {
	int num;
	char ident[MAXLENGTH+1];
}

%token SBEGIN DO ELSE SEND
%token FOR FORWARD FUNCTION IF PROCEDURE
%token PROGRAM READ THEN TO VAR
%token WHILE WRITE

%left PLUS MINUS                       // ← 注意
%left MULT DIV                         // ← 注意

%token EQ NEQ LE LT GE GT
%token LPAREN RPAREN LBRACKET RBRACKET
%token COMMA SEMICOLON COLON INTERVAL
%token PERIOD ASSIGN
%token <num> NUMBER                    // ← yylval の型を指定
%token <ident> IDENT                   // ← yylval の型を指定

%%

program
        :
		{
			fp = fopen(fname, "w");
			if (fp == NULL) {
				printf("ERROR cannot open\n");
				exit(1);
			}
			printf("[program start]\n");
			printf("------------------\n");
		}
		PROGRAM IDENT SEMICOLON outblock PERIOD
		{
			printf("[program end.]\n");
			print_all();
			displayLlvmfundecl(declhd);
		}
        ;

outblock
        : var_decl_part subprog_decl_part
        {
			// printf("[outblock]\n");
			insertDecl("main", 0, NULL);
			init_fstack();
			Factor f;
			f.type = CONSTANT;
			f.val = 0;
			factorpush(f);
			generateCode(Alloca);
			generateCode(Store);
        }
		statement
		{
			Factor f;
			f.type = CONSTANT;
			f.val = 0;
			factorpush(f);
			generateCode(Ret);
		}
        ;

var_decl_part
        : /* empty */
        | var_decl_list SEMICOLON
		{
			displayGlobalVar();
		}
        ;

var_decl_list
        : var_decl_list SEMICOLON var_decl
        | var_decl
        ;

var_decl
        : VAR id_list
        ;

subprog_decl_part
        : subprog_decl_list SEMICOLON
        | /* empty */
        ;

subprog_decl_list
        : subprog_decl_list SEMICOLON subprog_decl
        | subprog_decl
        ;

subprog_decl
        : proc_decl
        ;

proc_decl
        : PROCEDURE proc_name SEMICOLON
		{
			flag = LOCAL_VAR;
		}
		inblock
		{
			// printf("[proc_decl]\n");
			delete();
			flag = GLOBAL_VAR;
		}
        ;

proc_name
        : IDENT
		{
			insert($1, PROC_NAME);
			insertDecl($1, 0, NULL);
		}
        ;

inblock
        : var_decl_part statement
        ;

statement_list
        : statement_list SEMICOLON statement
        | statement
        ;

statement
        : assignment_statement
        | if_statement
        | while_statement
        | for_statement
        | proc_call_statement
        | null_statement
        | block_statement
        | read_statement
        | write_statement
        ;

assignment_statement
        : IDENT ASSIGN expression
		{
			// printf("[assignment_statement %s %d]\n", $1, flag);

			factorpush(generateFactor($1));
			generateCode(Store);
		}
        ;

if_statement
        : IF condition
		{
			generateCode(BrCond);
		}
		THEN
		{
			labelpush(cntr);
			generateCode(Label);
		}
		statement else_statement
		{
			generateCode(Label);
		}
        ;

else_statement
        : {
			generateCode(BrCond);
			generateCode(Label);
		}
		ELSE statement
        | /* empty*/
        ;

while_statement
        : WHILE 
		{
			generateCode(BrUncond); // Bru0作成
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; // Bru0完成
			labelpush(cntr); // WHILEのスタートラベルをpush
			generateCode(Label); // WHILEのスタートラベル
		}
		condition
		{
			generateCode(BrCond); // Br1作成
			printf("%d\n", codetl->command);
			LLVMcode *tmp = brpop();
			(tmp->args).brcond.arg2 = cntr; // Br1 True時即埋め
			brpush(tmp); // Br1 Fasle時 push
		}
		DO
		{
			generateCode(Label); // 真ラベル作成
		}
		statement
		{
			generateCode(BrUncond); // スタートに戻るためのBru1作成
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = labelpop(); // WHILEのスタートラベルをpopしてBru1即埋め
			tmp = brpop();
			(tmp->args).brcond.arg3 = cntr; // Br1 Fasle時popして偽ラベル埋める
			generateCode(Label); // 偽ラベル作成
		}
        ;

for_statement
        : FOR IDENT
		{
			// printf("[for_statement %s %d]\n", $2, flag);
			lookup($2);
		} ASSIGN expression TO expression DO statement
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name
        : IDENT
		{
			// printf("[proc_call_name %s %d]\n", $1, flag);
			lookup($1);
		}
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement
        : READ LPAREN IDENT RPAREN
		{
			// printf("[read_statement %s %d]\n", $3, flag);
			lookup($3);
		}
        ;

write_statement
        : WRITE LPAREN expression RPAREN
        ;

null_statement
        : /* empty */
        ;

condition
        : expression EQ expression
		{
			generateIcmp(EQUAL);
        }
        | expression NEQ expression
		{
			generateIcmp(NE);
		}
        | expression LT expression
		{
			generateIcmp(SLT);
		}
        | expression LE expression
		{
			generateIcmp(SLE);
		}
        | expression GT expression
		{
			generateIcmp(SGT);
		}
        | expression GE expression
		{
			generateIcmp(SGE);
		}
        ;

expression
        : term
        | PLUS term
        | MINUS term
		{
			Factor f;
			f = factorpop();
			f.val = -f.val;
			factorpush(f);
		}
        | expression PLUS term
        {
			// printf("[ex PLUS term]\n");
			generateCode(Add);
        }
        | expression MINUS term
        {
			// printf("[ex Sub term]\n");
			generateCode(Sub);
        }
        ;


term
        : factor
        | term MULT factor
		{
			// printf("[term Mult factor]\n");
			generateCode(Mult);
		}
        | term DIV factor
		{
			// printf("[term Div factor]\n");
			generateCode(Div);
		}
        ;

factor
        : var_name
        | NUMBER
		{
			Factor f;
			f.type = CONSTANT;
			f.val = $1;
			factorpush(f);
		}
        | LPAREN expression RPAREN
        ;

var_name
        : IDENT
		{
			// printf("[var_name %s %d]\n", $1, flag);

			Factor f = generateFactor($1);
			factorpush(f);
			generateCode(Load);
		}
        ;

// arg_list
//         : expression
//         | arg_list COMMA expression
//         ;

id_list
        : IDENT
		{
			// printf("[id_list]\n");
			insert($1, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			}
		}
        | id_list COMMA IDENT
		{
			// printf("[id_list]\n");
			insert($3, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			}
		}
        ;


%%
void yyerror(char *s)
{
	fprintf(stderr, "%s in line %d: token '%s'\n", s, yylineno, yytext);
}
