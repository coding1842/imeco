LIB_PATH=.
LIB_NAME="dup"

lib:
	ar -rcs libdup.a dupfunc.o

install:
	gcc -c -Wall -Werror -Wextra *.c
	make lib
	gcc dupfunc.c -L. -ldup -o dup

remove:
	rm -rf *.o
	rm dup

