#ifndef __BSTMAP_H__
#define __BSTMAP_H__
#include "map.h"
#include "cstdlib"
#include <iostream>

template<typename K, typename V>
class BstMap : public Map<K , V> {
private:
  class Node {
  public:
    K key;
    V value;
    Node *left;
    Node *right;
    Node (K key, V value) : key(key), value(value),left(NULL),
			    right(NULL) {}
  };

  Node *root;
public:
  BstMap () : root(NULL) {}
  virtual void add(const K &key, const V & value) {
    Node ** current = &root;
    while (*current != NULL) {
      if (key < (*current)->key) {
	current = &(*current)->left;
      }
      else if (key > (*current)->key) {
	current = &(*current)->right;
      }
      else {
	(*current)->value = value;
	return;
      }
    }
    *current = new Node(key, value);
  }
   
  virtual const V & lookup(const K& key) const throw (std::invalid_argument) {
    Node *current = root;
    while (current != NULL) {
      if (key == current->key) {
	return current->value;
      }
      else if (key < current->key) {
	current = current->left;
      }
      else {
	current = current->right;
      }
    }
    throw std::invalid_argument("key not found.");
  }
  
  Node * FindMin(Node *node) {
    while(node->left != NULL) {
      node = node->left;
    }
      return node;
  }

  Node * removeKey(Node *node, const K& key) {
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
      if (node->left ==NULL) {       //one child case
	Node *temp = node;
	node = node->right;
	delete temp;
      }
      else if (node->right ==NULL) {
	Node *temp = node;
	node = node->left;
	delete temp;
      }
      else {                          // two children
	Node *temp = FindMin(node->right);
	node->key = temp->key;
	node->value = temp->value;
	node->right = removeKey(node->right, temp->key);
      }
    }
    return node;
  }     
  
  virtual void remove(const K& key) {
    root = removeKey(root, key);
  }
   
  void destroy(Node *curr) {
    if (curr != NULL) {
      destroy(curr->left);
      destroy(curr->right);
      delete curr;
    }
  }

  virtual ~BstMap<K,V>() {
    destroy(root);
  }

  void printInorder(Node *curr) {           
    if (curr != NULL) {
      printInorder(curr->left);
      std::cout << curr->key << " "<<curr->value<<"\n";
      printInorder(curr->right);
    }
  }
  
  void inorder() {
    printInorder(root);
  }
};
#endif
