#ifndef NODE_H
#define NODE_H

#include <cstdlib>
#include <iostream>

using namespace std;

class HuffmanNode
{
public:
  unsigned char data;
  unsigned int frequency;
  HuffmanNode *left;
  HuffmanNode *right;
  bool isLeaf;

  HuffmanNode();
  HuffmanNode(unsigned char dat, unsigned int freq);
  HuffmanNode(HuffmanNode *l, HuffmanNode *r);
  ~HuffmanNode();

  bool operator<(const HuffmanNode &rhs) const;
//  friend ostream& operator<<(ostream &os, HuffmanNode const &rhs);
};  // Node

#endif
