#include"Header.h"

int main(){
    /*SingleLinkedList<int> list;
    list.insertAtTail(0);
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.removeAt(0);
    list.removeAt(0);
    list.removeAt(0);
    list.removeAt(0);
    list.removeAt(0);
    list.removeAt(0);
    list.removeAt(0);
    list.print();*/
    queue1<int> q;
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
}