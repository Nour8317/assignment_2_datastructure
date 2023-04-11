#include"Header.h"

int main(){
    SingleLinkedList<int> list;
    
    list.insertAtHead(5);
    list.insertAtHead(5);
    list.insertAtHead(5);
    list.insertAtTail(9);
    list.insertAtTail(9);
    list.insertAtTail(9);
    list.insertAt(9, 4);
    cout << "before swap" << endl;
    list.print();
    cout << endl;
    list.swap(1, 4);
    cout << "after swap" << endl;
    list.print();
}