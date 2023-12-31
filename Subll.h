#ifndef SUBLIST_H
#define SUBLIST_H

#include <iostream>
#include <type_traits>
#include <vector>
#include "Cake.h"

using namespace std;
template <typename T>
struct node {
  T *data;
  node *next;
  node *prev;
  size_t front;
  size_t rear;
  size_t sizeofNode;

  node();
  ~node();
  void displayNode();
  void enqueue(T value);
  T dequeue();
  T dequeueWithoutDelete();
  T frontElement() const;
  T backElement();
  bool isEmpty() const;
  bool isFull();
};

template <typename T>
class Subll {
public:

  node<T> *head;
  node<T> *tail;
  size_t size;

  Subll();
  size_t getSize();
  void print();
  vector<T>copyToVector();
  // void addData();
  bool isEmpty();
  void push(T value);
  T pop();
  T popWithoutDelete();
  // void remove_at(int value);
  // void remove_atIndex(int index);
};


#endif // SUBLIST_H
