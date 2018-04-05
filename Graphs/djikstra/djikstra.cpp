#include<bits/stdc++.h>
#include<iostream>
#define INF 100000000

using namespace std;
typedef pair<int,int> IPair;

class Graph {
  public:
    int vertices;
    list<IPair> *adj;

    Graph(int v) {
      this->vertices = v;
      this->adj = new list<IPair>[v];
    }

    void addEdge(int u,int v,int w) {
      adj[u].push_back(make_pair(v,w));
      adj[v].push_back(make_pair(u,w));
    }

    void dijkstra(int start) {

      // Item Container Comparator
      priority_queue< IPair,vector<IPair>,greater<IPair> > pq;
      vector<int> dist(this->vertices,INF);

      pq.push(make_pair(0,start));
      dist[start] = 0;

      while(!pq.empty()) {
        int vertex = pq.top().second;
        pq.pop();

        list< IPair >::iterator p;

        for(p=adj[vertex].begin();p!=adj[vertex].end();p++) {
          int adj_vertex = (*p).first;
          int weight = (*p).second;

          if(dist[adj_vertex] > dist[vertex] + weight) {
            // Update distance
            dist[adj_vertex] = dist[vertex] + weight;
            pq.push(make_pair(dist[adj_vertex],adj_vertex));
          }
        }
      }

      for(int i = 0; i < vertices; i++) {
        if (i!=start)
        if (dist[i] != INF)
          cout << dist[i] << " " ;
        else
          cout << -1 << " ";
        }


    }
};

int main(int argc, char const *argv[]) {

  int cases;
  cin >> cases;
  for(int j = 0; j< cases; j++) {
    int vertices,edges;
    cin >> vertices >> edges;

    Graph g(vertices);

    for(int i = 0;i < edges; i++) {
      int u,v,w;
      cin >> u >> v >> w;
      g.addEdge(u-1,v-1,w);
    }

    int start = 0;
    cin.clear();
    cin.ignore();
    cin >> start;
    g.dijkstra(start-1);
    cout << endl;
  }

  return 0;
}
