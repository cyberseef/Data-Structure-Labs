#include <iostream>
using namespace std;

<template T>
class Stack {
private:
    T* values;
    int capacity;
    int counter;
public:
    Stack(int capacity) {
        this->capacity = capacity;
        values = new T[capacity];
        counter = 0;
    }
    ~Stack() {
        delete[] values;
    }
   void insert(T value) {
        if (counter == capacity) {
            cout << "Stack is full" << endl;
            return;
        }
        values[counter] = value;
        counter++;
    }
    void remove() {
        if (counter == 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        counter--;
    }
    bool isFull() {
        return counter == capacity;
    }
    void print() {
        for (int i = 0; i < counter; i++) {
            cout << values[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> stack(5);
    stack.insert(1);
    stack.insert(2);
    stack.insert(3);
    stack.insert(4);
    stack.insert(5);
    stack.insert(6);
    stack.print();
    stack.remove();
    stack.remove();
    stack.print();
    stack.insert(6);
    stack.insert(7);
    stack.print();
    return 0;
}