#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template <typename T, size_t InitialCapacity = 10>
class Queue {
private:
    T *elements;
    size_t capacity;
    size_t front;
    size_t rear;
    size_t size;

    void resize() {
        size_t newCapacity = capacity * 2; 
        T *newElements = new T[newCapacity];

        for (size_t i = 0; i < size; ++i) {
            newElements[i] = elements[(front + i) % capacity];
        }

        delete[] elements;

        elements = newElements;
        capacity = newCapacity;
        front = 0;
        rear = size;
    }

public:
    Queue() : elements(new T[InitialCapacity]), capacity(InitialCapacity), front(0), rear(0), size(0) {}

    ~Queue() {
        delete[] elements;
    }

    void enqueue(const T &element) {
        if (size == capacity) {
            resize();
        }

        elements[rear] = element;
        rear = (rear + 1) % capacity;
        ++size;
    }

    T dequeue() {
        if (empty()) {
            std::cerr << "Queue is empty. Unable to dequeue." << std::endl;
            throw std::out_of_range("Queue is empty");
        }

        T frontElement = elements[front];
        front = (front + 1) % capacity;
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

