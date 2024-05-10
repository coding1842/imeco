LIB_PATH=.
LIB_NAME="binary"

lib:
	ar -rcs libbinary.a binary.o

install:
	gcc -c -Wall -Werror -Wextra *.c
	make lib
	gcc binary.c -L. -lbinary -o binary

remove:
	rm -rf *.o
	rm binary

