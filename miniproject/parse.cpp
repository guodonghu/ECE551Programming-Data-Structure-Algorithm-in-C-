#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>


char **parse(char *line) {
  char **tokens = NULL;
  char *token = NULL;
  size_t pos = 0;
  size_t pslash = 0;
  char * ptr;
  std::string temp;
  const char *c = " ";
  token = strsep(&line, c);
  while (*token == *c) {
    token = strsep(&line, c);
  }
  while (token != NULL) {
    if (*token != '\0') {
      if (((ptr = strrchr(token, '\\')) != NULL) && (*(ptr+1) == '\0')) {
	if (temp.size() > 0) {
	  pslash += (ptr - token + 1);
	}
	else {
	  pslash += ptr - token;
	}
	temp.append(token);
	temp.replace(pslash, 1, c);
	if (*line == *c) {
	  tokens = (char **)realloc(tokens, (pos + 1) * sizeof(*tokens));
	  tokens[pos] =(char *)malloc((temp.size() + 1) * sizeof(char));
	  size_t len = temp.copy(tokens[pos], temp.size(), 0);
	  tokens[pos][len] = '\0';
	  pos++;
	  temp.clear();
	  pslash = 0;
	}
      }
      else {
	temp.append(token);
	tokens = (char **)realloc(tokens, (pos + 1) * sizeof(*tokens));
	tokens[pos] =(char *)malloc((temp.size() + 1) * sizeof(char));
	size_t len = temp.copy(tokens[pos], temp.size(), 0);
	tokens[pos][len] = '\0';
	pos++;
	temp.clear();
	pslash = 0;
      }
    }
    token = strsep(&line, c);
  }
  tokens = (char **)realloc(tokens, (pos + 1) * sizeof(*tokens));
  tokens[pos] = NULL;
  if (strcmp(tokens[pos - 1], "\n") != 0) {
    tokens[pos - 1] = strtok(tokens[pos - 1] , "\n");
  }
  return tokens;
}
