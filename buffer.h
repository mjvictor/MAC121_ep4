/*
  buffer.h

  A character buffer.
*/

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <stdio.h>

/*Buffer struct.*/
typedef struct buffer_s {
  char *data;
  int max, i;
} Buffer;

/*
  Create and return a new and empty buffer.
*/
Buffer *buffer_create();

/*
  Destroy a buffer.
*/
void buffer_destroy(Buffer *B);

/*
  Reset buffer, eliminating contents.
*/
void buffer_reset(Buffer *B);

/*
  Add a character c to the end of the buffer.
*/
void put_char(Buffer *B, int c);

int read_word (FILE *input, Buffer *word);

void print_buffer (Buffer *word);


#endif
