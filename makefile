SRC := $(shell find . -name '*.c')
HEADER := $(shell find . -name '*.h')

CC = gcc
CFLAGS = -std=c11 -pedantic -Wall -Wextra 
LDFLAGS = -lm

all: program

run: program
	./program

program: $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC)

clean:
	rm -f program

.PHONY: all run clean

