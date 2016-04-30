#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

void split(char * line, kvpair_t *kvpair) {
  char *p = strchr(line, '=');
  if (p != NULL) {
    kvpair->key = malloc((p-line+1) * sizeof(char));
    kvpair->value = malloc ((strlen(line) - (p - line)) *sizeof(char));
    strncpy(kvpair->key, line, p-line);
    kvpair->key[p-line] = '\0';
    int j = 0;                           //copy value
    while (line[p - line + 1 + j] != '\n') {
      kvpair->value[j] = line[p - line + 1 + j];
      j++;
    }
    kvpair->value[j] = '\0';
  } 
}

void readLines(kvarray_t *kv, FILE *f) {
  kv->kvpairs = NULL;
  char *curr = NULL;
  size_t sz;
  size_t i = 0;
  while(getline(&curr, & sz, f) >= 0) {
    kv->kvpairs = realloc(kv->kvpairs, (i+1) * sizeof(char *));
    kvpair_t *kvpair = malloc(sizeof(*kvpair));
    split(curr, kvpair);  
    kv->kvpairs[i] = kvpair;
    free(curr);
    curr = NULL;
    i++;
  }
  free(curr);
  kv->length = i;
}


kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  if(fname == NULL) {
    perror("invalid input");
    exit(EXIT_FAILURE);
  }
  FILE *f = fopen(fname, "r");
  if (f == NULL) {
    perror("Could not open the file");
    exit(EXIT_FAILURE);
  }
  kvarray_t *kv = malloc(sizeof (*kv));
  readLines(kv, f);
  if (fclose(f) != 0) {
    perror("Failed to close file");
    exit(EXIT_FAILURE);
  }
  return kv;
}


void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++) {
    free(pairs->kvpairs[i]->key);
    free(pairs->kvpairs[i]->value);
    free(pairs->kvpairs[i]);
  }
  free(pairs->kvpairs);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++) {
    printf("key = '%s' value = '%s'\n", pairs->kvpairs[i]->key, pairs->kvpairs[i]->value); 
}
}
char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for (int i = 0 ; i < pairs->length; i++) {
    if ((strncmp(pairs->kvpairs[i]->key, key, strlen(pairs->kvpairs[i]->key))) == 0) {
      return pairs->kvpairs[i]->value;
    }
  }
  return NULL;
}

