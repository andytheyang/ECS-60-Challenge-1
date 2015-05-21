//  Author: Sean Davis

#include "encoder.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>
#include "BinaryHeap.h"
#include "dsexceptions.h"
#include "vector.h"
#include "HuffmanNode.h"
#include "StackAr.h"
#include "HuffmanTree.cpp"

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
  stringstream out;
  int elements = 0;
  out << encodedMessage;
  BinaryHeap <HuffmanNode *> heap(512);		// to store nodes
  getHeap(message, size, heap, elements);	// create the heap
//  printHeap(heap);
//  cout << "there are " << elements << " elements" << endl;
  writeHeap(out, heap, elements, encodedSize);	// writes heap (hopefully)
  cout << (const unsigned char *) out.str().c_str();
  HuffmanNode *root = getTree(heap);		// return the node to root of completed tree
  StackAr<char> currKey(STACK_SIZE);		// for remembering key (size can be changed)
  StackAr<char> arr[256];			// key for value
  getHuffList(root, currKey, arr);


}  // encode()


// PRIVATE ----------------------------------------------------------------------

void Encoder::getHeap(const unsigned char *message, const int size,
                      BinaryHeap<HuffmanNode *> &heap, int &elements) const
{
  unsigned int frequency[256] = {0};

  for (int i = 0; i < size; i++)
  {
    frequency[message[i]]++;
  }  // for each character

  for (int chars = 0; chars < 256; chars++)
  {
    if (frequency[chars] != 0)
    {
      elements++;		// to keep track of how large BHeap is
      HuffmanNode *ins = new HuffmanNode((unsigned char)chars, frequency[chars]);
      heap.insert(ins);
    }  // if character is in file, add to heap
  }  // for freqlist

  return;
}  // getHeap()

void Encoder::writeHeap(stringstream &out, BinaryHeap<HuffmanNode *> heap, int elements, int *csize) const
{
  out << elements;	// store how many heap elements at beginning
//  *csize += sizeof(int);

  HuffmanNode *node;	// to store temporary node
  while(!heap.isEmpty())
  {
    heap.deleteMin(node);
//    cout << "writing " << node->data;
    out << node->data;
//    *csize += sizeof(unsigned char);
    out << node->frequency;
//    *csize += sizeof(unsigned int);
  }  // traverse the entire heap

  return;
}  // writeHeap()


/*
HuffmanNode *Encoder::getTree(BinaryHeap<HuffmanNode *> &heap)
{
  HuffmanNode *node;

  while (true)
  {
    heap.deleteMin(node);

//    cout << "min is " << node->data << endl;
    if (heap.isEmpty())		// recently popped node is root
      break;

    HuffmanNode *node2;
    heap.deleteMin(node2);
    HuffmanNode *t = new HuffmanNode(node, node2);
//    cout << t->left->data << " - " << t->data << " - " << t->right->data << endl;
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
//    cout << root->data << " is ";
    StackAr<char> key = flipStack(currKey);
//    printStack(key);
    return;
  }  // if root is a leaf (char)

  // TODO: investigate why 1's and 0's are flipped
  currKey.push('1');
  getHuffList(root->left, currKey, arr);
  currKey.pop();

  currKey.push('0');
  getHuffList(root->right, currKey, arr);
  currKey.pop();
  return;
}  // getHuffList()

StackAr<char> Encoder::flipStack(StackAr<char> flip) const
{
  StackAr<char> other(STACK_SIZE);

  while (!flip.isEmpty())
  {
    other.push(flip.topAndPop());
  }

  return other;
}  // flip stack

// PRINT ------------------------------------------------------


void Encoder::printHeap(const BinaryHeap<HuffmanNode *> heap) const
{
  BinaryHeap<HuffmanNode *> copy = heap;
  while (!copy.isEmpty())
  {
    HuffmanNode *next;
    copy.deleteMin(next);
    cout << next->data << " " << next->frequency << endl;
  }

  return;
}

void Encoder::printStack(const StackAr<char> stack) const
{
  StackAr<char> copy = stack;
  while (!copy.isEmpty())
  {
    cout << copy.topAndPop();
  }  // while there are more things in the stack
  cout << endl;
  return;
}  // printStack()
*/
