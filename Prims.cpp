#include <bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<char, list<pair<char, int>>> l;

public:
    void addEdge(char u, char v, int wt) {
        l[u].push_back({v, wt});
        l[v].push_back({u, wt});
    }

    int primsAlgo(char src) {
        // {weight, currentNode, parent}
        priority_queue<
            tuple<int, char, char>,
            vector<tuple<int, char, char>>,
            greater<tuple<int, char, char>>
        > pq;

        unordered_map<char, bool> mst;

        pq.push({0, src, '-'});

        int totalCost = 0;

        cout << "Edges in MST:\n";

        while (!pq.empty()) {
            auto [cost, u, parent] = pq.top();
            pq.pop();

            if (mst[u])
                continue;

            mst[u] = true;
            totalCost += cost;

            if (parent != '-') {
                cout << parent << " - " << u
                     << "  (Weight = " << cost << ")\n";
            }

            for (auto [v, wt] : l[u]) {
                if (!mst[v]) {
                    pq.push({wt, v, u});
                }
            }
        }

        return totalCost;
    }
};

int main() {
    Graph g;

    // Demo graph
    g.addEdge('A', 'B', 4);
    g.addEdge('A', 'H', 8);
    g.addEdge('B', 'C', 8);
    g.addEdge('B', 'H', 11);
    g.addEdge('C', 'D', 7);
    g.addEdge('C', 'F', 4);
    g.addEdge('C', 'I', 2);
    g.addEdge('D', 'E', 9);
    g.addEdge('D', 'F', 14);
    g.addEdge('E', 'F', 10);
    g.addEdge('F', 'G', 2);
    g.addEdge('G', 'H', 1);
    g.addEdge('G', 'I', 6);
    g.addEdge('H', 'I', 7);

    char src = 'A';

    cout << "Starting Vertex: " << src << "\n\n";

    int cost = g.primsAlgo(src);

    cout << "\nTotal MST Cost = " << cost << endl;

    return 0;
}


/* 

int main(){
  Graph g;

  int nodes, edges;
  cout<<"Enter number of nodes and edges of graph: ";
  cin>>nodes>>edges;
  cout<<"Enter the edges (u v wt): "<<endl;
  for(int i = 0; i < edges; i++){
    int  wt;
    char u, v;
    cin>>u>>v>>wt;
    g.addEdge(u, v, wt); 
  }

  char src;
  cout<<"Enter source vertex: ";
  cin>>src;
  cout<<"Minimum cost of spanning tree: ";
  cout<<g.primsAlgo(src)<<endl;
} */