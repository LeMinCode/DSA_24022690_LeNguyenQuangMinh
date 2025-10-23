#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <iostream>
#include <algorithm>
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

Node* put(Node* root, int x) {
    if (root == nullptr)
        return CreateNode(x);

    if (x < root->data)
        root->left = put(root->left, x);
    else if (x > root->data)
        root->right = put(root->right, x);

    return root;
}

Node* get(Node* root, int x){
    if (root == nullptr) return nullptr;
    if (root->data == x) return root;
    if (x < root->data) return get(root->left, x);
    return get(root->right, x);
}

Node* findMin(Node* r){
    while(r && r->left) r = r->left;
    return r;
}

Node* deleteNode(Node* root, int x){
    if(root == nullptr) return nullptr;
    if(x < root->data) root->left = deleteNode(root->left, x);
    else if(x > root->data) root->right = deleteNode(root->right, x);
    else {
        if(root->left == nullptr) {
            Node* t = root->right;
            delete root;
            return t;
        } else if(root->right == nullptr){
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* t = findMin(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

bool isBSTUtil(Node* r, int minV, int maxV){
    if(!r) return true;
    if(r->data <= minV || r->data >= maxV) return false;
    return isBSTUtil(r->left, minV, r->data) &&
           isBSTUtil(r->right, r->data, maxV);
}

bool isBST(Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int height(Node* r){
    if(!r) return 0;
    return 1+max(height(r->left), height(r->right));
}

bool isBalancedBST(Node* root){
    if(!root) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh - rh) > 1) return false;
    return isBalancedBST(root->left) && isBalancedBST(root->right);
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
