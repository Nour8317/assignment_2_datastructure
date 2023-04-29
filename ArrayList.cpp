#include"Header.h"

template<typename T>
ArrayList<T>::ArrayList(int cap) {
    capacity = cap;
    array = new T[capacity];
}

template<typename T>
void ArrayList<T>::insert(T element) {
    if (isFull()) return void(cout << "Array Full!\n");

    array[size++] = element;
}

template<typename T>
void ArrayList<T>::insertAt(T element, int index) {
    if (index < 0 || index > size) return void(cout << "Out of Range!\n");
    if (isFull()) return void(cout << "Array Full!\n");

    size++;
    for (int i = size - 1; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = element;
}

template<typename T>
T ArrayList<T>::retrieveAt(int index) {
    if (index < 0 || index >= size) {
        cout << "Out of Range!\n";
        return T(NULL);
    }

    return array[index];
}

template<typename T>
void ArrayList<T>::removeAt(int index) {
    if (index < 0 || index >= size) return void(cout << "Out of Range!\n");

    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
}

template<typename T>
void ArrayList<T>::replaceAt(T newElement, int index) {
    if (index < 0 || index >= size) return void(cout << "Out of Range!\n");

    array[index] = newElement;
}

template<typename T>
bool ArrayList<T>::isItemAtEqual(T element, int index) {
    if (index < 0 || index >= size) return false;

    return array[index] == element;
}

template<typename T>
bool ArrayList<T>::isEmpty() {
    return !size;
}

template<typename T>
bool ArrayList<T>::isFull() {
    return size == capacity;
}

template<typename T>
int ArrayList<T>::listSize() {
    return size;
}

template<typename T>
int ArrayList<T>::maxListSize() {
    return capacity;
}

template<typename T>
void ArrayList<T>::clear() {
    size = 0;
}

template<typename T>
void ArrayList<T>::print() {
    if (isEmpty()) return void(cout << "Empty Array!\n");

    for (int i = 0; i < size - 1; i++) {
        cout << array[i] << ' ';
    }
    cout << array[size - 1] << '\n';
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] array;
}