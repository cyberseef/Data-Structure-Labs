#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* front;
    Node* rear;
};

class Queue{
private:
    Node* front;
    Node* rear;
public:
    void enQueue(int data){
        Node* temp = new Node();
        temp->data = data;
        temp->front = NULL;
        temp->rear = NULL;
        if (front == NULL && rear == NULL)
        {
            front = rear = temp;
        }
        else{
            rear->front = temp;
            rear = temp;
        }
    }

    void deQueue(){
        Node* temp = front;
        if (front == NULL)
        {
            cout << "Queue Underflow";
        }
        else if(front == rear){
            front = rear = NULL;
        }
        else{
            front = front->front;
        }
        delete temp;
    }

    void frontPeek(){

    }

    void rearPeak(){

    }

    bool isEmpty(){
        if (front == NULL)
        {
            return true;
        }
        return false;       
    }  

    bool isFull(){
        return false;
    }
};

int main() {
    Queue myQueue;

    myQueue.enQueue(10);
    myQueue.enQueue(20);
    myQueue.enQueue(30);

    cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl; // Output: No

    myQueue.deQueue();

    cout << "Front element: ";
    myQueue.frontPeek(); // Output: 20

    cout << "Rear element: ";
    myQueue.rearPeak(); // Output: 30

    myQueue.deQueue();
    myQueue.deQueue();

    cout << "Is queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}
