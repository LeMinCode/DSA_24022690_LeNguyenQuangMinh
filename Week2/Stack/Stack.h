#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#include "list.h"
#include "LinkedList.h"
using namespace std;

struct StackList {
    List l;

    bool Empty() {
        if(l.size == 0) {
            return true;
        } else {
            return false;
        }
    }

    void push(int x) {
        l.AddLast(x);
    }

    int pop() {
        if (Empty()) {
            return -1;
        }
        int value = l.arr[l.size - 1];
        l.DeleteLast();
        return value;
    }

    int top() {
        if (Empty()) {
            return -1;
        }
        return l.arr[l.size - 1];
    }

    int size() {
        return l.size;
    }

    void print() {
        l.printNor();
    }
};

struct StackLinked {
    LinkedList l;

    bool Empty() {
        if(l.size == 0) {
            return true;
        } else {
            return false;
        }
    }


    void push(int x) {
        l.AddLast(x);
    }

    int pop() {
        if (Empty()) {
            return -1;
        }
        Node* temp = l.head;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            temp = temp->next;
        }
        int value;
        if (temp->next == nullptr) {
            value = l.head->data;
            l.DeleteFirst();
        } else {
            value = temp->next->data;
            delete temp->next;
            temp->next = nullptr;
            l.size--;
        }
        return value;
    }

    int top() {
        if (Empty()) {
            return -1;
        }
        Node* temp = l.head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    int size() {
        return l.size;
    }

    void print() {
        l.printNor();
    }
};

#endif // STACK_H_INCLUDED

