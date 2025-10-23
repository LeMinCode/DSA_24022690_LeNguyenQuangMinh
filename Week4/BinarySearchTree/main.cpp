#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder   : "; inorder(root);   cout << endl;
    cout << "Preorder  : "; preorder(root);  cout << endl;
    cout << "Postorder : "; postorder(root); cout << endl;

}
