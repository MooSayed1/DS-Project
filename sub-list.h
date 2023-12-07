#ifndef SUBLIST_H
#define SUBLIST_H

#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
using namespace std;

template <typename T> class Subll {
private:
  linkedList<Queue<Stack<T>>> elements;
  int size;

public:
  Subll() : size(0) {}

  void pushBack() {
    Queue<Stack<T>> newQueue;
    elements.pushBack(newQueue);
    ++size;
  }

  void popFront() {
    if (size == 0)
      std::cout << "Empty" << std::endl;
    else {
      elements.popFront();
      --size;
    }
  }
};

#endif
