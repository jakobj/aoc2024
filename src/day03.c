#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  bool part1 = true;
  int n0;
  int n1;
  int sum = 0;
  bool enabled = true;
  char c;
  FILE *instream = fopen("../inputs/03.txt", "r");
  if (!instream) {
    return EXIT_FAILURE;
  }
  while ((c = fgetc(instream)) != EOF) {
    if (c == 'm') {
      if (fgetc(instream) == 'u' && fgetc(instream) == 'l' &&
          fgetc(instream) == '(') {
        fscanf(instream, "%d", &n0);
        if (n0 == 0) {
          continue;
        }
        if (fgetc(instream) != ',') {
          continue;
        }
        fscanf(instream, "%d", &n1);
        if (n1 == 0) {
          continue;
        }
        if (fgetc(instream) != ')') {
          continue;
        }
        if (part1 || enabled) {
          sum += n0 * n1;
        }
      }
    } else if (c == 'd') {
      if (fgetc(instream) == 'o') {
        c = fgetc(instream);
        if (c == '(' && fgetc(instream) == ')') {
          enabled = true;
        } else if (c == 'n' && fgetc(instream) == '\'' &&
                   fgetc(instream) == 't' && fgetc(instream) == '(' &&
                   fgetc(instream) == ')') {
          enabled = false;
        }
      }
    }
  }
  printf(
      "If you add up all of the results of the multiplications you get %d.\n",
      sum);
  return EXIT_SUCCESS;
}
