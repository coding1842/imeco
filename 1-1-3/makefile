LIB_PATH=.
LIB_NAME="array"

lib:
	ar -rcs libarray.a array_func.o array_funcs.o

install:
	gcc -c -Wall -Werror -Wextra *.c
	make lib
	gcc array_funcs.c -L. -larray -o array

remove:
	rm -rf *.o
	rm array
