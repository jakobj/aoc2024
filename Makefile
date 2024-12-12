CC=clang -Wall -std=c23 -fdiagnostics-color -g

targets = src/day01 src/day02 src/day03 src/day04

.PHONY: format

all: $(targets)

$(targets): src/%: src/%.c
	$(CC) -o $@ $< && $@

format:
	cd src && clang-format -i *.c
