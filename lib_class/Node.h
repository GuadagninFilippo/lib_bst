#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

class Node{
private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;

public:
    Node(int key);

    Node* insertR(int k);

    Node* insertI(int k);

    bool searchI(int k);
    
    bool searchR(int k);

    void inOrder();
};

#endif
