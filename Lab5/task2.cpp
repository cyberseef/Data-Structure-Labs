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
    void Odd()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data % 2 != 0)
            {
                cout << temp->data << " ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    void Update(int data, int newData)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                temp->data = newData;
                return;
            }
            temp = temp->next;
        }
    }
    void Search(int data)
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                cout << "Found at position " << count << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Not Found" << endl;
    }
    void Delete(int data)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                if (prev == NULL)
                {
                    head = temp->next;
                    delete temp;
                    return;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void Merge(LinkedList &l1, LinkedList &l2)
    {
        Node *temp1 = l1.head;
        Node *temp2 = l2.head;
        while (temp1 != NULL)
        {
            Insert(temp1->data);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            Insert(temp2->data);
            temp2 = temp2->next;
        }
    }
};

class LinkedList2
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
    LinkedList2()
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
    void Even()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data % 2 == 0)
            {
                cout << temp->data << " ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    void Update(int data, int newData)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                temp->data = newData;
                return;
            }
            temp = temp->next;
        }
    }
    void Search(int data)
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                cout << "Found at position " << count << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Not Found" << endl;
    }
    void Delete(int data)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                if (prev == NULL)
                {
                    head = temp->next;
                    delete temp;
                    return;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void Merge(LinkedList &l1, LinkedList &l2)
    {
        Node *temp1 = l1.head;
        Node *temp2 = l2.head;
        while (temp1 != NULL)
        {
            Insert(temp1->data);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            Insert(temp2->data);
            temp2 = temp2->next;
        }
    }
};

int main()
{
    LinkedList l1;
    LinkedList2 l2;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(4);
    l1.Insert(5);
    l1.Insert(6);
    l1.Insert(7);
    l1.Insert(8);
    l1.Insert(9);
    l1.Insert(10);
    l1.print();
    l1.Odd();
    l1.Update(5, 50);
    l1.print();
    l1.Search(50);
    l1.Delete(50);
    l1.print();
    l2.Insert(11);
    l2.Insert(12);
    l2.Insert(13);
    l2.Insert(14);
    l2.Insert(15);
    l2.Insert(16);
    l2.Insert(17);
    l2.Insert(18);
    l2.Insert(19);
    l2.Insert(20);
    l2.print();
    l2.Even();
    l2.Update(15, 150);
    l2.print();
    l2.Search(150);
    l2.Delete(150);
    l2.print();
    l1.Merge(l1, l2);
    l1.print();
    l2.Merge(l2);
    l2.print();
    return 0;
}