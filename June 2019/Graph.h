//
// Created by shreyas on 19/6/19.
//

#ifndef DSA_PRACTICE_GRAPH_H
#define DSA_PRACTICE_GRAPH_H

#include<bits/stdc++.h>
#include "DisjointSetUnion.h"
#include "constants.h"

using namespace std;

class EdgeRepr {
public:
    int u;
    int v;
    int w;

    EdgeRepr(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    bool operator<(EdgeRepr &b) {
        return w < b.w;
    }
};

class Graph {
public:
    int vertices;
    vector<vector<IPair>> adjList;
    vector<bool> visited;

    Graph(int vertices) {
        this->vertices = vertices;
        this->adjList.resize(vertices);
        this->visited = vector<bool>(vertices, false);
    }

    void addDirectedEdge(int u, int v, int w) {
        adjList[u].push_back(make_pair(v, w));
    }

    void addUndirectedEdge(int u, int v, int w) {
        adjList[v].push_back(make_pair(u, w));
        adjList[u].push_back(make_pair(v, w));
    }

    void markAllUnvisited() {
        for (auto i = 0; i < vertices; i++) {
            visited[i] = false;
        }
    }

    void bfs(int start) {
        markAllUnvisited();

        queue<int> q;
        q.push(start);

        // Visit check before loop
        visited[start] = true;

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            cout << vertex << " " << endl;

            for (auto i = adjList[vertex].begin(); i != adjList[vertex].end(); i++) {
                int other_vertex = i->first;

                if (!visited[other_vertex]) {
                    q.push(other_vertex);
                    visited[other_vertex] = true;
                }
            }    // them to the set of vertices included in MST.

        }

    }

    void dfs(int start) {

        stack<int> q;
        q.push(start);

        visited[start] = true;

        while (!q.empty()) {
            int vertex = q.top();
            q.pop();

            cout << vertex << " ";

            for (auto i = adjList[vertex].begin(); i != adjList[vertex].end(); i++) {
                int other_vertex = i->first;

                if (!visited[other_vertex]) {
                    q.push(other_vertex);
                    visited[other_vertex] = true;
                }
            }
        }
    }

    void dfsDisconnected() {
        markAllUnvisited();

        for (auto i = 0; i < vertices; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }

    bool cycleDetectDirectedUtil(int start, vector<bool> &visited, vector<bool> &recStack) {

        if (visited[start] == false) {
            visited[start] = true;
            recStack[start] = true;

            for (auto i = adjList[start].begin(); i != adjList[start].end(); i++) {
                int other_vertex = i->first;

                if (!visited[other_vertex] && cycleDetectDirectedUtil(other_vertex, visited, recStack)) {
                    return true;
                } else if (recStack[other_vertex] == 1) {
                    return true;
                }
            }
        }
        recStack[start] = false;
        return false;
    }

    void cycleDetectDirected() {
        markAllUnvisited();
        vector<bool> recStack(vertices, false);
        for (auto i = 0; i < vertices; i++) {
            bool check = cycleDetectDirectedUtil(i, visited, recStack);
            if (check)
                cout << "Cycle was detected" << endl;
        }
    }

    void cycleDetectUndirected() {
        DisjointSetUnion dsu(vertices);

        dsu.MakeSet();

        for (auto i = 0; i < vertices; i++) {
            for (auto j = adjList[i].begin(); j != adjList[i].end(); j++) {
                int first = i;
                int second = j->first;

                visited[first] = true;
                visited[second] = true;

                int first_repr = dsu.Find(first)->data;
                int second_repr = dsu.Find(second)->data;

                if (first_repr == second_repr) {
                    cout << "Cycle was detected" << endl;
                }

                dsu.Union(first, second);
            }
        }
    }

    void djikstra(int start) {
        markAllUnvisited();

        vector<int> distances(vertices, INFINITY);
        vector<int> parent(vertices, 0);

        // greater<IPair> is a comparator. Compares the first element. less<IPair> does the opposite.
        priority_queue<IPair, vector<IPair>, greater<IPair>> pq;

        pq.push(make_pair(0, start));

        distances[start] = 0;
        parent[start] = 0;

        while (!pq.empty()) {
            IPair top = pq.top();

            pq.pop();

            int vertex = top.second;
            int vertex_distance = top.first;

            for (auto i = adjList[vertex].begin(); i != adjList[vertex].end(); i++) {

                int other_vertex = i->first;
                int weight = i->second;

                if (distances[vertex] + weight < distances[other_vertex]) {
                    distances[other_vertex] = distances[vertex] + weight;
                    parent[other_vertex] = vertex;
                    pq.push(make_pair(distances[other_vertex], other_vertex));
                }
            }
        }

        for (auto i = 0; i < vertices; i++) {
            std::cout << i << " : " << distances[i] << endl;
        }

    }

    void floydWarshall() {
        vector<vector<int>> distances(vertices, vector<int>(vertices, 10000000));
        vector<int> parent(vertices, 0);

        // Convert Adj List to Adj Matrix to self is zero
        for (auto i = 0; i < vertices; i++) {
            distances[i][i] = 0;
        }

        for (auto j = 0; j < vertices; j++) {
            for (auto k = adjList[j].begin(); k != adjList[j].end(); k++) {

                int other_vertex = k->first;
                int weight = k->second;

                distances[j][other_vertex] = weight;
            }
        }

        // i is the intermediate vertex.
        for (auto i = 0; i < vertices; i++) {
            for (auto j = 0; j < vertices; j++) {
                for (auto k = 0; k < vertices; k++) {
                    if (distances[j][k] > distances[j][i] + distances[i][k]) {
                        distances[j][k] = distances[j][i] + distances[i][k];
                    }
                }
            }
        }

        for (auto i = 0; i < vertices; i++) {
            for (auto j = 0; j < vertices; j++) {
                cout << distances[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Iterate via vertices
    // The key value for these vertices indicate the minimum weight edges connecting
    // them to the set of vertices included in MST.
    void prims(int start) {
        priority_queue<IPair, vector<IPair>, greater<IPair>> pq;

        vector<bool> inMST(vertices, false);
        vector<int> keys(vertices, INFINITY);
        vector<int> parent(vertices, INFINITY);

        int mstWeightSum = 0;

        keys[start] = 0;
        parent[start] = start;

        // Key is set to zero just to keep it at the top of the pq.
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            IPair top = pq.top();

            pq.pop();

            int vertex = top.second;
            int weight = top.first;

            if (inMST[vertex] == false) {
                mstWeightSum += weight;
            }

            inMST[vertex] = true;

            for (auto i = adjList[vertex].begin(); i != adjList[vertex].end(); i++) {
                int other_vertex = i->first;
                int other_vertex_weight = i->second;

                if (!inMST[other_vertex] && keys[other_vertex] > other_vertex_weight) {

                    keys[other_vertex] = other_vertex_weight;
                    pq.push(make_pair(keys[other_vertex], other_vertex));
                    parent[other_vertex] = vertex;

                }

            }
        }

        for (auto i = 0; i < vertices; i++) {
            cout << parent[i] << " " << i << endl;
        }

        cout << "MST Edge Cost: " << mstWeightSum << endl;
    }

    // Iterate over edges
    void kruskals() {

        vector<EdgeRepr> edges;

        for (auto i = 0; i < vertices; i++) {
            for (auto j = adjList[i].begin(); j != adjList[i].end(); j++) {
                auto edge = new EdgeRepr(i, j->first, j->second);
                edges.push_back(*edge);
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSetUnion dsu(vertices);

        dsu.MakeSet();

        int mstWeightSum = 0;

        for (auto i = 0; i < edges.size(); i++) {

            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;

            if (dsu.Find(u) != dsu.Find(v)) {
                mstWeightSum += w;
                dsu.Union(u, v);
            }
        }

        cout << "MST Edge Cost: " << mstWeightSum << endl;
    }

    void topologicalSortUtil(int vertex, vector<bool> &visited, stack<int> &st) {

        visited[vertex] = true;

        for (auto i = adjList[vertex].begin(); i != adjList[vertex].end(); i++) {
            int other_vertex = i->first;
            if(!visited[other_vertex])
                topologicalSortUtil(other_vertex, visited, st);
        }

        st.push(vertex);
    }

    void topologicalSort() {
        markAllUnvisited();

        stack<int> st;

        for(auto i = 0; i < vertices; i++) {
            if(!visited[i])
                topologicalSortUtil(i,visited,st);
        }

        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
    }

};

#endif //DSA_PRACTICE_GRAPH_H
