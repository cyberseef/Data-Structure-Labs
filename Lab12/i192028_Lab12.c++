#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        left = right = NULL;
        data = 0;
    }
    Node(Node *copy)
    {
        left = right = NULL;
        data = copy->data;
    }
    void Set(Node *copy) { data = copy->data; }
};

class AVL
{
public:
    Node *root;
    Node *dele;
    int height;
    int lh = 0, rh = 0;
    int h = 0, a = 0;
    bool avail = 1;
    AVL()
    {
        root = dele = NULL;
        height = 0;
    }
    Node *getRoot()
    {
        return root;
    }
    int R_H()
    {
        h = 0, a = 0;
        Height(root);
        // cout << "\nRoot\t" << root->data << "\t Root Height = " << h << endl;
        return 1;
    }
    int balanceFactor(Node *r)
    {
        lh = 0, rh = 0;
        Height(r->left);
        lh = h;
        Height(r->right);
        rh = h;
        return (lh - rh);
    }
    int Height(Node *r)
    {
        if (r == NULL)
        {
            h = 0;
            return 0;
        }
        else
        {
            Height(r->left);
            a = h;
            Height(r->right);
            if (a > h)
                h = a;
            h++;
            return h;
        }
    }
    void Insert(Node *n, Node **r)
    {
        if (*r == NULL)
        {
            *r = n;
            return;
        }
        else
        {
            if (n->data < (*r)->data)
                Insert(n, &(*r)->left);
            else
                Insert(n, &(*r)->right);
        }
        int bf = balanceFactor(*r);
        if (bf > 1)
        {
            if (n->data < (*r)->left->data)
                LL(r);
            else
                LR(r);
        }
        else if (bf < -1)
        {
            if (n->data > (*r)->right->data)
                RR(r);
            else
                RL(r);
        }
    }
    void LL(Node **r)
    {
        Node *temp = (*r)->left;
        (*r)->left = temp->right;
        temp->right = *r;
        *r = temp;
    }
    void RR(Node **r)
    {
        Node *temp = (*r)->right;
        (*r)->right = temp->left;
        temp->left = *r;
    }
    void LR(Node **r)
    {
        RR(&(*r)->left);
        LL(r);
    }
    void RL(Node **r)
    {
        LL(&(*r)->right);
        RR(r);
    }
    void Delete(Node *n, Node **r)
    {
        if (*r == NULL)
        {
            cout << "Not Found" << endl;
            return;
        }
        else
        {
            if (n->data < (*r)->data)
                Delete(n, &(*r)->left);
            else if (n->data > (*r)->data)
                Delete(n, &(*r)->right);
            else
            {
                if ((*r)->left == NULL && (*r)->right == NULL)
                {
                    *r = NULL;
                    return;
                }
                else if ((*r)->left == NULL)
                {
                    *r = (*r)->right;
                    return;
                }
                else if ((*r)->right == NULL)
                {
                    *r = (*r)->left;
                    return;
                }
                else
                {
                    Node *temp = (*r)->right;
                    while (temp->left != NULL)
                        temp = temp->left;
                    (*r)->Set(temp);
                    Delete(temp, &(*r)->right);
                }
            }
        }
        int bf = balanceFactor(*r);
        if (bf > 1)
        {
            if (balanceFactor((*r)->left) >= 0)
                LL(r);
            else
                LR(r);
        }
        else if (bf < -1)
        {
            if (balanceFactor((*r)->right) <= 0)
                RR(r);
            else
                RL(r);
        }
    }
    void display(Node *r)
    {
        if (r == NULL)
            return;
        display(r->left);
        cout << r->data << "\t";
        display(r->right);
    }

    void update(int old, int newdata)
    {
        dele = new Node();
        dele->data = old;
        Delete(dele, &root);
        dele->data = newdata;
        Insert(dele, &root);
    }
    void search(int data)
    {
        dele = new Node();
        dele->data = data;
        Delete(dele, &root);
        if (dele->data == data)
            cout << "Found" << endl;
        else
            cout << "Not Found" << endl;
        Insert(dele, &root);
    }
};

int main()
{
    AVL tree;
    int temp = 20;
    cout << "\n\nData Entered in the Form of 20,30,40,50,60\n\n";
    for (int i = 0; i < 5; i++)
    {
        Node *node = new Node();
        node->data = temp;
        tree.Insert(node, &tree.root);
        temp += 10;
    }
    cout << "Tree Balancing after Rotation\n";
    tree.display(tree.root);
    cout << "\n\nupdate 30 to 100\n\n";
    tree.update(30, 100);
    tree.display(tree.root);
    tree.Delete(tree.root, &tree.root);
    cout << "\n\nAfter deletion of 100 tree balances itself again as shown\n\n";
    tree.display(tree.root);
}