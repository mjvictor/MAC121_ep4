#include <stdlib.h>
#include <string.h>
#include "tabelaSimbolo_VO.h"


SymbolTable *create_stable (int n) {
	SymbolTable *table;
	table = malloc (sizeof (SymbolTable));
	table->v = malloc (n * sizeof (pair));
	table->max = n;
	table->i = 0;
	for (i = 0; i < 1024; i++) {
		table->v[i].key = malloc (100 * sizeof (char));
		table->v[i].freq = 0;
	}
	return table;
}

void put_binary(SymbolTable *table, char *key) {
	
}



void destroy_stable (SymbolTable *table) {
	int i;
	for (i = 0; i < table->i; i++) free(table->v[i].key);
	free(table->v);
	free(table);
}


insersão binaria

busca binaria
