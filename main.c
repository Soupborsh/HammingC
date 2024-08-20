#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 16

short find_xor_ones(bool a[]);
bool is_odd(bool a[]);
void print_bits(bool a[]);

int main()
{
  srand(time(NULL));
  
  bool block[N];
  short xor_ones;
  
  // fill block bool array with rand()
  for (short i = 0; i < N; i++) {
    block[i] = (rand() % 2) == 1;
  }
  
  printf("Random N bits block:\n");
  print_bits(block);
  //find XOR
  xor_ones = find_xor_ones(block);
  
//  printf("is_odd = %u\n", is_odd);
  printf("XOR of ones: %u\n", xor_ones);
  printf("\n");
  
  for(short i = 1; i != N; i = i << 1) {
    if ((xor_ones & i) != 0) {
      block[i] = !block[i];
    }
  }
  printf("Parity bits correction:\n");
  print_bits(block);
  printf("is_odd = %u\n", is_odd(block));
  printf("XOR of ones: %u\n", find_xor_ones(block));
  printf("\n");
  
  //flip first bit if total n of ones is odd
  if ((is_odd(block))) {
    block[0] = !block[0];
  }
  
  //recalculate XOR
  xor_ones = find_xor_ones(block);
  
  //print
  printf("Number of ones correction(final):\n");
  print_bits(block);
  printf("is_odd = %u\n", is_odd(block));
  printf("XOR of ones: %u\n", xor_ones);
  
  return 0;
}







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
