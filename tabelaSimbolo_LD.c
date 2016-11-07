#include "linked_op.h"

pointer swap_linked (pointer start, pointer p, pointer n){
	tmp.key = strdup (p->info.key)
	tmp.freq = p->info.freq;
	if (strlen(p->info.key) >= strlen(n->info.key)) {
		free(p->info.key);
		p->info.key = strdup (n->info.key);
	}
	else p->info.key = strcpy (n->info.key);
	p->info.freq = n->info.freq;
	if (strlen(n->info.key) >= strlen(tmp.key)) {
		free(n->info.key);
		n->info.key = strdup (tmp.key);
	}
	else n->info.key = strcpy (tmp.key);
	n->info.freq = tmp.freq;

	free(tmp.key);
	return start;
}

pointer selection_alfa (pointer start) {
	int i;
	pointer p, ant;
	pair tmp;
	for (p = start; p != NULL; p = p->prox) {
		for (n = p->prox; n != NULL; n = n->prox) {
			i = strcmp (p->info.key, n->info.key);
			if (i > 0)
				swap_linked (start, p, n);
		}
	}
	return start;
}

pointer selection_freq (pointer start) {
	pointer p, ant;
	pair tmp;
	for (p = start; p != NULL; p = p->prox) {
		for (n = p->prox; n != NULL; n = n->prox) {
			if (p->info.freq < n->info.freq)
				swap_linked (start, p, n);
		}
	}
	return start;
}


void unsorted_linked (FILE *input, char *ordenation_type) {
	pointer start;
	Buffer *word;
	word = buffer_create ();

	while (read_word(input, word) != -1) {
		p = find_linked (start);
		if (p == NULL) 
			insert_start (&start, key);
		else 
			p->info.freq++;
	} 
	if (word->i) {
		p = find_linked (start);
		if (p == NULL) 
			insert_start (&start, key);
		else 
			p->info.freq++;
	}

	if (ordenation_type[0] == "A") 
		selection_alfa (start);
	else 
		selection_freq (start);

	print_linked (start);

	buffer_destroy (word);

	destroy_linked (start);
}

