#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int rotate (FILE *f) {
  int row = 0;
  char matrix[10][10];
  char matrixLine[12];                              //store a row of matrix in f           
  int i,j;
  while (fgets(matrixLine, 12, f) != NULL) {
    if (row >= 10 || matrixLine[10] != '\n') {
      fprintf(stderr, "wrong matrix, need 10*10 matrix!\n");
      return EXIT_FAILURE;
    }
    for (i = 0 ; i < 10; i++) {                    //rotate matrix,[row][i] in f ->matrix[i][9-row]
      matrix[i][9-row] = matrixLine[i];         
    }
    row++;
  }
  if (row < 10) {
    fprintf(stderr, "Wrong matrix, need 10*10 matrix!\n");
    return EXIT_FAILURE;
  }
    
  
  for (i = 0; i < 10; i++) {                      //print matrix
    for (j = 0; j <= 10; j++) {
      if (j <= 9) {
	fprintf(stdout, "%c", matrix[i][j]);
      } else {
	fprintf(stdout, "\n");
      }
    }
  } 
  return 0;
}

int main (int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage:.\\RotateMatrix inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("could not open file");
    return EXIT_FAILURE;
  }
  rotate(f);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
