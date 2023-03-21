#include <iostream>
using namespace std;

class Node {
private:
    Node* head;
    Node* tail;
public:
    int data;
    Node* next;

    Node() {
        next = NULL;
        head = NULL;
        tail = NULL;
    }

    Node(int data) {
        this->data = data;
        next = NULL;
        head = NULL;
        tail = NULL;
    }

    int getNode() {
        return data;
    }

    void setNode(int data) {
        this->data = data;
    }

    void enqueue(int data) {
        Node* temp = new Node(data);
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void dequeue() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Front() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
        }
        else {
            cout << head->data << endl;
        }
    }

    void Rear() {
        if (tail == NULL) {
            cout << "Queue is empty" << endl;
        }
        else {
            cout << tail->data << endl;
        }
    }

    bool isEmpty() {
        if (head == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    void roundRobin(int time) {
    	Node* temp = head;
    	while (temp != NULL) {
        if (temp->data > time) {
            temp->data = temp->data - time;
            cout << "Task is not completed, it is under progress" << endl;
            cout << "Remaining time is " << temp->data << endl;
            cout << "Execution time is " << time << endl;
        }
        else {
            temp->data = 0;
            cout << "Task is completed in " << time << " time units" << endl;
        }
        temp = temp->next; // Move the pointer to the next node
    	}
	}


    int executionTime() {
        Node* temp = head;
        int sum = 0;
        while (temp != NULL) {
            sum = sum + temp->data;
            temp = temp->next;
        }
        return sum;
    }

    int remainingTime() {
        Node* temp = head;
        int sum = 0;
        while (temp != NULL) {
            sum = sum + temp->data;
            temp = temp->next;
        }
        return sum;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    Node q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);
    cout << "Execution Time: " << q.executionTime() << endl;
    cout << "Remaining Time: " << q.remainingTime() << endl;
    q.roundRobin(5);
    q.print();
}
