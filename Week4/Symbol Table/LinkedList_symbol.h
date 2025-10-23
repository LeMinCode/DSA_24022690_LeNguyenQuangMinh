#ifndef LINKEDLIST_SYMBOL_H
#define LINKEDLIST_SYMBOL_H
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    int value;
    Node* next;
};

Node* createNode(string key, int value) {
    Node* p = new Node;
    p->key = key;
    p->value = value;
    p->next = nullptr;
    return p;
}

void insertLL(Node*& head, string key, int value) {
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->key == key)
            return;
        cur = cur->next;
    }
    Node* newNode = createNode(key, value);
    newNode->next = head;
    head = newNode;
}

Node* searchLL(Node* head, string key) {
    while (head != nullptr) {
        if (head->key == key)
            return head;
        head = head->next;
    }
    return nullptr;
}

void removeKeyLL(Node*& head, string key) {
    if (head == nullptr) return;

    if (head->key == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* cur = head;
    while (cur->next != nullptr && cur->next->key != key) {
        cur = cur->next;
    }

    if (cur->next != nullptr) {
        Node* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
    }
}

void printLL(Node* head) {
    while (head != nullptr) {
        cout << head->key << " = " << head->value << endl;
        head = head->next;
    }
}

#endif // LINKEDLIST_SYMBOL_H
