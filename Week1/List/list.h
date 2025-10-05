#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
using namespace std;

struct List {
    int arr[100];
    int size;

    List() {
        size = 0;
    }

    void Access(int index) {        //O(1)
        if(index < 0 || index >= size) {
            cout << "Invalid" << endl;
            return;
        } else {
            cout << arr[index] << endl;
        }
    }

    void AddFirst(int add) {        //O(n)
        if(size >= 100) {
            cout << "List full" << endl;
            return;
        }
        for(int i = size;i > 0;i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = add;
        size++;
    }

    void AddLast(int add) {         //0(1)
        if(size >= 100) {
            cout << "List Full" << endl;
            return;
        }
        arr[size] = add;
        size++;
    }

    void InsertP(int index, int add) {      //O(n)
        if(index < 0 || index > size || size >= 100) {
            cout << "Invalid" << endl;
            return;
        }
        for(int i = size;i > index;i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = add;
        size++;
    }

    void DeleteFirst() {        //O(n)
        for(int i = 0;i < size - 1;i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void DeleteLast() {         //O(1)
        if(size <= 0) {
            cout << "Empty List" << endl;
            return;
        }
        size--;
    }

    void DeletePos(int pos) {       //O(n)
        if(pos < 0 || pos >= size) {
            cout << "Invalid" << endl;
            return;
        }
        for(int i = pos;i < size - 1;i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void printNor() {       //O(n)
        for(int i = 0;i < size;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void printReverse() {       //O(n)
        for(int i = size - 1;i >= 0;i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

#endif // LIST_H_INCLUDED
