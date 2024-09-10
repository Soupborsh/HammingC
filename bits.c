#include <stdio.h>
#include <stdbool.h>
#include "bits.h"

short find_xor_ones(bool a[]) {
  short n = 0;
  for (short i = 0; i < N; i++) {
    if (a[i]) {
      n = n ^ i;
    }
  }
  return n;
}

bool is_odd(bool a[]) {
  bool n = false;
  for (short i = 0; i < N; i++) {
    if (a[i]) {
      n = !n;
    }
  }
  return n;
}

void print_bits(bool a[]) {
  for (short i = 0; i < N; i++) {
    printf("%u", a[i]);
  }
  printf("\n");
}