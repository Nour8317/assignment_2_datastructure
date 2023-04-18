#include "Header.h"
template <typename T>
<<<<<<< Updated upstream
queue1<T>::queue1() {
=======
_queue<T>::_queue()
{
>>>>>>> Stashed changes
    size = 0;
    front = 0;
    rear = 0;
    data = new T[maxLength];
}
template <typename T>
<<<<<<< Updated upstream
void queue1<T>::enqueue(T element) {
    if (isEmpty()) {
=======
void _queue<T>::enqueue(T element)
{
    if (isEmpty())
    {
>>>>>>> Stashed changes
        data[0] = element;
        size++;
    }
    else if (rear == maxLength) {
        maxLength *= 2;
    }
    else {
        rear++;
        data[rear] = element;
        size++;
    }
}
template <typename T>
<<<<<<< Updated upstream
bool queue1<T>::isEmpty() {
    return (size == 0);
}
template <typename T>
T queue1<T>::dequeue() {
    if (isEmpty()) {
=======
bool _queue<T>::isEmpty()
{
    return (size == 0);
}
template <typename T>
T _queue<T>::dequeue()
{
    if (isEmpty())
    {
>>>>>>> Stashed changes
        cout << "empty queue" << endl;
        T temp;
        return temp;
    }
    else {
        T temp = data[front];
        front += 1;
        size--;
        return temp;
    }
}
template <typename T>
<<<<<<< Updated upstream
T queue1<T>::first() {
    if (isEmpty()) {
=======
T _queue<T>::first()
{
    if (isEmpty())
    {
>>>>>>> Stashed changes
        cout << "empty queue" << endl;
        T temp;
        return temp;
    }
    else {
        return data[front];
    }
}
template <typename T>
<<<<<<< Updated upstream
int queue1<T>::queueSize() {
    return (size);
}
template <typename T>
void queue1<T>::clear() {
    if (isEmpty()) {
=======
int _queue<T>::queueSize()
{
    return (size);
}
template <typename T>
void _queue<T>::clear()
{
    if (isEmpty())
    {
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
void queue1<T>::print() {
    if (size != 0) {
        for (int i = front; i <= rear; i++) {
=======
void _queue<T>::print()
{
    if (size != 0)
    {
        for (int i = front; i <= rear; i++)
        {
>>>>>>> Stashed changes
            cout << data[i] << " ";
        }
    }
}