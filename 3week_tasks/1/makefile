LIB_PATH=.
LIB_NAME="node"

lib:
	ar -rcs libnode.a linkedList_main.o linkedList_add.o linkedList_remove.o

install:
	gcc -c -Wall -Werror -Wextra *.c
	make lib
	gcc linkedList_main.c -L. -lnode -o node

remove:
	rm -rf *.o
	rm node
