#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename T> struct node {
  T data;
  node *next;
  node *prev;

  node(int value) : data(value) {}

  node() : next(NULL), prev(NULL) {}
};

template <typename T> class linkedList {
private:
  node<T> *head;
  node<T> *tail;

  int size;

public:
  linkedList() : size(0) {}

  void insert(int value) {
    node<T> *newNode = new node<T>(value);
    if (!size)
      head = tail = newNode;
    else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    ++size;
  }

  void print() {
    node<T> *temp = head;
    if (size > 0) {
      while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
      }
    }
  }

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

  void pushBack(int value) {

    node<T> *newNode = new node<T>(value);

    if (size == 0)
      head = newNode;

    else {

      node<T> *ptr = head;

      while (ptr->next) {

        ptr = ptr->next;
      }
      ptr->next = newNode;
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

  void pobBack() {

    if (size > 0) {

      node<T> *ptr = head;

      while (ptr->next->next) {

        ptr = ptr->next;
      }

      delete (ptr->next);

      ptr->next = NULL;
    }
    --size;
  }

  void insert_at(int index, int value) {

    if (index == 0)
      pushfront(value);

    else if (index == size - 1)
      pushBack(value);

    else {
      node<T> *newNode = new node<T>(value);
      // index = 2
      node<T> *prev = head;
      node<T> *curr = head; // 0  1    2 3

      while (index--) {
        prev = curr;
        curr = curr->next;
      }

      curr->prev = newNode;
      newNode->next = curr;

      prev->next = newNode;
      newNode->prev = prev;

      ++size;
    }
  }

  void remove_at(int value) {

    node<T> *ptr = head;
    while (ptr->data != value && ptr) {
      ptr = ptr->next;
    }

    if (ptr) {
      ptr->next->prev = ptr->prev;
      ptr->prev->next = ptr->next;
      delete (ptr);
      size--;
    }
  }

  void remove_atIndex(int index) {
    node<T> *temp = head;
    temp = head;
    while (index--) {
      temp = temp->next;
    }
    if (temp) {
      temp->next->prev = temp->prev;
      temp->prev->next = temp->next;
      delete temp;
      --size;
    }
  }
};

#endif
