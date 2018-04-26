test: test.c hexdump.c
	$(CC) -Wall -O0 -g -o $@ $^
