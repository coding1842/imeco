LIB_PATH=.
LIB_NAME="wordCount"

lib:
	ar -rcs libwordCount.a wordCount.o

install:
	gcc -c -Wall -Werror -Wextra *.c
	make lib
	gcc wordCount.c -L. -lwordCount -o wordCount

remove:
	rm -rf *.o
	rm wordCount


