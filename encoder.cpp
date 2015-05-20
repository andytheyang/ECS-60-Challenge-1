//  Author: Sean Davis

#include "encoder.h"
#include <iostream>
#include <cassert>
#include "BinaryHeap.h"
#include "dsexceptions.h"
#include "vector.h"
#include "HuffmanNode.h"
#include "StackAr.h"

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
  BinaryHeap<HuffmanNode *> heap;		// to store nodes
  getHeap(message, size, heap);			// create the heap
  HuffmanNode *root = getTree(heap);		// return the node to root of completed tree
  StackAr<char> currKey;			// for remembering key (size can be changed)
  StackAr<char> arr[256];			// key for value
  getHuffList(root, currKey, arr);
}  // encode()

// PRIVATE ----------------------------------------------------------------------

void Encoder::getHeap(const unsigned char *message, const int size,
                      BinaryHeap<HuffmanNode *> &heap) const
{
  unsigned int frequency[256] = {0};

  for (int i = 0; i < size; i++)
  {
    frequency[message[i]]++;
  }  // for each character

//  prints freqlist
//  for (int i = 0; i < 256; i++)
//    cout << (char)i << ": " << frequency[i] << endl;

  for (int chars = 0; chars < 256; chars++)
  {
    if (frequency[chars] != 0)
    {
      HuffmanNode *ins = new HuffmanNode((unsigned char)chars, frequency[chars]);
      heap.insert(ins);
    }  // if character is in file, add to heap
  }  // for freqlist

  return;
}  // getHeap()


HuffmanNode *Encoder::getTree(BinaryHeap<HuffmanNode *> &heap)
{
  HuffmanNode *node;

  while (true)
  {
    node = heap.findMin();
    heap.deleteMin();

    if (heap.isEmpty())
      break;

    HuffmanNode *node2 = heap.findMin();
    heap.deleteMin();
//    cout << "tying " << node->data << " and " << node2->data << endl;
    HuffmanNode *t = new HuffmanNode(node, node2);
    heap.insert(t);
  }  // while

  return node;
}

void Encoder::getHuffList(HuffmanNode *root, StackAr<char> &currKey, StackAr<char> *arr)
{
  // TODO: make this work
  if (root->isLeaf)
  {
//    arr[root->data] = currKey;
    cout << root->data << " is ";
    StackAr<char> other = currKey;

    while(!other.isEmpty())
    {
      cout << other.topAndPop();
    }  // while there are more things

    cout << endl;
    return;
  }  // if root is a leaf (char)

  currKey.push('0');
  getHuffList(root->left, currKey, arr);

  currKey.push('1');
  getHuffList(root->right, currKey, arr);
  currKey.pop();
  return;
}

// PRINT ------------------------------------------------------

void Encoder::print(HuffmanNode *root) const
{
  if (root->isLeaf)
  {
    cout << " is " << root->data << endl;
    return;
  }

  cout << 0;
  print(root->left);
  cout << 1;
  print(root->right);
}  // print

void Encoder::printHeap(BinaryHeap<HuffmanNode *> heap) const
{
  while (!heap.isEmpty())
  {
    HuffmanNode *next;
    heap.deleteMin(next);
    cout << next->data << " " << next->frequency << endl;
  }

  return;
}
