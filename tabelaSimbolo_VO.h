#ifndef _TABELASIMBOLO_VO_H_
#define _TABELASIMBOLO_VO_H_
#include "stable_op.h"


int find_wordBin (SymbolTable *table, char *key, int *flag);

int find_freq (SymbolTable *table, int x);

void insert_VO (SymbolTable *table, int i, char *key);

void correct_freq (SymbolTable *table, int i, int j);

void sorted_array (FILE *input, char *type);

#endif