#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#include <iostream>
#include "LinkedList.h"
using namespace std;

struct HashTable {
    int capacity;
    LinkedList* table;

    HashTable(int c = 10) {
        capacity = c;
        table = new LinkedList[capacity];
    }

    int hashFunction(int key) {
        return key % capacity;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].AddLast(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        return table[index].TimKiem(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].XoaGiaTri(key);
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Index " << i << ": ";
            Node* temp = table[i].head;
            if (temp == nullptr) {
                cout << "NULL";
            } else {
                while (temp != nullptr) {
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }
};
#endif // HASHTABLE_H_INCLUDED
