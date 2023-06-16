#include <iostream>
using namespace std;

class Queue{
private:
    int rear, front;
    int n;
public:
    void enQueue(int a[], int data){
        if (rear == n-1) // if (isFull())
        {
            cout << "Queue Overflow";
        }
        else if (rear == -1){
            rear = front = 0;
            a[rear] = data;
        }
        else{
            rear++;
            a[rear] = data; 
        }
    }

    void deQueue(int a[]){
        if (front == -1) // if (isEmpty())
        {
            cout << "Queue Underflow";
        }
        else if(rear == front){
            rear = -1;
            front = -1;
        }
        else{
            a[front] = 0;
            front++;
        }
    }

    void frontPeek(){

    }

    void rearPeak(){

    }

    bool isEmpty(){
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull(){
        if (rear = n-1)
        {
            return true;
        }
        return false;
    }
};

const int MAX_SIZE = 5;

int main() {
    Queue myQueue;
    int arr[MAX_SIZE];

    myQueue.enQueue(arr, 10);
    myQueue.enQueue(arr, 20);
    myQueue.enQueue(arr, 30);

    myQueue.deQueue(arr);

    myQueue.deQueue(arr);

    myQueue.deQueue(arr);

    myQueue.deQueue(arr); // Output: Queue Underflow

    return 0;
}
