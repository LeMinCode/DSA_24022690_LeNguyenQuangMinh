#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    cout << "Stack List" << endl;
    StackList s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << "StackList (print): ";
    s1.print();  // 1 2 3

    cout << "Top: " << s1.top() << endl;   // 3
    cout << "Size: " << s1.size() << endl; // 3

    cout << "Pop: " << s1.pop() << endl;   // 3
    cout << "StackList (after pop): ";
    s1.print();  // 1 2

    cout << endl;

    cout << "Stack LinkedList" << endl;
    StackLinked s2;

    s2.push(10);
    s2.push(20);
    s2.push(30);

    cout << "StackLinked (print): ";
    s2.print();  // 10 20 30

    cout << "Top: " << s2.top() << endl;   // 30
    cout << "Size: " << s2.size() << endl; // 3

    cout << "Pop: " << s2.pop() << endl;   // 30
    cout << "StackLinked (after pop): ";
    s2.print();  // 10 20

    return 0;
}
