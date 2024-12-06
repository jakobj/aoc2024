#include <stdio.h>
#include <stdlib.h>

enum state {
  Invalid,
  M,
  U,
  L,
  /* LP, */
  N0,
  /* C, */
  N1,
  /* RP, */
};

int main() {
  enum state s = Invalid;
  int n0;
  int n1;
  char c;
  int sum = 0;
  FILE *instream = fopen("../inputs/03.txt", "r");
  if (!instream) {
    return EXIT_FAILURE;
  }
  while ((c = fgetc(instream)) != EOF) {
    switch (s) {
    case Invalid:
      s = (c == 'm') ? M : Invalid;
      break;
    case M:
      s = (c == 'u') ? U : Invalid;
      break;
    case U:
      s = (c == 'l') ? L : Invalid;
      break;
    case L:
      if (c == '(') {
        n0 = 0;
        fscanf(instream, "%d", &n0);
        s = (n0 > 0) ? N0 : Invalid;
      } else {
        s = Invalid;
      }
      break;
    case N0:
      if (c == ',') {
        n1 = 0;
        fscanf(instream, "%d", &n1);
        s = (n1 > 0) ? N1 : Invalid;
      } else {
        s = Invalid;
      }
      break;
    case N1:
      if (c == ')') {
        sum += n0 * n1;
      }
      s = Invalid;
      break;
    };
  }
  printf(
      "If you add up all of the results of the multiplications you get %d.\n",
      sum);
  return EXIT_SUCCESS;
}
