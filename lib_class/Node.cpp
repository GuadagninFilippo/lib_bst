#include"Node.h"
using namespace std;

Node::Node(int key): data(key), weight(0), lchild(nullptr), rchild(nullptr){}

Node* Node::insertR(int k) {
    if (k < data) {
        if (lchild == nullptr){
            lchild = new Node(k);
        }else{
            lchild->insertR(k);
        }
    
    }else if (k > data) {
        if (rchild == nullptr){
            rchild = new Node(k);
        }else{
            rchild->insertR(k);
        }
    }
    return this;
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