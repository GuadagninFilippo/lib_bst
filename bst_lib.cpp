#include"bst_lib.h"
using namespace std;

Node::Node(int key): data(key), weight(1), lchild(nullptr), rchild(nullptr){}

Node* Node::insertR(int k) {
    if(k==data){
        weight++;
        return this;
    } else if (k < data) {
        if (lchild == nullptr){
            lchild = new Node(k);
        }else{
            lchild->insertR(k);
        }
    
    }else if (k > data){
        if (rchild == nullptr){
            rchild = new Node(k);
        }else{
            rchild->insertR(k);
        }
    }
    return this;
}

// insert non ricorsivo
Node* Node::insertI(int k) {
    Node* Current = this;

    while (true) {
        if (k == Current->data) {
            Current->weight++; 
            break;
        
        } else if (k < Current->data) {
            if (Current->lchild == nullptr) {
                Current->lchild = new Node(k); 
                break;
            } else {
                Current=Current->lchild;
            }
        } else { 
            if (Current->rchild == nullptr) {
                Current->rchild = new Node(k); 
                break;

            } else {
                Current=Current->rchild;
            }
        }
    }
}

//search ricorsivo
bool Node::searchR(int k) {
    if (k == data) {
        return true; 
    }
    if (this == nullptr) {
        return false;
    }
    if (k < data) {
        if (lchild != nullptr) {
            return lchild->searchR(k);
        } else {
            return false;
        }
    } else { 
        if (rchild != nullptr) {
            return rchild->searchR(k);
        } else {
            return false;
        }
    }
}

// search iterattivo
bool Node::searchI(int k) {

    Node* current = this;
     
    while (current != nullptr) {
        if (k == current->data) {
            return true;

        } else if (k < current->data) {
            
            current = current->lchild;
        } else {
            current = current->rchild;
        }
    }
    return false; 
}

void Node::inOrder() {

    if (lchild != nullptr){
        lchild->inOrder();
        }
        
    cout << data << " ";                      
    
    if (rchild != nullptr){ 
        rchild->inOrder(); 
        }
        
}
