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

SymbolTable *create_stable () {
	SymbolTable *table;
	table = malloc (sizeof (SymbolTable));
	table->v = malloc (1024 * sizeof (pair));
	table->max = 1024;
	table->i = 0;
	for (i = 0; i < 1024; i++) {
		table->v[i].key = malloc (100 * sizeof (char));
		table->v[i].freq = 0;
	}
	return table;
}

void put_stable (SymbolTable *table, char *key) {
	

	if (table->i == table->max) {

	}
}

#endif