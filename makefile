# makefile
CC = gcc

CFLAGS = -c -O2 -Wall -Werror -fPIC -I ${INCLL}

SOOUT = libfbgl.so

SOVER = 
SONAME = ${SOOUT}${SOVER}

LOCALDIR = .
INCL = ${LOCALDIR}/include
INCLL = ${INCL}/fbgl
SRC = ${LOCALDIR}/src
BUILD = ${LOCALDIR}/build
LIB = ${LOCALDIR}/lib

DESTDIR = /usr
DESTINCL = ${DESTDIR}/include
DESTLIB = ${DESTDIR}/lib

build : ${LIB}/${SONAME}
	

${LIB}/${SONAME} : ${BUILD}/fbio.o ${BUILD}/shapes.o
	mkdir -p ${LIB}
	${CC} -shared $^ -o $@

${BUILD}/fbio.o : ${SRC}/fbio.c ${INCLL}/fbio.h
	mkdir -p ${BUILD}
	${CC} ${CFLAGS} $< -o $@

${BUILD}/shapes.o : ${SRC}/shapes.c ${INCLL}/fbio.h ${INCLL}/colours.h ${INCLL}/shapes.h
	mkdir -p ${BUILD}
	${CC} ${CFLAGS} $< -o $@

install : ${DESTLIB}/${SONAME}
	

${DESTLIB}/${SONAME} : ${LIB}/${SONAME}
	cp ${LIB}/${SONAME} ${DESTLIB}/${SONAME}
	cp -r ${INCL}/* ${DESTINCL}/

uninstall :
	rm -f ${DESTLIB}/${SONAME} ${DESTINCL}/fbgl.h ${DESTINCL}/fbgl/*
	rm -fd ${DESTINCL}/fbgl/

clean :
	rm -f ${BUILD}/* ${LIB}/*
	rm -fd ${BUILD} ${LIB}

auto : build install clean
