#ifndef __BSTSET_H__
#define __BSTSET_H__
#include "set.h"
#include "cstdlib"
#include <iostream>

template<typename T>
class BstSet : public Set<T> {
private:
  class Node {
  public:
    T key;
    Node *left;
    Node *right;
    Node(T d) : key(d), left(NULL),
		 right(NULL) {}
  };

  Node *root;
public:
  BstSet ():root(NULL) {}
  virtual void add(const T & key) {
    Node ** current = &root;
    while (*current != NULL) {
      if (key < (*current)->key) {
	current = &(*current)->left;
      }
      else  {
	current = &(*current)->right;
      }
    }
    *current = new Node(key);
  }
   
  virtual bool contains(const T& key) const {
    Node *current = root;
    while (current != NULL) {
      if (key == current->key) {
	return true;
      }
      else if (key < current->key) {
	current = current->left;
      }
      else {
	current = current->right;
      }
    }
    return false;
  }
  
  Node * FindMin(Node *node) {
    while(node->left != NULL) {
      node = node->left;
    }
      return node;
  }

  Node * removeKey(Node *node, const T& key) {
    if (node == NULL) {
      return node;
    }
    else if (key < node->key) {
      node->left = removeKey(node->left, key);
    }
    else if (key > node->key) {
      node->right = removeKey(node->right, key);
    }
    else {
      if (node->left ==NULL) {
	Node *temp = node;
	node = node->right;
	delete temp;
      }
      else if (node->right ==NULL) {
	Node *temp = node;
	node = node->left;
	delete temp;
      }
      else {
	Node *temp = FindMin(node->right);
	node->key = temp->key;
	node->right = removeKey(node->right, temp->key);
      }
    }
    return node;
  }     
  
  virtual void remove(const T& key) {
    Node * rootnode = root;
    removeKey(rootnode, key);
  }
   
  void destroy(Node *curr) {
    if (curr != NULL) {
      destroy(curr->left);
      destroy(curr->right);
      delete curr;
    }
  }

  virtual ~BstSet<T> () {
    Node *current = root;
    destroy(current);
  }

  void printInorder(Node *curr) {
    if (curr != NULL) {
      printInorder(curr->left);
      std::cout << curr->key <<std::endl;
      printInorder(curr->right);
    }
  }
  
  void inorder() {
    printInorder(root);
  }
};
#endif

