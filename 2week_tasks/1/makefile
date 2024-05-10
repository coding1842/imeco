LIB_PATH=.
LIB_NAME="binary"

lib:
	ar -rcs libbinary.a binaryToAscii.o binaryMain.o

install:
	gcc -c -Wall -Werror -Wextra *.c
	make lib
	gcc binaryMain.c -L. -lbinary -o binary

remove:
	rm -rf *.o
	rm binary


