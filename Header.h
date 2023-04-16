#ifndef Header_h
#define Header_h

#include<iostream>
using namespace std;

template<typename T>
struct Node{
    Node *next = NULL;
    T value;
};

template<typename T>
class SingleLinkedList{
    private:
    Node<T>* head;
    Node<T>* tail;
    int size;
    public:
    SingleLinkedList();
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T element, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T newElement, int index);
    bool isExist(T element);
    bool isItemAtEqual(T element, int index);
    void swap(int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print();
};
template<typename T>
class queue1{
private:
    int front, rear, size, maxLength = 100;
    int* data;
public:
    queue1();
    void enqueue(T element);
    T dequeue();
    T first(); // return the first element without removing it.
    bool isEmpty();
    int queueSize();
    void clear();
    void print();
};
#include"SingleLinkedList.cpp"
#include"queue.cpp"
#endif