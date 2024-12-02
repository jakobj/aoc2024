#include <stdio.h>
#include <stdlib.h>

enum {
  buf_max = 32,
  array_max = 1000,
};

size_t read_input(char *fn, int first[], int second[]) {
  int i = 0;
  char buffer[buf_max] = {};
  FILE *instream = fopen(fn, "r");
  if (instream) {
    while (fgets(buffer, buf_max, instream)) {
      sscanf(buffer, "%d %d", &first[i], &second[i]);
      ++i;
    }
    fclose(instream);
  } else {
    fprintf(stderr, "Could not open file \"%s\"\n", fn);
    return EXIT_FAILURE;
  }
  return i;
}

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  int first[array_max] = {};
  int second[array_max] = {};
  const size_t n_elements = read_input("../inputs/01.txt", first, second);
  qsort(first, n_elements, sizeof(int), compare);
  qsort(second, n_elements, sizeof(int), compare);
  int total_distance = 0;
  for (size_t i = 0; i < n_elements; ++i) {
    total_distance += abs(first[i] - second[i]);
  }
  printf("The total distance between the lists is %d.\n", total_distance);
  return EXIT_SUCCESS;
}
