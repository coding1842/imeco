LIB_PATH=.
LIB_NAME="static"

lib:
	ar -rcs libstatic.a memory_static_main.o memory_static_func.o memory_static_free.o

install:
	gcc -c -Wall -Werror -Wextra *.c
	make lib
	gcc memory_static_main.c -L. -lstatic -o static

remove:
	rm -rf *.o
	rm static

