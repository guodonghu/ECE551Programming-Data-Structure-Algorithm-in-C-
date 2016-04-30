#include "bstmap.h"
#include "map.h"
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
  BstMap<int, int> map;
  map.add(5, 55);
  map.add(10, 100);
  map.add(3, 33);
  map.add(4, 44);
  map.add(1, 11);
  map.add(11, 111);
  map.add(12, 122);
  map.add(12, 123);
  map.remove(5);
  std::cout<< "inorder: "<<endl;
  map.inorder();
  std::cout<<"value of 1 is:"<<map.lookup(1)<<endl; 
  //std::cout<<"value of 1 is:"<<map.lookup(9)<<endl; 
}
