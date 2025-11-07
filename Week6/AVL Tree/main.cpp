#include <iostream>
#include  "AVLTREE.h"
using namespace std;

int main() {
    AVLTree t;
    t.insert(30);
    t.insert(20);
    t.insert(10);
    t.insert(25);
    t.insert(40);
    t.insert(50);

    cout << "Cay sau khi chen: ";
    t.displayInOrder();

    cout << "Xoa 20: ";
    t.remove(20);
    t.displayInOrder();

    cout << "Xoa 40: ";
    t.remove(40);
    t.displayInOrder();

    return 0;
}
