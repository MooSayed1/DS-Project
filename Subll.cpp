// Subll.cpp
#include "Subll.h"

template <typename T>
node<T>::node()
    : next(nullptr), prev(nullptr), data(new T[4]), front(0), rear(0),
      sizeofNode(0) {}

template <typename T>
node<T>::~node() {
  delete[] data;
}



template <typename T>
void node<T>::displayNode() {
    static_assert(std::is_same<decltype(std::cout << std::declval<T>()), std::ostream&>::value,
                  "T must support the << operator for std::ostream");

    for (int i = 0; i < 4; ++i)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}


template <typename T>
void node<T>::enqueue(T value) {
  data[rear] = value;
  rear = (rear + 1) % 4;
  ++sizeofNode;
}

template <typename T>
T node<T>::dequeue() {
  T frontElement = data[front];
  data[front] = T();
  front = (front + 1) % 4;
  --sizeofNode;
  return frontElement;
}

template <typename T>
T node<T>::frontElement() const {
  if (isEmpty()) {
    std::cerr << "Queue is empty." << std::endl;
    throw std::out_of_range("Queue is empty");
  }
  return data[front];
}

template <typename T>
T node<T>::backElement() {
  return data[rear];
}

template <typename T>
bool node<T>::isEmpty() const {
  return sizeofNode == 0;
}

template <typename T>
bool node<T>::isFull() {
  return sizeofNode == 4;
}

template <typename T>
Subll<T>::Subll()
    : size(0), head(nullptr), tail(nullptr) {}

template <typename T>
size_t Subll<T>::getSize() {
  return size;
}

template <typename T>
void Subll<T>::print() {
  node<T> *temp = head;
  if (size > 0) {
    while (temp) {
      temp->displayNode();
      std::cout << std::endl;
      temp = temp->next;
    }
  }
}


template <typename T>
bool Subll<T>::isEmpty() {
  return size <= 0;
}

template <typename T>
void Subll<T>::push(T value) {
  node<T> *newNode = new node<T>;

  if (size == 0) {
    head = tail = newNode;
    newNode->enqueue(value);
  } else {
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

template <typename T>
T Subll<T>::pop() {
  if (size == 0)
    std::cout << "empty";

  if (head->sizeofNode == 1) {
    node<T> *temp = head;
    T value = head->data[0];
    head = head->next;
    delete temp;
    return value;
  } else {
    return head->dequeue();
  }
  --size;
}

// Explicit instantiation of the template class
template class Subll<int>; // Change int to the desired type of your Subll
template class Subll<string>; 
// template class Subll<Cake>; 
template class Subll<double>; 

