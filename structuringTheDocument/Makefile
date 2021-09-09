.RECIPEPATTERN = >
.SHELL := BASH
.PHONY: run

run: build
	./test < input.txt

build:
	gcc -g test.c -o test -lm

valgrind:
	gcc -g test.c -o test
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./test < input.txt