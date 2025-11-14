#include <iostream>
#include "graphZ.h"
using namespace std;

#include "graphz.h"

int main() {
    // Tạo đồ thị có 6 đỉnh (0 → 5)
    Graph g(6);

    // Thêm cạnh (vô hướng)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // In danh sách kề
    cout << "Danh sach ke:\n";
    g.printGraph();

    // DFS từ đỉnh 0
    cout << "\nDFS start 0: ";
    g.DFS(0);

    // BFS từ đỉnh 0
    cout << "\nBFS start 0: ";
    g.BFS(0);

    return 0;
}


