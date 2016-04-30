#include<stdio.h>
#include<stdlib.h>
int fib (int n) {
  int sum;
  if(n<0) {
    return 0;
  }
  else if(n==0 || n==1) {
    return n;
    }
  else {
    sum = fib(n-1) + fib(n-2);
  }
  return sum;
}

  int main (void) {
    int i;
    for (i=-2; i<31; i++) {
      printf("fib(%d) = %d\n", i, fib(i));
    }
    return EXIT_SUCCESS;
      }
   
