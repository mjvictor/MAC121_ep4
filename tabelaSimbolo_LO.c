#include <string.h>
#include "buffer.h"
#include "linked_op.h"
#include "tabelaSimbolo_LD.h"

pointer insert_sorted (pointer start, char *key) {
	int i;
	pointer p, ant, new;
	new = create_celula (key);
	for (p = start, ant = NULL, i = strcmp(p->info.key, key); p != NULL && i < 0; 
		ant = p, p = p->prox, i = strcmp(p->info.key, key));
	if (ant == NULL) start = new;
	else {
		if (i == 0)	{
			p->info.freq++;
			return start;
		}
		else ant->prox = new;
	}
	new->prox = p;
	return start; 
}

void sorted_linked (FILE *input, char *ordenation_type) {
	Buffer *word;
	pointer start;
	word = buffer_create ();

	while (read_word(input, word) != -1)
		start = insert_sorted (start, key);
	if (word->i)
		start = insert_sorted (start, key);

	if (ordenation_type[0] == "O")
		selection_freq (start);

	print_linked (start);

	buffer_destroy (word);

	destroy_linked (start);
}