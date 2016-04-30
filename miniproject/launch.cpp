#include"launch.h"
#include "searchCommand.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <string>
using namespace std;
extern char **environ;


int launch(char **args) {
  char *cmd = args[0];
  if (strstr(args[0], "/") == 0) {
    string command(args[0]);
    vector<string> pathv = getPath();
    command = searchCommand(command, pathv);
    cmd = (char *)command.c_str();
    if (strcmp(cmd, "command not found") == 0){
      printf("Command %s not found\n", args[0]);
      return 1;
    }
  } 
  else {
    char *ptr = strrchr(args[0], '/');
    char *program = strdup(ptr + 1);
    string command(program);
    char *path = strndup(args[0], ptr + 1 - args[0]);
    string programPath(path);
    vector<string> pathv;
    pathv.push_back(programPath);
    command = searchCommand(command, pathv);
    char *temp = (char *)command.c_str();
    if (strcmp(temp, "command not found") == 0){
      printf("Command %s not found\n", args[0]);
      free(path);
      free(program);
      return 1;
    }
    free(path);
    free(program);
  }  
  pid_t pid,w;
  int status;
  pid = fork();
  if (pid == 0) {                            //child process
    //kill((long)getpid(), SIGHUP);
    if (execve(cmd, args, environ) == -1) {
      if (strstr(args[0], "\\") == NULL) {
	printf("Command %s not found\n", args[0]);
      }
      else {
	perror("execve");
      }
      exit(100);
    } 
  }
  else if (pid < 0) {                      //forking error
    perror("forking error");
  } 
  else {                                   //parent process
    do {
      w = waitpid(pid, &status, WUNTRACED);
      if (w == -1) {
	perror("waitpid");
	exit(EXIT_FAILURE);
      }
      if (WIFEXITED(status)) {
	if (WEXITSTATUS(status) == 100) {
	  return 1;
	}
	printf("Program exited with status %d\n", WEXITSTATUS(status));
      } 
      else if (WIFSIGNALED(status)) {
	printf("Program was killed by signal %d\n", WTERMSIG(status));
      }
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1; 
}


