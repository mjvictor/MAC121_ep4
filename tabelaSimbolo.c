#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buffer.h"
#include "stable_op.h"
#include "tabelaSimbolo_VD.h"

int main (int argc, char **argv) {
	/*char *struct_type, */
	char *ordenation_type;
	
	FILE *input;

	input = fopen (argv[1], "r");

/*
	Buffer *word;
	struct_type = strdup (argv[2]);

	ordenation_type = strdup (argv[3]);
	
	switch (struct_type) {
		case "VD":
	
			break;
		case "VO":

			break;
		case "LO":

			break;
		case "LD":

			break;
		case "AB":
		
			break;
	}
	
	word = buffer_create();

	while (read_word(input, word) != -1) {
		print_buffer (word);
	} 

	print_buffer (word);
	buffer_destroy (word);
	*/

	ordenation_type = argv[2];

	printf("%s\n", ordenation_type);

	unsorted_vector (input, argv[2]);

	return 0;
}