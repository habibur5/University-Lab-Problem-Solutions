#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph{

public:
    vector<Edge> edges;
    int V;
    vector<int> parent;
    vector<int> rank;

    Graph(int V){
        this->V = V;
        for(int i = 0; i < V; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unionByRank(int u, int v){
        int parentU = find(u);
        int parentV = find(v);

        if(rank[parentU] == rank[parentV]){
            parent[parentV] = parentU;
            rank[parentU]++;
        }
        else if(rank[parentU] > rank[parentV]){
            parent[parentV] = parentU;
        }
        else{
            parent[parentU] = parentV;
        }
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u, v, wt));
    }

    void kruskal(){
        sort(edges.begin(), edges.end(),
             [](Edge &a, Edge &b){
                 return a.wt < b.wt;
             });

        int minCost = 0;
        int count = 0;

        cout << "\nEdges in MST:\n";

        for(int i = 0; i < edges.size() && count < V - 1; i++){

            Edge e = edges[i];

            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV){      // No cycle
                unionByRank(parU, parV);

                cout << e.u << " -- " << e.v
                     << "  Weight = " << e.wt << endl;

                minCost += e.wt;
                count++;
            }
        }

        cout << "\nMinimum Cost = " << minCost << endl;
    }
};

int main(){

    int V = 7;

    Graph g(V);

    /*
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v wt):\n";
    for(int i = 0; i < E; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        g.addEdge(u, v, wt);
    }
    */

    // Demo Data
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

    cout << "\nKruskal's MST\n";
    g.kruskal();

    return 0;
}