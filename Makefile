# Copyright 2025 rock3tsprocket
#
# Redistribution and use in source and binary forms, with or without modification, are permitted
# provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this list of conditions and
# the following disclaimer.

# 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
# and the following disclaimer in the documentation and/or other materials provided with the
# distribution.
#
# 3. Neither the name of the copyright holder nor the names of its contributors may be used to
# endorse or promote products derived from this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS”
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
# TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

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

