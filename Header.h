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
struct DNode{
    T data;
    DNode* previous;
    DNode* next;
};

template<typename T>
class DoubleLinkedList{
    int size = 0;
    DNode<T>* head;
    DNode<T>* tail;
public:
    DoubleLinkedList();    //constructior
    void insertAtHead(T element);   //insert element at head.
    void insertAtTail(T element);   //insert element at tail.
    void insertAt(T element, int index);   //insert element at a specific index.
    void insertAfter(DNode<T>* prev, T element);   //insert element after a specific node.  
    void removeAtHead();   //remove item at head.
    void removeAtTail();   //remove item at tail.
    void removeAt(int index);   //remove item at index.
    T retrieveAt(int index);   //retrieve item at index. 
    void replaceAt(T element, int index);  //replace item at index.
    bool isExist(T element);   //check for the existance of an item.
    bool isItemAtEqual(T element, int index);   //check for the equality of an item.
    void swap(int firstIndex, int secondIndex);  //swapping two nodes with each other.
    void reverse(); //reverse data in the linked list.
    bool isEmpty(); //check if list is empty.
    int doubleLinkedListSize(); //returns the size of the liked list.
    void clear(); //clears data.
    void forwardTraverse();  //prints from head to tail.
    void backwardTraverse();  //prints from tail to head.
    ~DoubleLinkedList(); //destructor.
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
#include"DoubleLinkedList.cpp"
#include"queue.cpp"
#endif