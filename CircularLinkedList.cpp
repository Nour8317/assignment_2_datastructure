#include"Header.h"

template<typename T>
CircularLinkedList<T>::CircularLinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<typename T>
void CircularLinkedList<T>::insertAtHead(T element) {
    Node<T>* temp = new Node<T>;
    temp->data = element;
    if (size == 0) {
        head = temp;
        tail = head;
    }
    else {
        temp->next = head;
        head = temp;
    }
    tail->next = head;
    size++;
}

template<typename T>
void CircularLinkedList<T>::insertAtEnd(T element) {
    if (size == 0) return insertAtHead(element);

    Node<T>* temp = new Node<T>;
    temp->data = element;
    
    tail->next = temp;
    tail = temp;
    tail->next = head;
    size++;
}

template<typename T>
void CircularLinkedList<T>::insertAt(T element, int index) {
    if (index < 0 || index > size) return void(cout << "Out of Range!\n");
    if (index == 0) return insertAtHead(element);
    if (index == size) return insertAtEnd(element);

    Node<T>* temp = new Node<T>;
    temp->data = element;

    Node<T>* current = head;
    while (index-- > 1) {
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;
    size++;
}

template<typename T>
void CircularLinkedList<T>::removeAtHead() {
    Node<T>* temp = head;
    head = head->next;
    tail->next = head;
    delete temp;
    size--;
}

template<typename T>
void CircularLinkedList<T>::removeAtEnd() {
    Node<T>* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = head;
    size--;
}

template<typename T>
void CircularLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= size) return void(cout << "Out of Range!\n");
    if (index == 0) return removeAtHead();
    if (index == size - 1) return removeAtEnd();


    Node<T>* current = head;
    while (index-- > 1) {
        current = current->next;
    }

    Node<T>* temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
}

template<typename T>
void CircularLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx < 0 || firstItemIdx > size - 1) return void(cout << "Out of Range!\n");
    if (secondItemIdx < 0 || secondItemIdx > size - 1) return void(cout << "Out of Range!\n");
    if (firstItemIdx == secondItemIdx) return;
    
    int temp1 = firstItemIdx;
    int temp2 = secondItemIdx;
    
    Node<T>* current = head;
    while (temp1-- > 1) {
        current = current->next;
    }
    Node<T>* firstPrev = firstItemIdx == 0 ? tail : current;
    Node<T>* firstItem = firstPrev->next;
    Node<T>* firstNext = firstItem->next;
    
    current = head;
    while (temp2-- > 1) {
        current = current->next;
    }
    Node<T>* secondPrev = secondItemIdx == 0 ? tail : current;
    Node<T>* secondItem = secondPrev->next;
    Node<T>* secondNext = secondItem->next;
        
    if (firstNext == secondItem) {
        secondItem->next = firstItem;
        firstItem->next = secondNext;
        firstPrev->next = secondItem;
    }
    else if (secondNext == firstItem) {
        firstItem->next = secondItem;
        secondItem->next = firstNext;
        secondPrev->next = firstItem;
    }
    else {
        firstPrev->next = secondItem;
        secondPrev->next = firstItem;
        firstItem->next = secondNext;
        secondItem->next = firstNext;
    }

    if (firstItemIdx == 0) {
        head = secondItem;
    }
    if (secondItemIdx == 0) {
        head = firstItem;
    }
    if (secondItemIdx == size - 1) {
        tail = firstItem;
    }
    if (firstItemIdx == size - 1) {
        tail = secondItem;
    }

    tail->next = head;
}

template<typename T>
T CircularLinkedList<T>::retrieveAt(int index) {
    if (index < 0 || index >= size) {
        cout << "Out of Range!\n";
        return T(NULL);
    }

    Node<T>* current = head;
    while (index--) {
        current = current->next;
    }

    return current->data;
}

template<typename T>
void CircularLinkedList<T>::replaceAt(T newElement, int index) {
    if (index < 0 || index >= size) return void(cout << "Out of Range!\n");

    Node<T>* current = head;
    while (index--) {
        current = current->next;
    }

    current->data = newElement;
}

template<typename T>
bool CircularLinkedList<T>::isExist(T element) {
    if (tail->data == element) return true;

    Node<T>* current = head;
    while (current != tail) {
        if (current->data == element) return true;

        current = current->next;
    }

    return false;
}

template<typename T>
bool CircularLinkedList<T>::isItemAtEqual(T element, int index) {
    if (index < 0 || index >= size) {
        cout << "Out of Range!\n";
        return false;
    }
    
    Node<T>* current = head;
    while (index--) {
        current = current->next;
    }
    
    if (current->data == element)
        return true;
    else
        return false;
}

template<typename T>
bool CircularLinkedList<T>::isEmpty() {
    return !size;
}

template<typename T>
int CircularLinkedList<T>::circularLinkedListSize() {
    return size;
}

template<typename T>
void CircularLinkedList<T>::clear() {
    Node<T>* temp;
    while (head != tail) {
        temp = head;
        head = head->next;
        delete temp;
    }
    delete tail;

    head = tail = NULL;
    size = 0;
}

template<typename T>
void CircularLinkedList<T>::print() {
    if (isEmpty()) return void(cout << "Empty List!\n");
    
    Node<T>* current = head;
    while (current != tail) {
        cout << current->data << ' ';
        current = current->next;
    }
    cout << tail->data << '\n';
}

template<typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    this->clear();
}