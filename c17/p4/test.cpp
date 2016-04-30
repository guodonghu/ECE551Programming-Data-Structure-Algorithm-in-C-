#include "bstset.h"
#include "set.h"
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
  BstSet<int> set;
  set.add(5);
  set.add(10);
  set.add(3);
  set.add(4);
  set.add(1);
  set.add(11);
  set.add(3);
  set.remove(5);
  std::cout<< "inorder: ";
  set.inorder();
  std::cout << endl;
  std::cout<<"value of 1 is:"<<set.contains(0)<<endl; 
}
