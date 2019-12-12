#include <string.h>
#include <stdlib.h>
#include "symbol_table.h"

struct SymbolTable *stack_head_ptr = NULL;
struct SymbolTable *stack_tail_ptr;
// *stack_head_ptr = NULL;


void print_rec(struct SymbolTable *rec)
{
    Scope scope_kind = rec->kind;

    if (rec != NULL)
    {
        switch (scope_kind)
        {
        case GLOBAL_VAR:
            printf("    %s %u GLOBAL \n", rec->name, rec->addr);
            break;

        case LOCAL_VAR:
            printf("    %s %u LOCAL\n", rec->name, rec->addr);
            break;

        case PROC_NAME:
            printf("    %s %u PROC\n", rec->name, rec->addr);
            break;

        // case CONSTANT:
        //     /* code */
        //     break;

        default:
            printf("%s    %u    !INVALID_INPUT!\n", rec->name, rec->addr);
            break;
        }
    }
}

void print_all()
{
    struct SymbolTable *rec;

    rec = stack_head_ptr;
    while (1)
    {
        print_rec(rec);
        if (rec->next == NULL)
            break;
        rec = rec->next;
    }
}

void insert(char *name, Scope kind)
{
    struct SymbolTable *new_rec, *rec;
    static unsigned int addr = 0;

    new_rec = (struct SymbolTable *)malloc(sizeof(struct SymbolTable *));
    new_rec->name = (char *)malloc(strlen(name));

    new_rec->next = NULL;
    strcpy((new_rec->name), name);
    new_rec->addr = addr;
    new_rec->kind = kind;

    if (stack_head_ptr == NULL)
    {
        //最初
        stack_head_ptr = new_rec;
        stack_tail_ptr = new_rec;
    }
    else
    {
        // 以降
        rec = stack_tail_ptr;
        stack_tail_ptr = new_rec;
        rec->next = new_rec;
    }
    addr++; //先頭アドレスをインクリメント

    printf("insert:\n");
    print_all();
    printf("\n↓\n↓\n\n");
}

//変数を検索して、すでに登録してあればその構造体のアドレスを返す
struct SymbolTable *lookup(char *name, Scope kind)
{
    struct SymbolTable *rec;

    rec = stack_head_ptr;
    for (rec = stack_head_ptr; rec != NULL; rec = rec->next)
    {
        if (strcmp(rec->name, name) == 0)
            break;
    }

    printf("lookup:\n");
    print_rec(rec);
    printf("\n↓\n↓\n\n");
    // 見つからなかった場合はrecにNULLが入っている
    return rec;
}

void delete()
{
    if (stack_head_ptr == NULL){
        printf("delete error:\n");
        printf("    記号表が空です\n");
        printf("\n↓\n↓\n\n");
        return;
    }

    struct SymbolTable *tmp, *rec;
    tmp = NULL;

    for (rec = stack_head_ptr; rec != NULL; rec = rec->next){
        if (rec->kind == PROC_NAME) {
            tmp = rec;
        }
    }

    if (tmp != NULL) {
        stack_tail_ptr = tmp;
        for (rec = tmp->next; rec != NULL;) {
            struct SymbolTable *tmp2;
            tmp2 = rec;
            rec = rec->next;
            free(tmp2);
        }
        tmp->next = NULL;
        // rec = tmp->next;
        // tmp->next = NULL;
        // while(rec != NULL){
        //     tmp = rec;
        //     rec = rec->next;
        //     free(tmp);
        // }
    }

    printf("delete complete:\n");
    print_all();
    printf("\n↓\n↓\n\n");
}
