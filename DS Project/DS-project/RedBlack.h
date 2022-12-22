#pragma once
#include<iostream>
using namespace std;

template<typename T>struct node {

    T data;
    node<T>* parent;
    char color;
    node<T>* left;
    node<T>* right;

public:
    node() {
        left = NULL;
        right = NULL;
    }
};
template<typename T> class RBtree {
    
    node<T>* q;

public:
    node<T>* root;
    RBtree() {
        q = NULL;
        root = NULL;
    }
    
    void leftrotate(node<T>* ptr) {

        if (ptr->right == NULL)
            return;
        else {
            node<T>* y = ptr->right;
            if (y->left != NULL) {
                ptr->right = y->right;
                y->left->parent = ptr;
            }
            else
                ptr->right = NULL;

            if (ptr->parent != NULL)
                y->parent = ptr->parent;
            if (ptr->parent == NULL)
                root = y;
            else {

                if (ptr == ptr->parent->left)
                    ptr->parent->left = y;
                else
                    ptr->parent->right = y;
            }

            y->left = ptr;
            ptr->parent = y;

        }
    }

    void rightrotate(node<T>* ptr) {

        if (ptr->left == NULL)
            return;
        else {

            node<T>* y = ptr->left;

            if (y->right != NULL) {

                ptr->left = y->right;
                y->right->parent = ptr;
            }
            else
                ptr->left = NULL;

            if (ptr->parent != NULL)
                y->parent = ptr->parent;
            if (ptr->parent == NULL)
                root = y;

            else {

                if (ptr == ptr->parent->left)
                    ptr->parent->left = y;
                else
                    ptr->parent->right = y;
            }
            y->right = ptr;
            ptr->parent = y;
        }
    }

    string getfirstval(string key) {
        stringstream sor(key);
        string s;
        getline(sor, s, ',');
        return s;

    }
    void search(T key, node<T>* temp)
    {
        
        bool found = false;
        if (temp == NULL)
            return;
        {
            search(key, temp->right);
            
            if (findString(temp->data, key,true))
                cout << temp->data << '\n';
            search(key, temp->left);
        }

    }


    void rangesearch(T key, node<T>* temp)
    {
        bool found = false;
        if (temp == NULL)
            return;

        rangesearch(key, temp->right);

        stringstream sor(key);

        string s;
        bool a = true;
        while (getline(sor, s, ',')) {
            if (!findString(temp->data, s))
            {
                a = false;
                break;
            }
        }
        if (a) {cout << temp->data;
        return;
    }
        rangesearch(key, temp->left);
        
    }

    



    void update(T key, T field, T old, T newVal, node<T>* temp)
    {
        bool found = false;
        if (temp == NULL)
            return;
        cout << temp->data;
        {
            update(key, field, old, newVal, temp->right);
            
            if (findString(temp->data, key, true))
            {
                temp->data = updateString(temp->data, field, old, newVal);
                found = true;
            }
            update(key, field, old, newVal, temp->left);
        }

    }

    void insertfixxx(node<T>* t) {

        node<T>* u;

        if (root == t) {

            t->color = 'b';

            return;

        }

        while (t->parent != NULL && t->parent->color == 'r') {

            node<T>* g = t->parent->parent;
            if (g->left == t->parent) {

                if (g->right != NULL) {

                    u = g->right;

                    if (u->color == 'r') {

                        t->parent->color = 'b';
                        u->color = 'b';
                        g->color = 'r';
                        t = g;

                    }


                }
                else {

                    if (t->parent->right == t) {

                        t = t->parent;
                        leftrotate(t);
                    }

                    t->parent->color = 'b';
                    g->color = 'r';
                    rightrotate(g);
                }
            }

            else {

                if (g->left != NULL) {
                    u = g->left;

                    if (u->color == 'r') {
                        t->parent->color = 'b';
                        u->color = 'b';
                        g->color = 't';
                        t = g;
                    }
                }

                else {

                    if (t->parent->left == t) {

                        t = t->parent;
                        rightrotate(t);
                    }
                    t->parent->color = 'b';
                    g->color = 'r';
                    leftrotate(g);
                }


            }
            root->color = 'b';
        }

    }

    void insert(T val) {

        int i = 0;

        node<T>* ptr, * q;

        node<T>* t = new node<T>;
        t->data = val;
        t->color = 'r';
        ptr = root;
        q = NULL;

        if (root == NULL) {
            root = t;
            t->parent = NULL;
        }
        else {
            while (ptr != NULL) {

                q = ptr;

                if (getfirstval(ptr->data) <= getfirstval(t->data))
                    ptr = ptr->right;
                else
                    ptr = ptr->left;

            }

            t->parent = q;

            if (getfirstval(q->data) <= getfirstval(t->data))
                q->right = t;

            else
                q->left = t;

        }

    }


    node<T>* successor(node<T>* ptr) {

        node<T>* y = NULL;

        if (ptr->left != NULL) {

            y = ptr->left;
            while (y->right == NULL) {
                y = y->right;
            }
        }
        else {
            y = ptr->right;
            while (y->left != NULL)
                y = y->left;
        }

        return y;
    }

    void dell(node<T>* ptr) {

        node<T>* s;
        while (ptr != root && ptr->color == 'b')
        {
            if (ptr->parent->left == ptr)
            {
                s = ptr->parent->right;
                if (s->color == 'r')
                {
                    s->color = 'b';
                    ptr->parent->color = 'r';
                    leftrotate(ptr->parent);
                    s = ptr->parent->right;
                }
                if (s->right->color == 'b' && s->left->color == 'b')
                {
                    s->color = 'r';
                    ptr = ptr->parent;
                }
                else
                {
                    if (s->right->color == 'b')
                    {
                        s->left->color == 'b';
                        s->color = 'r';
                        rightrotate(s);
                        s = ptr->parent->right;
                    }
                    s->color = ptr->parent->color;
                    ptr->parent->color = 'b';
                    s->right->color = 'b';
                    leftrotate(ptr->parent);
                    ptr = root;
                }
            }
            else {
                s = ptr->parent->left;
                if (s->color == 'r')
                {
                    s->color = 'b';
                    ptr->parent->color = 'r';
                    rightrotate(ptr->parent);
                    s = ptr->parent->left;
                }
                if (s->left->color == 'b' && s->right->color == 'b')
                {
                    s->color = 'r';
                    ptr = ptr->parent;
                }
                else
                {
                    if (s->left->color == 'b')
                    {
                        s->right->color = 'b';
                        s->color = 'r';
                        leftrotate(s);
                        s = ptr->parent->left;
                    }
                    s->color = ptr->parent->color;
                    ptr->parent->color = 'b';
                    s->left->color = 'b';
                    rightrotate(ptr->parent);
                    ptr = root;
                }
            }
            ptr->color = 'b';
            root->color = 'b';
        }
    }

    void rbFileRead(string fileName) {

        fstream file(fileName, ios::in);
        string line;

        if (file.is_open())
            while (getline(file, line)) 
                this->insert(line);        
        file.close();
    }

    ofstream myFile;
    void writeFile(node<T>* temp, int val = 0)  

    {

        if (temp == NULL || root == NULL)
            return;

        if (val <= 0)
            myFile << temp->data << "\n";	

        if (temp->left != NULL)
            writeFile(temp->left, val);    

        if (temp->right != NULL)
            writeFile(temp->right, val);




    }



    bool findString(string a, string b, bool id = false) {
        stringstream sor(a);

        string s;
        while (getline(sor, s, ',')) {
          
            if (s.compare(b) == 0)
                return true;
            if (id) return false;
            s = "";
        }

        return false;
    }
    string updateString(string org, string field, string old, string newVal) {

        stringstream sor(org);

        string s;
        string lol = "";
        while (getline(sor, s, ',')) {

            if (s.compare(old) == 0)
                lol += newVal;
            else lol += s;
            lol += ",";


        }
        cout << endl << lol << endl;
        return lol;

    }


    void search(T x) {

        if (root == NULL) {
            cout << "emty tree\n";
        }



        node<T>* ptr = root;
        int found = 0;

        while (ptr != NULL && found == 0) {

            if (ptr->data == x) {
                found = 1;
            }
            if (found == 0) {
                if (ptr->data < x)
                    ptr = ptr->right;
                else
                    ptr = ptr->left;
            }
        }

        if (found == 0)
            cout << "not found\n";
        else {

            cout << "found Node:\n" << ptr->data << endl << "color:" << ptr->color << endl;
        }
    }

    void update2(T key, T field, T old, T newVal, node<T>* ptr) {

        if (root == NULL) {
            
            return;
        }

        if (ptr != NULL) {

            if (findString(ptr->data, key, true)) {

                ptr->data = updateString(ptr->data, field, old, newVal);

            }


            if (ptr->left)
            {
                update2(key,field,old,newVal,ptr->left);
            }
            if (ptr->right)
            {
               
                update2(key, field, old, newVal, ptr->right);
            }

        }
    }

    void del2(T key,node<T>* ptr) {

        if (root == NULL) {
       
            return;
        }

        if (ptr != NULL) {

            if (findString(ptr->data, key, true)) {

                ptr->data ="";

            }


            if (ptr->left)
            {
                cout << "\n\nLeft:\n";
                del2(key, ptr->left);
            }
            if (ptr->right)
            {
                cout << "\n\nRight:\n";
                del2(key, ptr->right);
            }

        }
    }

    void display(node<T>* ptr) {

        if (root == NULL) {
            cout << "Empty Treee\n";
            return;
        }

        if (ptr != NULL) {

            cout << "NODE:\n" << "data:" << ptr->data << endl << "color:" << ptr->color << endl;
            if (ptr->parent != NULL)
                cout << "\n Parent: " << ptr->parent->data;
            else
                cout << "\n There is no parent";
            if (ptr->right != NULL)
                cout << "\n Right Child: " << ptr->right->data;
            else
                cout << "\n There is no right child";
            if (ptr->left != NULL)
                cout << "\n Left Child: " << ptr->left->data;
            else
                cout << "\n There is no left child";
            cout << endl;
            if (ptr->left)
            {
                cout << "\n\nLeft:\n";
                display(ptr->left);
            }
            if (ptr->right)
            {
                cout << "\n\nRight:\n";
                display(ptr->right);
            }

        }
    }

    void displayy() {
        display(root);

    }


};

