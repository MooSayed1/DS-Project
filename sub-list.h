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
  node<T> *head;
  node<T> *tail;

  int size;

public:
  Subll() : size(0) {}

  void pushfront(int value) {
    if (elements.getSize() = 0) {
       
    }
  }

  void pobFront() {

    if (size == 0)
      cout << "empty";

    else if (size == 1)
      head = tail = NULL;

    else {
      node<T> *ptr = tail;

      tail = tail->prev;
      delete (ptr);
      tail->next = NULL;
    }
    --size;
  }
};

#endif
