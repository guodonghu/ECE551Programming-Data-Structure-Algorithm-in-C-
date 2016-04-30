#include <stdlib.h>
#include <stdio.h>
unsigned power (unsigned x,unsigned y) {
  unsigned answer; 
  if (y == 0) {
    answer = 1;
  }else if (y == 1) {
    answer = x;
  } else {
    answer = power (x,y-1) * x;
  }
  return answer;
}

int main (void) {
  printf("2^3=%d\n", power (2, 3));
  printf("0^3=%d\n", power (0, 3));
  printf("2^0=%d\n", power (2, 0));
  printf("0^0=%d\n", power (0, 0));
  return EXIT_SUCCESS;
}
 
