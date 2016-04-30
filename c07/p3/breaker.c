#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getMax (int *count, int n) {      //get the max frequency
  int max = 0;
  int i;
  for (i = 1; i < n; i++) {
    if (count[i] > count[max]) {
      max = i;
    }
  }
  return max;
}

void breaker (FILE *f) {             //break Caesar Cipher         
  int key,c;
  int count[26] = {0};               // 26alpha_frequency
  int max = 0;                       // max frequency
  int str[26];                       // 26alpha
  while ((c = fgetc(f)) != EOF) {    // count alpha frequency 
    if (isalpha(c)) {
      count[c-97] += 1;
      str[c-97] = c;
    }
  }
  max = getMax(count, 26);
  key = str[max] - 'e';
  if (key < 0) {
    key = 26 + key;
  }
  fprintf (stdout,"%d\n" , key);
}

int main (int argc, char ** argv) {
  if (argc != 2) {
     fprintf(stderr,"Usage: breaker  inputFileName\n");
     return EXIT_FAILURE;
  }
  FILE *f = fopen (argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  breaker (f);
  if (fclose(f) != 0) {
    perror ("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
