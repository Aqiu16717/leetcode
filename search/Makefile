CC = gcc
CFLAGS = -std=c11 -D_GNU_SOURCE

SRCS := $(wildcard *.c)
BINS := $(patsubst %.c, %, $(SRCS))
OBJS := $(patsubst %.c, %.o, $(SRCS))

all: $(BINS)

binary_search: binary_search.o
	$(CC) $(CFLAGS) -o $@ $<
binary_search.o: binary_search.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) $(BINS) $(OBJS)

