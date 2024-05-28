LIB_PATH=.
LIB_NAME="readWrite"

lib:
	ar -rcs libreadWrite.a main.o read.o write.o

install:
	gcc -c -Wall -Werror -Wextra *.c
	make lib
	gcc main.c -L. -lreadWrite -o readWrite

remove:
	rm -rf *.o
	rm readWrite


