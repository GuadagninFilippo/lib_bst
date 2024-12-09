#include <iostream>
#include "Node.h"
using namespace std;

int main() {
    
    Node* root = new Node(10);

    root->insertR(5);
    root->insertR(15);
    root->insertR(3);
    root->insertR(7);
    root->insertR(12);
    root->insertR(18);

    cout << "Albero in ordine: ";
    root->inOrder();
    cout << endl;

    delete root;

    return 0;
}
