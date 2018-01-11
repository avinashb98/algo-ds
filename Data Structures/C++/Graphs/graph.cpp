#include<iostream>
#include<list>
#include<queue>
#include<cstdlib>
using namespace std;

class Graph {
  int V;
  list<int> *adj;
public:
  Graph(int v) {
    V = v;
    adj = new list<int>[V];
  }

  void addEdge(int u, int v, bool bidir = true) {
    adj[u].push_back(v);
    if(bidir)
      adj[v].push_back(u);
  }

  void BFS(int source) {
    int node;
    queue<int> q;
    bool *visited = new bool[V+1];
    for(int i = 0; i < V+1; i++) visited[i] = false;
    int *distance = new int[V+1];
    for(int i = 0; i < V+1; i++) distance[i] = 0;
    int *parent = new int[V+1];
    for(int i = 0; i < V+1; i++) parent[i] = -1;

    q.push(source);
    visited[source] = true;

    while(!q.empty()) {
      node = q.front();
      cout << node << " ";
      q.pop();

      list<int>::iterator j;
      for(j = adj[node].begin(); j != adj[node].end(); j++) {
        if(!visited[*j]){
          q.push(*j);
          visited[*j] = true;
          distance[*j] = distance[node] + 1;
          parent[*j] = node;
        }
      }
    }
    for(int i = 0; i < V; i++) {
      cout << "parent of " << i << " : " << parent[i]<< endl;
    }
  }

  void printAdjList() {
    list<int>::iterator j;
    for(int i = 0; i < V; i++) {
      cout << i << "->";
      for(j = adj[i].begin(); j != adj[i].end(); j++) {
        cout << (*j)<<" ";
      }
      cout << endl;
    }
  }

  int hasEdge(int u, int v) {
    list<int>::iterator j;
    for(j = adj[u].begin(); j != adj[u].end(); j++) {
      if(*j == v) return 1;
    }
    return 0;
  }
};

int main() {
  Graph g(25);
  g.addEdge(0, 6);
  g.addEdge(1, 12);
  g.addEdge(2, 6);
  g.addEdge(2, 15);
  g.addEdge(3, 6);
  g.addEdge(3, 15);
  g.addEdge(3, 10);
  g.addEdge(4, 15);

  g.addEdge(5, 18);
  g.addEdge(5, 19);
  g.addEdge(6, 17);
  g.addEdge(6, 20);
  g.addEdge(7, 18);
  g.addEdge(7, 21);
  g.addEdge(8, 17);
  g.addEdge(8, 22);
  g.addEdge(9, 20);
  g.addEdge(9, 21);
  g.addEdge(10, 19);
  g.addEdge(10, 22);
  g.addEdge(11, 17);
  g.addEdge(11, 24);
  g.addEdge(12, 18);
  g.addEdge(12, 23);
  g.addEdge(13, 20);
  g.addEdge(13, 23);
  g.addEdge(14, 19);
  g.addEdge(14, 24);
  g.addEdge(15, 22);
  g.addEdge(15, 23);
  g.addEdge(16, 21);
  g.addEdge(16, 24);

  float ppr[1][25];
  for(int i = 0; i < 25; i++) {
    ppr[0][i] = rand()%10;
  }

  float pv[1][25];
  for(int i = 0; i < 25; i++) {
    if(i == 2) pv[0][i] = 1;
    else pv[0][i] = 0;
  }

  float d[25] = {1, 1, 0.5, 0.33, 1, 0.5, 0.2, 0.5, 0.5, 0.5, 0.33, 0.5, 0.5, 
                0.33, 0.5, 0.5, 0.5, 0.33, 0.33, 0.33, 0.33, 0.33, 0.33, 0.33, 0.33};
  
  
  float T[25][25];
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      if(g.hasEdge(i, j)) {
        T[i][j] = d[i];
      } else {
        T[i][j] = 0;
      }
    }
  }

  float ppr1[1][25];

  int ite = 4;
  float tem[1][25];
  while(ite--) {

    //a * T * PPR(t-1)
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 25; j++) {
            tem[i][j] = 0;
            for (int x = 0; x < 25; x++) {
                *(*(tem + i) + j) += *(*(ppr + i) + x) *
                                     *(*(T + x) + j);
            }
            tem[i][j] *= 0.85;
        }
    }
    //a * T * PPR(t-1) + (1- a)*PV
    for(int i = 0; i < 25; i++) {
      ppr1[0][i] = tem[0][i] + 0.15*pv[0][i];
      cout << ppr1[0][i] << " ";
    }
    cout << endl;
  }
  
  
  return 0;
}
