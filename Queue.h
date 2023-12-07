#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "Stack.h"
using namespace std;
template <typename T> class Queue {
private:
  T elements[4];
  size_t front;
  size_t rear;
  size_t size;

public:
  Queue() : front(0), rear(0), size(0) {}

  void enqueue(const T &element) {
    if (size == 4) {
      std::cerr << "Queue is full. Unable to enqueue." << std::endl;
      return;
    }

    elements[rear] = element;
    rear = (rear + 1) % 4;
    ++size;
  }

  T dequeue() {
    if (empty()) {
      std::cerr << "Queue is empty. Unable to dequeue." << std::endl;
      throw std::out_of_range("Queue is empty");
    }

    T frontElement = elements[front];
    front = (front + 1) % 4;
    --size;
    return frontElement;
  }

  T frontElement() const {
    if (empty()) {
      std::cerr << "Queue is empty." << std::endl;
      throw std::out_of_range("Queue is empty");
    }

    return elements[front];
  }

  bool empty() const { return size == 0; }

  size_t queueSize() const { return size; }
};

#endif // QUEUE_H
