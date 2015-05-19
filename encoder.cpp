//  Author: Sean Davis

#include "encoder.h"
#include <iostream>
#include <cassert>
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

  for (int chars = 0; chars < 256; chars++)
  {
    if (frequency[chars] != 0)
    {
      HuffmanNode ins((unsigned char)chars, frequency[chars]);
      heap.insert(ins);
    }  // if character is in file, add to heap
  }  // for freqlist

/*  while (!heap.isEmpty())
  {
    HuffmanNode next;
    heap.deleteMin(next);
    cout << next.data << " " << next.frequency << endl;
  }

  return;
*/

  HuffmanNode node;

  while (true)
  {
    heap.deleteMin(node);

    if (heap.isEmpty())
      break;

    HuffmanNode node2;
    heap.deleteMin(node2);
    HuffmanNode t(&node, &node2);
    heap.insert(t);
  }  // while

  // node is root of tree
  print(&node);
}  // encode()

void Encoder::print(HuffmanNode *root)
{
  if (root->left == NULL || root->right == NULL)
  {
    cout << " is " << root->data << endl;
    return;
  }

//  cout << 0;
  print(root->left);
//  cout << 1;
  print(root->right);
}  // print
