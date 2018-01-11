#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph {
  int V;
  list<int> *adj;
public:
  Graph(int v) {
    V = v;
    adj = new list<int>[V];
  }
  int BFS(int source, int k) {
    int node, count;
    count = 0;
    queue<int> q;
    bool *visited = new bool[V+1];
    for(int i = 0; i < V+1; i++) visited[i] = false;
    int *distance = new int[V+1];
    for(int i = 0; i < V+1; i++) distance[i] = 0;

    q.push(source);
    visited[source] = true;

    while(!q.empty()) {
      node = q.front();
      q.pop();

      list<int>::iterator j;
      for(j = adj[node].begin(); j != adj[node].end(); j++) {
        if(!visited[*j]){
          q.push(*j);
          visited[*j] = true;
          distance[*j] = distance[node] + 1;
          if(distance[*j] == k) count++;
        }
      }
    }
    return count;
  }

  void addEdge(int u, int v, bool bidir = true) {
    adj[u].push_back(v);
    if(bidir)
      adj[v].push_back(u);
  }
};

int main() {
  int n, k, t, u, v, count;
  cin >> n >> k;
  count = 0;
  Graph g(n);
  t = n-1;
  while(t--) {
    cin >> u >> v;
    g.addEdge(u-1, v-1);
  }
  for(int i = 0; i < n; i++) {
    count += g.BFS(i, k);
  }
  cout << count/2;
  return 0;
}
