#include <stdio.h>
#include <stdlib.h>



int main (int argc, char **argv) {
	int struct_type, ordenation_type;
	FILE *input;

	input = fopen (argv[1], "r");

	struct_type = argv[2];

	ordenation_type = argv[3];

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
	
	return 0;
}