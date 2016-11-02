#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stable_op.h"
#include "buffer.h"
/*coloca desordenado, coloca no topo.*/

int find_word (SymbolTable *table, char *key){
	int i;
	for (i = 0; i < table->i; i++) 
		if (!strcmp (table->v[i].key, key)) return i;
	return -1;
}

void insert_VD (SymbolTable *table, char *key) {
	printf("key: %s\n", key);
	if (table->i == table->max) 
		reallocate_stable (table);

	put_word (table, table->i, key);
	printf("saida: %s\n", table->v[table->i].key);
	table->v[table->i].freq++;
	table->i++;
}
/*verificar a necessidade de fazer um intercalate_alfa e um
intercalate_freq.*/

void intercalate_freq (int start, int mid, int end, SymbolTable *table) {
	int i = start, j = mid + 1;
	SymbolTable *new;
	new = create_stable(end - start);

	print_stable (new);
	while (i < (mid + 1) && j < (end + 1)) {
		printf ("freq i:%d freq j:%d\n", table->v[i].freq, table->v[j].freq);
		if (table->v[i].freq > table->v[j].freq) {
			insert_VD(new, table->v[j].key);
			new->v[(new->i) - 1].freq = (table->v[j].freq);
			j++;
		}
		else {
			insert_VD(new, table->v[i].key);
			new->v[(new->i) - 1].freq = (table->v[i].freq);
			i++;
		}	
	}

	print_stable (new);
	
	while (i < (mid + 1)) {
		printf("TED\n");
		insert_VD(new, table->v[i].key);
		new->v[(new->i - 1)].freq = table->v[i].freq;
		i++;
	}
	while (j < (end + 1)) {
		printf("TED\n");
		insert_VD(new, table->v[j].key);
		new->v[(new->i - 1)].freq = table->v[j].freq;
		j++;
	}

	printf ("%s %d\n", new->v[new->i - 1].key, new->v[new->i - 1].freq);

	print_stable (new);

	for (i = start; i < (end + 1); i++) {
		table->v[i].key = strdup(new->v[i - start].key);
		table->v[i].freq = new->v[i - start].freq;
	}

	destroy_stable (new);
}

void intercalate_alfa (int start, int mid, int end, SymbolTable *table) {
	int i = start, j = mid + 1, cmp;
	SymbolTable *new;
	new = create_stable(end - start);
	while (i < mid + 1 && j < end + 1) {
		cmp = strcmp (table->v[i].key, table->v[j].key);
		if (cmp > 0) {
			insert_VD (new, table->v[j].key);
			new->v[(new->i) - 1].freq = (table->v[j].freq);
			j++;
		}
		else {
			insert_VD (new, table->v[i].key);
			new->v[(new->i) - 1].freq = (table->v[i].freq);
			i++;
		}	
	}
	while (i < mid + 1) {
		printf("TED\n");
		insert_VD (new, table->v[i].key);
		new->v[(new->i) - 1].freq = (table->v[i].freq);
		i++;
	}
	while (j < end + 1) {
		printf("TED\n");
		insert_VD (new, table->v[j].key);
		new->v[(new->i) - 1].freq = (table->v[j].freq);
		j++;
	}

	for (i = start; i < (end + 1); i++) {
		printf("%s\n", new->v[i - start].key);
		table->v[i].key = strdup(new->v[i - start].key);
		table->v[i].freq = new->v[i - start].freq;
	}

	destroy_stable (new);
} 		

void mergesort (int start, int end, SymbolTable *table, char *ordenation_type) {
	int mid;
	char a[1];
	a[0] = 'A';
	if (end > start) {
		mid = (start + end) / 2;
		mergesort (start, mid, table, ordenation_type);
		mergesort (mid + 1, end, table, ordenation_type);
		if (!(strcmp (ordenation_type, a))) { 
			intercalate_alfa (start, mid, end, table);
		}
		else {
			intercalate_freq (start, mid, end, table);
		}
	}
}

void unsorted_vector (FILE *input, char *ordenation_type) {
	int check_find;
	SymbolTable *table;
	Buffer *word;
	word = buffer_create();
	table = create_stable (100);

	while (read_word(input, word) != -1) {
		check_find = find_word (table, word->data);
		if (check_find == -1) 
			insert_VD (table, word->data);
		else 
			table->v[check_find].freq++;
	} 
	check_find = find_word (table, word->data);
		if (check_find == -1) 
			insert_VD (table, word->data);
		else 
			table->v[check_find].freq++;


	printf ("\n\n");

	print_stable (table);

	printf("stable size: %d\n", table->i);

	printf ("\n\n");
	mergesort (0, table->i - 1, table, ordenation_type);
	
	print_stable (table);

	buffer_destroy (word);

	destroy_stable (table);
}