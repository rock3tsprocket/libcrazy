# This is the makefile for libcrazy.

# Environment variables
AR := ar
CC := cc
CFLAGS := -g -O2 -fPIC
LDFLAGS := 
PREFIX := /usr/local

.PHONY: all
all: libcrazy.so libcrazy.a
	@printf " Congratulations, libcrazy should be built now.\n \
	If you want to install it, run 'make install'.\n \
	If you don't want it to install to /usr, do\n \
	'make PREFIX=[install location] install'.\n \
	To link against this library, add '-lcrazy'\n \
	to your linker flags.\n"
	

libcrazy.o:
	${CC} ${CFLAGS} -c -o libcrazy.o libcrazy.c

libcrazy.so: libcrazy.o
	${CC} -shared -o libcrazy.so libcrazy.o ${LDFLAGS}
	
libcrazy.a: libcrazy.o
	${AR} rcs libcrazy.a libcrazy.o

.PHONY: clean
clean:
	rm -f libcrazy.o libcrazy.so libcrazy.a

.PHONY: install
install: libcrazy.so libcrazy.a
	install --mode=644 libcrazy.h ${PREFIX}/include
	install --mode=755 libcrazy.so ${PREFIX}/lib
	install --mode=644 libcrazy.a ${PREFIX}/lib

