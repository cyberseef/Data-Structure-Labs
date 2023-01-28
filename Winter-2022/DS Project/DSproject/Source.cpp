#include <iostream>
#include <fstream>
#include <string>
#include "bTree.h"
#include "AVLTree.h"
#include "RedBlack.h"

using namespace std;

int writeupto = 3;
int readupto = 3;

string removeSpace(string input)
{

    string temp = "";
    for (int i = 0; input[i] != '\0'; i++)
    {

        if (input[i] != ' ')
            temp += input[i];
    }

    return temp;
}

int bTreeMenu()
{
    for (int i = 1; i < writeupto; i++)
    {

        fstream file("datafiles/NCHS_-_Leading_Causes_of_Death__United_States_" + to_string(i) + ".csv", ios::in);
        string line;
        string id;
        string rest;
        int count = 0;
        int c = 0;
        if (file.is_open())
        {
            getline(file, line);

            while (getline(file, line))
            {

                insertion(line);
            }
        }

        btreefileStore(root, "BInd/bTree" + to_string(i) + ".txt");
        MyFile.close();

        root = NULL;
    }

    int opt;
    string input;
    string input2;
    string input3;
    string input4;
    while (true)
    {
        cout << "1) Update Query\n2) Delete query\n"
             << "3) Search query\n4) Select * query\n"
             << "5) Exit\nEnter your input: ";
        cin >> opt;
        cout << endl;

        switch (opt)
        {
        case 1:
            cout << "Enter your key:";
            cin >> input;
            cout << "Enter your field:";
            cin >> input2;
            cout << "Enter your old input:";
            cin >> input3;
            cout << "Enter your new input:";
            cin >> input4;
            break;
        case 2:
            cout << "Enter the value to delete:";
            cin >> input;
            break;
        case 3:
            cout << "Enter the value to search:";
            cin >> input;
            break;
        case 4:
            break;
        case 5:
            exit(0);
        }
        bool check = false;

        for (int i = 1; i < readupto; i++)
        {

            root = NULL;
            readbtreefile<string>("BInd/bTree" + to_string(i) + ".txt");

            switch (opt)
            {
            case 1:
                (update(input, input2, input3, input4, root));
                check = true;
                opt = 1;
                break;
            case 2:
                Delete(input, root);
                check = true;
                break;
            case 3:
                search2(input, root);
                opt = 3;
                break;
            case 4:
                traversal(root);
                break;
            case 5:
                exit(0);
            }
            if (check)
            {

                ofstream ofs("BInd/bTree" + to_string(i) + ".txt");
                ofs << ""
                    << "\n";
                ofs.close();

                btreefileStore(root, "BInd/bTree" + to_string(i) + ".txt");
                MyFile.close();
                ;
            }
        }
        cout << endl;
    }
}

void avlTreeMenu()
{

    for (int i = 1; i < writeupto; i++)
    {
        AvlTree<string> avl;

        fstream file("datafiles/NCHS_-_Leading_Causes_of_Death__United_States_" + to_string(i) + ".csv", ios::in);
        string line;
        string id;
        string rest;
        int count = 0;
        int c = 0;
        if (file.is_open())
        {
            getline(file, line);

            while (getline(file, line))
            {

                AvlNode<string> *an = new AvlNode<string>();
                an->data = line;
                avl.Insert(an, &avl.root);
            }
        }
        avl.myFile = ofstream("Avl/avlTree" + to_string(i) + ".txt");
        avl.writeFile(avl.root);

        avl.myFile.close();
    }

    int opt;
    string input;
    string input2;
    string input3;
    string input4;
    while (true)
    {
        cout << "1) Update Query\n2) Delete query\n"
             << "3) Search query\n4) Select * query\n"
             << "5) Exit\nEnter your input: ";

        cin >> opt;
        cout << endl;

        switch (opt)
        {
        case 1:
            cout << "Enter your key:";
            cin >> input;
            cout << "Enter your field:";
            cin >> input2;
            cout << "Enter your old input:";
            cin >> input3;
            cout << "Enter your new input:";
            cin >> input4;
            break;
        case 2:
            cout << "Enter the value to delete:";
            cin >> input;
            break;
        case 3:
            cout << "Enter the value to search:";
            cin >> input;
            break;
        case 4:
            break;
        case 5:
            exit(0);
        }
        bool check = true;

        for (int i = 1; i < readupto; i++)
        {

            AvlTree<string> avl;
            avl.AvlFileRead("Avl/avlTree" + to_string(i) + ".txt");

            switch (opt)
            {
            case 1:
                avl.update(input, input2, input3, input4, avl.root);

                check = true;

                break;
            case 2:
                avl.deletes(input, avl.root);
                check = true;
                break;
            case 3:
                avl.search(input, avl.root);

                break;
            case 4:
                avl.display(avl.root);
                break;
            case 5:
                exit(0);
            }
            if (check)
            {

                ofstream ofs("Avl/avlTree" + to_string(i) + ".txt");
                ofs << ""
                    << "\n";
                ofs.close();

                avl.myFile = ofstream("Avl/avlTree" + to_string(i) + ".txt");
                avl.writeFile(avl.root);
                avl.myFile.close();
            }
        }
        cout << endl;
    }
}

void rbTreeMenu()
{

    for (int i = 1; i < writeupto; i++)
    {
        RBtree<string> rb;

        fstream file("datafiles/NCHS_-_Leading_Causes_of_Death__United_States_" + to_string(i) + ".csv", ios::in);
        string line;
        string id;
        string rest;
        int count = 0;
        int c = 0;
        if (file.is_open())
        {
            getline(file, line);

            while (getline(file, line))
            {

                rb.insert(removeSpace(line));
            }
        }
        file.close();
        rb.display(rb.root);
        rb.myFile = ofstream("RBInd/rbTree" + to_string(i) + ".txt");
        rb.writeFile(rb.root);

        rb.myFile.close();
    }

    int opt;
    string input;
    string input2;
    string input3;
    string input4;
    while (true)
    {
        cout << "1) Update Query\n2) Delete query\n"
             << "3) Search query\n4) Select * query\n"
             << "5) Exit\nEnter your input: ";
        cin >> opt;
        cout << endl;

        switch (opt)
        {
        case 1:
            cout << "Enter your key:";
            cin >> input;
            cout << "Enter your field:";
            cin >> input2;
            cout << "Enter your old input:";
            cin >> input3;
            cout << "Enter your new input:";
            cin >> input4;
            break;
        case 2:
            cout << "Enter the value to delete:";
            cin >> input;
            break;
        case 3:
            cout << "Enter the value to search:";
            cin >> input;
            break;
        case 4:
            break;
        case 5:
            cout << "Enter the value to search in range with , in between:";
            cin >> input;
            break;

        case 6:
            exit(0);
        }
        bool check = false;

        for (int i = 1; i < readupto; i++)
        {

            RBtree<string> rb;
            rb.rbFileRead("RBInd/rbTree" + to_string(i) + ".txt");
            string d;
            switch (opt)
            {
            case 1:
                rb.update2(input, input2, input3, input4, rb.root);
                check = true;
                break;
            case 2:
                rb.del2(input, rb.root);
                check = true;
                break;
            case 3:
                rb.search(input, rb.root);

                break;
            case 4:
                rb.display(rb.root);
                break;
            case 5:

                rb.rangesearch(input, rb.root);
                break;
            case 6:
                exit(0);
            }
            if (check)
            {

                ofstream ofs("RBInd/rbTree" + to_string(i) + ".txt");
                ofs << ""
                    << "\n";
                ofs.close();

                rb.myFile = ofstream("RBInd/rbTree" + to_string(i) + ".txt");
                rb.writeFile(rb.root);
                rb.myFile.close();
            }
        }
        cout << endl;
    }
}

void menu()
{
    int opt;
    string input;
    while (true)
    {
        cout << "--------WELCOME TO DMS System-------------\n1)Btree\n2)AVL Tree\n3)Red-Black\n";
        cin >> opt;
        cout << endl;
        switch (opt)
        {
        case 1:
            bTreeMenu();
            break;
        case 2:

            avlTreeMenu();
            break;
        case 3:
            rbTreeMenu();
            break;
        default:
            bTreeMenu();
            break;
        }
        cout << endl;
        break;
    }
}

int main()
{

    menu();

    return 0;
}