CC=clang -Wall -std=c23 -fdiagnostics-color -g

.PHONY: format

src/day01: src/day01.c
	cd src && $(CC) -o day01 day01.c && ./day01

src/day02: src/day02.c
	cd src && $(CC) -o day02 day02.c && ./day02

src/day03: src/day03.c
	cd src && $(CC) -o day03 day03.c && ./day03

format:
	cd src && clang-format -i *.c
