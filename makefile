# makefile
CC=gcc
CFLAGS=-v -O2 -Wall -Werror
LIBPATH=$(CURDIR)/lib
LIBSS=$(LIBPATH)/*.c
LIBSO=$(LIBPATH)/*.o
RPATH=$(LIBPATH)

test.c: libs
	$(CC) $(CFLAGS) -L$(LIBPATH) -Wl,-rpath=$(RPATH) $@ -o $(@:.c=.out) -lfbgl

heart.c: libs
	$(CC) $(CFLAGS) -L$(LIBPATH) -Wl,-rpath=$(RPATH) $@ -o $(@:.c=.out) -lfbgl

libs:
	$(CC) -c $(CFLAGS) -fPIC $(LIBSS)
	$(CC) -shared -o libfbgl.so $(LIBSO)
	mv libfbgl.so $(LIBPATH)

cleanlib: clean
	rm -f *.so

clean:
	rm -f *.out *.o
