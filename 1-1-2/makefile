LIB_PATH=.
LIB_NAME="grade"

lib:
	ar -rcs libgrade.a grade_func.o grade_funcs.o

install:
	gcc -c -Wall -Werror -Wextra *.c
	make lib
	gcc grade_funcs.c -L. -lgrade -o grade

remove:
	rm -rf *.o
	rm grade
