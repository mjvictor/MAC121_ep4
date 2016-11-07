#ifndef _TABELASIMBOLO_VD_H_
#define _TABELASIMBOLO_VD_H_
#include <stdio.h>

int find_word (SymbolTable *table, char *key);

void insert_VD (SymbolTable *table, char *key);

int compar_freq (const void * a, const void * b);

int compar_alfa (const void * a, const void * b);

void unsorted_array (FILE *input, char *ordenation_type);

#endif	