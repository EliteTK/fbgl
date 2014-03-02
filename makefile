# makefile
CC=gcc
CFLAGS=-O2
LIBS=lib/*.c

test:
	$(CC) $(CFLAGS) $(LIBS) test.c -o test.out

heart:
	$(CC) $(CFLAGS) $(LIBS) heart.c -o heart.out

clean:
	rm -f *.out
