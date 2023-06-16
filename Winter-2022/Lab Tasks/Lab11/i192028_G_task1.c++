#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }

    Node *
    search(Node *root, int key)
    {
        if (root == NULL || root->data == key)
            return root;

        // Key is greater than root's data
        if (root->data < key)
            return search(root->right, key);

        // Key is smaller than root's data
        return search(root->left, key);
    }

    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    Node *deletenode(Node *root, int k)
    {
        // Base case
        if (root == NULL)
            return root;
        // If root->data is greater than k then we delete the root's subtree
        if (root->data > k)
        {
            root->left = deletenode(root->left, k);
            return root;
        }
        else if (root->data < k)
        {
            root->right = deletenode(root->right, k);
            return root;
        }

        // If one of the children is empty
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *Parent = root;
            // Find successor of the node
            Node *succ = root->right;
            while (succ->left != NULL)
            {
                Parent = succ;
                succ = succ->left;
            }

            if (Parent != root)
                Parent->left = succ->right;
            else
                Parent->right = succ->right;

            // Copy Successor Data
            root->data = succ->data;

            // Delete Successor and return root
            delete succ;
            return root;
        }
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == NULL)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main()
{
    Node Tree(0);
    Node *root = NULL;
    // Number of nodes to be inserted
    int t;
    cout << "Enter number of nodes to be inserted: ";
    cin >> t;
    while (t--)
    {
        int data;
        cout << "Insert data: ";
        cin >> data;
        cout << endl;
        root = Tree.insert(root, data);
    }
    // cout << "The height of the tree is " << Tree.LevelOrder(root) << endl;

    cout << "Enter the data to find:";
    int data;
    cin >> data;
    Node *find_element = Tree.search(root, data);
    if (find_element == NULL)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Data found" << find_element->data << endl;
    }

    int delete_data;
    cout << "\nEnter Data to Delete: ";
    cin >> delete_data;
    Node *deleteelement = Tree.deletenode(root, delete_data);
    cout << "Deleted Element: " << deleteelement->data << endl;

    cout << "PostOrder Traversal : \n";
    Tree.postorder(root);
    cout << "\nInOrder Traversal : \n";
    Tree.inorder(root);
    cout << "\nPreOrder Traversal : \n";
    Tree.preorder(root);

    return 0;
}