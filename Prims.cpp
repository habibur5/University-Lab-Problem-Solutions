#include <bits/stdc++.h>
using namespace std;

class Graph{
  unordered_map<char, list<pair<char,int>>> l;
public:
  void addEdge(char u, char v, int wt){
    l[u].push_back({v, wt});
    l[v].push_back({u, wt});
  }

  int primsAlgo(char src){
    priority_queue<pair<int, char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;
    unordered_map<char, bool> mst;
    pq.push({0,src});
    int ans = 0;

    while (pq.size()>0) 
    {
      int u = pq.top().second;
      int cost = pq.top().first;

      pq.pop();

      if(!mst[u]){
        mst[u] = true;
        ans+=cost;

      for(auto [v, wt] : l[u]){
        if(!mst[v]){
          pq.push({wt, v});
        }
      }

      }
    }

    return ans;
    
  }
  
};
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
}