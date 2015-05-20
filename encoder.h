// Author: Sean Davis
#ifndef ENCODER_H
#define	ENCODER_H

#include "HuffmanNode.h"
#include "BinaryHeap.h"

class Encoder
{
public:
  Encoder();
  void encode(const unsigned char *message, const int size, 
    unsigned char *encodedMessage, int *encodedSize);
  ~Encoder();
private:
  void getHeap(const unsigned char *message, const int size,
               BinaryHeap<HuffmanNode *> &heap) const;
  HuffmanNode *getTree(BinaryHeap<HuffmanNode *> &heap);
  void print(HuffmanNode *root) const;
  void printHeap(BinaryHeap<HuffmanNode *> heap) const;
};

#endif	/* ENCODER_H */

