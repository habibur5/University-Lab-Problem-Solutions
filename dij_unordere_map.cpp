#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void dijkstra(int src, unordered_map<int, vector<Edge>> &graph) {

    // vertex -> shortest distance
    unordered_map<int, int> dist;

    // Initialize all distances to INF
    for (auto &node : graph) {
        dist[node.first] = INT_MAX;
    }

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {

        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Ignore outdated entries
        if (currDist > dist[u])
            continue;

        for (Edge &e : graph[u]) {

            if (dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push({dist[e.v], e.v});
            }
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";
    for (auto &p : dist) {
        cout << p.first << " -> ";
        if (p.second == INT_MAX)
            cout << "INF";
        else
            cout << p.second;
        cout << endl;
    }
}

int main() {

    /* int E;
    cout << "Enter number of edges: ";
    cin >> E;

    unordered_map<int, vector<Edge>> graph;

    cout << "Enter edges (u v wt):\n";

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        graph[u].push_back(Edge(v, wt));

        // Ensure destination vertex also exists
        if (graph.find(v) == graph.end())
            graph[v] = {};
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(src, graph); */



    unordered_map<int, vector<Edge>> graph;

// Demo graph
graph[0].push_back(Edge(1, 4));
graph[0].push_back(Edge(2, 1));

graph[1].push_back(Edge(3, 1));
graph[1].push_back(Edge(50, 7));

graph[2].push_back(Edge(1, 2));
graph[2].push_back(Edge(3, 5));
graph[2].push_back(Edge(50, 8));

graph[3].push_back(Edge(50, 3));

graph[50].push_back(Edge(5, 2));

// Ensure all vertices exist in the map
graph[5] = {};

int src = 0;

dijkstra(src, graph);

    return 0;
}