#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    Node* getRoot() {
        return root;
    }

    void insert(int data) {
        root = insertRecursive(root, data);
    }

    Node* insertRecursive(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }

        if (data < root->data) {
            root->left = insertRecursive(root->left, data);
        } else if (data > root->data) {
            root->right = insertRecursive(root->right, data);
        }

        return root;
    }

    bool search(int data) {
        return searchRecursive(root, data);
    }

    bool searchRecursive(Node* root, int data) {
        if (root == nullptr) {
            return false;
        }

        if (data == root->data) {
            return true;
        } else if (data < root->data) {
            return searchRecursive(root->left, data);
        } else {
            return searchRecursive(root->right, data);
        }
    }

    void remove(int data) {
        root = removeRecursive(root, data);
    }

    Node* removeRecursive(Node* root, int data) {
        if (root == nullptr) {
            return nullptr;
        }

        if (data < root->data) {
            root->left = removeRecursive(root->left, data);
        } else if (data > root->data) {
            root->right = removeRecursive(root->right, data);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* minValueNode = findMinValueNode(root->right);
                root->data = minValueNode->data;
                root->right = removeRecursive(root->right, minValueNode->data);
            }
        }

        return root;
    }

    Node* findMinValueNode(Node* root) {
        Node* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }
};

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder Traversal: ";
    bst.inorderTraversal(bst.getRoot());
    cout << endl;

    int searchData = 40;
    if (bst.search(searchData)) {
        cout << searchData << " is found in the BST." << endl;
    } else {
        cout << searchData << " is not found in the BST." << endl;
    }

    int removeData = 30;
    bst.remove(removeData);
    cout << "Inorder Traversal after removing " << removeData << ": ";
    bst.inorderTraversal(bst.getRoot());
    cout << endl;

    return 0;
}
