#include <bits/stdc++.h>
using namespace std;

class Edge{
  public:
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt){
      this->u = u;
      this->v =v;
      this->wt = wt;
    }
};

class Graph{
  
public:
  vector<Edge>edges;
  int V;
  vector<int> parent;
  vector<int> rank;

  Graph(int V){
    this->V = V;
    for(int i=0; i<V; i++){
      parent.push_back(i);
      rank.push_back(0);
    }
  }

  int find (int x){
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

    }else if(rank[parentU] > rank[parentV]){
      parent[parentV] = parentU;
    }else {
      parent[parentU] = parentV;
    }
  }

  void addEdge(int u, int v, int wt){
    edges.push_back(Edge(u,v,wt));
  }

  void kruskal(){
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt<b.wt;});
    int minCost = 0;
    int count = 0;

    for(int i =0; i<edges.size() && count<V-1; i++){

      Edge e = edges[i];
      
      int parU = find(e.u);
      int parV = find(e.v);
      if(parU != parV){ // no cycle edge
        unionByRank(parU, parV);
        minCost+=e.wt;
        count++;
      }
    }
    cout<<minCost<<endl;
  }

};
int main(){
  int V;
  cout<<"Enter number of vertices: ";
  cin>>V;
  Graph g(V);
  

  int E;
  cout<<"Enter number of edges: ";
  cin>>E;
  cout<<"Enter the edges (u v wt): "<<endl;

  for(int i = 0; i<E; i++){
    int u, v, wt;
    cin>>u>>v>>wt;
    g.addEdge(u, v, wt);
  }
  // g.addEdge(0, 1, 10);
  // g.addEdge(0, 2, 15);
  // g.addEdge(0, 3, 30);

  // g.addEdge(1,3,40);
  // g.addEdge(2,3,50);
  cout<<"Minimum cost of spanning tree: ";
  g.kruskal();
}