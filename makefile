# makefile
CC = gcc

CFLAGS = -c -O2 -Wall -Werror -fPIC -I $(INCLL)

SOOUT = libfbgl.so

SOVER = 
SONAME = $(SOOUT)$(SOVER)

LOCALPATH = .
INCL = $(LOCALPATH)/include
INCLL = $(INCL)/fbgl
SRC = $(LOCALPATH)/src
BUILD = $(LOCALPATH)/build
LIB = $(LOCALPATH)/lib

INSPATH = /usr
INSINCL = $(INSPATH)/include
INSLIB = $(INSPATH)/lib

build : $(LIB)/$(SONAME)
	

$(LIB)/$(SONAME) : $(BUILD)/fbio.o $(BUILD)/shapes.o
	mkdir -p $(LIB)
	$(CC) -shared $^ -o $@

$(BUILD)/fbio.o : $(SRC)/fbio.c $(INCLL)/fbio.h
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $< -o $@

$(BUILD)/shapes.o : $(SRC)/shapes.c $(INCLL)/fbio.h $(INCLL)/colours.h $(INCLL)/shapes.h
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $< -o $@

install : $(INSLIB)/$(SONAME)
	

$(INSLIB)/$(SONAME) : $(LIB)/$(SONAME)
	cp $(LIB)/$(SONAME) $(INSLIB)/$(SONAME)
	cp -r $(INCL)/* $(INSINCL)/

uninstall :
	rm -f $(INSLIB)/$(SONAME) $(INSINCL)/fbgl.h $(INSINCL)/fbgl/*
	rm -fd $(INSINCL)/fbgl/

clean :
	rm -f $(BUILD)/* $(LIB)/*
	rm -fd $(BUILD) $(LIB)
