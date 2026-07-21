#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, wt;

    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph {
public:
    vector<Edge> edges;

    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

    void addEdge(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));

        // Initialize DSU if vertex is new
        if (parent.find(u) == parent.end()) {
            parent[u] = u;
            rank[u] = 0;
        }

        if (parent.find(v) == parent.end()) {
            parent[v] = v;
            rank[v] = 0;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void kruskal() {

        sort(edges.begin(), edges.end(),
             [](Edge &a, Edge &b) {
                 return a.wt < b.wt;
             });

        int minCost = 0;

        cout << "Edges in MST:\n";

        for (auto &e : edges) {

            if (find(e.u) != find(e.v)) {

                unionByRank(e.u, e.v);

                cout << e.u << " -- " << e.v
                     << " (" << e.wt << ")\n";

                minCost += e.wt;
            }
        }

        cout << "\nMinimum Cost = " << minCost << endl;
    }
};

int main() {

    Graph g;

    // Demo graph
    g.addEdge(0, 1, 7);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 3, 9);
    g.addEdge(1, 4, 7);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 4, 15);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 8);
    g.addEdge(4, 6, 9);
    g.addEdge(5, 6, 11);

    g.kruskal();
}