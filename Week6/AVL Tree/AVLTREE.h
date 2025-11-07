#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED
#include <iostream>
#include <algorithm>
using namespace std;

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    // Constructor
    AVLNode(int k) {
        data = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

struct AVLTree {
    AVLNode* root;

    AVLTree() { root = nullptr; }
    ~AVLTree() { destroyTree(root); }

    //cac ham
    int getHeight(AVLNode* n) {
        return (n == nullptr) ? 0 : n->height;
    }

    void updateHeight(AVLNode* n) {
        if (n != nullptr)
            n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    }

    int getBalanceFactor(AVLNode* n) {
        if (n == nullptr) return 0;
        return getHeight(n->left) - getHeight(n->right); // trái - phải
    }

    AVLNode* findMin(AVLNode* node) {
        AVLNode* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    void destroyTree(AVLNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode* insertNode(AVLNode* node, int key) {
        if (node == nullptr)
            return new AVLNode(key);

        if (key < node->data)
            node->left = insertNode(node->left, key);
        else if (key > node->data)
            node->right = insertNode(node->right, key);
        else
            return node; // trùng khóa

        updateHeight(node);
        int balance = getBalanceFactor(node);

        // 4 trường hợp xoay
        if (balance > 1 && key < node->left->data)       // Left-Left
            return rightRotate(node);
        if (balance < -1 && key > node->right->data)     // Right-Right
            return leftRotate(node);
        if (balance > 1 && key > node->left->data) {     // Left-Right
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->data) {   // Right-Left
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* removeNode(AVLNode* node, int key) {
        if (node == nullptr)
            return node;

        if (key < node->data)
            node->left = removeNode(node->left, key);
        else if (key > node->data)
            node->right = removeNode(node->right, key);
    else {
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode* temp = node->left ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                AVLNode* temp = findMin(node->right);
                node->data = temp->data;
                node->right = removeNode(node->right, temp->data);
            }
        }

        if (node == nullptr)
            return node;

        updateHeight(node);
        int balance = getBalanceFactor(node);

        // 4 trường hợp xoay
        if (balance > 1 && getBalanceFactor(node->left) >= 0)
            return rightRotate(node);
        if (balance < -1 && getBalanceFactor(node->right) <= 0)
            return leftRotate(node);
        if (balance > 1 && getBalanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inOrder(AVLNode* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void displayInOrder() {
        cout << "InOrder: ";
        inOrder(root);
        cout << endl;
    }

    void insert(int key) { root = insertNode(root, key); }
    void remove(int key) { root = removeNode(root, key); }

};
#endif // AVL_H_INCLUDED
