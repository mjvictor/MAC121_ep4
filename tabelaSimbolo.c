#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabelaSimbolo_VD.h"
#include "tabelaSimbolo_VO.h"

void switch_type (FILE *input, char *struct_type, char *sort_type) {
	if (!(strcmp(sort_type, "VD")))
		unsorted_array (input, struct_type);
	else if (!(strcmp(sort_type, "VO")))
		sorted_array (input, struct_type);
	else if (!(strcmp(sort_type, "LD")))
		unsorted_linked (input, struct_type);
	else if (!(strcmp(sort_type, "LO")))
		sorted_linked (input, struct_type);
	else 
		binary_tree (input, struct_type);
}

int main (int argc, char **argv) {
	FILE *input;

	input = fopen (argv[1], "r");

	if (!(strcmp(argv[2], "VD"))) {
		unsorted_vector (input, argv[3]);
	}
	else {
		sorted_array (input, argv[3]);
	}

	return 0;
}