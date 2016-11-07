#ifndef _TABELASIMBOLO_LD_H_
#define _TABELASIMBOLO_LD_H_
#include "linked_op.h"

pointer swap_linked (pointer start, pointer p, pointer n);

pointer selection_alfa (pointer start);

pointer selection_freq (pointer start);

void unsorted_linked (FILE *input, char *ordenation_type);

#endif