#include "Header.h"

void FirstLinkedListProblem()
{
    DoubleLinkedList<int> Dlist;
    int sum = 0;
    int arr[8] = {0, 1, 0, 3, 0, 2, 2, 0};
    for (int i = 0; i < 8; i++)
    {
        if (arr[i] == 0 && i != 0)
        {
            Dlist.insertAtTail(sum);
            sum = 0;
        }
        else
        {
            sum += arr[i];
        }
    }
    Dlist.forwardTraverse();
}

void SecondStackProblem(string input)
{
    Stack<char> st;
    int count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        st.push(input[i]);
    }
    while (!st.isEmpty())
    {
        if (st.top() == ')')
        {
            st.pop();
            if (st.top() == '(')
            {
                count += 2;
            }
        }
        else
            st.pop();
    }
    cout << count;
}

void FirstQueueProblem(int n)
{
    _queue<string> q;
    q.enqueue("1");
    while (n--)
    {
        q.enqueue(q.first() + "0");
        q.enqueue(q.first() + "1");
        cout << q.first() << " ";
        q.dequeue();
    }
}
template <typename T>
void SecondLinkedlistProblem(SingleLinkedList<T> l1, SingleLinkedList<T> l2)
{
    int size = l1.linkedListSize() + l2.linkedListSize();

    SingleLinkedList<int> L;
    for (int i = 0; i < size; i++)
    {
        long long min = 10e9;
        for (int j = 0; j < l1.linkedListSize(); j++)
        {
            if (l1.retrieveAt(j)<min)
            {
                min = l1.retrieveAt(j);
            }
            
        }
        for (int j = 0; j < l2.linkedListSize(); j++)
        {
            if (l2.retrieveAt(j)<min)
            {
                min = l2.retrieveAt(j);
            }
            
        }
        for (int j = 0; j < l1.linkedListSize(); j++)
        {
            if (l1.retrieveAt(j)==min)
            {
                l1.removeAt(j);
                break;
            }
            
        }
        for (int j = 0; j < l2.linkedListSize(); j++)
        {
            if (l2.retrieveAt(j)==min)
            {
                l2.removeAt(j);
                break;
            }
            
        }
        
        L.insertAtTail(min);
    }
     L.print();
}
int main()
{
    //------------------Array Based List------------------//

    // ArrayList<int> arr(6);
    // cout << arr.isEmpty() << '\n';
    // arr.insert(1);
    // arr.insert(2);
    // arr.insert(3);
    // arr.insert(4);
    // arr.insert(5);
    // arr.print();
    // cout << arr.listSize() << '\n';
    // cout << arr.maxListSize() << '\n';
    // arr.insertAt(0, 3);
    // arr.print();
    // arr.removeAt(3);
    // arr.print();
    // arr.replaceAt(9, 0);
    // arr.print();
    // cout << arr.isItemAtEqual(9, 0) << ' ' << arr.isItemAtEqual(9, 1) << '\n';
    // arr.clear();
    // arr.print();

    //------------------Single Linked List------------------//

    SingleLinkedList<int> list;
    SingleLinkedList<int> list2;
    list.insertAtTail(0);
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.removeAt(0);
    list2.insertAtTail(-10);
    list2.insertAtTail(11);
    list2.insertAtTail(-12);
    list2.insertAtTail(0);
    list2.insertAtTail(0);
    list2.insertAtTail(50);
    SecondLinkedlistProblem(list, list2);
    /*cout << "before swap" << endl;
    list.print();
    cout << endl;
    list.swap(0, 5);
    cout << "after swap" << endl;
    list.print();*/

    // list.insertAtHead(5);
    // list.insertAtHead(5);
    // list.insertAtHead(5);
    // list.insertAtTail(9);
    // list.insertAtTail(9);
    // list.insertAtTail(9);
    // list.insertAt(9, 4);
    // cout << "before swap" << endl;
    // list.print();
    // cout << endl;
    // list.swap(1, 4);
    // cout << "after swap" << endl;
    // list.print();

    //------------------Double Linked List------------------//

    // DoubleLinkedList<int> Dlist;
    // cout << Dlist.isEmpty();
    // Dlist.insertAt(1, 0);
    // Dlist.insertAt(2, 1);
    // Dlist.insertAt(3, 2);
    // Dlist.insertAt(4, 3);
    // Dlist.insertAt(5, 4);
    // Dlist.clear();
    // Dlist.insertAtHead(1);
    // Dlist.insertAtHead(2);
    // Dlist.insertAtHead(3);
    // Dlist.forwardTraverse();

    //------------------Circular Linked List------------------//

    // CircularLinkedList<int> CLList;
    // CLList.insertAtEnd(0);
    // CLList.insertAtEnd(1);
    // CLList.insertAtEnd(2);
    // CLList.insertAtEnd(3);
    // CLList.insertAtEnd(4);
    // CLList.insertAtEnd(5);
    // CLList.insertAtEnd(6);
    // CLList.print();
    // CLList.swap(3, 5);
    // CLList.print();
    // CLList.insertAtHead(-9);
    // CLList.insertAt(-9, 5);
    // CLList.print();
    // CLList.removeAt(5);
    // CLList.removeAtHead();
    // CLList.print();
    // CLList.replaceAt(99, 3);
    // CLList.print();
    // cout << CLList.retrieveAt(3) << '\n';
    // cout << CLList.isExist(99) << '\n';
    // cout << CLList.isItemAtEqual(99, 0) << '\n';
    // cout << CLList.circularLinkedListSize() << '\n';
    // CLList.clear();
    // cout << CLList.isEmpty() << '\n';
    // cout << CLList.circularLinkedListSize() << '\n';
    // CLList.print();

    //------------------Queue------------------//

    // _queue<int> q;
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // q.dequeue();
    // cout <<"first= "<< q.first() << endl;
    // cout <<"size= "<<q.queueSize() << endl;
    // q.clear();
    // cout << q.isEmpty() << endl;
    // cout <<"size= "<<q.queueSize() << endl;
    // q.print();

    //------------------Stack------------------//
    // Stack<int> St;
    // St.push(5);
    // St.push(6);
    // St.push(7);
    // St.print();
    // St.clear();
    // cout << St.isEmpty() << " " << St.stackSize() << endl;
    // St.push(1);
    // St.push(2);
    // cout << St.top() << endl;
    // St.push(3);
    // St.print();
    // cout << St.stackSize() << endl;

    //------------------Problems------------------//

    // FirstQueueProblem(5);
}