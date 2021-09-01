.RECIPEPATTERN = >
.SHELL := BASH

build:
	gcc -g test.c -o test
	./test < test2.txt


valgrind:
	gcc -g test.c -o test
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./test < test2.txt