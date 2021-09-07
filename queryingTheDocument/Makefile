.RECIPEPATTERN = >
.SHELL := BASH
.PHONY: run

run: build
	./test < input.txt

build:
	gcc -g test.c -o test -lm