#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stable_op.h"

SymbolTable *create_stable (int n) {
	int i;
	SymbolTable *table;
	table = malloc (sizeof (SymbolTable));
	table->v = malloc (n * sizeof (pair));
	table->max = n;
	table->i = 0;
	for (i = 0; i < n; i++) {
		table->v[i].key = malloc (100 * sizeof (char));
		table->v[i].key = NULL;
		table->v[i].freq = 0;
	}
	return table;
}

void put_word (SymbolTable *table, int i, char *key) {
	/*
	int len;
	len = strlen (key);
	if (len > (strlen (table->v[i].key))) {
		free (table->v[i].key);
		table->v[i].key = malloc (len * sizeof (key));
	}
	*/
	table->v[i].key = strdup (table->v[i].key, key);

}

void reallocate_stable (SymbolTable *table) {
	SymbolTable *new;
	int i;
	new = create_stable (2*table->max);
	for (i = 0; i < table->max; i++, new->i++) {
		put_word (new, table->i, table->v[i].key);
		new->v[i].freq = table->v[i].freq;
		free(table->v[i].key);
	}
	free(table->v);
	table->v = new->v;
	table->max *= 2;
}

void destroy_stable (SymbolTable *table) {
	int i;
	for (i = 0; i < table->i; i++) free(table->v[i].key);
	free(table->v);
	free(table);
}

void print_stable (SymbolTable *table) {
	int i;
	printf("\n");
	for (i = 0; i< table->i; i++)
		printf("%s  %d\n", table->v[i].key, table->v[i].freq);
	printf("\n");
}

void print_stableInv (SymbolTable *table) {
	int i;
	printf("\n");
	for (i = table->i - 1; i >= 0; i--)
		printf("%s  %d\n", table->v[i].key, table->v[i].freq);
	printf("\n");
}