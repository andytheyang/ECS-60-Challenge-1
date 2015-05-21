// Author: Andy Yang
// This class provides various libraries for huffman tree generation from heaps
#ifndef HUFFMANTREE_CPP
#define HUFFMANTREE_CPP

#include <iostream>
#include "BinaryHeap.h"
#include "HuffmanNode.h"
#include "StackAr.h"
using namespace std;

const int STACK_SIZE = 32;

HuffmanNode *getTree(BinaryHeap<HuffmanNode *> &heap);
void getHuffList(HuffmanNode *root, StackAr<char> &currKey, StackAr<char> *arr);
StackAr<char> flipStack(StackAr<char> flip);
void printHeap(const BinaryHeap<HuffmanNode *> heap);
void printStack(const StackAr<char> stack);
void printChar(const unsigned char *mesg, const int size);

HuffmanNode *getTree(BinaryHeap<HuffmanNode *> &heap)
{
  HuffmanNode *node;

  while (true)
  {
    heap.deleteMin(node);

//    cout << "min is " << node->data << endl;
    if (heap.isEmpty())         // recently popped node is root
      break;

    HuffmanNode *node2;
    heap.deleteMin(node2);
    HuffmanNode *t = new HuffmanNode(node, node2);
//    cout << t->left->data << " - " << t->data << " - " << t->right->data << endl;
    heap.insert(t);
  }  // while

  return node;
}  // getTree()

void getHuffList(HuffmanNode *root, StackAr<char> &currKey, StackAr<char> *arr)
{
  // TODO: make this work
  if (root->isLeaf)
  {
//    arr[root->data] = currKey;
// TODO: comment this
    cout << root->data << " is ";
    StackAr<char> key = flipStack(currKey);
    arr[root->data] = key;
// TODO: comment this
    printStack(key);
    cout << endl;
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

StackAr<char> flipStack(StackAr<char> flip)
{
  StackAr<char> other(STACK_SIZE);

  while (!flip.isEmpty())
  {
    other.push(flip.topAndPop());
  }

  return other;
}  // flip stack


// PRINT STUFF ---------------------
void printHeap(const BinaryHeap<HuffmanNode *> heap)
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

void printStack(const StackAr<char> stack)
{
  StackAr<char> copy = stack;
  while (!copy.isEmpty())
  {
    cout << copy.topAndPop();
  }  // while there are more things in the stack
//  cout << endl;
  return;
}  // printStack()

void printChar(const unsigned char *mesg, const int size)
{
  for (int i = 0; i < size; i++)
    cout << mesg[i];

  cout << endl;
  return;
}  // printChar()

#endif
