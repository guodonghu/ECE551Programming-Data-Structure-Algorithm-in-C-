#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
  for (size_t j = 0; j < count; j++) {
    printf("%s",data[j]);
    free(data[j]);
  }
}
void readLines( FILE *f) {
  char **lines = NULL;
  char *curr = NULL;
  size_t sz;
  size_t i = 0;
  while(getline(&curr, & sz, f) >= 0) {
    lines = realloc(lines, (i+1) * sizeof(*lines));
    lines[i] = curr;
    curr = NULL;
    i++;
  }
  free(curr);
  sortData(lines, i);
  free(lines);
}
int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  if (argc == 1) {
    FILE *f = stdin;
    readLines(f);
  }  
  else {
    for (int i = 1; i < argc; i++) {
     FILE *f2 = fopen (argv[i],"r");
      if (f2 == NULL) {
	perror("Could not open file");
	return EXIT_FAILURE;
      }
      readLines(f2);
      if (fclose(f2) != 0) {
	perror("Failed to close file");
	return EXIT_FAILURE;;
      }
    }
  }
    return EXIT_SUCCESS;
}
