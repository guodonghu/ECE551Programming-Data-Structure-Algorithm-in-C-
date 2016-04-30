#ifndef _LL_H_
#define _LL_H_
#include <cstdlib>
#include <exception>
#include <assert.h>
#include <iostream>
using namespace std;
//YOUR CODE GOES HERE
template<typename T>
class LinkedList {
private:
  class Node {
  public:
    T data;
    Node *next;
    Node *previous;
  Node(T d, Node *n, Node *p ): data(d), next(n), previous(p) {}
    //  Node(T d) : data(d), next(NULL), previous(NULL) {}
    //Node() : next(NULL), previous(NULL) {}
  };

  class myexception: public exception {
    virtual const char* what() const throw() {
      return  "Requested item does not exit";
    }
  } myex;

  Node *head;
  Node *tail;
  int size;
public: 
  void addFront(const T &item) {
    head = new Node(item, head, NULL);
    if (tail == NULL) {
      tail = head;
    }
    else {
      head->next->previous = head;
    }
    size++;
  }
  
  void addBack(const T &item) {
    tail = new Node(item, NULL, tail);
    if (head == NULL) {
      head = tail;
    }
    else {
      if (tail->previous != NULL) {
      tail->previous->next = tail;
      }
    }
    size++;
  }
  
  bool remove(const T &item) {
    if (head == NULL) {
      return false;
    }
    Node *pre = NULL;
    Node *del = NULL;
    if (head->data ==item) {
      del =head;
      head = del->next;
      if (size == 1) {
	tail = NULL;
      }
      if (head != NULL) { 
      head->previous = NULL;
      }
      delete del;
      size--;
      return true;
    }
    pre = head;
    del = head->next;
    while (del != NULL) {
      if (del->data == item) {
	pre->next = del->next;
	if (del->next != NULL) {
	del->next->previous = pre;
	}
	if (del == tail) {
	  tail = pre;
	}
	delete del;
	size--;
	return true;
      }
      pre = del;
      del = del->next;
    }
    return false;
}

  void traverse_and_print() {
    Node *p = head;
    if (head == NULL) {
      cout<< "The list is empty" << endl;
      return;
    }
    cout << "Linkedlist: ";
    while (p != NULL) {
      std::cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }

  T & operator[](int index) {
    if (index > size - 1) {
      throw myex;
    }
    Node *ref = head;
    for (int i = 0; i < index; i++) {
      ref = ref->next;
    }
    T &refdata = ref->data;
    return refdata;
  }

 const T & operator[](int index) const {
    if (index > size - 1) {
      throw myex;
    }
    Node *ref = head;
    for (int i = 0; i < index; i++) {
      ref = ref->next;
    }
    T &refdata = ref->data;
    return refdata;
  }

  int find(const T &item) const {
    Node *search = head;
    if (search == NULL) {
      return -1;
    }
    for (int i = 0; i < size; i++) {
      if (search->data == item) {
	return i;
      }
      search = search->next;
    }
    return -1;
  }
  
  LinkedList() :head(NULL), tail(NULL), size(0) {}
  
 LinkedList(const LinkedList &rhs): head(NULL), tail(NULL),size(0) {      //
    for (int i = 0; i < rhs.size; i++) {
      addBack(rhs[i]);
    }
  }

  void destroy () {
    while (head != NULL) {
      Node *temp = head->next;
      delete head;
      head = temp;
    }
  }

  LinkedList & operator=(const LinkedList &rhs) {
    if (this != &rhs) {
      destroy();
      size = 0;
      for (int i = 0; i < rhs.size; i++) {
	addBack(rhs[i]);
      }  
    }
    return *this;
  }

  ~LinkedList () {
    destroy();
  }

  int getSize() const {
    return size;
  }
};
#endif
