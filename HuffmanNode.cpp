#include "HuffmanNode.h"
#include <iostream>

using namespace std;

HuffmanNode::HuffmanNode() : data(0), frequency(0), left(NULL),
                             right(NULL), isLeaf(false)
{

}  // blank constructor

HuffmanNode::HuffmanNode(unsigned char dat, unsigned int freq) : data(dat), frequency(freq),
                                                                 left(NULL), right(NULL),
                                                                 isLeaf(true)
{
}  // for char

HuffmanNode::HuffmanNode(HuffmanNode *l, HuffmanNode *r) : left(l), right(r), isLeaf(false)
{
  data = 't';
  frequency = l->frequency + r->frequency;
}  // for char


HuffmanNode::~HuffmanNode()
{
}  // destructor

bool HuffmanNode::operator<(const HuffmanNode &rhs) const
{
//  return (frequency < rhs.frequency);
  return (frequency > rhs.frequency);		// LOOOL
}  // less than operator

/*
friend ostream& operator<<(ostream &os, HuffmanNode const &rhs)
{
  os << rhs->left->data << " - " << rhs->data << " - " << rhs->right->data << endl;
}  // operator<<
*/
