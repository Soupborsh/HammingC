#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "bits.h"

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