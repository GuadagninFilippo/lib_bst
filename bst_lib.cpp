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

    while (Current!=nullptr) {
        if (k == Current->data) {
            Current->weight++; 
            return this;

        } else if (k < Current->data) {
            if (Current->lchild == nullptr) {
                Current->lchild = new Node(k); 
                return this;
            } else {
                Current=Current->lchild;
            }
        } else { 
            if (Current->rchild == nullptr) {
                Current->rchild = new Node(k); 
                return this;

            } else {
                Current=Current->rchild;
            }
        }
    }
    return this;
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

void Node::preOrder() {

    cout << data << " ";

    if (lchild != nullptr){
        lchild->preOrder();
        }                      
    
    if (rchild != nullptr){ 
        rchild->preOrder(); 
        }
        
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

void Node::postOrder() {

    if (lchild != nullptr){
        lchild->postOrder();
        }                    
    
    if (rchild != nullptr){ 
        rchild->postOrder(); 
        }

    cout << data << " ";  
        
}

Node* Node::deleteNode(int k) {
    if (k < data){
        if (lchild != nullptr) {
            lchild = lchild->deleteNode(k);
        }
    } else if (k >data){
        if (rchild != nullptr) {
            rchild = rchild->deleteNode(k);
        }
    } else {
        if (this->rchild==nullptr && this->lchild==nullptr) {
            delete this;
            return nullptr;

        } else if(this->rchild == nullptr) {
            Node* t{lchild};
            delete this;
            return t;

        } else if(this->lchild == nullptr) {
            Node* t{rchild};
            delete this;
            return t;

        } else {
            Node* ptr{rchild};
            while (ptr->lchild != NULL) {
                if(ptr==nullptr){
                    break;
                }
                ptr=ptr->lchild;
            }
            data = ptr->data;  
            rchild = rchild->deleteNode(ptr->data); 
        }
    }
    return this;
}


bool Node::isBst() {
  
    if (lchild != nullptr) {
        if (lchild->data >= data) {
            return false;
        }
        if (!lchild->isBst()) {
            return false;
        }
    }

    if (rchild != nullptr) {
        if (rchild->data <= data) {
            return false;
        }
        if (!rchild->isBst()) {
            return false;
        }
    }
    return true;
}


