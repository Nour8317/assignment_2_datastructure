#include "Header.h"

template <typename T>
_queue<T>::_queue() {
    size = 0;
    front = 0;
    rear = 0;
    data = new T[maxLength];
}

template <typename T>
void _queue<T>::enqueue(T element) {
    if (isEmpty()) {
        data[0] = element;
    }
    else if (rear == maxLength) {
        maxLength *= 2;
        rear++;
        data[rear] = element;
    }
    else {
        rear++;
        data[rear] = element;
    }
    size++;
}

template <typename T>
bool _queue<T>::isEmpty() {
    return (size == 0);
}

template <typename T>
T _queue<T>::dequeue() {
    if (isEmpty()) {
        cout << "empty queue" << '\n';
        T temp;
        return temp;
    }
    else {
        T temp = data[front];
        front++;
        size--;
        if (size <= 0) front = rear = 0;
        return temp;
    }
}

template <typename T>
T _queue<T>::first() {
    if (isEmpty()) {
        cout << "empty queue" << '\n';
        T temp;
        return temp;
    }
    else {
        return data[front];
    }
}

template <typename T>
int _queue<T>::queueSize() {
    return (size);
}

template <typename T>
void _queue<T>::clear() {
    if (isEmpty()) {
        cout << "empty queue" << endl;
    }
    else {
        size = 0;
        front = 0;
        rear = 0;
        delete data;
    }
}

template <typename T>
void _queue<T>::print() {
    if (size != 0) {
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << '\n';
    }
}