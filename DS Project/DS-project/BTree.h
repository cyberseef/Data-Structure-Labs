#include<iostream>
#include<conio.h>
#include<string.h>
#include<sstream>
using namespace std;

#define max_order 3
#define min_oder 0




template <typename T> struct btreeNode {

    T* data;
    int count;
    btreeNode* link[max_order + 1];
public:
    btreeNode() {
        data = new T[max_order + 1];
    }

};

btreeNode<string>* root;

template <typename T> btreeNode<T>* createNode(T d, btreeNode<T>* child) {

    btreeNode<T>* newnode = new btreeNode<T>;
    newnode->data[1] = d;
    newnode->count = 1;
    newnode->link[0] = root;
    newnode->link[1] = child;

    return newnode;

}

template <typename T> void insertdatainNode(T d, int pos, btreeNode<T>* node, btreeNode<T>* child) {
    int i;
    for (i = node->count;i > pos;i--) {
        node->data[i + 1] = node->data[i];
        node->link[i + 1] = node->link[i];
    }

    node->data[i + 1] = d;
    node->link[i + 1] = child;
    node->count++;
}

template <typename T> void splitnode(T d, T* ptrd, int pos, btreeNode<T>* node, btreeNode<T>* child, btreeNode<T>** newnode) {

    int mid, i;

    if (pos > min_oder)
        mid = min_oder + 1;
    else
        mid = min_oder;

    *newnode = new btreeNode<T>;

    i = mid + 1;

    while (i <= max_order) {
        (*newnode)->data[i - mid] = node->data[i];
        (*newnode)->link[i - mid] = node->link[i];
        i++;
    }

    node->count = mid;

    (*newnode)->count = max_order - mid;

    if (pos <= min_oder) {
        insertdatainNode(d, pos, node, child);
    }
    else {
        insertdatainNode(d, pos - mid, *newnode, child);
    }
    *ptrd = node->data[node->count];
    (*newnode)->link[0] = node->link[node->count];
    node->count--;
}

template <typename T> int setvalue(T d, T* ptrd, btreeNode<T>* node, btreeNode<T>** child) {

    int pos;

    if (!node) {
        *ptrd = d;
        *child = NULL;
        return 1;
    }

    if (d < node->data[1]) {
        pos = 0;
    }
    else {
        for (pos = node->count;d < node->data[pos] && pos>1;pos--);
        if (d == node->data[pos]) {
            cout << "duplicated not allowed";
            return 0;
        }

    }

    if (setvalue(d, ptrd, node->link[pos], child)) {
        if (node->count < max_order) {
            insertdatainNode(*ptrd, pos, node, *child);
        }
        else {
            splitnode(*ptrd, ptrd, pos, node, *child, child);
            return 1;
        }
    }

    return 0;
}

template <typename T> void insertion(T d) {
    int check;
    T i;
    btreeNode<T>* child;

    check = setvalue(d, &i, root, &child);

    if (check) {
        root = createNode(i, child);
    }

}

template <typename T> void copynextNodeifdeleted(btreeNode<T>* node, int pos) {
    btreeNode<T>* temp;
    temp = node->link[pos];
    for (;temp->link[0] != NULL;) {

        temp = temp->link[0];
    }

    node->data[pos] = temp->data[1];

}


template<typename T> void removeval(btreeNode<T>* node, int pos) {

    int i = pos + 1;

    while (i <= node->count) {
        node->data[i - 1] = node->data[i];
        node->link[i - 1] = node->link[i];
        i++;
    }
    node->count--;
}


template <typename T> void rightshift(btreeNode<T>* node, int pos) {

    btreeNode<T>* temp = node->link[pos];
    int i = temp->count;

    while (i > 0) {
        temp->data[i + 1] = temp->data[i];
        temp->link[i + 1] = temp->link[i];
    }

    temp->data[1] = node->data[pos];
    temp->link[1] = temp->link[0];
    temp->count++;

    temp = node->link[pos - 1];
    node->data[pos] = temp->data[temp->count];
    node->link[pos] = temp->link[temp->count];

    temp->count--;
    return;
}

template <typename T> void leftshift(btreeNode<T>* node, int pos) {

    int i = 1;

    btreeNode<T>* temp = node->link[pos - 1];

    temp->count++;

    temp->data[temp->count] = node->data[pos];
    temp->link[temp->count] = node->link[pos]->link[0];

    temp = node->link[pos];

    node->data[pos] = temp->data[1];
    temp->link[0] = temp->link[1];
    temp->count--;

    while (i <= temp->count) {
        temp->data[i] = temp->data[i + 1];
        temp->link[i] = temp->link[i + 1];
        i++;
    }

    return;

}

template <typename T>void mergenodes(btreeNode<T>* node, int pos) {

    int i = 1;
    btreeNode<T>* temp1 = node->link[pos], * temp2 = node->link[pos - 1];
    temp2->count++;
    temp2->data[temp2->count] = node->data[pos];
    temp2->link[temp2->count] = node->link[0];
    while (i <= temp1->count) {
        temp2->count++;
        temp2->data[temp2->count] = temp1->data[i];
        temp2->link[temp2->count] = temp1->link[i];
        i++;
    }
    i = pos;
    while (i < node->count) {
        node->data[i] = node->data[i + 1];
        node->link[i] = node->link[i + 1];
        i++;
    }
    node->count--;
    free(temp1);
}


template <typename T> void adjustNode(btreeNode<T>* node, int pos) {

    if (!pos) {
        if (node->link[1]->count > min_oder) {
            leftshift(node, 1);
        }
        else {
            mergenodes(node, 1);
        }
    }
    else {
        if (node->count != pos) {
            if (node->link[pos - 1]->count > min_oder) {
                rightshift(node, pos);
            }
            else {
                if (node->link[pos + 1]->count > min_oder) {
                    leftshift(node, pos + 1);
                }
                else {
                    mergenodes(node, pos);
                }
            }
        }

        else {
            if (node->link[pos - 1]->count > min_oder) {
                rightshift(node, pos);
            }
            else
                mergenodes(node, pos);
        }
    }
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


template <typename T> int delvalfromnode(T d, btreeNode<T>* node) {
    int pos, flag = 0;

    if (node) {
        if (d < node->data[1]) {
            pos = 0;
            flag = 0;
        }
        else {
            for (pos = node->count;d < node->data[pos] && pos>1;pos--);
            if (findString(node->data[pos],d,true) == 0) {
                flag = 1;
            }
            else {
                flag = 0;
            }

        }
        if (flag) {

            if (node->link[pos - 1]) {

                copynextNodeifdeleted(node, pos);

                flag = delvalfromnode(node->data[pos], node->link[pos]);

                if (flag == 0) {
                    cout << "given data is not present in Btree\n";
                }
            }
            else {

                removeval(node, pos);

            }
        }
        else {
            flag = delvalfromnode(d, node->link[pos]);
        }

        if (node->link[pos]) {
            if (node->link[pos]->count < min_oder) {
                adjustNode(node, pos);

            }
        }



    }

    return flag;
}

template <typename T> void deletion(T d, btreeNode<T>* node) {
    btreeNode<T>* temp;
    if (!delvalfromnode(d, node)) {
        cout << "data is not present \n";
        return;
    }
    else {
        if (node->count == 0) {
            temp = node;
            node = node->link[0];
            free(temp);
        }
    }
    root = node;
    return;
}





string returnupdatedstring(string original,string field,string old,string newVal) {
    
    stringstream sor(original);

    string s;
    string updatedstring = "";
    while (getline(sor, s, ',')) {
        
        if (s.compare(old)==0)
            updatedstring += newVal;
        else updatedstring += s;
        updatedstring += ",";


    }
    cout << endl <<updatedstring << endl;
    return updatedstring;
    
}

template <typename T> void update(T d,string field,string old,string newVal, btreeNode<T>* node) {
    int i;
    if (node) {
        for (i = 0; i < node->count; i++) {
            update(d, field, old, newVal, node->link[i]);
            if (findString(node->data[i + 1], d,true)) {
                cout << node->data[i + 1] << '\n';
                node->data[i + 1] = returnupdatedstring(node->data[i + 1], field, old, newVal);
                
            }
        }
        update(d,field,old,newVal, node->link[i]);
    }
}



template <typename T> void Delete(T d, btreeNode<T>* node) {
    int i;
    if (node) {
        for (i = 0; i < node->count; i++) {
            Delete(d, node->link[i]);
            if (findString(node->data[i + 1], d))
                node->data[i + 1] = "";
        }
        Delete(d, node->link[i]);
    }
}


template <typename T> void search2(T d,btreeNode<T>* node) {
    int i;
    if (node) {
        for (i = 0; i < node->count; i++) {
            search2(d,node->link[i]);
            if(findString(node->data[i + 1],d))
            cout << node->data[i + 1] << '\n';
        }
        search2(d,node->link[i]);
    }
}

template <typename T> void traversal(btreeNode<T>* node) {
    int i;
    if (node) {
        for (i = 0; i < node->count; i++) {
            traversal(node->link[i]);
            cout << node->data[i + 1] << '\n';
        }
        traversal(node->link[i]);
    }
} 
ofstream MyFile;

template <typename T> void btreefileStore(btreeNode<T>* node,string name="") {
    int i;
 
    if(name.compare(""))
         MyFile = ofstream(name);

    if (node) {
        for (i = 0; i < node->count; i++) {
            btreefileStore(node->link[i]);
            MyFile << node->data[i+1] << '\n';
        }
        btreefileStore(node->link[i]);
    }
  
}

template <typename T> void readbtreefile(string fileName) {
  
    fstream file(fileName, ios::in);
    string line;
    string id;
    string rest;
    int count = 0;int c = 0;
  
    if (file.is_open())
    {


        while (getline(file, line)) {
            
            insertion(line);
        }
    }
    file.close();

}
