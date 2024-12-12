#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { array_max = 200 };

size_t read_input(char *fn, char array[array_max][array_max]) {
  FILE *instream = fopen(fn, "r");
  if (!instream) {
    exit(EXIT_FAILURE);
  }
  char buffer[array_max] = {};
  size_t i = 0;
  while (fgets(buffer, array_max, instream)) {
    assert(i < array_max);
    for (size_t j = 0; j < strlen(buffer); ++j) {
      assert(j < array_max);
      array[i][j] = buffer[j];
    }
    ++i;
  }
  return i;
}

int main() {
  char *fn = "inputs/04.txt";
  char array[array_max][array_max];
  const size_t length = read_input(fn, array);

  int count = 0;
  for (size_t i = 0; i < length; ++i) {
    for (size_t j = 0; j < length; ++j) {
      if (array[i][j] == 'X') {
        // scan all directions
        for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            // make sure we're within bounds
            if ((((int)i + 3 * dy) < 0 && (i + 3 * dy) >= length) ||
                (((int)j + 3 * dx) < 0 && (j + 3 * dx) >= length)) {
              continue;
            }

            if (array[i + 1 * dy][j + 1 * dx] == 'M' &&
                array[i + 2 * dy][j + 2 * dx] == 'A' &&
                array[i + 3 * dy][j + 3 * dx] == 'S') {
              ++count;
            }
          }
        }
      }
    }
  }
  printf("XMAS appears %d times.\n", count);
  return EXIT_SUCCESS;
}
