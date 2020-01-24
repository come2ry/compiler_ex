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
			fprintf(fp, "declare dso_local i32 @scanf(i8*, ...)\n");
			fprintf(fp, "declare dso_local i32 @printf(i8*, ...)\n");
		}
        ;

outblock
        : var_decl_part
		{
			displayGlobalVar();
		}
		subprog_decl_part
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
			strcpy(f.vname, "I32");
			f.type = CONSTANT;
			f.val = 0;
			factorpush(f);
			generateCode(Ret);
		}
        ;

var_decl_part
        : /* empty */
        | var_decl_list SEMICOLON
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

			Factor f;
			strcpy(f.vname, "VOID");
			factorpush(f);
			generateCode(Ret);
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
			factorpush(generateFactor($1));
			generateCode(Store);
		}
        ;

if_statement
        : IF condition
		{

			generateCode(BrCond); // Br1 arg1埋め
			LLVMcode *tmp = brpop();
			(tmp->args).brcond.arg2 = cntr; // Br1 arg2即埋め
			brpush(tmp);
		}
		THEN
		{
			generateCode(Label); // 真ラベル作成
		}
		statement
		{
			generateCode(BrUncond); // Bru2作成
		}
		else_statement
		{
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; // Bru2 arg1埋め
			generateCode(Label); // retラベル作成
		}
        ;

else_statement
        : ELSE
		{
			LLVMcode *tmp1 = brpop();
			LLVMcode *tmp2 = brpop();
			brpush(tmp1);
			(tmp2->args).brcond.arg3 = cntr; // Br1 arg3埋め
			generateCode(Label); // 偽ラベル作成
		}
		statement
		{
			generateCode(BrUncond);
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = cntr; // Br3 arg1即埋め
		}
        | /* empty*/
		{
			LLVMcode *tmp1 = brpop();
			LLVMcode *tmp2 = brpop();
			brpush(tmp1);
			(tmp2->args).brcond.arg3 = cntr; // Br1 arg3埋め
		}
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
        : FOR IDENT ASSIGN expression
		{
			// あとでIDENTを使いたいのでassignment_stateは使わない
			Factor f = generateFactor($2);
			factorpush(f);
			generateCode(Store);
			generateCode(BrUncond); // forを開始するBru1
			labelpush(cntr); // 戻り用ラベルpush
			generateCode(Label); // 真ラベル作成
		}
		TO
		{
			Factor f = generateFactor($2);
			factorpush(f);
			generateCode(Load);
		}
		expression
		{
			generateIcmp(SLE);
			generateCode(BrCond); // Br2作成
			LLVMcode *tmp = brpop();
			(tmp->args).brcond.arg2 = cntr; // Br2 True時即埋め
			brpush(tmp); // Br2 Fasle時 push
		}
		DO
		{
			generateCode(Label);
		}
		statement
		{
			generateCode(BrUncond);
			LLVMcode *tmp = brpop();
			(tmp->args).bruncond.arg1 = labelpop(); // Bru3 arg1埋め 戻る
			tmp = brpop();
			(tmp->args).brcond.arg3 = cntr; // Bru1 False埋め
			generateCode(Label); // for外ラベル作成
		}
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name
        : IDENT
		{
			// printf("[proc_call_name %s %d]\n", $1, flag);
			// lookup($1);
			Factor fname;
			fname.type = PROC_NAME;
			strcpy(fname.vname, $1);
			fname.val = 0;
			Factor args[10] = {};
			generateCall(VOID, fname, args);
		}
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement
        : READ LPAREN IDENT RPAREN
		{
			// %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* @x)
			// lookup($3);
			Factor fname;
			fname.type = PROC_NAME;
			strcpy(fname.vname, "scanf");
			fname.val = 1;
			Factor f = generateFactor($3);
			Factor args[10] = {f};
			generateCall(I32, fname, args);
		}
        ;

write_statement
        : WRITE LPAREN expression RPAREN
		{
			Factor fname;
			fname.type = PROC_NAME;
			strcpy(fname.vname, "printf");
			fname.val = 1;
			Factor f = factorpop();
			Factor args[10] = {f};
			generateCall(I32, fname, args);
		}
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
