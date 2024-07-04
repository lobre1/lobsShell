CC=gcc

all: install

install: main.c execute.c builtin.c
	$(CC) -Wall -Wextra -o lbsh main.c execute.c builtin.c

clean:
	rm lbsh
