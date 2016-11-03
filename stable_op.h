#ifndef _STABLE_OP_H_
#define _STABLE_OP_H_

#include <stdio.h>
typedef struct {
	char *key;
	int freq;
}pair;

typedef struct {
	pair *v;
	int i;
	int max;
}SymbolTable;

SymbolTable *create_stable ();

void reallocate_stable (SymbolTable *table);

void put_word (SymbolTable *table, int i, char *key);

void destroy_stable (SymbolTable *table);

void print_stable (SymbolTable *table);

void print_stableInv (SymbolTable *table);

#endif