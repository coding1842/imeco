LIB_PATH=.
LIB_NAME="matrix"

lib:
	ar -rcs libmatrix.a matrix.o

install:
	gcc -c -Wall -Werror -Wextra *.c
	make lib
	gcc matrix.c -L. -lmatrix -o matrix

remove:
	rm -rf *.o
	rm matrix

