#ifndef SUBLIST_H
#define SUBLIST_H

#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

template <typename T> struct node {
  Queue<Stack<T>>elements;
  node *next;
  node *prev;

  node() : next(NULL), prev(NULL) {}
};

template <typename T> class SubList {
private:
  node<T> *head;
  node<T> *tail;

  int size;

public:
  SubList() : size(0) {}

  

 void pushfront(int value) {

    node<T> *newNode = new node<T>(value);

    if (size == 0)
      head = tail = newNode;

    else {

      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    ++size;
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
