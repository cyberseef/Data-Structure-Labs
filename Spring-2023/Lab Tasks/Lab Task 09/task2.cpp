#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        arr = new int[size];
        top = -1;
        this->size = size;
    }
    void Push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    void Pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            top--;
        }
    }
    void Peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << arr[top] << endl;
        }
    }
    void clear()
    {
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s(5);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Push(6);
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Peek();
    s.clear();
    s.isEmpty();
    return 0;
}