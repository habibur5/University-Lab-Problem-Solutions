#include <bits/stdc++.h>
using namespace std;
class Graph{
  unordered_map<int, list<int>> l;
  public:
    void addEdge(int u, int v){
      l[u].push_back(v);
    }

    // sort graph according to finishing time (Z-A) 
    void dfs1(int node, unordered_map<int, bool> &vis, stack<int> &st){
      vis[node] = true;
      for(auto p : l[node]){
        if(!vis[p]){
          dfs1(p, vis, st);
        }
      }
      st.push(node);
    }

    // transpose a graph
    Graph transpose(){
      Graph g;
      for(auto p: l){
        int u = p.first;
        for(auto v: p.second){
          g.l[v].push_back(u);
        }
      }
      return g;
    }

    // dfs in reverse graph DFS for SCC
    void dfs2(int node, unordered_map<int,bool> &visited){
      visited[node] = true;
      cout << node << " ";
      for(auto p: l[node]){
        if(!visited[p]){
          dfs2(p, visited);
        }
      }
    }
     // Kosaraju Main
    void kosaraju(){
      
        stack<int> st;
        unordered_map<int,bool> visited;

        // Step 1: Order by finish time
        for(auto p : l){
            if(!visited[p.first])
                dfs1(p.first, visited, st);
        }

        // Step 2: Reverse graph
        Graph gt = transpose();

        // Step 3: DFS in stack order
        visited.clear();

        cout << "Strongly Connected Components:\n";
        int sccCount = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                cout << "SCC: " << ++sccCount << " -> ";
                gt.dfs2(node, visited);
                cout << endl;
            }
        }
    }


};
int main(){

   Graph g;
  // take input for directed graph
/*     int V;
    cout<<"Enter number of edges of graph: ";
    cin>>V;

    cout<<"Enter the edges (u v): "<<endl;
    for(int i = 0; i<V; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    } */


    // Directed graph example
    g.addEdge(0,1);
    g.addEdge(1,2); // O(1)
    g.addEdge(2,0); // 
    g.addEdge(1,3);
    g.addEdge(3,4);

    g.kosaraju();

  
  return 0;
}