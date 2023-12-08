#ifndef SUBLIST_H
#define SUBLIST_H
#include "Stack.h"
#include <iostream>
using namespace std;

template <typename T> struct node {
  T *data;
  node *next;
  node *prev;
  size_t front;
  size_t rear;
  size_t sizeofNode;

  //---------------------------------------

  node() : next(nullptr), prev(nullptr), data(new T[4]), front(0), rear(0), sizeofNode(0) {}

 ~node() {
        delete[] data;
    }
  void displayNode() {
    for (int i = 0; i < 4; ++i)
      cout << data[i] << " ";
  }

  void enqueue(T value) {

    data[rear] = value;
    rear = (rear + 1) % 4;
    ++sizeofNode;
  }
  T dequeue() {

    T frontElement = data[front];
     data[front] = T();  // Assign a default-constructed value to remove the element
    front = (front + 1) % 4;
    --sizeofNode;
    return frontElement;
  }

  T frontElement() const {
    if (isEmpty()) {
      std::cerr << "Queue is empty." << std::endl;
      throw std::out_of_range("Queue is empty");
    }

    return data[front];
  }

  bool isEmpty() const { return sizeofNode == 0; }
  bool isFull() { return sizeofNode == 4; }
};

//-----------------------------------------------------

template <typename T> class Subll {
private:
  node<T> *head;
  node<T> *tail;

  size_t size;

public:
  Subll() : size(0), head(nullptr), tail(nullptr) {}
  size_t getSize() { return size; }

  void print() {
    node<T> *temp = head;
    if (size > 0) {
      while (temp) {
        temp->displayNode();
        cout << endl;
        temp = temp->next;
      }
    }
  }

  // void pushfront(int value) {
  //
  //   node<T> *newNode = new node<T>(value);
  //
  //   if (size == 0)
  //     head = tail = newNode;
  //
  //   else {
  //
  //     newNode->next = head;
  //     head->prev = newNode;
  //     head = newNode;
  //   }
  //   ++size;
  // }

  void push(T value) {

    node<T> *newNode = new node<T>;

    if (size == 0) {
      head = tail = newNode;
      newNode->enqueue(value);
    }

    else {
      // if last Node be Full make a new node and link it by the last Node
      if (tail->sizeofNode == 4) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->enqueue(value);
      } else {
        tail->enqueue(value);
      }
    }
    ++size;
  }

  void pobFront() {

    if (size == 0)
      cout << "empty";

    // cout << "Size equal " << head->sizeofNode << endl;
    if (head->sizeofNode == 1) {
      node<T> *temp = head;
      head = head->next;
      delete temp;
    } else {
      head->dequeue();
    }
    --size;
  }

  // void pobBack() {
  //
  //   if (size > 0) {
  //
  //     node<T> *ptr = head;
  //
  //     while (ptr->next->next) {
  //
  //       ptr = ptr->next;
  //     }
  //
  //     delete (ptr->next);
  //
  //     ptr->next = NULL;
  //   }
  //   --size;
  // }

  // void insert_at(int index, int value) {
  //
  //   if (index == 0)
  //     pushfront(value);
  //
  //   else if (index == size - 1)
  //     pushBack(value);
  //
  //   else {
  //     node<T> *newNode = new node<T>(value);
  //     // index = 2
  //     node<T> *prev = head;
  //     node<T> *curr = head; // 0  1    2 3
  //
  //     while (index--) {
  //       prev = curr;
  //       curr = curr->next;
  //     }
  //
  //     curr->prev = newNode;
  //     newNode->next = curr;
  //
  //     prev->next = newNode;
  //     newNode->prev = prev;
  //
  //     ++size;
  //   }
  // }

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
