#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>
#include "list.h"
#include "LinkedList.h"
using namespace std;

struct QueueList {
    List l;

    bool Empty() {
        if(l.size == 0) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int x) {
        l.AddLast(x);
    }

    int dequeue() {
        if (Empty()) {
            return -1;
        }
        int value = l.arr[0];
        l.DeleteFirst();
        return value;
    }

    int front() {
        if (Empty()) {
            return -1;
        } else {
        return l.arr[0];
        }
    }

    int size() {
        return l.size;
    }

    void print() {
        l.printNor();
    }
};

struct QueueLinked {
    LinkedList l;

    bool Empty() {
        if(l.size == 0) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int x) {
        l.AddLast(x);
    }

    int dequeue() {
        if (Empty()) {
            return -1;
        }
        int value = l.head->data;
        l.DeleteFirst();
        return value;
    }

    int front() {
        if (Empty()) {
            return -1;
        } else {
        return l.head->data;
        }
    }

    int size() {
        return l.size;
    }

    void print() {
        l.printNor();
    }
};

#endif // QUEUE_H_INCLUDED
