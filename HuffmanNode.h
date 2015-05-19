#ifndef NODE_H
#define NODE_H

class HuffmanNode
{
public:
  unsigned char data;
  unsigned int frequency;
  HuffmanNode *left;
  HuffmanNode *right;

  HuffmanNode();
  HuffmanNode(unsigned char dat, unsigned int freq, 
              HuffmanNode *l, HuffmanNode *r);
  ~HuffmanNode();

  bool operator<(const HuffmanNode &rhs) const;
};  // Node

#endif
