#include"Header.h"

int main() {
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
    list.insertAtTail(0);
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.removeAt(0);
    /*cout << "before swap" << endl;
    list.print();
    cout << endl;
    list.swap(1, 4);
    cout << "after swap" << endl;*/
    //list.print();

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


    //------------------Queue------------------//

    _queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    cout <<"first= "<< q.first() << endl;
    cout <<"size= "<<q.queueSize() << endl;
    q.clear();
    cout << q.isEmpty() << endl;
    cout <<"size= "<<q.queueSize() << endl;
    q.print();


    //------------------Stack------------------//
    Stack<int> St;
    St.push(5);
    St.push(6);
    St.push(7);
    St.print();
    St.clear();
    cout << St.isEmpty() << " " << St.stackSize() << endl;
    St.push(1);
    St.push(2);
    cout << St.top() << endl;
    St.push(3);
    St.print();
    cout << St.stackSize() << endl;
    
}