CC=clang -Wall -Werror -std=c23 -fdiagnostics-color

.PHONY: format

src/day01: src/day01.c
	cd src && $(CC) -o day01 day01.c && ./day01

src/day02: src/day02.c
	cd src && $(CC) -o day02 day02.c && ./day02

format:
	cd src && clang-format -i *.c
