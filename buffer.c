#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "buffer.h"

/*
  Create and return a new and empty buffer.
*/
Buffer *buffer_create() {
	
	Buffer *buf;
	buf = malloc(sizeof(Buffer));
	
	buf->data = malloc(10);
	buf->max = 10;
	buf->i = 0; 
	
	return(buf);
}

/*
  Destroy a buffer.
*/
void buffer_destroy(Buffer *B) {
	
	free(B->data);
	B->data = NULL;
	
	free(B);
	B = NULL;
}

/*
  Reset buffer, eliminating contents.
*/
void buffer_reset(Buffer *B) {

	while (B->i > 0) {
		
		B->data[B->i] = 0;
		B->i--;
	}
	B->max = 10;

}

/*
  Add a character c to the end of the buffer.
*/
void put_char (Buffer *B, int c) {

	int j;
	Buffer *new_buf;
	
	/*Realloc the buffer if necessary.*/
	if (B->i >= B->max) {
		new_buf = malloc(sizeof(Buffer));
		new_buf->data = malloc(2*(B->max));

		for (j = 0 ; j < B->max; j++)
			new_buf->data[j] = B->data[j];

		free(B->data);
		B->data = new_buf->data;
		B->i = B->max;
		B->max  *= 2;
	}
	if (c > 64 && c < 91) c = tolower (c);
	B->data[B->i] = (char)c;
	B->i++;
}

int read_word (FILE *input, Buffer *word) {
	int c;

	buffer_reset (word);
	
	c = fgetc(input);
	while (c != EOF && (c < 65 || c > 122 || (c > 90 && c < 97))) {
		c = fgetc (input);
	}
    /*The text file is read, the words and their frequency are registered.*/
	while (c != EOF && ((c > 47 && c < 58) || 
		  (c > 64 && c < 91) || (c > 96 && c < 126))) {
		put_char(word, c);
		c = fgetc(input);
	}

	if (c == EOF) return -1;
	return (word->i);
}

void print_buffer (Buffer *word) {
	if (word->i) printf("%s\n", word->data);
}