CC = gcc
CFLAGS = -std=c11 -D_GNU_SOURCE

BIN = test_hash_table
SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SRCS))

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) $(BIN) $(OBJS)
