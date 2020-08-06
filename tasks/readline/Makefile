NAME = my_readline

SRCS = *.c

SANITIZE = -g3 -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: main.o my_readline.o my.o tests.o
	gcc ${SANITIZE} ${CFLAGS} main.o my_readline.o my.o tests.o -o ${NAME}

main.o: main.c
	gcc ${SANITIZE} ${CFLAGS} -c main.c

my.o: my.c
	gcc ${SANITIZE} ${CFLAGS} -c my.c

my_readline.o: my_readline.c
	gcc ${SANITIZE} ${CFLAGS} -c my_readline.c

tests.o: tests.c
	gcc ${SANITIZE} ${CFLAGS} -c tests.c

clean:
	rm -f *.o

fclean:
	rm -f *.o ${NAME}

re: fclean all