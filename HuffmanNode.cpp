#include "HuffmanNode.h"
#include <iostream>

using namespace std;

HuffmanNode::HuffmanNode() : data(0), frequency(0), left(NULL),
                             right(NULL)
{

}  // blank constructor

HuffmanNode::HuffmanNode(unsigned char dat, unsigned int freq,
                         HuffmanNode *l, HuffmanNode *r) :
                         data(dat), frequency(freq), left(l),
                         right(r)
{
}  // constructor

HuffmanNode::~HuffmanNode()
{
  delete left;
  delete right;
}  // destructor

bool HuffmanNode::operator<(const HuffmanNode &rhs) const
{
  return (frequency < rhs.frequency);
}  // less than operator

