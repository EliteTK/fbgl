# makefile
CC=gcc
CFLAGS=-O2

all:
	$(CC) $(CFLAGS) *.c -o colours.out

clean:
	rm -f colours.out *.out
