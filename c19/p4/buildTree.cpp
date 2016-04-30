#include "node.h"

Node *  buildTree(uint64_t * counts) {
  //WRITE ME!
  priority_queue_t pq;
  for (int i = 0; i < 257; i++) {
    if (counts[i] > 0) {
      pq.push(new Node(i, counts[i]));
    }
  }
  Node *node;
  while (pq.size() > 1) {
      Node *topl = pq.top();
      pq.pop();
      Node *topr = pq.top();
      pq.pop();
      node = new Node(topl, topr);
      pq.push(node);
    }
    Node *tree = pq.top();
    pq.pop();
    return tree;
}
