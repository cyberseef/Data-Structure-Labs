#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
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
    BinaryTree binaryTree;

    binaryTree.insert(50);
    binaryTree.insert(30);
    binaryTree.insert(20);
    binaryTree.insert(40);
    binaryTree.insert(70);
    binaryTree.insert(60);
    binaryTree.insert(80);

    binaryTree.printInorderTraversal();

    return 0;
}
