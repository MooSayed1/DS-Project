#ifndef STACK_H
#define STACK_H

#include "Cake.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> class Stack {
private:
  // Cake ckobj;
  Cake cakeObj;
  T operations[4];
  size_t size;

public:
  // Stack():(10),size(0
  // Constructor
  Stack() : size(0) {
    // operations[0] = "Mixing and Batching";
    // operations[1] = "Baking";
    // operations[2] = "Decorating and Icing";
    // operations[3] = "Packaging";
  }

  // DestructorPackaging
  ~Stack() {}
  void displayStack() {
    for (int i = 0; i < 4; ++i)
      cout << operations[i] << " |";
    cout << endl;
  }
  // Push an element onto the stack
  // void push(const T &element) { operations[size++] = element; }
  void addOperations() {
    cout << "Enter Operations: ";
    for (int i = 0; i < 4; ++i)
      cin >> operations[1];
  }

  // Remove and return the top element from the stack
  T pop() {
    // if (empty()) {
    //   throw std::out_of_range("Stack is empty");
    // }
    T temp = operations[3];
    for (int i = 3; i >= 0; --i)
      operations[i] = operations[i - 1];
    // copy(operations, operations + 3, operations + 1);
    operations[0] = temp;

    return temp;
  }
  void addDatafromStack(){
    cakeObj.addData();

  }

  // Return the top element without removing it
  // T top() const {
  //   if (empty()) {
  //     throw std::out_of_range("Stack is empty");
  //   }
  //
  //   return operations[size - 1];
  // }
  //
  // Check if the stack is empty
  bool empty() const { return size == 0; }

  // Return the number of operations in the stack
  size_t stackSize() const { return size; }
};
#endif // STACK_H
