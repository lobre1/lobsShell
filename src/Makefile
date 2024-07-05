CC=gcc
NAME=lbsh

all: install

install: main.c execute.c builtin.c
	$(CC) -o $(NAME) main.c execute.c builtin.c

debug: main.c execute.c builtin.c
	$(CC) -Wall -Wextra -o $(NAME) main.c execute.c builtin.c

clean:
	rm $(NAME)
