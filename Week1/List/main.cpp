#include <iostream>
#include "list.h"
using namespace std;

int main() {
    List L;

    L.AddLast(1);
    L.AddLast(2);
    L.AddLast(3);
    L.printNor(); //1 2 3

    L.AddFirst(0);
    L.printNor(); //0 1 2 3

    L.InsertP(2, 88);
    L.printNor(); //0 1 2 88 2 3

    L.DeleteFirst();
    L.printNor(); //1 2 88 3

    L.DeleteLast();
    L.printNor(); //1 88 2

    L.DeletePos(2);
    L.printNor(); //1 88

    L.printReverse(); //88 1
}
