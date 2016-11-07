#include <stdlib.h>
#include <string.h>
#include "tabelaSimbolo_VO.h"
#include "stable_op.h"
#include "buffer.h"

int find_wordBin (SymbolTable *table, char *key, int *flag) {
	int start, end, mid, comp;
	start = 0;
	if (table->i == 0) {
		printf("0\n");
		return 0;
	}
	else 
		end = table->i - 1;

	while (start <= end) {
		mid = (start + end) / 2;
		comp = strcmp (table->v[mid].key, key);
		if (comp == 0) {
			*flag = 1;
			printf ("%d\n", mid);
			return mid;	
		}
		else if (comp > 0) end = mid - 1;
		else start = mid + 1;
	}
	printf ("%d\n", end);
	return (end);
}
/*
int find_freq (SymbolTable *table, int x) {
	int start, end, mid;
	start = 0; 
	end = table->i - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (table->v[mid].freq == x) return mid;
		if (table->v[mid].freq > x) end = mid - 1;
		else start = mid + 1;
	}
	return (end);
} 
*/
void insert_VO (SymbolTable *table, int i, char *key) {
	int j;
	if (table->i == table->max) 
		reallocate_stable (table);
	if (i > 0) 	
		for (j = (table->i - 1); j > i; j--) {
			put_word (table, j + 1, table->v[j].key);
			table->v[j + 1].freq = table->v[j].freq;
		}
	put_word (table, i, key);
	table->v[i].freq = 1;
}
/*
void correct_freq (SymbolTable *table, int i, int j) {
	int ind;
	pair tmp;
	tmp.key = strdup (table->v[i].key);
	tmp.freq = table->v[i].freq;
	for (ind = i; ind < j; ind++) {
		table->v[ind].key = strdup (table->v[ind + 1].key);
		table->v[ind].freq = table->v[ind + 1].freq;
	}
	table->v[j].key = strdup (tmp.key);
	table->v[j].freq = tmp.freq;
}

*/
void sorted_array (FILE *input, char *type) {
	int i, flag = 0;
	SymbolTable *table;
	Buffer *word;

	table = create_stable (100);
	word = buffer_create ();
	printf ("%s\n", type);


	for (;read_word (input, word) != -1; flag = 0) {
		i = find_wordBin (table, word->data, &flag);
		printf ("%d\n", flag);
		if (flag) 
			table->v[i].freq++;
		else {
			insert_VO (table, i, word->data);
		}
	}
	if (word->i) {
		i = find_wordBin (table, word->data, &flag);
		if (flag) 
			table->v[i].freq++;
		else 
			insert_VO (table, i, word->data);
	}	
	
	/*
	if (type[0] == 'A'){
		
	}
	
	else {
		while (read_word (input, word) != -1) {
			i = find_wordBin (table, word->data);
			if (i == -1) {
				table->v[i].freq++;
				j = find_freq (table, table->v[i].freq);
				correct_freq (table, i, j);
			}
			else insert_VO (table, 0, word->data);
		}
		i = find_wordBin (table, word->data);
		if (i == -1) {
			table->v[i].freq++;
			j = find_freq (table, table->v[i].freq);
			correct_freq (table, i, j);
		}
		else insert_VO (table, 0, word->data);
	}
	*/

	print_stable (table);

	buffer_destroy (word);
		
	destroy_stable (table);
}