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

class SubStack : public Stack
{
    Stack *stack;
    Stack *aux;
    int size;
    int top;

public:
    SubStack(int size)
    {
        stack = new Stack(size);
        aux = new Stack(size);
        this->size = size;
        top = -1;
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
            stack->Push(data);
        }
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            int data = stack->Peek();
            stack->Pop();
            top--;
            return data;
        }
    }
    int top()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return stack->Peek();
        }
    }
    int size()
    {
        return top + 1;
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
    int getMin()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            int min = stack->Peek();
            while (!stack->isEmpty())
            {
                int data = stack->Peek();
                stack->Pop();
                if (data < min)
                {
                    min = data;
                }
                aux->Push(data);
            }
            while (!aux->isEmpty())
            {
                int data = aux->Peek();
                aux->Pop();
                stack->Push(data);
            }
            return min;
        }
    }
};
