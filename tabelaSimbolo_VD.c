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
	if (table->i == table->max) 
		reallocate_stable (table);

	put_word (table, table->i, key);
	table->v[table->i].freq++;
	table->i++;
}

int compare_freq (const void * a, const void * b){
  if ((*(pair*)a).freq < (*(pair*)b).freq) return -1;
  if ((*(pair*)a).freq == (*(pair*)b).freq) return 0;
  if ((*(pair*)a).freq > (*(pair*)b).freq) return 1;
  return 0;
}

int compare_alfa (const void * a, const void * b){
	return (strcmp ((*(pair *)a).key, (*(pair *)b).key));
}

void unsorted_vector (FILE *input, char *ordenation_type) {
	int check_find, cond;
	SymbolTable *table;
	Buffer *word;
	word = buffer_create();
	table = create_stable (100);

	while ((cond = read_word(input, word)) != -1) {
		check_find = find_word (table, word->data);
		if (check_find == -1) 
			insert_VD (table, word->data);
		else 
			table->v[check_find].freq++;
	} 
	if (word->i) {
		check_find = find_word (table, word->data);
		if (check_find == -1) 
			insert_VD (table, word->data);
		else 
			table->v[check_find].freq++;
	}
	
	if (ordenation_type[0] == 'A') {
		qsort (table->v, table->i, sizeof(pair), compare_alfa);
		print_stable (table);
	}
	else { 
		qsort (table->v, table->i, sizeof(pair), compare_freq);
		print_stableInv (table);
	}
	

	buffer_destroy (word);

	destroy_stable (table);
}