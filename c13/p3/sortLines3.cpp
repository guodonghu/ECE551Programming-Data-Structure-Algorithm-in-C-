#include<cstdlib>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

template<typename T>
void sortdata(T &f) {                                  //sort data and print 
  string inputstr;
  vector<string> str;
  while(getline(f, inputstr)) {                        //read one line at a time
    str.push_back(inputstr);                           //push the line to str
  }
  sort(str.begin(), str.end());                        //sort the data stored in str
  for (vector<string>::iterator it = str.begin(); it != str.end(); ++it) {      //print the sorted data
    cout<< *it<<endl;
  }
}

int main(int argc, char **argv) {
  if(argc == 1) {                                      //check if we are reading from cin
    sortdata<istream>(cin);                            //read data from standard input
  }
  else {                                               //read data from file
    for (int i = 1; i < argc; i++) {
      ifstream input(argv[i]);
      if (input.good()) {
	sortdata<ifstream>(input);
      }
      else {
	cout<< "can not open the file"<<endl;
	return EXIT_FAILURE;
      }
      input.close();
    }	
  }
  return EXIT_SUCCESS;
}	
    

