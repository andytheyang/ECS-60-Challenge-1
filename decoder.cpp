//  Author: Sean Davis

#include "decoder.h"
#include <iostream>
#include "HuffmanNode.h"
#include "BinaryHeap.h"
#include "StackAr.h"
//#include "HuffmanTree.cpp"

using namespace std;

Decoder::Decoder()
{
} // Decoder()


Decoder::~Decoder()
{
} // ~Decoder()


void Decoder::decode(const unsigned char* encodedMessage, const int encodedSize, 
  unsigned char* decodedMessage, int *decodedSize)
{
  BinaryHeap <HuffmanNode *> heap(512);
  // generate heap from stored data in encodedMessage
  // use HuffmanTree libraries to generate HuffmanTree
  // decode and write to decodedMessage
} // decode()
