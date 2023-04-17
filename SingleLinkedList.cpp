#include "Header.h"

template <typename T>
SingleLinkedList<T>::SingleLinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename T>
void SingleLinkedList<T>::insertAtHead(T element)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = element;
    newNode->next = head;
    head = newNode;
    size++;
    if (tail == NULL)
    {
        tail = head;
    }
}

template <typename T>
void SingleLinkedList<T>::insertAtTail(T element)
{
    if (size == 0)
    {
        insertAtHead(element);
        return;
    }
    
    Node<T> *current = new Node<T>;
    current->data = element;
    tail->next = current;
    tail = current;
    size++;
}

template <typename T>
void SingleLinkedList<T>::insertAt(T element, int index)
{
    if (index == 0)
    {
        insertAtHead(element);
        return;
    }
    else if (index == size - 1)
    {
        insertAtTail(element);
        return;
    }
    else if (index < size)
    {
        int c = 0;
        Node<T> *current = head;
        Node<T> *temp = new Node<T>;
        temp->data = element;
        while (c + 1 != index)
        {
            current = current->next;
            c++;
        }
        temp->next = current->next;
        current->next = temp;
        size++;
    }
    else
    {
        cout << "Out of Range!\n";
    }
}

template <typename T>
void SingleLinkedList<T>::removeAtHead()
{
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    size--;
}

template <typename T>
void SingleLinkedList<T>::removeAtTail()
{

    Node<T> *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    size--;
}

template <typename T>
void SingleLinkedList<T>::removeAt(int index)
{
    if (index == 0)
    {
        removeAtHead();
        size--;
        return;
    }
    else if (index == size - 1)
    {
        removeAtTail();
        size--;
        return;
    }
    else if (index < size)
    {
        int c = 0;
        Node<T> *temp = head;
        while (c + 1 != index)
        {
            temp = temp->next;
            c++;
        }
        temp->next = temp->next->next;
        size--;
    }
    else
    {
        cout << "Out Of Range!\n";
    }
}
template <typename T>
T SingleLinkedList<T>::retrieveAt(int index)
{
    if (index == 0)
    {
        return head->data;
    }
    else if (index == size - 1)
    {
        return tail->data;
    }
    else
    {
        int c = 0;
        Node<T> *temp = head;
        while (c != index)
        {
            temp = temp->next;
            c++;
        }
        return temp->data;
    }
}

template <typename T>
void SingleLinkedList<T>::replaceAt(T newElement, int index)
{
    if (index == 0)
    {
        head->data = newElement;
    }
    else if (index == size - 1)
    {
        tail->data = newElement;
    }
    else
    {
        int c = 0;
        Node<T> *temp = head;
        while (c != index)
        {
            temp = temp->next;
            c++;
        }
        temp->data = newElement;
    }
}

template <typename T>
bool SingleLinkedList<T>::isExist(T element)
{
    Node<T> *temp = head;
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
bool SingleLinkedList<T>::isItemAtEqual(T element, int index)
{
    int c = 0;
    Node<T> *temp = head;
    while (c != index)
    {
        temp = temp->next;
        c++;
    }
    if (temp->data == element && c == index)
    {
        return true;
    }
    return false;
}

template <typename T>
void SingleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx)
{
    int c = 0;
    Node<T> *before1 = head;
    while (c + 1 != firstItemIdx)
    {
        before1 = before1->next;
        c++;
    }
    int c2 = 0;
    Node<T> *before2 = head;
    while (c2 + 1 != secondItemIdx)
    {
        before2 = before2->next;
        c2++;
    }
    Node<T> *node1 = before1->next;
    Node<T> *node2 = before2->next;
    Node<T> *next1 = node1->next;
    Node<T> *next2 = node2->next;
    Node<T> *nex2 = node2->next;

    before1->next = node2;
    before2->next = node1;

    node1->next = next2;
    next2 = next1;
}

template <typename T>
bool SingleLinkedList<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
int SingleLinkedList<T>::linkedListSize()
{
    return size;
}

template <typename T>
void SingleLinkedList<T>::clear()
{
    while (head != NULL)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template <typename T>
void SingleLinkedList<T>::print()
{
    if (size == 0)
    {
        cout << "Empty List!";
        return;
    }

    Node<T> *current = head;
    while (current != tail)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << tail->data;
}
