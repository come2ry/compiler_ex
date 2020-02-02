#ifndef SYMBOL_DATE
#define SYMBOL_DATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"


struct SymbolTable
{
  char *name;
  unsigned int addr;
  Scope kind;
  struct SymbolTable *next;
};

struct SymbolTable *stack_head_ptr;
struct SymbolTable *stack_tail_ptr;

void print_rec(struct SymbolTable *rec);
void print_all();
struct SymbolTable *lookup(char *name);
void delete();
void insert(char *name, Scope kind, int cntr);
#endif