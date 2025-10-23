#include <iostream>
#include "linkedlist_symbol.h"
using namespace std;

int main() {
    Node* table = nullptr;

    insertLL(table, "x", 10);
    insertLL(table, "y", 20);
    insertLL(table, "z", 30);
    insertLL(table, "y", 999);

    cout << "Danh sach sau insert:\n";
    printLL(table);

    Node* p = searchLL(table, "y");
    if (p) cout << "\nTim thay y = " << p->value << endl;
    else cout << "\nKhong tim thay y\n";

    removeKeyLL(table, "y");
    cout << "\nSau khi xoa y:\n";
    printLL(table);

    return 0;
}
