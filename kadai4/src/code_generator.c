#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "code_generator.h"

LLVMcode *codehd = NULL; /* 命令列の先頭のアドレスを保持するポインタ */
LLVMcode *codetl = NULL; /* 命令列の末尾のアドレスを保持するポインタ */

/* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
Fundecl *declhd = NULL;
/* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
Fundecl *decltl = NULL;

static int cntr = 0;

char cmp_array[][4] = {
    "eq",
    "ne",
    "sgt",
    "sge",
    "slt",
    "sle"
};

void init_fstack()
{ /* fstackの初期化 */
    fstack.top = 0;
    return;
}

Factor factorpop()
{
    Factor tmp;
    tmp = fstack.element[fstack.top];
    fstack.top--;
    return tmp;
}

void factorpush(Factor x)
{
    fstack.top++;
    fstack.element[fstack.top] = x;
    return;
}


void generateCode(LLVMcommand command) {
    LLVMcode *tmp;             /* 生成した命令へのポインタ */
    tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
    tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
    tmp->command = command;        /* 命令の種類を加算に設定 */
    Factor arg1, arg2, arg3, retval, l, type; /* 結果 */

    switch( command ){
        case Alloca:
            retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
            retval.val = cntr;         /* 新規のレジスタ番号を取得 */
            cntr++;                    /* カウンタをインクリメント */
            (tmp->args).alloca.retval = retval; /* 返り場所のレジスタを指定 */
            _insertCode(tmp);
            factorpush( retval ); /* 関数の返り場所をスタックにプッシュ */
            break;
        case Store:
            // store i32 10, i32* @n, align 4
            arg2 = factorpop();
            arg1 = factorpop();
            (tmp->args).store.arg1 = arg1;
            (tmp->args).store.arg2 = arg2;
            _insertCode(tmp);
            break;
        case Load:
            // %6 = load i32, i32* @sum, align
            arg1 = factorpop();
            retval.type = LOCAL_VAR;
            retval.val = cntr;
            cntr++;
            (tmp->args).load.arg1 = arg1;
            (tmp->args).load.retval = retval;
            _insertCode(tmp);
            factorpush( retval );
            break;
        case BrUncond:
            // // br label %2
            // (tmp->args).bruncond.arg1 = arg1.val;
            // _insertCode(tmp);
            break;
        case BrCond:
            // br i1 %4, label %5, label %1
            // arg3 = factorpop();
            // arg2 = factorpop();
            // arg1 = factorpop();
            // (tmp->args).brcond.arg1 = arg1;
            // (tmp->args).brcond.arg2 = arg2.val;
            // (tmp->args).brcond.arg3 = arg3.val;
            // _insertCode(tmp);
            break;
        case Label:
            // ; <label>:5
            // l = factorpop();
            // (tmp->args).label.l = l.val;
            // _insertCode(tmp);
            break;
        case Add:
            // %8 = add nsw i32 %6, %7
            arg2 = factorpop();
            arg1 = factorpop();
            retval.type = LOCAL_VAR;
            retval.val = cntr;
            cntr++;
            if (arg1.type != CONSTANT || arg2.type != CONSTANT) {
                (tmp->args).add.arg1 = arg1;
                (tmp->args).add.arg2 = arg2;
                (tmp->args).add.retval = retval;
                _insertCode(tmp);
            }
            factorpush( retval );
            break;
        case Sub:
            // %10 = sub nsw i32 %9, 1
            arg2 = factorpop();
            arg1 = factorpop();
            retval.type = LOCAL_VAR;
            retval.val = cntr;
            cntr++;
            if (arg1.type != CONSTANT || arg2.type != CONSTANT) {
                (tmp->args).sub.arg1 = arg1;
                (tmp->args).sub.arg2 = arg2;
                (tmp->args).sub.retval = retval;
                _insertCode(tmp);
            }
            factorpush( retval );
            break;
        case Mult:
            // %3 = mul nsw i32 %2, 2
            arg2 = factorpop();
            arg1 = factorpop();
            retval.type = LOCAL_VAR;
            retval.val = cntr;
            cntr++;
            if (arg1.type != CONSTANT || arg2.type != CONSTANT) {
                (tmp->args).mult.arg1 = arg1;
                (tmp->args).mult.arg2 = arg2;
                (tmp->args).mult.retval = retval;
                _insertCode(tmp);
            }
            factorpush( retval );
            break;
        case Div:
            // %10 = add nsw i32 %9, -1
            arg2 = factorpop();
            arg1 = factorpop();
            retval.type = LOCAL_VAR;
            retval.val = cntr;
            cntr++;
            if (arg1.type != CONSTANT || arg2.type != CONSTANT) {
                (tmp->args).div.arg1 = arg1;
                (tmp->args).div.arg2 = arg2;
                (tmp->args).div.retval = retval;
                _insertCode(tmp);
            }
            factorpush( retval );
            break;
        case Icmp:
            // %4 = icmp sgt i32 %3, 0
            // arg1 = factorpop();
            // arg2 = factorpop();
            // type = factorpop();
            // retval.type = LOCAL_VAR;
            // retval.val = cntr;
            // cntr++;
            // (tmp->args).icmp.type = type.val;
            // (tmp->args).icmp.arg1 = arg1;
            // (tmp->args).icmp.arg2 = arg2;
            // (tmp->args).icmp.retval = retval;
            // _insertCode(tmp);
            // factorpush( retval );
            break;
        case Ret:
            // ret i32 0
            // (tmp->args).ret.arg1 = arg1;
            // _insertCode(tmp);
            break;
        default:
            break;
    }
}

void _insertCode(LLVMcode *tmp) {
    if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
        if( decltl == NULL ){   /* 解析中の関数がない場合 */
            /* 関数宣言を処理する段階でリストが作られているので，ありえない */
            fprintf(stderr,"unexpected error\n");
        }
        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
    } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
        codetl->next = tmp; /* 命令列の末尾に追加 */
        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
    }
}

void displayFactor( Factor factor ){
    switch( factor.type ){
        case GLOBAL_VAR:
            printf("@%s", factor.vname );
            break;
        case LOCAL_VAR:
            printf("%%%d", factor.val );
            break;
        case CONSTANT:
            printf("%d", factor.val );
            break;
        default:
            break;
    }

    return;
}

void displayLlvmcodes( LLVMcode *code ){
    if( code == NULL )
        return;
    printf("  ");
    switch( code->command ){
        // case Common:
        //     // @n = common global i32 0, align 4
        //     displayFactor( (code->args).common.retval );
        //     printf(" = common global i32 ");
        //     displayFactor( (code->args).common.arg1 );
        //     printf(", align 4\n");
        //     break;
        case Alloca:
            // %1 = alloca i32, align 4
            displayFactor( (code->args).alloca.retval );
            printf(" = alloca i32, align 4\n");
            break;
        case Store:
            // store i32 10, i32* @n, align
            printf("store i32 ");
            displayFactor( (code->args).store.arg1 );
            printf(", i32* ");
            displayFactor( (code->args).store.arg2 );
            printf(", align 4\n");
            break;
        case Load:
            // %6 = load i32, i32* @sum, align
            displayFactor( (code->args).load.retval );
            printf(" = load i32, i32* ");
            displayFactor( (code->args).load.arg1 );
            printf(", align 4\n");
            break;
        case BrUncond:
            // br label %2
            printf("br label %%%i\n", (code->args).bruncond.arg1 );
            break;
        case BrCond:
            // br i1 %4, label %5, label %1
            printf("br i1 ");
            displayFactor( (code->args).brcond.arg1 );
            printf(", label %%%i, %%%i\n", (code->args).brcond.arg2, (code->args).brcond.arg3);
            break;
        case Label:
            // ; <label>:5
            printf("; <label>:%i\n", (code->args).label.l );
            break;
        case Add:
            // %8 = add nsw i32 %6, %7
            displayFactor( (code->args).add.retval );
            printf(" = add nsw i32 ");
            displayFactor( (code->args).add.arg1 );
            printf(", ");
            displayFactor( (code->args).add.arg2 );
            printf("\n");
            break;
        case Sub:
            // %10 = sub nsw i32 %9, 1
            displayFactor( (code->args).sub.retval );
            printf(" = sub nsw i32 ");
            displayFactor( (code->args).sub.arg1 );
            printf(", ");
            displayFactor( (code->args).sub.arg2 );
            printf("\n");
            break;
        case Mult:
            // %5 = mul nsw i32 %4, 2
            displayFactor( (code->args).add.retval );
            printf(" = mul nsw i32 ");
            displayFactor( (code->args).add.arg1 );
            printf(", ");
            displayFactor( (code->args).add.arg2 );
            printf("\n");
            break;
        case Div:
            // %3 = sdiv i32 %2, 2
            displayFactor( (code->args).sub.retval );
            printf(" = sdiv i32 ");
            displayFactor( (code->args).sub.arg1 );
            printf(", ");
            displayFactor( (code->args).sub.arg2 );
            printf("\n");
            break;
        case Icmp:
            // %4 = icmp sgt i32 %3, 0
            displayFactor( (code->args).icmp.retval );
            printf(" = icmp ");
            printf(cmp_array[(code->args).icmp.type]);
            printf(" i32 ");
            displayFactor( (code->args).icmp.arg1 );
            printf(", ");
            displayFactor( (code->args).icmp.arg2 );
            printf("\n");
            break;
        case Ret:
            // ret i32 0
            // printf("ret i32 ");
            // displayFactor( (code->args).ret.arg1 );
            // printf("\n");
            break;
        default:
            break;
    }
    displayLlvmcodes( code->next );
}

void displayLlvmfundecl( Fundecl *decl ){
    if( decl == NULL )
        return;
    printf("define i32 @%s() #0 {\n", decl->fname );
    displayLlvmcodes( decl->codes );
    printf("}\n");
    if( decl->next != NULL ) {
        printf("\n");
        displayLlvmfundecl( decl->next );
    }

    return;
}



void insertDecl(char *fname, unsigned arity, Factor *args)
{
    Fundecl *decl_ptr = (Fundecl *)malloc(sizeof(Fundecl));
    strcpy(decl_ptr->fname, fname);
    decl_ptr->arity = arity;
    decl_ptr->codes = codehd = codetl = NULL;
    decl_ptr->next = NULL;

    if (declhd == NULL)
    {
        declhd = decltl = decl_ptr;
    } else {
        decltl->next = decl_ptr;
        decltl = decl_ptr;
    }

    cntr = 1; // %1
    return;
}


Factor generateFactor(char *name)
{
    struct SymbolTable *rec = lookup(name);
    if (rec == NULL) {
        fprintf(stderr, "ERROR: %sは未定義の変数です。\n", name);
        exit(1);
    }

    Factor f;
    f.type = rec->kind;
    strcpy(f.vname, rec->name);
    f.val = NULL;
    return f;
}

void displayGlobalVar(){
    struct SymbolTable *rec;

    for (rec = stack_head_ptr; rec != NULL; rec = rec->next)
    {
        if (rec->kind != GLOBAL_VAR)
            break;

        printf("@%s = common global i32 0, align 4\n", rec->name);
    }

    printf("\n");
}