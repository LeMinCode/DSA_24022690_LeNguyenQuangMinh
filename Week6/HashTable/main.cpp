#include <iostream>
#include "Hash.h"
#include "LinkedList.h"
using namespace std;

int main() {
    HashTable ht(7);

    // Thêm dữ liệu
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(14);
    ht.insert(28);

    cout << "=== Hash Table ban dau ===" << endl;
    ht.display();

    // Tìm kiếm
    cout << "\nTim 15: " << (ht.search(15) ? "Tim thay" : "Khong thay") << endl;
    cout << "Tim 99: " << (ht.search(99) ? "Tim thay" : "Khong thay") << endl;

    // Xóa phần tử
    cout << "\nXoa 14..." << endl;
    ht.remove(14);
    ht.display();

    cout << "\nXoa 10..." << endl;
    ht.remove(10);
    ht.display();

    return 0;
}
