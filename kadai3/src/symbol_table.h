#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 記号表の管理 + 変数・定数の区別用 */
typedef enum {
    GLOBAL_VAR, /* 大域変数 */
    LOCAL_VAR, /* 局所変数 */
    PROC_NAME, /* 手続き */
    CONSTANT /* 定数 */
} Scope;


struct SymbolTable
{
  char *name;
  unsigned int addr;
  Scope kind;
  struct SymbolTable *next;
};

// struct SymbolTable *stack_head_ptr;


void print_rec(struct SymbolTable *rec);
void print_all();
struct SymbolTable *lookup(char *name, Scope kind);
void delete(Scope kind);
void insert(char *name, Scope kind);