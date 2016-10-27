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

void put_stable (SymbolTable *table, char *key) {
	SymbolTable *new;
	char *word;
	int len;

	if (table->i == table->max) {
		new = create_stable (2*table->max);
		for (i = 0; i < table->max; i++) {
			/*melhorar isso*/
			len = strlen (table->v[i].key);
			free (new->v[i].key);
			new->v[i].key = malloc (len * sizeof (char));
			new->v[i].key = strdup (table->v[i].key);
			new->v[i].freq = table->v[i].freq
			free(table->v[i].key);
		}
		free(table->v);
		table->v = new->v;
	}
	table->v[table->i].key = strdup (key);
	table->v[table->i].freq++;
	table->i++;
}


insersão binaria

busca binaria
