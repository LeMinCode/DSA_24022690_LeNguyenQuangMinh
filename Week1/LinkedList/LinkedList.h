#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

struct LinkedList {
    Node* head;
    int size;

    LinkedList() {
        head = nullptr;
        size = 0;
    }


    void Access(int index) {    //O(n)
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return;
    }
    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    cout << temp->data << endl;
}

    void AddFirst(int x) {      //O(1)
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void AddLast(int x) {       //O(n)
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void InsertP(int pos, int x) {      //O(n)
        if (pos < 0 || pos > size) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 0) {
            AddFirst(x);
            return;
        }
        Node* newNode = new Node(x);
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void DeleteFirst() {        //O(1)
        if (head == nullptr) {
            cout << "Empty list" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void DeleteLast() {     //O(n)
        if (head == nullptr) {
            cout << "Empty List" << endl;;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        size--;
    }

    void DeletePos(int pos) {    //0(n)
        if (pos < 0 || pos >= size) {
            cout << "Invalid position" << endl;;
            return;
        }
        if (pos == 0) {
            DeleteFirst();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        size--;
    }

    void printNor() {       //O(n)
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printReverse(Node* node) {     //O(n)
        if (node == nullptr) {
            return;
        }
        printReverse(node->next);
        cout << node->data << " ";
    }
};

#endif // LINKEDLIST_H_INCLUDED

