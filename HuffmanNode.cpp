#include "HuffmanNode.h"
#include <iostream>

using namespace std;

HuffmanNode::HuffmanNode() : data(0), frequency(0), left(NULL),
                             right(NULL)
{

}  // blank constructor

HuffmanNode::HuffmanNode(unsigned char dat, unsigned int freq) : data(dat), frequency(freq)
{
}  // for char

HuffmanNode::HuffmanNode(HuffmanNode *l, HuffmanNode *r) : left(l), right(r)
{
  frequency = l->frequency + r->frequency;
}  // for char


HuffmanNode::~HuffmanNode()
{
}  // destructor

bool HuffmanNode::operator<(const HuffmanNode &rhs) const
{
  return (frequency < rhs.frequency);
}  // less than operator

