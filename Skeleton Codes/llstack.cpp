#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
private:
    Node(){
        data = NULL;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
private:
 int max;
 Node* top;
 Node* current;
public:
    void push(int data){
        if (current == NULL)
        {
            cout<<"Stack Overflow";
            return;
        }
        else if (top == NULL)
        {
            current->data = data;
            current->next = NULL;
            top = current;
            return;
        }
        else
        {
            current->data = data;
            current->next = top;
            top = current;
            return;
        }
    }

    void pop(){
        if (current == NULL)
        {
            cout<<"Stack Underflow";
            return;
        }
        else
        {
            current = top;
            top = top->next;
            delete current;
            return;
        }
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myStack.pop();

    myStack.pop();

    myStack.pop();

    myStack.pop(); // Output: Stack Underflow

    return 0;
}
