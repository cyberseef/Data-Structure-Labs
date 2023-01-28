#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
};

class Queue
{
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void Enqueue(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
        }
        size++;
    }
    void Dequeue()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            size--;
        }
    }
    void Front()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << head->data << endl;
        }
    }
    void isEmpty()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Queue is not empty" << endl;
        }
    }
};

int main()
{
    Queue q;
    q.isEmpty();
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Front();
    q.Dequeue();
    q.Front();
    q.Dequeue();
    q.Front();
    q.Dequeue();
    q.Front();
    q.Dequeue();
    q.Front();
    q.Dequeue();
    q.Front();
    q.isEmpty();
    return 0;
}