#include<iostream>
using namespace std;

#ifndef NODE_H
#define NODE_H

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

/*
struct node{
    int key;
    node* left;
    node* right;

    node(int value){
        key = value;
        left = nullptr;
        right = nullptr;
    }
};



//-------------------------------------------INSERIMENTO---------------------------------------------------------------------------------
node* insert(node* root, int key){
    if(root == nullptr){
        return new node(key);
    }
    
    if(key < root->key){
    root->left = insert(root->left, key);

    }else if(key > root->key){
        root->right = insert(root->right, key);
    }

    return  root;

}



//-------------------------------------------INSERIMENTO  IN MODO NON RICORSIVO-----------------------------------------------------------
node* create_node(node* root, int key){
    node* current{root};

    while(current != nullptr && current->key != key){
        if(key > current->key && current->right == nullptr){
            current->right = new node(key);
            break;
        }else if(key > current->key){
            current = current->right;
            continue;
        }

        if(key < current->key && current->left == nullptr){
            current->left = new node(key);
            break;
        }else if(key < current->key){
            current = current->left;
            continue;
        }
    }

    if(current->key == key){
        return root;
    }

    return root;
}




//-------------------------------------------RICERCA DI UN ELEMENTO----------------------------------------------------------------------
node*  search(node* root, int key){
    if(root == nullptr || key == root->key){
        return root;
        }
    if(key < root->key){
        return search(root->left, key);

    } else if (key > root->key){
        return search(root->right, key);
    }

    return nullptr;
}


//-------------------------------------------ELIMINA FOGLIA------------------------------------------------------------------------------
node* deleteLeaf(node* root, int key) {
    if (root == nullptr) {
        return nullptr; // Se l'albero è vuoto
    }

    // Cerca il nodo da eliminare
    if (key < root->key) {
        root->left = deleteLeaf(root->left, key); // Vai a sinistra
    } else if (key > root->key) {
        root->right = deleteLeaf(root->right, key); // Vai a destra
    } else {
        // Trovato il nodo con la chiave giusta
        if (root->left == nullptr && root->right == nullptr) {
            // Se è una foglia
            delete root; // Libera la memoria
            return nullptr; // Ritorna nullptr al genitore
        }
    }

    return root; // Ritorna il ndo attuale
}


//-------------------------------------------ELIMINA ROOT CON  UN FILGIO-----------------------------------------------------------------
node* deleteLeaf_whitchild(node* root, int key) {
    if (root == nullptr) {
        return nullptr; // Se l'albero è vuoto
    }

    // Cerca il nodo da eliminare
    if (key < root->key) {
        root->left = deleteLeaf_whitchild(root->left, key); // Vai a sinistra
    } else if (key > root->key) {
        root->right = deleteLeaf_whitchild(root->right, key); // Vai a destra
    } else {

        if (root->left == nullptr) { // Ha solo il figlio destro
            node* temp = root->right;
            delete root; // Libera memoria del nodo corrente
            return temp; // Ritorna il figlio destro al genitore
        } else if (root->right == nullptr) { // Ha solo il figlio sinistro
            node* temp = root->left;
            delete root; // Libera memoria del nodo corrente
            return temp; // Ritorna il figlio sinistro al genitore
        }
    }

    return root;
}

//-------------------------------------------ELIMINA ROOT CON DUE FILGI-----------------------------------------------------------------
node* findMin(node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}
node* deleteNode(node* root, int key) {
    if (root == nullptr) {
        return root; 
    }
    
    // Ricerca del nodo da cancellare
    if (key < root->key) {
        root->left = deleteNode(root->left, key); //vai nel sottoalbero sinistro
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key); //vai nel sottoalbero destro
    } else {

        node* temp = findMin(root->right); // Trova il successore in ordine 
        root->key = temp->key; // Copia il valore del successore al nodo corrente
        root->right = deleteNode(root->right, temp->key); // Cancella il successore in ordine
    }
    return root;
}

//-------------------------------------------VISITA PREORDER------------------------------------------------------------------------------
void PreOrderTraversal(node* root){
    if (root == nullptr) {
        return;  //se il nodo è nullo, ritorna
    }

    // stampa il valore del nodo
    cout << root->key << " ";

    // Visita il sottoalbero sinistro
    PreOrderTraversal(root->left);


    // Visita il sottoalbero destro
    PreOrderTraversal(root->right);
}


//-------------------------------------------VISITA INORDER-------------------------------------------------------------------------------
void inOrderTraversal(node* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);

    cout << root->key << " ";

    inOrderTraversal(root->right);
}


//-------------------------------------------VISITA POSTORDER------------------------------------------------------------------------------
void PostOrderTraversal(node* root) {
    if (root == nullptr) {
        return;  
    }

    PostOrderTraversal(root->left);

    PostOrderTraversal(root->right);

    cout << root->key << " ";

}


//-------------------------------------------CALCOLO ALTEZZA-------------------------------------------------------------------------------
int calcHeight(node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = calcHeight(root->left);
    int rightHeight = calcHeight(root->right);
    
      if (leftHeight > rightHeight) {
        return 1 + leftHeight;
    } else {
        return 1 + rightHeight;
    }
}

//-------------------------------------------VERIFICA BST IS BST----------------------------------------------------------------------------
bool isBst(node* node){

    if(node==nullptr){
        return true;
    }

    if((node->right!=nullptr && node->right->key>node->key) && (node->left!=nullptr && node->left->key<node->key) ){
        isBst(node->left);
        isBst(node->right);
    } else{
        return false;
    }

    return true;

}
*/