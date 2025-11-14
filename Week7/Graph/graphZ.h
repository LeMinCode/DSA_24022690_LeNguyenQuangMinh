#ifndef GRAPHZ_H_INCLUDED
#define GRAPHZ_H_INCLUDED
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;

    //Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    //Vô hướng
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //In danh sách
    void printGraph() {
        for(int i = 0;i < V;i++) {
            cout << i << " :";
            for(int v : adj[i]) {
                cout << v << " "; //in ra số đỉnh v kề với từng đỉnh i
            }
            cout << endl; //xuống dòng mỗi lần in xong đỉnh kề của một 1 đỉnh
        }
    }

    //DFS
    void DFSmethod(int u, vector<bool> &visited) { //u đỉnh đang duyệt, vector visit dùng & để tránh kết quả cập nhập sai trong lần đệ quy sau
        visited[u] = true; //đánh dấu là đã thăm tránh lập chu trình
        cout << u << " "; //duyệt

        for(int v : adj[u]) {
            if(!visited[v]) {
                DFSmethod(v, visited); //duyệt hết tất cả các đỉnh kề đến sâu nhất sau đó đệ quy sẽ quay lại gọi tiếp các đỉnh kề với u
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSmethod(start, visited); //bắt đầu từ start
    }

    //BFS
    void BFS(int start) {
        vector<bool> visited (V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start); //đặt start = true đẩy vào queue

        while(!q.empty()) {
           int u = q.front();
           q.pop();
           cout << u << " ";

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v); //đẩy tất cả các đỉnh kề vào queue
                }
            }
        }
    }
};
#endif // GRAPHZ_H_INCLUDED
