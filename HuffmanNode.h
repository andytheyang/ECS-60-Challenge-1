#ifndef NODE_H
#define NODE_H

#include <cstdlib>

class HuffmanNode
{
public:
  unsigned char data;
  unsigned int frequency;
  HuffmanNode *left = NULL;
  HuffmanNode *right = NULL;

  HuffmanNode();
  HuffmanNode(unsigned char dat, unsigned int freq);
  HuffmanNode(HuffmanNode *l, HuffmanNode *r);
  ~HuffmanNode();

  bool operator<(const HuffmanNode &rhs) const;
};  // Node

#endif
