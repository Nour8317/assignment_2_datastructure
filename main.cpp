#include"Header.h"

int main(){
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
    list.print();
}