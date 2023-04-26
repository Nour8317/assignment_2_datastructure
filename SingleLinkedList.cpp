#include "Header.h"

template <typename T>
SingleLinkedList<T>::SingleLinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename T>
void SingleLinkedList<T>::insertAtHead(T element) {
    Node<T>* newNode = new Node<T>;
    newNode->data = element;
    newNode->next = head;
    head = newNode;
    size++;
    if (tail == NULL) {
        tail = head;
    }
}

template <typename T>
void SingleLinkedList<T>::insertAtTail(T element) {
    if (size == 0) {
        insertAtHead(element);
        return;
    }

    Node<T>* current = new Node<T>;
    current->data = element;
    tail->next = current;
    tail = current;
    size++;
}

template <typename T>
void SingleLinkedList<T>::insertAt(T element, int index) {
    if (index == 0) {
        insertAtHead(element);
        return;
    }
    else if (index == size - 1) {
        insertAtTail(element);
        return;
    }
    else if (index < size) {
        int c = 0;
        Node<T>* current = head;
        Node<T>* temp = new Node<T>;
        temp->data = element;
        while (c + 1 != index) {
            current = current->next;
            c++;
        }
        temp->next = current->next;
        current->next = temp;
        size++;
    }
    else {
        cout << "Out of Range!\n";
    }
}

template <typename T>
void SingleLinkedList<T>::removeAtHead() {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template <typename T>
void SingleLinkedList<T>::removeAtTail() {

    Node<T>* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    size--;
}

template <typename T>
void SingleLinkedList<T>::removeAt(int index) {
    if (index == 0) {
        removeAtHead();
        return;
    }
    else if (index == size - 1) {
        removeAtTail();
        return;
    }
    else if (index < size) {
        int c = 0;
        Node<T>* temp = head;
        while (c + 1 != index) {
            temp = temp->next;
            c++;
        }
        temp->next = temp->next->next;
        size--;
    }
    else {
        cout << "Out Of Range!\n";
    }
}
template <typename T>
T SingleLinkedList<T>::retrieveAt(int index) {
    if (index == 0) {
        return head->data;
    }
    else if (index == size - 1) {
        return tail->data;
    }
    else {
        int c = 0;
        Node<T>* temp = head;
        while (c != index) {
            temp = temp->next;
            c++;
        }
        return temp->data;
    }
}

template <typename T>
void SingleLinkedList<T>::replaceAt(T newElement, int index) {
    if (index == 0) {
        head->data = newElement;
    }
    else if (index == size - 1) {
        tail->data = newElement;
    }
    else {
        int c = 0;
        Node<T>* temp = head;
        while (c != index) {
            temp = temp->next;
            c++;
        }
        temp->data = newElement;
    }
}

template <typename T>
bool SingleLinkedList<T>::isExist(T element) {
    Node<T>* temp = head;
    while (temp != NULL) {
        if (temp->data == element) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
bool SingleLinkedList<T>::isItemAtEqual(T element, int index) {
    int c = 0;
    Node<T>* temp = head;
    while (c != index) {
        temp = temp->next;
        c++;
    }
    if (temp->data == element && c == index) {
        return true;
    }
    return false;
}

template<typename T>
void SingleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    int c = 0;
    if (firstItemIdx == secondItemIdx) {
        return; 
    }
    Node<T> *prev1 = nullptr, *cur1 = head;
    while (c + 1 != firstItemIdx)  {
        prev1 = cur1;
        cur1 = cur1->next;
        c++;
    }
    Node<T> *prev2 = nullptr, *cur2 = head;
    for (int i = 0; cur2 && i < secondItemIdx; i++) {
        prev2 = cur2;
        cur2 = cur2->next;
    }
    if (!cur1 || !cur2) {
        return;
    }
    if (!prev1) {
        head = cur2;
    } else {
        prev1->next = cur2;
    }
    if (!prev2) {
        head = cur1;
    } else {
        prev2->next = cur1;
    }
    Node<T> *temp = cur1->next;
    cur1->next = cur2->next;
    cur2->next = temp;
}

template <typename T>
bool SingleLinkedList<T>::isEmpty() {
    return size == 0;
}

template <typename T>
int SingleLinkedList<T>::linkedListSize() {
    return size;
}

template <typename T>
void SingleLinkedList<T>::clear() {
    while (head != NULL) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template <typename T>
void SingleLinkedList<T>::print() {
    if (size == 0) {
        cout << "Empty List!";
        return;
    }

    Node<T>* current = head;
    while (current != tail) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << tail->data;
}
