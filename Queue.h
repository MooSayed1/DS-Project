#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template <typename T, size_t Capacity> class Queue {
private:
  T elements[Capacity];
  size_t front;
  size_t rear;
  size_t size;

public:
  Queue() : front(0), rear(0), size(0) {}

  void enqueue(const T &element) {
    if (size == Capacity) {
      std::cerr << "Queue is full. Unable to enqueue." << std::endl;
      return;
    }

    elements[rear] = element;
    rear = (rear + 1) % Capacity;
    ++size;
  }

  T dequeue() {
    if (empty()) {
      std::cerr << "Queue is empty. Unable to dequeue." << std::endl;
      throw std::out_of_range("Queue is empty");
    }

    T frontElement = elements[front];
    front = (front + 1) % Capacity;
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
