CC=clang -Wall -Werror -std=c23 -fdiagnostics-color

src/day01: src/day01.c
	cd src && $(CC) -o day01 day01.c && ./day01

format:
	cd src && clang-format -i *.c
