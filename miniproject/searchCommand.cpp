#include <vector>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "searchCommand.h"
using namespace std;
char *pathValue = getenv("PATH");

vector<string> getPath(void) {
  vector<string> pathv;
  char *path;
  char *temp = strdup(pathValue);
  path = strtok(temp, ":");
  while (path != NULL) {
    pathv.push_back(path);
    path = strtok(NULL, ":");
  }
  free(temp);
  return pathv;
}
  
string searchCommand(string command, vector<string> pathv) {
  DIR *dir;
  struct dirent *ent;
  for (vector<string> :: iterator it = pathv.begin(); it != pathv.end(); ++it) {
    if ((dir = opendir((*it).c_str())) != 0) {
      while ((ent = readdir (dir)) != 0) {
	string file(ent->d_name);
	if (file == "." || file == "..") {
	  continue;
	}
	if (file == command) {
	  if (pathv.size() > 1) {
	    string path = *it + "/" + command;
	    closedir(dir);
	    return path;
	  }
	  else {
	    string path = *it + command;
	    closedir(dir);
	    return path;
	  } 
	}
      }
      closedir(dir);
    }
    else {
      printf("can not open directory :%s\n", (*it).c_str());
    }
  }
  return "command not found";
}
