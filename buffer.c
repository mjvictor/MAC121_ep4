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
void put_char (Buffer *B, char c) {

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
		
		free(new_buf->data);
		new_buf->data = NULL;
		
		free(new_buf);
		new_buf = NULL;
	}

	B->data[B->i] = c;
	B->i++;
}

int read_word (FILE *input, Buffer *word) {
	
	int i; 
	char c;

	buffer_reset (word);
	
	c = fgetc(input);
	i = (int)c;
	while (c != EOF && (i < 65 || i > 122 || (i > 90 && i < 97))) {
		c = fgetc (input);
		i = (int)c;
	}
    /*The text file is read, the words and their frequency are registered.*/
	while (c != EOF && (isspace (c)) == 0) {
		put_char(word, ((char)c));
		c = fgetc(input);
	}

	if (c == EOF) return -1;
	return (word->i);
}

void print_buffer (Buffer *word) {
	if (word->i) printf("%s\n", word->data);
}

/*
  Read a line (i.e., reads up to a newline '\n' character or the
  end-of-file) from the input file and places it into the given
  buffer, including the newline character if it is present. The buffer
  is resetted before the line is read.

  Returns the number of characters read; in particular, returns ZERO
  if end-of-file is reached before any characters are read.

int read_line(FILE *input, Buffer *B) {

	int c, word;

	word = 0;
	buffer_reset(B);

	while ((c = fgetc(input)) != EOF && c != 10) {
		
		if (isspace (c) && word) {
			buffer_push_back(B, ((char)c));
			word = 0;
		}

		else if (!isspace (c)) {
			word++;
			buffer_push_back(B, ((char)c));
		}
	}


 	
 	if (c == 10) {
 		
 		if (B->i && isspace (B->data[B->i - 1])) {
 			B->i--;
 		}
 		
 		buffer_push_back(B, ((char)c));
 	}
 	
 	else {
 		
 		if (isspace (B->data[B->i - 1]))
 			B->i--;
 	}
 	
 	return B->i; 
}
*/