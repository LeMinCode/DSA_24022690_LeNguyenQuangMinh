#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    cout << "Queue List" << endl;
    QueueList q1;

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);

    cout << "QueueList (print): ";
    q1.print();  // 10 20 30

    cout << "Front: " << q1.front() << endl;   // 1
    cout << "Size: " << q1.size() << endl;     // 3

    cout << "Dequeue: " << q1.dequeue() << endl;  // 1
    cout << "QueueList (after dequeue): ";
    q1.print();  // 2 3

    cout << endl;

    cout << "Queue LinkedList" << endl;
    QueueLinked q2;

    q2.enqueue(100);
    q2.enqueue(200);
    q2.enqueue(300);

    cout << "QueueLinked (print): ";
    q2.print();  // 100 200 300

    cout << "Front: " << q2.front() << endl;   // 100
    cout << "Size: " << q2.size() << endl;     // 3

    cout << "Dequeue: " << q2.dequeue() << endl;  // 100
    cout << "QueueLinked (after dequeue): ";
    q2.print();  // 200 300

    return 0;
}
