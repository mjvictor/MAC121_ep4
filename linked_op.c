#include <stdlib.h>
#include "linked_op.h"

pointer create_celula (int n) {
	pointer new;
	new = malloc (sizeof(celula));
	new->info = malloc(sizeof(pair));
	new->info.key = malloc (n * sizeof(char));
	new->info.freq = 0;
	return new;
}	

void insert_start (apontador *start, pair v) {
	pointer p;
	p = malloc (sizeof (celula));
	p->info.key = strdup (v.key);
	p->info.freq = v.freq;
	p->prox = *start;
	*start = p;
}