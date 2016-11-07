#include <stdlib.h>
#include <string.h>
#include "linked_op.h"

pointer create_celula (char *key) {
	pointer new;
	new = malloc (sizeof(celula));
	new->info = malloc(sizeof(pair));
	new->info.key = strdup (key);
	new->info.freq = 1;
	return new;
}	

void insert_start (apontador *start, char *key) {
	pointer p;
	p = create_celula (key);
	p->prox = *start;
	*start = p;
}

pointer find_linked (pointer start, char *key) {
	if (start == NULL) return NULL;
	if (!strcmp(start->info.key, key)) return start;
	return (find_linked(start->prox, key));
}

void print_linked (pointer start) {
	pointer p;
	for (p = start; p != NULL; p = p->prox) 
		printf ("%s %d\n", p->info.key, p->info.freq);
}

void destroy_linked (pointer start) {
	pointer p, ant;
	for (p = start, ant = NULL; p != NULL; ant = p, p = p->prox) {
		free (p->info.key);
		if (ant != NULL) {
			free (ant);
		}
	}
}
