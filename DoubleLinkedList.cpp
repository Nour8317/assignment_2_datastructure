#include "Header.h"


template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template<typename T>
void DoubleLinkedList<T>::insertAtHead(T element){
    DNode<T>* newNode = new DNode<T>;
    newNode->data = element;
    newNode->next = NULL;
    newNode->previous = NULL;
    if (head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template<typename T>
void DoubleLinkedList<T>::insertAtTail(T element){
    DNode<T>* newNode = new DNode<T>;
    newNode->data = element;
    newNode->next = NULL;
    newNode->previous = NULL;
    if (head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    size++;
}

template<typename T> 
void DoubleLinkedList<T>::insertAt(T element,int index){
    if (index > size || index < 0){
        cout << "Index Not Found!\n";
        exit(-1);
    }
    else{
        if (index == 0){
            insertAtHead(element);
        }
        else if (index == size){
            insertAtTail(element);
        }
        else{
            DNode<T>* newNode = new DNode<T>;
            newNode->next = NULL;
            newNode->previous = NULL;
            newNode->data = element;
            DNode<T>* current = head;
            DNode<T>* tailCurrent;
            while(index != 0){
                tailCurrent = current;
                current = current->next;
                index--;
            }
            tailCurrent->next = newNode;
            newNode->previous = tailCurrent;
            current->previous = newNode;
            newNode->next = current;

            size++;
        }
    }
}

template<typename T>
void DoubleLinkedList<T>::forwardTraverse(){
    DNode<T>* current = head;
    cout  << '[';
    while (current->next != NULL){
        cout << current->data << ',';
        current = current->next;
    }
    cout << current->data <<  ']' << endl;
}

template<typename T>
void DoubleLinkedList<T>::insertAfter(DNode<T>* prev, T element){
    DNode<T>* newNode = new DNode<T>;
    newNode->data = element;
    newNode->previous = NULL;
    newNode->next = NULL;
    if (prev->next == NULL && prev != NULL){
        prev->next = newNode;
        newNode->previous = prev;
        tail = newNode;
        size++;
    }
    else if (prev == NULL){
        cout << "Cannot Initialize Node!";
        exit(-1);
    }
    else{
        DNode<T>* nxt = prev->next;
        nxt->previous = newNode;
        prev->next = newNode;
        newNode->next = nxt;
        newNode->previous = prev;
        size++;
    }
}

template<typename T>
void DoubleLinkedList<T>::removeAtHead(){
    DNode<T>* temp = head;
    head = head->next;
    head->previous = NULL;
    delete temp;
    size--;
}

template<typename T>
void DoubleLinkedList<T>::removeAtTail(){
    DNode<T>* temp = tail;
    tail = tail->previous;
    tail->next = NULL;
    delete temp;
    size--;
}

template<typename T>
void DoubleLinkedList<T>::removeAt(int index){
    if (index > size - 1 || index < 0){
        cout << "Index Not Found!\n";
        exit(-1);
    }
    else {
        if (index == 0) {
            removeAtHead();
        }
        else if (index == size - 1) {
            removeAtTail();
        }
        else {
            DNode<T>* current = head; 
            while (index--) {
                current = current->next;
            }
            current->next->previous = current->previous;
            current->previous->next = current->next;
            delete current;
            size--;
        }
    }
}

template<typename T>
T DoubleLinkedList<T>::retrieveAt(int index) {
    if (index > size - 1 || index < 0){
        cout << "Index Not Found!\n";
        exit(-1);
    }
    else {
        DNode<T>* current = head;
        while(index--) {
            current = current->next;
        }
        return current->data;
    }
}

template<typename T>
void DoubleLinkedList<T>::replaceAt(T element,int index) {
    if (index > size - 1 || index < 0){
        cout << "Index Not Found!\n";
        exit(-1);
    }
    else {
        DNode<T>* current = head;
        while(index--) {
            current = current->next;
        }
        current->data = element;
    }
}

template<typename T>
bool DoubleLinkedList<T>::isExist(T element) {
    DNode<T>* current = head;
    while (current != NULL) {
        if (current->data == element) return true;
        current = current->next;
    }
    return false;
}

template<typename T>
bool DoubleLinkedList<T>::isItemAtEqual(T element,int index){
    if (index > size - 1 || index < 0){
        cout << "Index Not Found!\n";
        exit(-1);
    }
    else {
        DNode<T>* current = head;
        while (index--) {
            current = current->next;
        }
        if (current->data == element) return true;
        else return false;
    }
}

template<typename T>
void DoubleLinkedList<T>::swap(int firstIndex, int secondIndex) {
    if (firstIndex > size - 1 || firstIndex < 0 || secondIndex > size - 1 || secondIndex < 0){
        cout << "Index Not Found!\n";
        exit(-1);
    }
    if (firstIndex > secondIndex) {
        if (firstIndex = secondIndex + 1) { // adjacent.
            if (secondIndex == 0){  //swap with head.

            }
            else if (firstIndex == size - 1) {  //swap with tail.

            }
            else {

            }
        }
        else {  //non adjacent.
            if (secondIndex == 0 && firstIndex == size - 1){  //swap head with tail.

            }
            else if (firstIndex == size - 1) {  //swap with tail.

            }
            else if (secondIndex == 0) {  //swap head with tail.

            }
        }
    }
    else if (secondIndex > firstIndex) {
        if (secondIndex = firstIndex + 1) { //adjacent
            if (firstIndex == 0){  //swap with head.

            }
            else if (secondIndex == size - 1) {  //swap with tail.
                
            }
            else {

            }
        }
        else {

        }
    }
}

template<typename T>
int DoubleLinkedList<T>::doubleLinkedListSize(){
    return size;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){

}