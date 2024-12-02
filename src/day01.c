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
    exit(EXIT_FAILURE);
  }
  return i;
}

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void part1(int first[], int second[], int n_elements) {
  qsort(first, n_elements, sizeof(int), compare);
  qsort(second, n_elements, sizeof(int), compare);
  int total_distance = 0;
  for (size_t i = 0; i < n_elements; ++i) {
    total_distance += abs(first[i] - second[i]);
  }
  printf("The total distance between the lists is %d.\n", total_distance);
}

void part2(int first[], int second[], int n_elements) {
  int similarity_score = 0;
  for (size_t i = 0; i < n_elements; ++i) {
    int count = 0;
    for (size_t j = 0; j < n_elements; ++j) {
      if (first[i] == second[j]) {
        ++count;
      }
    }
    similarity_score += first[i] * count;
  }
  printf("Their similarity score is %d.\n", similarity_score);
}

int main() {
  int first[array_max] = {};
  int second[array_max] = {};
  const size_t n_elements = read_input("../inputs/01.txt", first, second);
  part1(first, second, n_elements);
  part2(first, second, n_elements);
  return EXIT_SUCCESS;
}
