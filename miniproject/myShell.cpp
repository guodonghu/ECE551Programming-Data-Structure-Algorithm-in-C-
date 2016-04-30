#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <string>
#include "parse.h"
#include <stack>
#include "launch.h"
#include "searchCommand.h"


char *readLine(void) {
  char *line = NULL;
  size_t sz = 0;
  ssize_t len = 0;
  if ((len = getline (&line, &sz, stdin)) == -1) {
    exit(0);
  }
  return line;
}

int cd(char **args) {
  if ((args[1] == NULL) || (*args[1] == '\n')) {
    return 1;
  }
  else {
    char *dir = strtok(args[1], " \n");
    if (chdir(dir) != 0) {
      perror("cd");
    }
  }
  return 1;
}

int pushd(char **args, std::stack<char *> & mystack) {
  if (args[1] == NULL) {
    printf("pushd: no other directory\n");
    return 1;
  }
  else {
    char *newdir = strtok(args[1], " \n");
    char *olddir = NULL;
    size_t size = 0;
    olddir = getcwd(olddir, size);
    mystack.push(olddir);
    if (chdir(newdir) != 0) {
      mystack.pop();
      free(olddir);
      perror("pushd");
    }
  }
  return 1;
}

int popd(char **args, std::stack<char *> & mystack) {
  if (mystack.empty()) {
    printf("pod: directory stack empty\n");
  }
  else {
    char *dir = mystack.top(); 
    if (chdir(dir) != 0) {
      perror("popd");
    }
    free(mystack.top());
    mystack.pop();
  }
  return 1;
}

int dirstack(char **args, std::stack<char *> & mystack) {
  if (mystack.empty()) {
    printf("dirstack: directory stack empty\n");
  }
  else {
    std::stack<char *> dirstack;
    std::stack<char *> temp(mystack);
    while (!temp.empty()) {
      dirstack.push(temp.top());
      temp.pop();
    }
    while (!dirstack.empty()) {
      printf("%s\n", dirstack.top());
      dirstack.pop();
    }
  }
  return 1;
}

int execute(char **args, std::stack<char *> & mystack) {
  if (strncmp(args[0], "\n", 1) == 0) {            //new line
    return 1;
  }
  strtok(args[0], " \n");
  if (strcmp(args[0], "exit") == 0) {              //exit
    return 0;
  }
  if (strcmp(args[0], "cd") == 0) {                //cd
    return cd(args);
  }
  if (strcmp(args[0], "pushd") == 0) {             //pushd
    return pushd(args, mystack);
  }

  if (strcmp(args[0], "popd") == 0) {              //popd
    return popd(args, mystack);
  }                                              

  if (strcmp(args[0], "dirstack") == 0) {           //dirstack
    return dirstack(args, mystack);
  }
  return launch(args);
}
  

int main(int argc, char *argv[]) {
  char *line;
  char **args;
  int status;
  std::stack<char *> mystack;
  do {
    char *buf= NULL;
    size_t size = 0;
    buf = getcwd(buf, size);
    printf("myShell:%s $", buf);
    line = readLine();
    args = parse(line);
    status = execute(args, mystack);
    int j = 0;
    while (args[j] != NULL) {
      free(args[j]);
      j++;
    }
    free(args[j]);
    free(args);
    free(line);
    free(buf);
  } while (status);
  while (!mystack.empty()) {
    free(mystack.top());
    mystack.pop();
  }
  return EXIT_SUCCESS;
}
