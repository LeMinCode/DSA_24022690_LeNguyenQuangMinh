#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

Node* insert(Node* root, int x) {
    if (root == nullptr)
        return CreateNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

#endif // BST_H_INCLUDED
