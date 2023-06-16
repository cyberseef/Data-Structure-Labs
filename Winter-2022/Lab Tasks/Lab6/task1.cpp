#include <iostream>
using namespace std;

class DoubleLinkedList
{
public:
    int data;
    DoubleLinkedList *next;
    DoubleLinkedList *prev;
    DoubleLinkedList()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    bool IsEmpty()
    {
        if (next == NULL)
            return true;
        else
            return false;
    }
    void Insert(int value)
    {
        DoubleLinkedList *temp = new DoubleLinkedList;
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;
        if (IsEmpty())
        {
            next = temp;
            prev = temp;
        }
        else
        {
            temp->prev = prev;
            prev->next = temp;
            prev = temp;
        }
    }
    void Search(int value)
    {
        DoubleLinkedList *temp = new DoubleLinkedList;
        temp = next;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << "Value found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found" << endl;
    }
    void Remove(int value)
    {
        DoubleLinkedList *temp = new DoubleLinkedList;
        temp = next;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                if (temp->prev == NULL)
                {
                    next = temp->next;
                    temp->next->prev = NULL;
                    delete temp;
                    return;
                }
                else if (temp->next == NULL)
                {
                    prev = temp->prev;
                    temp->prev->next = NULL;
                    delete temp;
                    return;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    return;
                }
            }
            temp = temp->next;
        }
        cout << "Value not found" << endl;
    }
    void UpdateSalary(int value, int newValue)
    {
        DoubleLinkedList *temp = new DoubleLinkedList;
        temp = next;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                temp->data = newValue;
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found" << endl;
    }
    void MaximumSalary()
    {
        DoubleLinkedList *temp = new DoubleLinkedList;
        temp = next;
        int max = 0;
        while (temp != NULL)
        {
            if (temp->data > max)
            {
                max = temp->data;
            }
            temp = temp->next;
        }
        cout << "Maximum Salary is: " << max << endl;
    }
    void print()
    {
        DoubleLinkedList *temp = new DoubleLinkedList;
        temp = next;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DoubleLinkedList list;
    list.Insert(100);
    list.Insert(200);
    list.Insert(300);
    list.Insert(400);
    list.Insert(500);
    list.Insert(600);
    list.Insert(700);
    list.Insert(800);
    list.Insert(900);
    list.Insert(1000);
    list.print();
    list.Search(500);
    list.Remove(500);
    list.print();
    list.UpdateSalary(100, 200);
    list.print();
    list.MaximumSalary();
    return 0;
}