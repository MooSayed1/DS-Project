#ifndef STACK_H
#define STACK_H

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> class Stack {
private:
  string operations[4];
  size_t size;

public:
  // Stack():(10),size(0
  // Constructor
  Stack() : size(0) {}

  // Destructor
  ~Stack() {}

  // Push an element onto the stack
  void displayStack() {
    for (int i = 0; i < 4; ++i)
      cout << operations[i] << " ";
  }
  void push(const T &element) { operations[size++] = element; }

  void addOperations() {
    cout << "Enter Operations: ";
    for (int i = 0; i < 4; ++i)
      cin >> operations[i];
  }

  // Remove and return the top element from the stack
  T pop() {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    T temp = operations[3];
    copy(operations + 1, operations + 4, operations);
    operations[0] = temp;

    return operations[3];
  }

  // Return the top element without removing it
  T top() const {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }

    return operations[size - 1];
  }

  // Check if the stack is empty
  bool empty() const { return size == 0; }

  // Return the number of operations in the stack
  size_t stackSize() const { return size; }
};
#endif // STACK_H
