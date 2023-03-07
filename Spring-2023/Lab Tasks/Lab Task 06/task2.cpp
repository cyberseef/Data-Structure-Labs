#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void Insert(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
        size++;
    }
    void Merge(LinkedList &list2)
    {
        Node *temp1 = head;
        Node *temp2 = list2.head;
        Node *prev = NULL;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data > temp2->data)
            {
                if (prev == NULL)
                {
                    list2.head = temp2->next;
                    temp2->next = temp1;
                    head = temp2;
                    prev = head;
                    temp2 = list2.head;
                }
                else
                {
                    prev->next = temp2;
                    temp2 = temp2->next;
                    prev->next->next = temp1;
                    prev = prev->next;
                }
            }
            else
            {
                prev = temp1;
                temp1 = temp1->next;
            }
        }
        if (temp2 != NULL)
        {
            if (prev != NULL)
            {
                prev->next = temp2;
            }
            else
            {
                head = temp2;
            }
        }
    }
    void Print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList L1, L2;
    L1.Insert(1);
    L1.Insert(3);
    L1.Insert(5);
    L1.Insert(7);
    L2.Insert(2);
    L2.Insert(4);
    L2.Insert(6);
    L2.Insert(8);
    cout << "List 1: ";
    L1.Print();
    cout << "List 2: ";
    L2.Print();
    L1.Merge(L2);
    cout << "Merged List: ";
    L1.Print();
    return 0;
}