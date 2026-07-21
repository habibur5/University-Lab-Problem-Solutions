#include <bits/stdc++.h>
using namespace std;
class Edge{
  public:
    int v;
    int wt;
  Edge(int v, int wt){
    this->v = v;
    this->wt = wt;
  }

};
void dijkstras(int src, vector<vector<Edge>> graph, int V){

  // pair< dist, v>
  priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
  vector<int> dist(V, INT_MAX);
  pq.push(make_pair(0,src));

  dist[src] = 0;


  while(pq.size()>0){
    int u = pq.top().second;
    pq.pop();

    vector<Edge> edges = graph[u];
    
    for(Edge e: edges){
      if(dist[e.v] > dist[u] + e.wt){
        dist[e.v] = dist[u] + e.wt;
        pq.push(make_pair(dist[e.v], e.v));
      }
    }
  }
  cout<<"Shortest distances from source vertex "<<src<<": ";
  for(auto d: dist){
    cout<<d<<" ";
  }
  cout<<endl;
}

int main(){
  int V, E;
  cout<<"Enter number of vertices and edges of graph: ";
  cin>>V>>E;
  vector<vector<Edge>> graph(V);

  // taking input 
  cout<<"Enter the edges (u v wt): "<<endl;
  for(int i = 0; i<E; i++){
    int u, v, wt;
    cin>>u>>v>>wt;
    graph[u].push_back(Edge(v, wt));
  }
  int src;
  cout<<"Enter source vertex: ";
  cin>>src;
  dijkstras(src, graph, V);
  
  return 0;
}