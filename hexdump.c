#include "hexdump.h"

#define LINE_WIDTH 16
typedef unsigned char u8;

static void put_line(FILE *fd, const u8 *ptr, size_t size) {
  fprintf(fd,  "%p: ", ptr);

  for(size_t i = 0; i < size; i++){
    fprintf(fd,  "%02x ", ptr[i]);
  }

  for(size_t i = 0; i < LINE_WIDTH - size; i++){
    fprintf(fd,  "   ");
  }

  for(size_t i = 0; i < size; i++){
    char c = ptr[i];

    if(c < ' ' || c > '~')
      c = '.';

    fprintf(fd,  "%c", c);
  }

  fprintf(fd,  "\n");
}


void hexdump(FILE *fd, const void *ptr, size_t size) {
  int lines = size / LINE_WIDTH;
  for(int i = 0; i < lines; i++){
    put_line(fd, ptr + i*LINE_WIDTH, LINE_WIDTH);
  }

  if(lines*LINE_WIDTH < size)
    put_line(fd, ptr + lines*LINE_WIDTH, size - lines*LINE_WIDTH);
}
