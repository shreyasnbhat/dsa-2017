//
// Created by shreyas on 19/6/19.
//

#ifndef DSA_PRACTICE_UNIONFIND_H
#define DSA_PRACTICE_UNIONFIND_H

#include "bits/stdc++.h"

using namespace std;

class DSUNode {
public:
    int data;
    int rank;
    DSUNode *parent;

    DSUNode(int data) {
        this->data = data;
        this->rank = 0;
    }

    void print() {
        cout << "Data:   " << data << endl;
        cout << "Rank:   " << rank << endl;
        cout << "Parent: " << parent->data << endl;
    }

};

class DisjointSetUnion {
public:
    int size;
    vector<DSUNode> elements;

    DisjointSetUnion(int size) {
        this->size = size;
    }

    void MakeSet() {
        for (auto i = 0; i < size; i++) {
            DSUNode* node = new DSUNode(i);
            node->parent = node;
            elements.emplace_back(*node);
        }
    }

    void Union(int u, int v) {
        DSUNode *first = Find(u);
        DSUNode *second = Find(v);

        if (first->rank == second->rank) {
            second->parent = first;
            first->rank += 1;
        } else if (first->rank > second->rank) {
            second->parent = first;
        } else {
            first->parent = second;
        }
    }

    DSUNode *Find(DSUNode *node) {
        DSUNode *parent = node->parent;

        if (node == parent) {
            return node;
        }

        // Path Compression
        node->parent = Find(node->parent);

        return node->parent;
    }

    DSUNode *Find(int u) {
        Find(&elements[u]);
    }

};

#endif //DSA_PRACTICE_UNIONFIND_H
