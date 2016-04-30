#include<dirent.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<functional>
#include<unordered_map>
#include<assert.h>
using namespace std;

void compareDelete (pair<size_t, string> mypair, unordered_map<size_t, string> &myhashmap) {
  // cout << get<0>(mypair) << get<1>(mypair) << endl;
  //cout << myhashmap.count(get<0>(mypair)) << endl;
  size_t count = myhashmap.count(get<0>(mypair)); 
  if (count > 0) {
    unordered_map<size_t, string>::const_iterator got = myhashmap.find(get<0>(mypair));
    cout << "#Removing " << get<1>(mypair) << " (duplicate of " << got->second << ")." << endl;
    cout << "rm " << get<1>(mypair) << endl;
  }
}
      
size_t hashfile(ifstream &f, string filepath) {
  string inputstr;
  size_t hashval = 0;
  hash<string> str_hash;
  while(getline(f, inputstr)) {
    hashval += str_hash(inputstr);
    //  cout << hashval<< endl;
  }
  return hashval;
}

void Findfile(const string &di,  unordered_map<size_t, string> &myhashmap) {
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir(di.c_str())) != 0) {
    while ((ent = readdir (dir)) != 0) {
      string file(ent->d_name);
      if (file == "." || file == "..") {
	continue;
      }
      if (ent->d_type == DT_DIR) {
	string dirPath = di + "/" + file;
	//cout<< file << ": Directory" << endl;
	Findfile(dirPath, myhashmap);
      }
      if (ent->d_type == DT_REG ) {
	//cout<< file << endl;
	string dirPath = di + "/" + file;
	ifstream input(dirPath.c_str());
	if (input.good()) {
	  size_t hashval = hashfile(input, dirPath);
	  pair<size_t, string> mypair(hashval, dirPath);
	  compareDelete(mypair, myhashmap);
	  myhashmap.insert(mypair);
	}
	else {
	  cout << "can not open the file" << endl;
	  exit(1);
	}
	input.close();
      }
    }
    closedir(dir);
  }
  else {
    cout << "could not open directory" << endl;
    exit(1);
  }
}

int main(int argc, char **argv) {
  unordered_map<size_t, string> myhashmap;
  if (argc == 1) {
    cout << "./deduplication directory" << endl;
    return EXIT_FAILURE;
  }
  else {
    cout << "#!/bin/bash" <<endl;
    for (int i = 1; i < argc; i++) {
      const string dir = argv[i];
      Findfile(dir, myhashmap);
    }
    /*    for (auto& x: myhashmap) {
      cout << x.first<< ":" << x.second << endl;
      }
    */
  }
  return EXIT_SUCCESS;
}
