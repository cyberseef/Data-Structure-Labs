#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node() {
        next = NULL;
    }
    Node(string data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
private:
    Node* head;
    Node* tail;
public:
    Queue() {
        head = NULL;
        tail = NULL;
    }
    void enqueue(string data) {
        Node* temp = new Node(data);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void dequeue() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    string front() {
        if (head == NULL) {
            cout << "Queue is empty" << endl;
            return "";
        } else {
            return head->data;
        }
    }
    string rear() {
        if (tail == NULL) {
            cout << "Queue is empty" << endl;
            return "";
        } else {
            return tail->data;
        }
    }
    bool isEmpty() {
        if (head == NULL) {
            return true;
        } else {
            return false;
        }
    }
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    static void concatenateQueue(Queue q1, Queue q2, Queue& q3) {
        Node* temp = q1.head;
        while (temp != NULL) {
            q3.enqueue(temp->data);
            temp = temp->next;
        }
        temp = q2.head;
        while (temp != NULL) {
            q3.enqueue(temp->data);
            temp = temp->next;
        }
    }
};

int main() {
    Queue q1, q2, q3;
    q1.enqueue("A");
    q1.enqueue("B");
    q1.enqueue("C");
    q2.enqueue("X");
    q2.enqueue("Y");
    q2.enqueue("Z");
    q1.print();
    q2.print();
    Queue::concatenateQueue(q1, q2, q3);
    q3.print();
    return 0;
}
