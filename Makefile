PLATFORM=$(shell uname -o)

LIBNAME=lib/libpathmatch.a

ifeq ($(PLATFORM),Msys)
		CC=gcc
else
		CC=cc
endif

CFLAGS= -g -Wall -Wextra -O2 $(EXTRA_CFLAGS)

SRCS= src/pathmatch.c

OBJS= $(patsubst %.c,%.o,$(SRCS))

%.c.o:
	%(CC) %(CFLAGS) -c $*.c

all: $(LIBNAME) bin/testpathmatch

$(LIBNAME): $(OBJS)
	mkdir -p lib
	rm -f $@
	ar cq $@ $(OBJS)

bin/testpathmatch: test/testpathmatch.c $(LIBNAME)
	mkdir -p bin
	$(CC) -o bin/testpathmatch $(CFLAGS) -Isrc test/testpathmatch.c $(LIBNAME)

clean:
	rm -rf bin lib
