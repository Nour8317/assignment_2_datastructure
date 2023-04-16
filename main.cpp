#include"Header.h"

int main(){
    //------------------Single Linked List------------------//
    SingleLinkedList<int> list;
    
    list.insertAtTail(0);
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    //list.insertAt(9, 4);
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
    DoubleLinkedList<int> Dlist;

    Dlist.insertAt(1,0);
    Dlist.insertAt(2,1);
    Dlist.insertAt(3,2);
    Dlist.insertAtTail(5);
    Dlist.insertAt(4,3);
    Dlist.insertAt(6,1);
    cout << Dlist.isItemAtEqual(5,-1);
    cout << endl;
    Dlist.forwardTraverse();

    //------------------Circular Linked List------------------//

}