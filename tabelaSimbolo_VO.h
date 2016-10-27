#ifndef _TABELASIMBOLO_VO_H_
#define _TABELASIMBOLO_VO_H_

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

void put_stable (SymbolTable *table, char *key);

#endif