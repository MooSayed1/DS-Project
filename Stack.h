#ifndef STACK_H
#define STACK_H

#include<iostream>
using namespace std;
template <typename T>
class Stack {
private:
    T* data; 
    size_t capacity;  
    size_t size;     

public:
    Stack():capacity(10),size(0){}
    // Constructor
    Stack(size_t capacity = 10) : capacity(capacity), size(0) {
        data = new T[capacity];
    }

    // Destructor
    ~Stack() {
        delete[] data;
    }

    // Push an element onto the stack
    void push(const T& element) {
        if (size == capacity) {
            // If the array is full, double its capacity
            capacity *= 2;
            T* newdata = new T[capacity];

            // Copy existing data to the new array
            for (size_t i = 0; i < size; ++i) {
                newdata[i] = data[i];
            }

            // Delete the old array and update the pointer
            delete[] data;
            data = newdata;
        }

        data[size++] = element;
    }

    // Remove and return the top element from the stack
    T pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }

        return data[--size];
    }

    // Return the top element without removing it
    T top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }

        return data[size - 1];
    }

    // Check if the stack is empty
    bool empty() const {
        return size == 0;
    }
    
    void resize()
    {

    }
    // Return the number of data in the stack
    size_t stackSize() const {
        return size;
    }
};
#endif //STACK_H
