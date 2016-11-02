#ifndef _TABELASIMBOLO_VD_H_
#define _TABELASIMBOLO_VD_H_
#include <stdio.h>

int find_word (SymbolTable *table, char *key);

void insert_VD (SymbolTable *table, char *key);

void intercalate_freq (int start, int mid, int end, SymbolTable *table);

void intercalate_alfa (int start, int mid, int end, SymbolTable *table);

void mergesort (int start, int end, SymbolTable *table, char *ordenation_type);

void unsorted_vector (FILE *input, char *ordenation_type);

#endif