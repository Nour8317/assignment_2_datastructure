#include "Header.h"

// FirstLinkedListProblem
void FirstLinkedListProblem() {
    DoubleLinkedList<int> Dlist;
    int sum = 0;
    int arr[8] = { 0, 1, 0, 3, 0, 2, 2, 0 };
    for (int i = 0; i < 8; i++) {
        if (arr[i] == 0 && i != 0) {
            Dlist.insertAtTail(sum);
            sum = 0;
        }
        else {
            sum += arr[i];
        }
    }
    Dlist.forwardTraverse();
}

// SecondLinkedListProblem
void SecondLinkedlistProblem(vector<SingleLinkedList<int>> lists) {
    int size = lists.size();
    SingleLinkedList<int> l1;
    SingleLinkedList<int> l2;
    SingleLinkedList<int> ans;

    for (int i = 0; i < size; i++) {
        if (i <= size / 2) {
            for (int j = 0; j < lists[i].linkedListSize(); j++) {
                l1.insertAtTail(lists[i].retrieveAt(j));
            }
        }

        else {
            for (int j = 0; j < lists[i].linkedListSize(); j++) {
                l2.insertAtTail(lists[i].retrieveAt(j));
            }
        }
    }

    int lsize = l1.linkedListSize() + l2.linkedListSize();

    for (int i = 0; i < lsize; i++) {
        int mine = INT_MAX;
        for (int j = 0; j < l1.linkedListSize(); j++) {
            mine = min(l1.retrieveAt(j), mine);
        }

        for (int j = 0; j < l2.linkedListSize(); j++) {
            mine = min(l2.retrieveAt(j), mine);
        }
        bool deleted = false;
        for (int j = 0; j < l1.linkedListSize(); j++) {
            if (l1.retrieveAt(j) == mine) {
                l1.removeAt(j);
                deleted = true;
                break;
            }
        }
        if (!deleted) {
            for (int j = 0; j < l2.linkedListSize(); j++) {
                if (l2.retrieveAt(j) == mine) {
                    l2.removeAt(j);
                    break;
                }
            }
        }
        ans.insertAtTail(mine);
    }
    ans.print();
}

// FirstStackProblem
int GetPriority(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;

    return 0;
}
string FirstStackProblem(string input) {
    string postfix = "";
    Stack<char> operators;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ' ') continue;

        if (!isalpha(input[i]) && !isdigit(input[i])) {
            if (input[i] == '(') {
                operators.push(input[i]);
            }
            else if (input[i] == ')') {
                while (operators.top() != '(') {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.pop();
            }
            else {
                while (!operators.isEmpty() && GetPriority(input[i]) <= GetPriority(operators.top())) {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(input[i]);
            }
        }
        else {
            postfix += input[i];
        }

    }
    return postfix;
}

// SecondStackProblem
void SecondStackProblem(string input) {
    Stack<char> st;
    int count = 0;
    for (int i = 0; i < input.size(); i++) {
        st.push(input[i]);
    }
    while (!st.isEmpty()) {
        if (st.top() == ')') {
            st.pop();
            if (st.top() == '(') {
                count += 2;
            }
        }
        else
            st.pop();
    }
    cout << count;
}

// FirstQueueProblem
void FirstQueueProblem(int n) {
    _queue<string> q;
    q.enqueue("1");
    while (n--) {
        q.enqueue(q.first() + "0");
        q.enqueue(q.first() + "1");
        cout << q.first() << " ";
        q.dequeue();
    }
}

// SecondQueueProblem
template <typename T>
class stack {
private:
    int sz;
    _queue<T> q;

public:
    void push(T val) {
        q.enqueue(val);
        sz++;
    }
    void pop() {
        if (sz == 0) {
            cout << "Empty stack" << endl;
            return;
        }
        else {
            for (int i = 0; i < sz - 1; i++) {
                T temp = q.first();
                q.dequeue();
                q.enqueue(temp);
            }
            q.dequeue();
            sz--;
        }
    }
    void print() {
        q.print();
    }
};

// ThirdQueueProblem
int MinIndex(_queue<int>& q, int sortedIndex) {
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.queueSize();
    for (int i = 0; i < n; i++) {
        int curr = q.first();
        q.dequeue();
        if (curr <= min_val && i <= sortedIndex) {
            min_index = i;
            min_val = curr;
        }
        q.enqueue(curr);
    }
    return min_index;
}

void InsertMinToRear(_queue<int>& q, int min_index) {
    int min_val;
    int n = q.queueSize();
    for (int i = 0; i < n; i++) {
        int curr = q.first();
        q.dequeue();
        if (i != min_index)
            q.enqueue(curr);
        else
            min_val = curr;
    }
    q.enqueue(min_val);
}

void SortQueue(_queue<int>& q) {
    for (int i = 1; i <= q.queueSize(); i++) {
        int min_index = MinIndex(q, q.queueSize() - i);
        InsertMinToRear(q, min_index);
    }
}

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
    // SingleLinkedList<int> list;
    // SingleLinkedList<int> list2;
    // SingleLinkedList<int> list3;
    // SingleLinkedList<int> list4;
    // SingleLinkedList<int> list5;
    // SingleLinkedList<int> list6;
    // list.insertAtTail(0);
    // list.insertAtTail(1);
    // list.insertAtTail(2);
    // list.insertAtTail(3);
    // list.insertAtTail(4);
    // list.insertAtTail(5);
    // list.insertAtTail(6);
    // list2.insertAtTail(-10);
    // list2.insertAtTail(0);
    // list2.insertAtTail(0);
    // list2.insertAtTail(11);
    // list2.insertAtTail(-12);
    // list2.insertAtTail(50);
    // list3.insertAtTail(60);
    // list3.insertAtTail(500);
    // list3.insertAtTail(5000);
    // list3.insertAtTail(-5);
    // list4.insertAtTail(10);
    // list4.insertAtTail(100);
    // list4.insertAtTail(-100);
    // list5.insertAtTail(-510);
    // list5.insertAtTail(522);
    // list5.insertAtTail(5);
    // list6.insertAtTail(51);
    // list6.insertAtTail(-51);
    // list6.insertAtTail(55);
    // cout << "before swap" << endl;
    // list.print();
    // cout << endl;
    // list.swap(0, 5);
    // cout << "after swap" << endl;
    // list.print();
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
    // cout << "first = " << q.first() << endl;
    // cout << "size = " << q.queueSize() << endl;
    // q.clear();
    // cout << q.isEmpty() << endl;
    // cout << "size = " << q.queueSize() << endl;
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
    // Stack<char> stk;
    // stk.push('A');
    // stk.push(' ');
    // stk.push(' ');
    // stk.push('B');
    // stk.print();

    //------------------Problems------------------//
    // FirstQueueProblem(5);
    //vector<SingleLinkedList<int>> arr = {list, list2, list3, list4, list5, list6};
    //SecondLinkedlistProblem(arr);
    // stack<int> s;
    // s.push(50);
    // s.push(51);
    // s.push(52);
    // s.push(53);
    // s.pop();
    // s.print();
    // cout << FirstStackProblem("X^Y/(5*Z)+2") << '\n';
    // cout << FirstStackProblem("A+B*C+D") << '\n';
    // cout << FirstStackProblem("( A + B ) * (C + D)") << '\n';
    // _queue<int> q;
    // q.enqueue(5);
    // q.enqueue(3);
    // q.enqueue(7);
    // q.enqueue(9);
    // q.enqueue(1);
    // SortQueue(q);
    // q.print();
}