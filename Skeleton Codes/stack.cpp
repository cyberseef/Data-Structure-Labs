#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Stack {
private:
    int max;
    int top;

public:
    Stack() {
        max = MAX_SIZE;
        top = -1;
    }

    void push(int s[], int data) {
        if (top == max - 1) {
            cout << "Stack Overflow";
        } else {
            top++;
            s[top] = data;
        }
    }

    int pop(int s[]) {
        if (top == -1) {
            cout << "Stack Underflow";
            return -1; // Return a default value indicating underflow
        } else {
            int x = s[top];
            top--;
            return x;
        }
    }

    int peek(int s[]) {
        if (top == -1) {
            cout << "Stack is empty";
            return -1; // Return a default value indicating empty stack
        } else {
            return s[top];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == max - 1;
    }
};

int main() {
    Stack myStack;
    int arr[MAX_SIZE];

    myStack.push(arr, 10);
    myStack.push(arr, 20);
    myStack.push(arr, 30);

    cout << "Peek: " << myStack.peek(arr) << endl;

    cout << "Pop: " << myStack.pop(arr) << endl;
    cout << "Pop: " << myStack.pop(arr) << endl;
    cout << "Pop: " << myStack.pop(arr) << endl;
    cout << "Pop: " << myStack.pop(arr) << endl; // Output: Stack Underflow

    cout << "Is Empty: " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
