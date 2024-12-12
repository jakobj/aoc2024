#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  buf_max = 32,
  levels_max = 16,
  reports_max = 1000,
};

struct report {
  int levels[levels_max];
  size_t length;
};

size_t read_input(char *fn, struct report rs[]) {
  size_t n = 0;
  char buffer[buf_max] = {};
  FILE *instream = fopen(fn, "r");
  if (!instream) {
    exit(EXIT_FAILURE);
  }
  while (fgets(buffer, buf_max, instream)) {
    struct report *cr = &rs[n];
    cr->length = 0;
    int offset = 0;
    int read_count;
    while ((cr->length < levels_max) &&
           (sscanf(buffer + offset, "%d%n", &cr->levels[cr->length],
                   &read_count) == 1)) {
      offset += read_count;
      ++cr->length;
    }
    ++n;
  }
  return n;
}

bool is_increasing(struct report r) {
  for (size_t i = 1; i < r.length; ++i) {
    if (r.levels[i - 1] >= r.levels[i]) {
      return false;
    }
  }
  return true;
}

bool is_decreasing(struct report r) {
  for (size_t i = 1; i < r.length; ++i) {
    if (r.levels[i - 1] <= r.levels[i]) {
      return false;
    }
  }
  return true;
}

bool is_safe(struct report r) {
  if (!(is_decreasing(r) || is_increasing(r))) {
    return false;
  }
  for (size_t i = 1; i < r.length; ++i) {
    int diff = abs(r.levels[i - 1] - r.levels[i]);
    if (diff < 1 || diff > 3) {
      return false;
    }
  }
  return true;
}

void part1(struct report rs[], size_t n) {
  int n_safe = 0;
  for (size_t i = 0; i < n; ++i) {
    if (is_safe(rs[i])) {
      n_safe += 1;
    }
  }
  printf("%d reports are safe.\n", n_safe);
}

void erase(struct report *r, size_t pos) {
  for (size_t i = pos; i < r->length - 1; ++i) {
    r->levels[i] = r->levels[i + 1];
  }
  --r->length;
}

void part2(struct report rs[], size_t n) {
  int n_safe = 0;
  for (size_t i = 0; i < n; ++i) {
    if (is_safe(rs[i])) {
      n_safe += 1;
    } else {
      struct report r = {};
      for (size_t j = 0; j < rs[i].length; ++j) {
        memcpy(r.levels, rs[i].levels, levels_max * sizeof(int));
        r.length = rs[i].length;
        erase(&r, j);
        if (is_safe(r)) {
          n_safe += 1;
          break;
        }
      }
    }
  }
  printf("%d reports are safe when using the Problem Damper.\n", n_safe);
}

int main() {
  struct report rs[reports_max];
  const size_t n = read_input("inputs/02.txt", rs);
  part1(rs, n);
  part2(rs, n);
  return EXIT_SUCCESS;
}
