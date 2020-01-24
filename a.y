%{
/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
#include "symbol_table.h"
#include "code_generator.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                 省略
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

extern LLVMcode *codehd;
extern LLVMcode *codetl;
extern Fundecl *declhd;
extern Fundecl *decltl;

Scope flag = GLOBAL_VAR;
char *fname = "result.ll";
FILE *fp;

%}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                 省略
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
%%

program
        : {
            fp = fopen(fname, "w");
            if (fp == NULL) {
                printf("ERROR cannot open\n");
                exit(1);
            }
        }
        PROGRAM IDENT SEMICOLON outblock PERIOD
        {
            // printf("[program end.]\n");
            // print_all();
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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                 省略
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

proc_name
        : IDENT
        {
            insert($1, PROC_NAME);
            insertDecl($1, 0, NULL);
        }
        ;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                 省略
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

assignment_statement
        : IDENT ASSIGN expression
        {
            // printf("[assignment_statement %s %d]\n", $1, flag);

            factorpush(generateFactor($1));
            generateCode(Store);
        }
        ;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                 省略
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
            // printf("[factor]\n");
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
            };
        }
        ;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                 省略
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
