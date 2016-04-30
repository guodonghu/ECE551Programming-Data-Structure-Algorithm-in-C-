#include"ll.h"
#include<iostream>
using namespace std;

int main() {
  LinkedList<int> test1;
  test1.addFront(3);
  test1.addFront(4);
  test1.addFront(5);
  test1.addBack(2);
  test1.addBack(6);
  LinkedList<int> test2(test1);
  LinkedList<int> test3;
  test3 = test2;
  for (int i = 0; i < test1.getSize(); i++) {
    cout<< test1[i] << endl;
  }
  cout<<test1.find(5)<<endl;
  cout<<test1.find(6)<<endl;
  cout<<test1.find(4)<<endl;
  test2.traverse_and_print();
  test3.traverse_and_print();
  cout<<test2.find(5)<< endl;
  cout<<test2[2]<< endl;
  cout<<test2.find(5)<< endl;
  cout<<test2[2]<< endl;
  return EXIT_SUCCESS;
}
