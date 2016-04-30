#include<cstdlib>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

int main(int argc, char **argv) {
  if(argc == 1) {
    string inputstr;
    vector<string> str;
    while(getline(cin, inputstr)) {
      str.push_back(inputstr);
    }
    sort(str.begin(), str.end());
    for (vector<string>::iterator it = str.begin(); it != str.end(); ++it) {
      cout<< *it<<endl;
    }
  }
  else {
    for (int i = 1; i < argc; i++) {
      string inputstr;
      vector<string> str;
      ifstream input(argv[i]);
      if (input.good()) {
	while(getline(input, inputstr)) {
	  str.push_back(inputstr);
	}
	sort(str.begin(), str.end());
	for (vector<string>::iterator it = str.begin(); it != str.end(); ++it) {
	  cout<< *it<<endl;
	}
      }
      else {
	cout<< "can not open the file"<<endl;
	exit(1);
      }
      input.close();
    }	
  }
  return EXIT_SUCCESS;
}	
    

