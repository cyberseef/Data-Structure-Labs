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
                    head = head->next;
                    delete temp;
                    size--;
                    return;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                    size--;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Not Found" << endl;
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
    LinkedList list;
    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(40);
    list.Insert(50);
    list.Insert(60);
    list.Insert(70);
    list.Insert(80);
    list.Insert(90);
    list.Insert(100);
    list.Print();
    list.Search(50);
    list.Update(50, 500);
    list.Print();
    list.Delete(500);
    list.Print();
    return 0;
}