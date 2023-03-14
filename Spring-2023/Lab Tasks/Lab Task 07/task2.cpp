#include <iostream>
using namespace std;

class CircularLinkedList
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
    CircularLinkedList()
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
            temp->next = head;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
            tail->next = head;
        }
        size++;
    }

    void Display()
    {
        Node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

    void Delete(int data)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next != head)
        {
            if (temp->data == data)
            {
                if (temp == head)
                {
                    head = head->next;
                    tail->next = head;
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
        if (temp->data == data)
        {
            prev->next = head;
            delete temp;
            size--;
        }
    }

    void Search(int data)
    {
        Node *temp = head;
        while (temp->next != head)
        {
            if (temp->data == data)
            {
                cout << "Value found" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp->data == data)
        {
            cout << "Value found" << endl;
            return;
        }
        cout << "Value not found" << endl;
    }

    void Reverse()
    {
        Node *temp = head;
        Node *prev = NULL;
        Node *next = NULL;
        while (temp->next != head)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        temp->next = prev;
        head = temp;
        tail->next = head;
    }

    void Sort()
    {
        Node *temp = head;
        Node *temp2 = head;
        int tempData;
        while (temp->next != head)
        {
            temp2 = temp->next;
            while (temp2 != head)
            {
                if (temp->data > temp2->data)
                {
                    tempData = temp->data;
                    temp->data = temp2->data;
                    temp2->data = tempData;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
    
    void Josephus(int k)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (size != 1)
        {
            for (int i = 0; i < k - 1; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            cout << temp->data << " ";
            delete temp;
            temp = prev->next;
            size--;
        }
        cout << endl;
        cout << temp->data << endl;
    }
};

int main()
{
    CircularLinkedList list;
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    list.Insert(5);
    list.Insert(6);
    list.Insert(7);
    list.Insert(8);
    list.Insert(9);
    list.Insert(10);
    list.Display();
    list.Josephus(3);
    return 0;
}