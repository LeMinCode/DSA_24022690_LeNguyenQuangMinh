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
                cout << v << " ";
            }
            cout << endl;
        }
    }

    //DFS
    void DFSmethod(int u, vector<bool> &visited) {
        visited[u] = true;
        cout << u << " ";

        for(int v : adj[u]) {
            if(!visited[v]) {
                DFSmethod(v, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSmethod(start, visited);
    }

    //BFS
    void BFS(int start) {
        vector<bool> visited (V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while(!q.empty()) {
           int u = q.front();
           q.pop();
           cout << u << " ";

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
                }
            }
        }
    }
};
#endif // GRAPHZ_H_INCLUDED
