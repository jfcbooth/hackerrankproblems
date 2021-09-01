.RECIPEPATTERN = >
.SHELL := BASH

build:
	gcc -g test.c -o test
	./test < input.txt


valgrind:
	gcc -g test.c -o test
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./test < input.txt