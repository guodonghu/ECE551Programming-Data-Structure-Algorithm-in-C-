#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t *counts = malloc(sizeof(*counts));
  counts->len = 0;
  counts->unknown = 0;
  counts->countArray = NULL;
  return counts;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if (name == NULL) {
    (c->unknown)++;
  } 
  else {
    one_count_t *oneCount = malloc(sizeof(*oneCount));
    oneCount->value = name;
    oneCount->count = 1;
    if (c->len == 0) {
      c->countArray = realloc(c->countArray, sizeof(one_count_t *));
      c->countArray[0] = oneCount;
      (c->len)++;
    } 
    else {
      int j=0;
      for (int i = 0; i < c->len; i++) {
	if (strcmp(c->countArray[i]->value, name) == 0) {
	  (c->countArray[i]->count)++;
	  j++;
	  free(oneCount);
	}
      }	
      if (j == 0) {
	(c->len)++;
	c->countArray = realloc(c->countArray,(c->len) * sizeof(one_count_t *));
	c->countArray[c->len - 1] = oneCount;
      }        
    }
  }
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for (int i = 0; i < c->len; i++) {
    fprintf(outFile, "%s: %d\n", c->countArray[i]->value, c->countArray[i]->count);
  }
  if ((c->unknown) > 0) {
  fprintf(outFile, "<unknown> : %d\n", c->unknown);
  }
}


void freeCounts(counts_t * c) {
  //WRITE ME
  for (int i = 0; i < c->len; i++) {
    free(c->countArray[i]);
  }
  free(c->countArray);
  free(c);
}
