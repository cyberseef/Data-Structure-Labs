#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	Node* head;
	Node* tail;
public:
	string data;
	Node* next;
	Node(string data)
	{
		this->data = data;
		next = NULL;
	}
	int Queue()
	{
		Node* head = NULL;
		Node* tail = NULL;
	}
	int enqueue(string data)
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
	int concatenateQueue(Node* q1, Node* q2)
	{
		Node* temp = q1->head;
		while (temp != NULL)
		{
			enqueue(temp->data);
			temp = temp->next;
		}
		temp = q2->head;
		while (temp != NULL)
		{
			enqueue(temp->data);
			temp = temp->next;
		}
	}
};

int main()
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* temp = NULL;
	Node q1,q2;
	q1.Queue();
	q2.Queue();
	q1.enqueue("K");
	q2.enqueue("M");
	cout << "Concatenated Queues" << concatenateQueue(q1, q2);
}