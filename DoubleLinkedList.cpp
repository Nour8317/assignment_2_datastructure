#include "Header.h"


template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template<typename T>
void DoubleLinkedList<T>::insertAtHead(T element){
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    newNode->next = NULL;
    newNode->previous = NULL;
    if (head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    size++;
}

template<typename T>
void DoubleLinkedList<T>::insertAtTail(T element){
    Node<T>* newNode = new Node<T>;
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
            Node<T>* newNode = new Node<T>;
            newNode->next = NULL;
            newNode->previous = NULL;
            newNode->data = element;
            Node<T>* current = head;
            Node<T>* tailCurrent;
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
    Node<T>* current = head;
    if (size >= 1) {
        cout  << '[';
        while (current->next != NULL){
            cout << current->data << ',';
            current = current->next;
        }
        cout << current->data <<  "]\n";
    }
    else {
        cout << "list is Empty!\n";
        exit(-1);
    }
}

template<typename T>
void DoubleLinkedList<T>::backwardTraverse() {
    Node<T>* current = tail;
    if (size >= 1) {
        cout << '[';
        while (current->previous != NULL) {
            cout << current->data << ',';
            current = current->previous;
        }
        cout << current->data << "]\n";
    }
    else {
        cout << "list is Empty!\n";
        exit(-1);
    }
}

template<typename T>
void DoubleLinkedList<T>::insertAfter(Node<T>* prev, T element){
    Node<T>* newNode = new Node<T>;
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
        Node<T>* nxt = prev->next;
        nxt->previous = newNode;
        prev->next = newNode;
        newNode->next = nxt;
        newNode->previous = prev;
        size++;
    }
}

template<typename T>
void DoubleLinkedList<T>::removeAtHead(){
    Node<T>* temp = head;
    head = head->next;
    head->previous = NULL;
    delete temp;
    size--;
}

template<typename T>
void DoubleLinkedList<T>::removeAtTail(){
    Node<T>* temp = tail;
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
            Node<T>* current = head; 
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
        Node<T>* current = head;
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
        Node<T>* current = head;
        while(index--) {
            current = current->next;
        }
        current->data = element;
    }
}

template<typename T>
bool DoubleLinkedList<T>::isExist(T element) {
    Node<T>* current = head;
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
        Node<T>* current = head;
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
    else {
        int temp1 = firstIndex;
        int temp2 = secondIndex;
        Node<T>* FNode = head;
        Node<T>* SNode = head;
        while (temp1--) {
            FNode = FNode->next;
        }
        while (temp2--) {
            SNode = SNode->next;
        }
        if (firstIndex > secondIndex) {
            if (firstIndex == secondIndex + 1) { // adjacent.
                if (secondIndex == 0 && firstIndex == size - 1) { //swapping head with tail.
                    SNode->next = NULL;
                    SNode->previous = FNode;
                    FNode->previous = NULL;
                    FNode->next = SNode;
                    head = FNode;
                    tail = SNode;
                }
                else if (secondIndex == 0){  //swap with head.
                    Node<T>* temp = FNode->next;
                    FNode->previous = NULL;
                    SNode->next = temp;
                    temp->previous = SNode;
                    FNode->next = SNode;
                    SNode->previous = FNode;
                    head = FNode;
                }
                else if (firstIndex == size - 1) {  //swap with tail.
                    Node<T>* temp = SNode->previous;
                    temp->next = FNode;
                    FNode->previous = temp;
                    SNode->next = NULL;
                    SNode->previous = FNode;
                    FNode->next = SNode;
                    tail = SNode;
                }
                else { //general case.
                    Node<T>* tempS = SNode->previous;
                    Node<T>* tempF = FNode->next;
                    tempS->next = FNode;
                    tempF->previous = SNode;
                    SNode->next = tempF;
                    FNode->previous = tempS;
                    FNode->next = SNode;
                    SNode->previous = FNode;
                }
            }
            else {  //non adjacent.
                if (secondIndex == 0 && firstIndex == size - 1){  //swap head with tail.
                    Node<T>* tempF = FNode->previous;
                    Node<T>* tempS = SNode->next;
                    tempF->next = SNode;
                    tempS->previous = FNode;
                    SNode->next = NULL;
                    FNode->previous = NULL;
                    SNode->previous = tempF;
                    FNode->next = tempS;
                    head = FNode;
                    tail = SNode;
                }
                else if (firstIndex == size - 1) {  //swap with tail.
                    Node<T>* tempF = FNode->previous;
                    Node<T>* tempS = SNode->next;
                    Node<T>* tempFP = SNode->previous;
                    tempF->next = SNode;
                    tempS->previous = FNode;
                    SNode->next = NULL;
                    FNode->previous = tempFP;
                    tempFP->next = FNode;
                    SNode->previous = tempF;
                    FNode->next = tempS;
                    tail = SNode;
                }
                else if (secondIndex == 0) {  //swap head with tail.
                    Node<T>* tempF = FNode->previous;
                    Node<T>* tempS = SNode->next;
                    Node<T>* tempSP = FNode->next;
                    tempF->next = SNode;
                    tempS->previous = FNode;
                    SNode->next = tempSP;
                    tempSP->previous = SNode;
                    FNode->previous = NULL;
                    SNode->previous = tempF;
                    FNode->next = tempS;
                    head = FNode;
                }
                else {  //general case.
                    Node<T>* tempF = FNode->previous;
                    Node<T>* tempS = SNode->next;
                    Node<T>* tempFN = FNode->next;
                    Node<T>* tempSP = SNode->previous;
                    tempF->next = SNode;
                    tempS->previous = FNode;
                    SNode->next = tempFN;
                    FNode->previous = tempSP;
                    tempFN->previous = SNode;
                    tempSP->next = FNode;
                    SNode->previous = tempF;
                    FNode->next = tempS;
                }
            }
        }
        else if (secondIndex > firstIndex) {
            if (secondIndex == firstIndex + 1) { //adjacent
                if (firstIndex == 0 && secondIndex == size - 1){
                    FNode->next = NULL;
                    FNode->previous = SNode;
                    SNode->previous = NULL;
                    SNode->next = FNode;
                    head = SNode;
                    tail = FNode;
                }
                else if (firstIndex == 0){  //swap with head.
                    Node<T>* temp = SNode->next;
                    SNode->previous = NULL;
                    FNode->next = temp;
                    temp->previous = FNode;
                    SNode->next = FNode;
                    FNode->previous = SNode;
                    head = SNode;
                }
                else if (secondIndex == size - 1) {  //swap with tail.
                    Node<T>* temp = FNode->previous;
                    temp->next = SNode;
                    SNode->previous = temp;
                    FNode->next = NULL;
                    FNode->previous = SNode;
                    SNode->next = FNode;
                    tail = FNode;
                }
                else {  //general case.
                    Node<T>* tempS = FNode->previous;
                    Node<T>* tempF = SNode->next;
                    tempS->next = SNode;
                    tempF->previous = FNode;
                    FNode->next = tempF;
                    SNode->previous = tempS;
                    SNode->next = FNode;
                    FNode->previous = SNode;
                }
            }
            else { //non adjacent.
                if (firstIndex == 0 && secondIndex == size - 1) {  //swap head with tail.
                    Node<T>* tempF = SNode->previous;
                    Node<T>* tempS = FNode->next;
                    tempF->next = FNode;
                    tempS->previous = SNode;
                    FNode->next = NULL;
                    SNode->previous = NULL;
                    FNode->previous = tempF;
                    SNode->next = tempS;
                    head = SNode;
                    tail = FNode;
                }
                else if (secondIndex == size - 1) {  //swap with tail.
                    Node<T>* tempF = SNode->previous;
                    Node<T>* tempS = FNode->next;
                    Node<T>* tempFP = FNode->previous;
                    tempF->next = FNode;
                    tempS->previous = SNode;
                    FNode->next = NULL;
                    SNode->previous = tempFP;
                    tempFP->next = SNode;
                    FNode->previous = tempF;
                    SNode->next = tempS;
                    tail = FNode;
                }
                else if (firstIndex == 0){  //swap with head.
                    Node<T>* tempF = SNode->previous;
                    Node<T>* tempS = FNode->next;
                    Node<T>* tempSP = SNode->next;
                    tempF->next = FNode;
                    tempS->previous = SNode;
                    FNode->next = tempSP;
                    tempSP->previous = FNode;
                    SNode->previous = NULL;
                    FNode->previous = tempF;
                    SNode->next = tempS;
                    head = SNode;
                }
                else {  //general case.
                    Node<T>* tempF = SNode->previous;
                    Node<T>* tempS = FNode->next;
                    Node<T>* tempFN = SNode->next;
                    Node<T>* tempSP = FNode->previous;
                    tempF->next = FNode;
                    tempS->previous = SNode;
                    FNode->next = tempFN;
                    SNode->previous = tempSP;
                    tempFN->previous = FNode;
                    tempSP->next = SNode;
                    FNode->previous = tempF;
                    SNode->next = tempS;
                }
            }
        }
    }
}

template<typename T>
void DoubleLinkedList<T>::reverse() {
    Node<T>* current = head;
    Node<T>* temp;
    Node<T>* swapTemp;
    while (current != NULL) {
        temp = current->next;
        swapTemp = current->next;
        current->next = current->previous;
        current->previous = swapTemp;
        current = temp;
    }
    swapTemp = head;
    head = tail;
    tail = swapTemp;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() {
    return (size == 0);
}

template<typename T>
void DoubleLinkedList<T>::clear() {
    Node<T>*  current = head;
    Node<T>* temp = current;
    while (temp != NULL) {
        temp = current->next;
        delete current;
        current = temp;
    }
    size = 0;
    head = NULL;
    tail = NULL;
    delete temp;
}


template<typename T>
int DoubleLinkedList<T>::doubleLinkedListSize(){
    return size;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){

}