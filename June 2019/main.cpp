#include <iostream>
#include "Graph.h"
#include "DisjointSetUnion.h"
#include "BinarySearchTree.h"
#include "CoinChangeSolutions.h"
#include "SubsequenceDP.h"
#include "RodCut.h"

void run_bfs() {
    Graph g(6);
    g.addDirectedEdge(0, 1, 1);
    g.addDirectedEdge(0, 2, 1);
    g.addDirectedEdge(1, 3, 1);
    g.addDirectedEdge(2, 3, 1);
    g.addDirectedEdge(3, 4, 1);
    g.addDirectedEdge(4, 5, 1);
    g.addDirectedEdge(0, 5, 1);

    g.bfs(0);
}

void run_dfs() {
    Graph g(6);
    g.addDirectedEdge(0, 1, 1);
    g.addDirectedEdge(0, 2, 1);
    g.addDirectedEdge(1, 3, 1);
    g.addDirectedEdge(2, 3, 1);
    g.addDirectedEdge(3, 4, 1);
    g.addDirectedEdge(4, 5, 1);
    g.addDirectedEdge(0, 5, 1);

    g.dfs(0);
}

void run_dfs_disconnected() {
    Graph g(6);
    g.addDirectedEdge(0, 1, 1);
    g.addDirectedEdge(0, 2, 1);
    g.addDirectedEdge(1, 3, 1);
    g.addDirectedEdge(2, 3, 1);
    g.addDirectedEdge(4, 5, 1);

    g.dfsDisconnected();
}

void run_cycle_detect_directed() {
    Graph g(6);
    g.addDirectedEdge(0, 1, 1);
    g.addDirectedEdge(1, 2, 1);
    g.addDirectedEdge(2, 0, 1);
    g.addDirectedEdge(3, 4, 1);
    g.addDirectedEdge(4, 3, 1);

    g.cycleDetectDirected();
}

void run_cycle_detect_undirected() {
    Graph g(6);
    g.addDirectedEdge(0, 1, 1);
    g.addDirectedEdge(1, 2, 1);
    g.addDirectedEdge(2, 0, 1);
    g.addDirectedEdge(3, 4, 1);
    g.addDirectedEdge(4, 3, 1);

    g.cycleDetectUndirected();
}

void run_dsu() {
    DisjointSetUnion dsu(5);
    dsu.MakeSet();
    dsu.Union(0, 1);
    dsu.Union(1, 2);
    dsu.Union(3, 4);
}

void run_djikstra() {
    Graph g(5);

    g.addUndirectedEdge(0, 1, 5);
    g.addUndirectedEdge(1, 2, 2);
    g.addUndirectedEdge(2, 0, 6);
    g.addDirectedEdge(3, 4, 12);
    g.addDirectedEdge(4, 3, 13);

    g.djikstra(0);
}

void run_floyd() {
    Graph g(5);

    g.addUndirectedEdge(0, 1, 5);
    g.addUndirectedEdge(1, 2, 2);
    g.addUndirectedEdge(2, 0, 6);
    g.addDirectedEdge(3, 4, 12);
    g.addDirectedEdge(4, 3, 13);

    g.floydWarshall();
}

void run_prims() {
    Graph g(5);

    g.addUndirectedEdge(0, 1, 5);
    g.addUndirectedEdge(1, 2, 2);
    g.addUndirectedEdge(2, 0, 6);
    g.addDirectedEdge(2, 4, 12);
    g.addDirectedEdge(4, 3, 13);

    g.prims(0);
}

void run_kruskals() {
    Graph g(5);

    g.addUndirectedEdge(0, 1, 5);
    g.addUndirectedEdge(1, 2, 2);
    g.addUndirectedEdge(2, 0, 6);
    g.addDirectedEdge(2, 4, 12);
    g.addDirectedEdge(4, 3, 13);

    g.kruskals();
}

void run_toposort() {
    Graph g(5);

    g.addUndirectedEdge(0, 1, 1);
    g.addUndirectedEdge(0, 2, 1);
    g.addUndirectedEdge(2, 3, 1);
    g.addDirectedEdge(2, 4, 1);
    g.addDirectedEdge(3, 4, 1);

    g.topologicalSort();
}


void run_BST() {
    BinarySearchTree x;

    x.insertNode(10);
    x.insertNode(5);
    x.insertNode(6);
    x.insertNode(12);
    x.insertNode(13);
    x.insertNode(11);
    x.insertNode(14);
    x.insertNode(1);

    x.levelOrder();

    x.inOrderIterative();

    cout << endl;
    x.leftView();

    cout << endl;
    x.rightView();

    cout << endl;
    x.topView();

    cout << endl;
    x.bottomView();

}

void run_DP() {
    coinChange();
    LCS();
    rodCut();
}

int main() {
//    run_bfs();
//    cout << endl;
//    run_dfs();
//    cout << endl;
//    run_dfs_disconnected();
//    cout << endl;
//    run_cycle_detect_directed();
//    cout << endl;
//    run_cycle_detect_undirected();
//    cout << endl;
//    run_djikstra();
//    cout << endl;
//    run_floyd();
//    cout << endl;
//    run_prims();
//    cout << endl;
//    run_kruskals();

    //run_BST();

    run_toposort();
}