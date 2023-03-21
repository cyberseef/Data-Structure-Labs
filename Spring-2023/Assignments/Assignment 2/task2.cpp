#include <iostream>
using namespace std;

class Node {
public:
	int data; //do not change this
	Node* next;
	Node* prev;

	Node(int d) : data(d)
	{
		this->next = NULL;
		this->prev = NULL;
	}
};


int input(Node*& head, Node*& tail, int no_of_elements)
{
	cout << "\nEnter total number you want : ";
	cin >> no_of_elements;
	
	return no_of_elements;
}



bool binarySearch(Node*& head, Node*& tail, Node*& mid, int search_number)
{
	bool found = false;
	if (search_number == mid->data)
	{
		return true;
	}
	else if (search_number > mid->data)
	{
		mid = mid->next;
		binarySearch(head, tail, mid, search_number);

	}
	else if (search_number < mid->data)
	{
		mid = mid->prev;
		binarySearch(head, tail, mid, search_number);
	}

	return found;

}

void insertionSort(Node*& head, Node*& tail)
{


}


Node* findMiddle(Node*& head,int middle)
{
	Node* temp = head;
	for (int i = 0; i <= middle; i++)//find the middle
	{
		temp = temp->next;
	}
	return temp;
}

int main()
{
	bool result;
	Node* head = NULL;
	Node* tail = NULL;
	Node* mid = NULL;
	int no_of_elements = 0;
	int search_number = 0;
	no_of_elements = input(head, tail, no_of_elements);

	int number;
	for (int i = 0; i < no_of_elements; i++)
	{
		cout << "\nEnter the number for this node : ";
		cin >> number;

		Node* node1 = new Node(number);
		if (head == NULL)
		{
			head = node1;
			tail = node1;
			
		}
		else
		{
			tail->next = node1;
			node1->prev = tail;
			tail = node1;
		}


	}

	insertionSort(head, tail);

	int middle = no_of_elements / 2;
	cout << "The number you want to find: "; cin >> search_number;
	

	

	mid = findMiddle(head,middle);

	result = binarySearch(head, tail, mid, search_number);

}