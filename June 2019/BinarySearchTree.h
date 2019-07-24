//
// Created by shreyas on 21/6/19.
//

#ifndef DSA_PRACTICE_BINARYSEARCHTREE_H
#define DSA_PRACTICE_BINARYSEARCHTREE_H

#include<bits/stdc++.h>
#include "constants.h"

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    // Next Right Question
    Node *nextRight;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        nextRight = NULL;
    }
};

class BinarySearchTree {
public:
    Node *root;

    // Augmenting Node Coordinate Storage
    int xMax = 0;
    int xMin = 10000;

    BinarySearchTree() {
        root = NULL;
    }

    void insertNode(int data) {
        root = insertUtil(root, data);
    }

    void deleteNode(int data) {
        root = deleteUtil(root, data);
    }

    void preOrder() {
        preOrderUtil(root);
        cout << endl;
    }

    void inOrder() {
        inOrderUtil(root);
        cout << "\n";
    }

    void postOrder() {
        postOrderUtil(root);
        cout << endl;
    }

    // Basically BFS
    void levelOrder() {
        queue<pair<Node*,int>> q;

        q.push(make_pair(root,0));

        int maxLevel = -1;

        while(!q.empty()) {
            pair<Node*,int> top = q.front();
            q.pop();

            if(maxLevel < top.second) {
                maxLevel = top.second;
            }

            cout << top.first->data << " ";

            if(top.first->left != NULL) {
                q.push(make_pair(top.first->left,top.second + 1));
            }

            if(top.first->right != NULL) {
                q.push(make_pair(top.first->right,top.second + 1));
            }
        }
    }

    void verticalOrder(vector<vector<IPair>> &coordinates) {
        verticalOrderUtil(root, 0, 0, coordinates);

        for (auto i = 150 + xMin; i <= 150 + xMax; i++) {
            sort(coordinates[i].begin(), coordinates[i].end(), less<IPair>());
            for (auto j = 0; j < coordinates[i].size(); j++) {
                cout << coordinates[i][j].second << " ";
            }
            cout << endl;
        }
    }


    int LowestCommonAncestor(int x, int y) {
        return LowestCommonAncestorUtil(root, x, y)->data;
    }

    void preOrderUtil(Node *node) {
        if (node == NULL)
            return;

        cout << node->data << " ";
        preOrderUtil(node->left);
        preOrderUtil(node->right);
    }

    void inOrderUtil(Node *node) {
        if (node == NULL)
            return;

        inOrderUtil(node->left);
        cout << node->data << " ";
        inOrderUtil(node->right);
    }

    void inOrderIterative() {
        stack<Node *> s;

        Node *top = root;

        while (top != NULL || !s.empty()) {

            while (top != NULL) {
                s.push(top);
                top = top->left;
            }

            // top->left is NULL now.
            top = s.top();
            s.pop();

            cout << top->data << " ";

            top = top->right;
        }
    }

    void postOrderUtil(Node *node) {
        if (node == NULL)
            return;

        postOrderUtil(node->left);
        postOrderUtil(node->right);
        cout << node->data << " ";
    }

    void verticalOrderUtil(Node *node, int x, int y, vector<vector<IPair>> &coordinates) {

        if (node == NULL)
            return;

        xMax = (xMax < x ? x : xMax);
        xMin = (xMin > x ? x : xMin);

        verticalOrderUtil(node->left, x - 1, y + 1, coordinates);
        coordinates[x + 150].push_back(make_pair(y, node->data));
        verticalOrderUtil(node->right, x + 1, y + 1, coordinates);

    }

    Node *insertUtil(Node *node, int data) {

        if (node == NULL) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insertUtil(node->left, data);
        } else {
            node->right = insertUtil(node->right, data);
        }

        return node;
    }

    Node *findMin(Node *node) {

        while (node && node->left != NULL) {
            node = node->left;
        }

        return node;
    }

    Node *inOrderSuccesor(Node *node) {

        Node *successor = NULL;
        Node *root = this->root;

        if (node->right != NULL) {
            return findMin(node->right);
        }

        while (root != NULL) {
            if (node->data < root->data) {
                successor = root;
                root = root->left;
            } else if (node->data > root->data) {
                root = root->right;
            } else {
                break;
            }
        }

        return successor;
    }

    Node *deleteUtil(Node *node, int data) {

        if (data < node->data) {
            node->left = deleteUtil(node->left, data);
        } else if (data > node->data) {
            node->right = deleteUtil(node->right, data);
        } else {
            // It is middle node.
            // If both children aren't null. Select InOrderSuccessor. And delete this value in right subtree.

            if (node->left == NULL && node->right == NULL) {
                return NULL;
            } else if (node->left == NULL) {
                return node->right;
            } else if (node->right == NULL) {
                return node->left;
            } else {
                Node *succ = inOrderSuccesor(node);
                node->data = succ->data;
                node->right = deleteUtil(node->right, succ->data);
            }
        }

        return node;
    }

    Node *LowestCommonAncestorUtil(Node *root, int x, int y) {
        if (root->data > x && root->data > y) {
            return LowestCommonAncestorUtil(root->left, x, y);
        } else if (root->data < x && root->data < y) {
            return LowestCommonAncestorUtil(root->right, x, y);
        } else if (root->data > x && root->data < y) {
            return root;
        }
        return root;
    }

    // This function sets the next right for node's children.
    // nextRight of level i get's set before i+1
    Node *getNextRight(Node *node) {
        Node *node_right = node->nextRight;

        while (node_right != NULL) {
            if (node_right->left != NULL) {
                return node_right->left;
            } else if (node_right->right != NULL) {
                return node_right->right;
            }
            node_right = node_right->nextRight;
        }

        // This happens when node_right is a left node. So nextRight should be NULL
        return NULL;
    }

    void connectNextRightRecursive(Node *node) {
        if (node == NULL) {
            return;
        }

        // First populate nextRight of the right side of this node.
        if (node->nextRight != NULL) {
            connectNextRightRecursive(node->nextRight);
        }

        // Now connect nextRight of children
        // Once that's done, recursive call to child node.
        if (node->left != NULL) {
            if (node->right != NULL) {
                node->left->nextRight = node->right;
                node->right->nextRight = getNextRight(node);
            } else {
                node->left->nextRight = getNextRight(node);
            }
            connectNextRightRecursive(node->left);
        } else if (node->right != NULL) {
            node->right->nextRight = getNextRight(node);
            connectNextRightRecursive(node->right);
        } else {
            connectNextRightRecursive(getNextRight(node));
        }
    }

    void connectNextRight() {
        root->nextRight = NULL;
        connectNextRightRecursive(root);
    }

    void leftView() {
        queue<pair<Node*,int>> q;

        q.push(make_pair(root,0));

        int maxLevel = -1;

        while(!q.empty()) {
            pair<Node*,int> top = q.front();
            q.pop();

            if(maxLevel < top.second) {
                maxLevel = top.second;
                cout << top.first->data << " ";
            }


            if(top.first->left != NULL) {
                q.push(make_pair(top.first->left,top.second + 1));
            }

            if(top.first->right != NULL) {
                q.push(make_pair(top.first->right,top.second + 1));
            }
        }
    }

    void rightView() {
        queue<pair<Node*,int>> q;

        q.push(make_pair(root,0));

        Node* prevNode = root;

        int maxLevel = -1;

        while(!q.empty()) {
            pair<Node*,int> top = q.front();
            q.pop();

            // This is where the level changes
            if(maxLevel < top.second) {
                maxLevel = top.second;
                cout << top.first->data << " ";
            }

            if(top.first->right != NULL) {
                q.push(make_pair(top.first->right,top.second + 1));
            }

            if(top.first->left != NULL) {
                q.push(make_pair(top.first->left,top.second + 1));
            }
        }
    }

    void topView() {
        queue<pair<Node*,int>> q;
        map<int,int> view;

        q.push(make_pair(root,0));

        int maxRight = -1;
        int minLeft = 1;

        while(!q.empty()) {
            pair<Node*,int> top = q.front();
            q.pop();

            if(maxRight < top.second) {
                maxRight = top.second;
                view[maxRight] = top.first->data;
            }

            if(minLeft > top.second) {
                minLeft = top.second;
                if(!top.second == 0)
                    view[minLeft] = top.first->data;
            }


            if(top.first->left != NULL) {
                q.push(make_pair(top.first->left,top.second - 1));
            }

            if(top.first->right != NULL) {
                q.push(make_pair(top.first->right,top.second + 1));
            }
        }

        for(auto i = view.begin(); i!= view.end(); i++) {
            cout << i->second << " " << endl;
        }
    }

    void bottomView() {
        queue<pair<Node*,int>> q;
        map<int,int> view;

        q.push(make_pair(root,0));

        int maxRight = -1;
        int minLeft = 1;

        while(!q.empty()) {
            pair<Node*,int> top = q.front();
            q.pop();

            if(maxRight < top.second) {
                maxRight = top.second;
            }

            if(minLeft > top.second) {
                minLeft = top.second;
                if(!top.second == 0);

            }

            view[top.second] = top.first->data;

            if(top.first->left != NULL) {
                q.push(make_pair(top.first->left,top.second - 1));
            }

            if(top.first->right != NULL) {
                q.push(make_pair(top.first->right,top.second + 1));
            }
        }

        for(auto i = view.begin(); i!= view.end(); i++) {
            cout << i->second << " " << endl;
        }
    }


};

#endif //DSA_PRACTICE_BINARYSEARCHTREE_H
