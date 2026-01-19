// Subll.cpp
#include "Subll.h"

template <typename T>
node<T>::node()
    : data(new T[4]), next(nullptr), prev(nullptr), front(0), rear(0),
      sizeofNode(0) {}

template <typename T> node<T>::~node() { delete[] data; }

template <typename T> void node<T>::displayNode() {
  static_assert(std::is_same<decltype(std::cout << std::declval<T>()),
                             std::ostream &>::value,
                "T must support the << operator for std::ostream");

  for (int i = 0; i < 4; ++i)
    std::cout << data[i] << " ";
  std::cout << std::endl;
}

template <typename T> void node<T>::enqueue(T value) {
  data[rear] = value;
  rear = (rear + 1) % 4;
  ++sizeofNode;
}

template <typename T> T node<T>::dequeue() {
  T frontElement = data[front];
  data[front] = T();
  front = (front + 1) % 4;
  --sizeofNode;
  return frontElement;
}


template <typename T> T node<T>::frontElement() const {
  if (isEmpty()) {
    std::cerr << "Queue is empty." << std::endl;
    throw std::out_of_range("Queue is empty");
  }
  return data[front];
}

template <typename T> T node<T>::backElement() { return data[rear]; }

template <typename T> bool node<T>::isEmpty() const { return sizeofNode == 0; }

template <typename T> bool node<T>::isFull() { return sizeofNode == 4; }

template <typename T>
Subll<T>::Subll() : head(nullptr), tail(nullptr) ,size(0) {}

template <typename T>
Subll<T>::~Subll() {
    while (head) {
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

template <typename T> size_t Subll<T>::getSize() { return size; }

template <typename T> void Subll<T>::print() {
  node<T> *temp = head;
  if (size > 0) {
    while (temp) {
      temp->displayNode();
      std::cout << std::endl;
      temp = temp->next;
    }
  }
}

template <typename T> std::vector<T> Subll<T>::copyToVector() {
  std::vector<T> returnedVector;
  node<T> *temp = head;
  while (temp) {
    for (int i = 0; i < 4; ++i) {
      if ((int)temp->data[i].getId() != -1)
        returnedVector.push_back(temp->data[i]);
    }
    temp = temp->next;
  }

  return returnedVector;
}

template <typename T> bool Subll<T>::isEmpty() { return size <= 0; }

template <typename T> void Subll<T>::push(T value) {
  if (size == 0) {
    node<T> *newNode = new node<T>;
    head = tail = newNode;
    newNode->enqueue(value);
  } else {
    if (tail->sizeofNode == 4) {
      node<T> *newNode = new node<T>;
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

template <typename T> T Subll<T>::pop() {
  if (size == 0) {
    std::cout << "empty" << std::endl;
    return T(); // Default constructed T
  }

  T value = head->dequeue();

  if (head->isEmpty()) {
      node<T> *temp = head;
      head = head->next;
      if (head) {
          head->prev = nullptr;
      } else {
          tail = nullptr;
      }
      delete temp;
  }

  --size;
  return value;
}
template class Subll<Cake>;
