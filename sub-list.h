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

  void pushBack(const T &value) {
    if (size == 0 || elements.back().isFull()) {
      Queue<Stack<T>> newQueue;
      elements.pushBack(newQueue);
      newQueue.enqueue(value);
      ++size;
    } else {
      elements.getTail().pushBack(value);
    }
  }

  void popFront() {
    if (size == 0) {
      std::cout << "Empty" << std::endl;
    } else {
      elements.front().popFront();

      // Check if the first queue becomes empty, and if so, pop the entire node
      if (elements.front().isEmpty()) {
        elements.popFront();
        --size;
      }
    }
  }
};
#endif
