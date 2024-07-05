CC         =gcc
CDBUGFLAGS =-Wall -Wextra
NAME       =lbsh
FILES      =main.c execute.c builtin.c

all: install

install: $(FILES)
	$(CC) -o $(NAME) $(FILES)

debug: $(FILES)
	$(CC) $(CDBUGFLAGS) -o $(NAME) $(FILES)

clean:
	rm $(NAME)
