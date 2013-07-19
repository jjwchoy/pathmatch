PLATFORM=$(shell uname -o)

LIBNAME=lib/libpathmatch.a

ifeq ($(PLATFORM),Msys)
		CC=gcc
		CXX=g++
else
		CC=cc
		CXX=c++
endif

CFLAGS= -g -Wall -Wextra -O2 $(EXTRA_CFLAGS)

SRCS= src/pathmatch.c

OBJS= $(patsubst %.c,%.o,$(SRCS))

%.c.o:
	%(CC) %(CFLAGS) -c $*.c

all: $(LIBNAME) bin/testpathmatch bin/testpathmatchcpp

$(LIBNAME): $(OBJS)
	mkdir -p lib
	rm -f $@
	ar cq $@ $(OBJS)

bin/testpathmatch: test/testpathmatch.c $(LIBNAME)
	mkdir -p bin
	$(CC) -o bin/testpathmatch $(CFLAGS) -Isrc test/testpathmatch.c $(LIBNAME)

bin/testpathmatchcpp: test/testpathmatchcpp.cc $(LIBNAME)
	mkdir -p bin
	$(CXX) -o bin/testpathmatchcpp $(CFLAGS) -Isrc test/testpathmatchcpp.cc $(LIBNAME)

clean:
	rm -rf bin lib
