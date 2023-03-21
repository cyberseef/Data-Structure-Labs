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
	Node() {
		head = NULL;
		tail = NULL;
	}
	Node(int data)
	{
		this->data = data;
		next = NULL;
		head = NULL;
		tail = NULL;
	}
	void enqueue(int data)
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
	void dequeue()
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
	void Rear()
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
	void print()
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
	Node q;
	q.enqueue(10);
	q.enqueue(20);
	q.dequeue();
	q.dequeue();
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.dequeue();
	cout << "Queue Front : ";
	q.Front();
	cout << "Queue Rear : ";
	q.Rear();
	cout << "Queue is Empty : " << q.isEmpty() << endl;
}
