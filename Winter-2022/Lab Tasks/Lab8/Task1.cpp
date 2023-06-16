#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	Node* head;
	Node* tail;
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
	int Queue()
	{
		Node* head = NULL;
		Node* tail = NULL;
	}
	int enqueue(int data)
	{
		Node* temp = new Node(data);
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	int dequeue()
	{
		if (head == NULL)
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	int Front()
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
	int Rear()
	{
		if (tail == NULL)
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			cout << tail->data << endl;
		}
	}
	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int print()
	{
		Node* temp = head;
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
	Node* head = NULL;
	Node* tail = NULL;
	Node* temp = NULL;
	Node q;
	q.Queue();
	q.enqueue(10);
	q.enqueue(20);
	q.dequeue();
	q.dequeue();
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.dequeue();
	cout << "Queue Front : " << q.Front() << endl;
	cout << "Queue Rear : " << q.Rear() << endl;
	cout << "Queue is Empty : " << q.isEmpty() << endl;
}