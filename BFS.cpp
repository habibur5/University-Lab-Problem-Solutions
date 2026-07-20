#include <bits/stdc++.h>
using namespace std;

class Graph{
  unordered_map<int, list<int>> l;
  public:
  void addEdge(int u, int v){
    l[u].push_back(v);
    l[v].push_back(u);
  }

  void bfs(int start){
    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    cout<<"BFS Traversal: ";
    while(!q.empty()){
      int node = q.front();
      q.pop();
      cout<<node<<" ";
      for(auto nbr : l[node]){
        if(!visited[nbr]){
          q.push(nbr);
          visited[nbr] = true;
        }
      } 
    }
  }

  void dfs(int start){
    unordered_map<int, bool> visited;
    stack<int> s;
    s.push(start);
    visited[start] = true;
    cout<<"\nDFS Traversal: ";
    while(!s.empty()){
      int node = s.top();
      s.pop();
      cout<<node<<" ";
      for(auto nbr : l[node]){
        if(!visited[nbr]){
          s.push(nbr);
          visited[nbr] = true;
        }
      } 
    }
  }

};


int main(){
  Graph graph;
  int V;
  cout<<"Enter number of edges of graph: ";
  cin>>V;
  cout<<"Enter the edges (u v): "<<endl;
  for(int i = 0; i<V; i++){
    int u, v;
    cin>>u>>v;
    graph.addEdge(u,v);
  }
  cout << "Enter Starting Node: ";
  int start;
  cin>>start;
  graph.bfs(start);
  graph.dfs(start);
  return 0;
}

/* 
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 3);
  graph.addEdge(2, 4);
  graph.addEdge(0, 1);
*/