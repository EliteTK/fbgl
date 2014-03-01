# makefile
CC=gcc
CFLAGS=-O2

all:
	$(CC) $(CFLAGS) test.c fbio.c shapes.c -o colours.out

clean:
	rm -f colours.out *.out
