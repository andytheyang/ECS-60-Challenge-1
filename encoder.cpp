//  Author: Sean Davis

#include "encoder.h"
#include <iostream>
#include "BinaryHeap.h"
#include "dsexceptions.h"
#include "vector.h"
#include "HuffmanNode.h"

using namespace std;

Encoder::Encoder()
{
} // Encoder()


Encoder::~Encoder()
{
} // ~Encoder()

void Encoder::encode(const unsigned char *message, const int size, 
  unsigned char *encodedMessage, 
    int *encodedSize)
{
  unsigned int frequency[256] = {0};

  for (int i = 0; i < size; i++)
  {
    frequency[message[i]]++;
  }  // for each character

// prints freqlist
//  for (int i = 0; i < 256; i++)
//    cout << (char)i << ": " << frequency[i] << endl;

  BinaryHeap<HuffmanNode> heap;

  for (int i = 0; i < 256; i++)
  {
    if (frequency[i] != 0)
    {
      HuffmanNode ins((unsigned char)i, frequency[i], NULL, NULL);
      heap.insert(ins);
    }  // if character is in file, add to heap
  }  // for freqlist

  while(!heap.isEmpty())
  {
    HuffmanNode del;
    heap.deleteMin(del);
    cout << del.data << " occurs " << del.frequency << endl;
  }
}  // encode()
