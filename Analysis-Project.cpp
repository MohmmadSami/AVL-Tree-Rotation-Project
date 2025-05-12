#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

// Utility function to get the height of the tree
int height(Node* n) {
    return n ? n->height : 0;
}

// Utility function to update the height of a node
void updateHeight(Node* n) {
    n->height = 1 + max(height(n->left), height(n->right));
}

// Utility function to get balance factor
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Right rotate (LL case)
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

// Left rotate (RR case)
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// Insert a key in AVL Tree
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // No duplicates

    updateHeight(node);
    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // RR
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// In-order traversal
void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

// Benchmark insertions
void benchmark(int numElements) {
    Node* root = nullptr;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
        root = insert(root, rand());
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Inserted " << numElements << " nodes in " << diff.count() << " seconds\n";
}

int main() {
    Node* root = nullptr;
    int data[] = {30, 20, 40, 10, 25, 35, 50, 5};
    for (int key : data)
        root = insert(root, key);

    cout << "In-order traversal of AVL Tree:\n";
    inOrder(root);
    cout << "\n\nBenchmarking performance:\n";
    benchmark(100);
    benchmark(1000);
    benchmark(10000);
    benchmark(100000);

    return 0;
}
