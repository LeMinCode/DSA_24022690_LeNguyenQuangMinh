#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    Node* root = nullptr;

    root = put(root, 50);
    root = put(root, 30);
    root = put(root, 70);
    root = put(root, 10);
    root = put(root, 20);
    root = put(root, 60);
    root = put(root, 80);
    root = put(root, 65);

    cout << isBST(root) << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    root = deleteNode(root, 60);
    cout << "AfterDelete 60: " << endl;

    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    return 0;
}
