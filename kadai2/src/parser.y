%{
/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>

%}

%union {
    int num;
    char ident[MAXLENGTH+1];
}

%token SBEGIN DO ELSE SEND
%token FOR FORWARD FUNCTION IF PROCEDURE
%token PROGRAM READ THEN TO VAR
%token WHILE WRITE

%left PLUS MINUS                       ← 注意
%left MULT DIV                         ← 注意

%token EQ NEQ LE LT GE GT
%token LPAREN RPAREN LBRACKET RBRACKET
%token COMMA SEMICOLON COLON INTERVAL
%token PERIOD ASSIGN
%token <num> NUMBER                    ← yylval の型を指定
%token <ident> IDENT                   ← yylval の型を指定

%%

program
        : PROGRAM IDENT SEMICOLON outblock PERIOD
        ;

outblock
        : var_decl_part subprog_decl_part statement
        ;

var_decl_part
        : /* empty */
        | var_decl_list SEMICOLON
        ;

var_decl_list
        : var_decl_list SEMICOLON var_decl
        | var decl
        ;

var_decl
        : VAR id_list
        ;

subprog_decl_part
        : subprog_decl_list SEMICOLON subprog_decl
        | subprog_decl
        ;

subprog_decl
        : proc_decl
        ;

proc_decl
        : PROCEDURE proc_name SEMICOLON inblock
        ;

proc_name
        : IDENT
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
        : FOR IDENT ASSIGN expression TO expression DO statement
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name
        : ‘IDENT’
        ;

block_statement
        : BEGIN statement_list END
        ;

read_statement
        : READ LPAREN IDENT RPAREN
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
        | expression PLUS term
        | expression MINUS term
        ;

term
        : factor
        | term MULT factor
        | term DIV factor
        ;

factor
        : var_name
        | NUMBER
        | LPAREN expression RPAREN
        ;

var_name
        : IDENT
        ;

arg_list
        : expression
        | arg_list COMMA expression
        ;

id_list
        : IDENT
        | id_list COMMA IDENT
        ;




⟨subprog decl part⟩
⟨subprog decl list⟩
⟨subprog decl⟩
⟨proc decl⟩
::=
::=
⟨subprog decl list⟩ ‘;’
/* empty */
⟨subprog decl list⟩ ‘;’ ⟨subprog decl⟩
⟨subprog decl⟩
⟨proc decl⟩
‘procedure’ ⟨proc name⟩ ‘;’ ⟨inblock⟩
::=
‘IDENT’
⟨var decl part⟩ ⟨statement⟩
⟨statement list⟩
⟨statement⟩
::=
|
::=
⟨proc name⟩
⟨inblock⟩
::=
|
::=
|
|
|
|
|
|
|
|
::=
|
⟨statement list⟩ ‘;’ ⟨statement⟩
⟨statement⟩
⟨assignment statement⟩
⟨if statement⟩
⟨while statement⟩
⟨f or statement⟩
⟨proc call statement⟩
⟨null statement⟩
⟨block statement⟩
⟨read statement⟩
⟨write statement⟩
37⟨assignment statement⟩
⟨if statement⟩
::=
‘IDENT’ ‘:=’ ⟨expression⟩
::=‘if’ ⟨condition⟩ ‘then’ ⟨statement⟩ ⟨else statement⟩
⟨else statement⟩
::=
|
⟨while statement⟩
⟨f or statement⟩
::=
::=
⟨proc call statement⟩
⟨proc call name⟩
::=
‘else’ ⟨statement⟩
/* empty */
‘while’ ⟨condition⟩ ‘do’ ⟨statement⟩
‘for’ ‘IDENT’ ‘:=’ ⟨expression⟩
‘to’ ⟨expression⟩ ‘do’ ⟨statement⟩
::=
⟨proc call name⟩
‘IDENT’
⟨block statement⟩ ::= ‘begin’ ⟨statement list⟩ ‘end’
⟨read statement⟩ ::= ‘read’ ‘(’ ‘IDENT’ ‘)’
⟨write statement⟩
::=
‘write’ ‘(’ ⟨expression⟩ ‘)’
⟨null statement⟩ ::=
⟨condition⟩ ⟨expression⟩
⟨expression⟩
⟨expression⟩
⟨expression⟩
⟨expression⟩
⟨expression⟩
::=
|
|
|
|
|
/* empty */
‘=’ ⟨expression⟩
‘<>’ ⟨expression⟩
‘<’ ⟨expression⟩
‘<=’ ⟨expression⟩
‘>’ ⟨expression⟩
‘>=’ ⟨expression⟩
⟨expression⟩ ::=
|
|
|
|
⟨term⟩ ⟨f actor⟩
⟨term⟩ ‘*’ ⟨f actor⟩
⟨term⟩ ‘div’ ⟨f actor⟩
::=
|
|
⟨f actor⟩
⟨arg list⟩
⟨var name⟩
‘NUMBER’
‘(’ ⟨expression⟩ ‘)’
::=
|
|
⟨var name⟩
⟨term⟩
‘+’ ⟨term⟩
‘-’ ⟨term⟩
⟨expression⟩ ‘+’ ⟨term⟩
⟨expression⟩ ‘-’ ⟨term⟩
::=
::=
|
‘IDENT’
⟨expression⟩
⟨arg list⟩ ‘,’ ⟨expression⟩
38⟨id list⟩
::=
|
‘IDENT’
⟨id list⟩ ‘,’ ‘IDENT’

%% 
yyerror(char *s)
{
  fprintf(stderr, "%s\n", s);
}
