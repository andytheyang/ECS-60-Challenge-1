// Author: Sean Davis
#ifndef ENCODER_H
#define	ENCODER_H

#include "HuffmanNode.h"

class Encoder
{
public:
  Encoder();
  void encode(const unsigned char *message, const int size, 
    unsigned char *encodedMessage, int *encodedSize);
  ~Encoder();
private:
  void print(HuffmanNode *root);
};

#endif	/* ENCODER_H */

