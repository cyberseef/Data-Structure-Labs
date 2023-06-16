#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class AVL {
public:
    Node* root;

    AVL() {
        root = nullptr;
    }

    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* node) {
        Node* newRoot = node->left;
        Node* subtree = newRoot->right;

        newRoot->right = node;
        node->left = subtree;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    Node* rotateLeft(Node* node) {
        Node* newRoot = node->right;
        Node* subtree = newRoot->left;

        newRoot->left = node;
        node->right = subtree;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    Node* insertNode(Node* node, int data) {
        if (node == nullptr)
            return new Node(data);

        if (data < node->data)
            node->left = insertNode(node->left, data);
        else if (data > node->data)
            node->right = insertNode(node->right, data);
        else
            return node; // Duplicate keys are not allowed

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && data < node->left->data)
            return rotateRight(node);

        // Right Right Case
        if (balance < -1 && data > node->right->data)
            return rotateLeft(node);

        // Left Right Case
        if (balance > 1 && data > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && data < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void insert(int data) {
        root = insertNode(root, data);
    }

    void printInorder(Node* node) {
        if (node == nullptr)
            return;

        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }

    void printInorderTraversal() {
        cout << "Inorder Traversal: ";
        printInorder(root);
        cout << endl;
    }
};

int main() {
    AVL avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    avl.printInorderTraversal();

    return 0;
}
