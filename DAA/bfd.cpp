#include <bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<int, list<int>> l;

public:
    void addEdge(int u, int v, bool bidir = true) {
        l[u].push_back(v);
        if (bidir)
            l[v].push_back(u);
    }

    void print() {
        for (auto p : l) {
            cout << p.first << " -> [ ";
            for (int nbr : p.second) {
                cout << nbr << ", ";
            }
            cout << "]" << endl;
        }
    }

    void bfs(int start) {
        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int nbr : l[node]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main() {
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(0, 1);
    graph.print();
    cout << "BFS starting from node 0:" << endl;
    graph.bfs(0);
    return 0;
}