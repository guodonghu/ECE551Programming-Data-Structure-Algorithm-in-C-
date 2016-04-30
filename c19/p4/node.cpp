#include "node.h"

void buildMapHelper(BitString b, std::map<unsigned,BitString> & theMap, bool isLeft, Node *root) ;

void Node::buildMap(BitString b, std::map<unsigned,BitString> & theMap) {
  //WRITE ME!
  if (left == NULL || right == NULL) {
    return;
  } else {
    buildMapHelper(b, theMap, true, this->left);
    buildMapHelper(b, theMap, false, this->right);
  }
}

 
void buildMapHelper(BitString b, std::map<unsigned,BitString> & theMap, bool isLeft, Node * root) {
  b = isLeft ? b.plusZero() : b.plusOne();
  if (root->sym != NO_SYM) {
    assert((root->left == NULL) && (root->right == NULL));
    theMap.insert(std::pair<unsigned, BitString>(root->sym, b) );
  } else {
    buildMapHelper(b, theMap, true, root->left);
    buildMapHelper(b, theMap, false, root->right);
  }
}
