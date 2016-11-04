#ifndef _LINKED_OP_H_
#define _LINKED_OP_H_
#include <stable_op.h>

typedef struct no{
	pair info;
	struc no *prox;
}celula;

typedef celula* pointer;

pointer create_celula (int n);

void insert_start (apontador *start, pair v);

#endif
