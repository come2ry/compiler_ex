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

Scope flag = GLOBAL_VAR;

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
        : PROGRAM IDENT SEMICOLON outblock PERIOD
		{
			// printf("[program end.]\n");
			// print_all();
			displayLlvmfundecl(declhd);
		}
        ;

outblock
        : var_decl_part subprog_decl_part
        {
			insertDecl("main", 0, NULL);
			Factor f;
			f.type = CONSTANT;
			f.val = 0;
			factorpush(f);
			generateCode(Alloca);
			generateCode(Store);
        } statement
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
			printf("[proc_decl]\n");
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
        : IF condition THEN statement else_statement
        ;

else_statement
        : ELSE statement
        | /* empty*/
        ;

while_statement
        : WHILE condition DO statement
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
        | expression NEQ expression
        | expression LT expression
        | expression LE expression
        | expression GT expression
        | expression GE expression
        ;

expression
        : term
        | PLUS term
        | MINUS term
		{
			// Factor f;
			// f = factorpop();
			// f.val = -f.val;
			// factorpush(f);
		}
        | expression PLUS term
        {
			generateCode(Add);
        }
        | expression MINUS term
        {
			generateCode(Sub);
        }
        ;


term
        : factor
        | term MULT factor
		{
			generateCode(Mult);
		}
        | term DIV factor
		{
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

arg_list
        : expression
        | arg_list COMMA expression
        ;

id_list
        : IDENT
		{
			insert($1, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			}
		}
        | id_list COMMA IDENT
		{
			insert($3, flag);
			if (flag == LOCAL_VAR) {
				generateCode(Alloca);
			};
		}
        ;


%%
yyerror(char *s)
{
	fprintf(stderr, "%s in line %d: token '%s'\n", s, yylineno, yytext);
}
