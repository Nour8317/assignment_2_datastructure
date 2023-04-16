#include "Header.h"
template <typename T>
queue1<T>::queue1()
{
    size = 0;
    front = 0;
    rear = 0;
    data = new T[maxLength];
}
template <typename T>
void queue1<T>::enqueue(T element)
{
    if (isEmpty())
    {
        data[0] = element;
        size++;
    }
    else if (rear == maxLength)
    {
        maxLength *= 2;
    }
    else
    {
        rear++;
        data[rear] = element;
        size++;
    }
}
template <typename T>
bool queue1<T>::isEmpty()
{
    return (size == 0);
}
template <typename T>
T queue1<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "empty queue" << endl;
    }
    else
    {
        T temp = data[front];
        front += 1;
        size--;
        return temp;
    }
}
template <typename T>
T queue1<T>::first()
{
    if (isEmpty())
    {
        cout << "empty queue" << endl;
    }
    else
    {
        return data[front];
    }
}
template <typename T>
int queue1<T>::queueSize()
{
    return (size);
}
template <typename T>
void queue1<T>::clear()
{
    if (isEmpty())
    {
        cout << "empty queue" << endl;
    }
    else
    {
        size = 0;
        front = 0;
        rear = 0;
        delete data;
    }
}
template <typename T>
void queue1<T>::print()
{
    if (size != 0)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << data[i] << " ";
        }
    }
}