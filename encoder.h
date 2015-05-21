// Author: Sean Davis
#ifndef ENCODER_H
#define	ENCODER_H

#include "HuffmanNode.h"
#include "BinaryHeap.h"
#include "StackAr.h"
#include <iostream>
#include <sstream>

using namespace std;

class Encoder
{
public:
  Encoder();
  void encode(const unsigned char *message, const int size, 
    unsigned char *encodedMessage, int *encodedSize);
  ~Encoder();
private:
  void getHeap(const unsigned char *message, const int size,
               BinaryHeap<HuffmanNode *> &heap, int &elements) const;
  void writeHeap(stringstream &out, BinaryHeap<HuffmanNode *> heap, int elements) const;
  void writeMesg(const unsigned char *message, const int size, 
                 unsigned char *encodedMessage, int *encodedSize,
                 const StackAr<char> arr[256]) const;
/*
  HuffmanNode *getTree(BinaryHeap<HuffmanNode *> &heap);
  void getHuffList(HuffmanNode *root, StackAr<char> &currKey, StackAr<char> *arr);
  StackAr<char> flipStack(StackAr<char> flip) const;
//  void print(const HuffmanNode *root) const;
  void printHeap(const BinaryHeap<HuffmanNode *> heap) const;
  void printStack(const StackAr<char> stack) const;
*/
};

#endif	/* ENCODER_H */

