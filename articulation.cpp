#include <bits/stdc++.h>
using namespace std;

class Graph{
  unordered_map<int, list<int>> l;
  int time = 0;
  public:
  void addEdge(int u, int v){
    l[u].push_back(v);
    l[v].push_back(u);
  }

  void dfsAp(
    int node,
    int parrent,
    unordered_map<int, bool> &visited,
    unordered_map<int, int> &disc,
    unordered_map<int, int> &low,
    unordered_map<int, bool> &isAp
  ){

    visited[node] = true;
    disc[node] = low[node] = ++time;
    int child = 0;
    for(auto nbr : l[node]){
      if(nbr == parrent) continue;
      if(visited[nbr]){
        low[node] = min(low[node], disc[nbr]);
      }else{
        child++;
        dfsAp(nbr, node, visited,disc,low, isAp);
        low[node] = min(low[nbr], low[node]);
        if(parrent == -1 && child >1){
          isAp[node] = true;
        }else if(parrent !=-1 &&  disc[node] <= low[nbr]){
          isAp[node] =true;
        }
      }
    }

  }

  void articulationPoints(){
    unordered_map<int, bool> visited;
    unordered_map<int, int> disc;
    unordered_map<int, int> low;
    unordered_map<int, bool> isAp;
    
    for(auto p : l){
      if(!visited[p.first]){
        dfsAp(p.first, -1, visited,disc,low,isAp);
      }
    }

    cout<<"\nArticulation Points: ";
    for(auto p : isAp){
        if(p.second)
            cout<<p.first<<" ";
    }
    cout<<endl;
  }
};
int main(){

  Graph g;


  // take input from user
    int V;
    cout<<"Enter number of edges of graph: ";
    cin>>V;
    cout<<"Enter the edges (u v): "<<endl;
    for(int i = 0; i<V; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

 
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,4);

    g.articulationPoints();
  
  return 0;
}