LIB_PATH=.
LIB_NAME="game"

lib:
	ar -rcs libgame.a main.o game.o

install:
	gcc -c -Wall -Werror -Wextra *.c
	make lib
	gcc main.c -L. -lgame -o game

remove:
	rm -rf *.o
	rm game

