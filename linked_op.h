#ifndef _LINKED_OP_H_
#define _LINKED_OP_H_
#include <stable_op.h>

typedef struct no{
	pair info;
	struc no *prox;
}celula;

typedef celula* pointer;

pointer create_celula (char *key);

void insert_start (apontador *start, char *key);

pointer find_linked (pointer start, char *key);

void print_linked (pointer start);

void destroy_linked (pointer start);

#endif
