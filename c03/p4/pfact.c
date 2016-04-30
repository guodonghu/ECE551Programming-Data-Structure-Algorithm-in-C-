#include <stdio.h>
#include <stdlib.h>


void printFactors(int n) {
  int i;
  int j;
  if (n < 1) {
    printf("n should be more than 1!\n");
  }
  else if (n ==1) {
    printf("\n");
  }
  else {
    for (i=2; i<=n; i++) {
      if (n % i == 0) {
	printf("%d",i);
	n=n/i;
        break; 
      }
    }
    for (j=i; j<=n; j++) {
      if (n % j == 0) {
	printf(" * %d",j);
	n=n/j;
	if (n == 1) {
	  printf("\n");
	  break;
	
	}
	j--;
      }
    }
  }
}
int main(void) {
  printf("Factorization of 1:\n");
  printFactors(1);
  printf("Factorization of 60:\n");
  printFactors(60);
  printf("Factorization of 132:\n");
  printFactors(132);
  printf("Factorization of 11726:\n");
  printFactors(11726);
  printf("Factorization of 2169720:\n");
  printFactors(2169720);
  printf("Factorization of 1789220887:\n");
  printFactors(1789220887);
  return EXIT_SUCCESS;
}
