#include "hexdump.h"

#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[]) {
  int fd;
  struct stat sb;

  if (argc < 2)
    return 1;

  // get size;
  stat(argv[1], &sb);
  fd = open(argv[1], O_RDONLY, 0);

  if (fd < 0)
    return 1;

  void *ptr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

  if (!ptr)
    return 1;

  hexdump(stdout, ptr, sb.st_size);
}
