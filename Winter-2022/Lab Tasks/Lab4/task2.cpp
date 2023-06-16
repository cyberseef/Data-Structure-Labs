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
	int getNode()
	{
		return data;
	}
	int setNode(int data)
	{
		this->data = data;
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
	Node(int data)
	{
		this->data = data;
		next = NULL;
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
	int roundRobin(int time)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data > time)
			{
				temp->data = temp->data - time;
				temp = temp->next;
				cout << "Task is not completed, it is underprogress" << endl;
			}
			else
			{
				temp->data = 0;
				temp = temp->next;
				cout << "Task is completed in 5 time units" << endl;
			}
		}
	}
	int executionTime()
	{
		Node* temp = head;
		int sum = 0;
		while (temp != NULL)
		{
			sum = sum + temp->data;
			temp = temp->next;
		}
		return sum;
	}
	int remainingTime()
	{
		Node* temp = head;
		int sum = 0;
		while (temp != NULL)
		{
			sum = sum + temp->data;
			temp = temp->next;
		}
		return sum;
	}
	int print()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

int main()
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* temp = NULL;
	int data;
	int time;
	int choice;
	Node q;
	q.Queue();
	q.enqueue(5);
	q.enqueue(10);
	q.enqueue(15);
	q.enqueue(20);
	q.enqueue(25);
	q.enqueue(30);
	cout << "Execution Time: " << q.executionTime() << endl;
	cout << "Remaining Time: " << q.remainingTime() << endl;
	q.roundRobin(5);
}