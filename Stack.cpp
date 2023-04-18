#include "Header.h"

template<typename T>
void Stack<T>::push(T element) {
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    if (head == NULL) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template<typename T>
T Stack<T>::pop() {
    Node<T>* temp = head;
    T val = temp->data;
    head = head->next;
    delete temp;
    size--;
    return val;
}

template<typename T>
T Stack<T>::top() {
    return head->data;
}

template<typename T>
int Stack<T>::stackSize() {
    return size;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return (size == 0);
}

template<typename T>
void Stack<T>::clear() {
    Node<T>* temp = head;
    Node<T>* current = head;
    while (temp != NULL) {
        temp = temp->next;
        delete current;
        current = temp;
    }
    head = NULL;
    size = 0;
}

template<typename T>
void Stack<T>::print() {
    if (size > 0) {
        Node<T>* current = head;
        while (current->next != NULL) {
            cout << current->data << ',';
            current = current->next;
        }
        cout << current->data << '\n';
    }
    else {
        cout << "Stack is empty!\n";
        exit(-1);
    }
}