#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  if (inputName == NULL) {
    perror("invalid inputname!");
    exit(EXIT_FAILURE);
  }
  const char *suffix = ".counts";
  unsigned len = strlen(inputName) + strlen(suffix) + 1;
  char *output = malloc(len * sizeof(*output));
  snprintf(output, len, "%s%s", inputName, suffix);
  return output;
}
