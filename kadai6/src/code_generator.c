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

int cntr = 0;
extern FILE *fp;
BrAddstack brstack = {{}, 0};
Labelstack lstack = {{}, 0};

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
    // displayfstack();
    return tmp;
}

void factorpush(Factor x)
{
    fstack.top++;
    fstack.element[fstack.top] = x;
    // displayfstack();
    return;
}

LLVMcode *brpop() {
    LLVMcode *tmp;
    tmp = brstack.element[brstack.top];
    brstack.top--;
    return tmp;
}

void brpush(LLVMcode *x) {
    brstack.top++;
    brstack.element[brstack.top] = x;
    return;
}

int labelpop() {
    int tmp;
    tmp = lstack.element[lstack.top];
    lstack.top--;
    return tmp;
}

void labelpush(int x) {
    lstack.top++;
    lstack.element[lstack.top] = x;
    return;
}


void displayfstack() {
    int i;
    for (i = 1; i <= fstack.top; i++) {
        displayFactor(fstack.element[i]);
        fprintf(fp, " ");
    }
    fprintf(fp, "\n");
}

void generateIcmp(Cmptype type) {
    LLVMcode *tmp;             /* 生成した命令へのポインタ */
    tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
    tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
    tmp->command = Icmp;        /* 命令の種類を加算に設定 */
    Factor arg1, arg2, retval; /* 結果 */

    // %4 = icmp sgt i32 %3, 0
    arg2 = factorpop();
    arg1 = factorpop();
    retval.type = LOCAL_VAR;
    retval.val = cntr++;
    (tmp->args).icmp.type = type;
    (tmp->args).icmp.arg1 = arg1;
    (tmp->args).icmp.arg2 = arg2;
    (tmp->args).icmp.retval = retval;
    insertCode(tmp);
    factorpush( retval );
}

void generateCall(Type rtype, Factor fname, Factor args[10]) {
    LLVMcode *tmp;              /* 生成した命令へのポインタ */
    tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
    tmp->next = NULL;           /* 次の命令へのポインタを初期化 */
    tmp->command = Call;        /* 命令の種類を加算に設定 */
    Factor retval;       /* 結果 */

    retval.type = LOCAL_VAR;
    if (rtype != VOID) {
        retval.val = cntr++;
    }
    (tmp->args).call.rtype = rtype;
    (tmp->args).call.fname = fname;
    int i;
    for (i = 0; i < fname.val; i++) {
        (tmp->args).call.args[i] = args[i];
    }
    (tmp->args).call.retval = retval;
    insertCode(tmp);
    if (rtype != VOID && strcmp(fname.vname, "read") != 0 && strcmp(fname.vname, "write") != 0) {
        factorpush(retval);
    }
}

void generateCode(LLVMcommand command) {
    LLVMcode *tmp;             /* 生成した命令へのポインタ */
    tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
    tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
    tmp->command = command;        /* 命令の種類を加算に設定 */
    Factor arg1, arg2, arg3, retval; /* 結果 */

    switch( command ){
        case Alloca:
            retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
            retval.val = cntr++;       /* 新規のレジスタ番号を取得 */
            (tmp->args).alloca.retval = retval; /* 返り場所のレジスタを指定 */
            insertCode(tmp);
            factorpush( retval ); /* 関数の返り場所をスタックにプッシュ */
            break;
        case Store:
            // store i32 10, i32* @n, align 4
            arg2 = factorpop();
            arg1 = factorpop();
            (tmp->args).store.arg1 = arg1;
            (tmp->args).store.arg2 = arg2;
            insertCode(tmp);
            break;
        case Load:
            // %6 = load i32, i32* @sum, align
            arg1 = factorpop();
            retval.type = LOCAL_VAR;
            retval.val = cntr++;
            (tmp->args).load.arg1 = arg1;
            (tmp->args).load.retval = retval;
            insertCode(tmp);
            factorpush( retval );
            break;
        case BrUncond:
            // br label %2
            insertCode(tmp);
            brpush(tmp);
            break;
        case BrCond:
            // br i1 %4, label %5, label %1
            arg1 = factorpop();
            (tmp->args).brcond.arg1 = arg1;
            insertCode(tmp);
            brpush(tmp);
            break;
        case Label:
            // ; <label>:5
            (tmp->args).label.l = cntr++;
            insertCode(tmp);
            break;
        case Add:
            // %8 = add nsw i32 %6, %7
            arg2 = factorpop();
            arg1 = factorpop();
            if (arg1.type != CONSTANT || arg2.type != CONSTANT) {
                retval.type = LOCAL_VAR;
                retval.val = cntr++;
                (tmp->args).add.arg1 = arg1;
                (tmp->args).add.arg2 = arg2;
                (tmp->args).add.retval = retval;
                insertCode(tmp);
            } else {
                retval.type = CONSTANT;
                retval.val = arg1.val + arg2.val;
            }
            factorpush( retval );
            break;
        case Sub:
            // %10 = sub nsw i32 %9, 1
            arg2 = factorpop();
            arg1 = factorpop();
            if (arg1.type != CONSTANT || arg2.type != CONSTANT) {
                retval.type = LOCAL_VAR;
                retval.val = cntr++;
                (tmp->args).sub.arg1 = arg1;
                (tmp->args).sub.arg2 = arg2;
                (tmp->args).sub.retval = retval;
                insertCode(tmp);
            } else {
                retval.type = CONSTANT;
                retval.val = arg1.val - arg2.val;
            }
            factorpush( retval );
            break;
        case Mult:
            // %3 = mul nsw i32 %2, 2
            arg2 = factorpop();
            arg1 = factorpop();
            if (arg1.type != CONSTANT || arg2.type != CONSTANT) {
                retval.type = LOCAL_VAR;
                retval.val = cntr++;
                (tmp->args).mult.arg1 = arg1;
                (tmp->args).mult.arg2 = arg2;
                (tmp->args).mult.retval = retval;
                insertCode(tmp);
            } else {
                retval.type = CONSTANT;
                retval.val = arg1.val * arg2.val;
            }
            factorpush( retval );
            break;
        case Div:
            // %10 = add nsw i32 %9, -1
            arg2 = factorpop();
            arg1 = factorpop();
            if (arg1.type != CONSTANT || arg2.type != CONSTANT) {
                retval.type = LOCAL_VAR;
                retval.val = cntr++;
                (tmp->args).div.arg1 = arg1;
                (tmp->args).div.arg2 = arg2;
                (tmp->args).div.retval = retval;
                insertCode(tmp);
            } else {
                retval.type = CONSTANT;
                retval.val = arg1.val / arg2.val;
            }
            factorpush( retval );
            break;
        case Ret:
            // ret i32 0
            arg1 = factorpop();
            if (strcmp(arg1.vname, "VOID") == 0) {
                (tmp->args).ret.rtype = VOID;
            } else {
                (tmp->args).ret.rtype = I32;
                (tmp->args).ret.arg1 = arg1;
            }

            insertCode(tmp);
            break;
        default:
            break;
    }
}


void insertCode(LLVMcode *tmp) {
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
            fprintf(fp, "@%s", factor.vname );
            break;
        case LOCAL_VAR:
            fprintf(fp, "%%%d", factor.val );
            break;
        case CONSTANT:
            fprintf(fp, "%d", factor.val );
            break;
        case PROC_NAME:
            fprintf(fp, "@%s", factor.vname );
            break;
        default:
            break;
    }

    return;
}

void displayLlvmcodes( LLVMcode *code ){
    if( code == NULL )
        return;

    switch( code->command ){
        case Alloca:
            // %1 = alloca i32, align 4
            fprintf(fp, "  ");
            displayFactor( (code->args).alloca.retval );
            fprintf(fp, " = alloca i32, align 4\n");
            break;
        case Store:
            // store i32 10, i32* @n, align
            fprintf(fp, "  ");
            fprintf(fp, "store i32 ");
            displayFactor( (code->args).store.arg1 );
            fprintf(fp, ", i32* ");
            displayFactor( (code->args).store.arg2 );
            fprintf(fp, ", align 4\n");
            break;
        case Load:
            // %6 = load i32, i32* @sum, align
            fprintf(fp, "  ");
            displayFactor( (code->args).load.retval );
            fprintf(fp, " = load i32, i32* ");
            displayFactor( (code->args).load.arg1 );
            fprintf(fp, ", align 4\n");
            break;
        case BrUncond:
            // br label %2
            fprintf(fp, "  ");
            fprintf(fp, "br label %%%d\n", (code->args).label.l );
            break;
        case BrCond:
            // br i1 %4, label %5, label %1
            fprintf(fp, "  ");
            fprintf(fp, "br i1 ");
            displayFactor( (code->args).brcond.arg1 );
            fprintf(fp, ", label %%%d, label %%%d\n", (code->args).brcond.arg2, (code->args).brcond.arg3);
            break;
        case Label:
            // ; <label>:5
            fprintf(fp, "\n%i:\n", (code->args).label.l );
            break;
        case Add:
            // %8 = add nsw i32 %6, %7
            fprintf(fp, "  ");
            displayFactor( (code->args).add.retval );
            fprintf(fp, " = add nsw i32 ");
            displayFactor( (code->args).add.arg1 );
            fprintf(fp, ", ");
            displayFactor( (code->args).add.arg2 );
            fprintf(fp, "\n");
            break;
        case Sub:
            // %10 = sub nsw i32 %9, 1
            fprintf(fp, "  ");
            displayFactor( (code->args).sub.retval );
            fprintf(fp, " = sub nsw i32 ");
            displayFactor( (code->args).sub.arg1 );
            fprintf(fp, ", ");
            displayFactor( (code->args).sub.arg2 );
            fprintf(fp, "\n");
            break;
        case Mult:
            // %5 = mul nsw i32 %4, 2
            fprintf(fp, "  ");
            displayFactor( (code->args).add.retval );
            fprintf(fp, " = mul nsw i32 ");
            displayFactor( (code->args).add.arg1 );
            fprintf(fp, ", ");
            displayFactor( (code->args).add.arg2 );
            fprintf(fp, "\n");
            break;
        case Div:
            // %3 = sdiv i32 %2, 2
            fprintf(fp, "  ");
            displayFactor( (code->args).sub.retval );
            fprintf(fp, " = sdiv i32 ");
            displayFactor( (code->args).sub.arg1 );
            fprintf(fp, ", ");
            displayFactor( (code->args).sub.arg2 );
            fprintf(fp, "\n");
            break;
        case Icmp:
            // %4 = icmp sgt i32 %3, 0
            fprintf(fp, "  ");
            displayFactor( (code->args).icmp.retval );
            fprintf(fp, " = icmp ");
            fprintf(fp, "%s", cmp_array[(code->args).icmp.type]);
            // fprintf(fp, "%d", (code->args).icmp.type);
            fprintf(fp, " i32 ");
            displayFactor( (code->args).icmp.arg1 );
            fprintf(fp, ", ");
            displayFactor( (code->args).icmp.arg2 );
            fprintf(fp, "\n");
            break;
        case Ret:
            // ret i32 0
            fprintf(fp, "  ");
            fprintf(fp, "ret ");
            switch ((code->args).ret.rtype)
            {
            case VOID:
                fprintf(fp, "void");
                break;
            case I32:
                fprintf(fp, "i32 ");
                displayFactor( (code->args).ret.arg1 );
                break;
            default:
                break;
            }
            fprintf(fp, "\n");
            break;
        case Call:
            // call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i32 0, i32 0), i32 %6)
            fprintf(fp, "  ");
            switch ((code->args).call.rtype)
            {
            case VOID:
                fprintf(fp, "call void ");
                break;
            case I32:
                displayFactor((code->args).call.retval);
                fprintf(fp, " = call i32 (i8*, ...) ");
                break;
            default:
                break;
            }

            displayFactor( (code->args).call.fname );
            int arity = (code->args).call.fname.val;
            if (arity > 0) {
                if (strcmp((code->args).call.fname.vname, "scanf") == 0) {
                    fprintf(fp, "(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str1, i32 0, i32 0)");
                } else if (strcmp((code->args).call.fname.vname, "printf") == 0) {
                    fprintf(fp, "(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str2, i32 0, i32 0)");
                } else {
                    fprintf(fp, "(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str1, i32 0, i32 0)");
                }

                int i;
                for (i = 0; i < arity; i++) {
                    if (strcmp((code->args).call.fname.vname, "scanf") == 0) {
                        fprintf(fp, ", i32* ");
                    } else if (strcmp((code->args).call.fname.vname, "printf") == 0) {
                        fprintf(fp, ", i32 ");
                    } else {
                        fprintf(fp, ", i32 ");
                    }

                    displayFactor( (code->args).call.args[i] );
                }
            } else {
                fprintf(fp, "(");
            }

            fprintf(fp, ")\n");
            break;
        default:
            break;
    }
    displayLlvmcodes( code->next );
}

void displayLlvmfundecl( Fundecl *decl ){
    if( decl == NULL )
        return;
    fprintf(fp, "define ");
    fprintf(fp, "%s ", (strcmp(decl->fname, "main") == 0) ? "i32": "void");
    fprintf(fp, "@%s() #0 {\n", decl->fname );
    displayLlvmcodes( decl->codes );
    fprintf(fp, "}\n");
    if( decl->next != NULL ) {
        fprintf(fp, "\n");
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
    f.val = rec->addr;
    return f;
}

void displayGlobalVar(){
    struct SymbolTable *rec;
    fprintf(fp, "@.str1 = private unnamed_addr constant [3 x i8] c\"%%d\\00\", align 1\n");
    fprintf(fp, "@.str2 = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\", align 1\n");
    for (rec = stack_head_ptr; rec != NULL; rec = rec->next)
    {
        if (rec->kind != GLOBAL_VAR)
            break;

        fprintf(fp, "@%s = common global i32 0, align 4\n", rec->name);
    }

    fprintf(fp, "\n");
}

Factor *getArgs() {
    Factor args[10] = {};
    printf("getArg\n");

    while (fstack.top != 0) {
        Factor f = factorpop();
        args[fstack.top] = f;

        switch( f.type ){
            case GLOBAL_VAR:
                printf("@%s", f.vname );
                break;
            case LOCAL_VAR:
                printf("%%%d", f.val );
                break;
            case CONSTANT:
                printf("%d", f.val );
                break;
            case PROC_NAME:
                printf("@%s", f.vname );
                break;
            default:
                break;
        }
    }
    printf("\n----------------\n");
    return &args;
}