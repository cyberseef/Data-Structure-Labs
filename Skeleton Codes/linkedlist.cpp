#include <iostream>
using namespace std;

class Node{
public:
    int data; 
    Node* next; // pointer to next node 

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
private:
    Node* head;
    Node* current;
public:
    LinkedList(){
        head = NULL;
    }

    void traverseNode(){
        if(head == NULL)
        {
            cout << "Empty Linked List!";
            return;
        }
        current = head;
        while (current != NULL)
        { 
            // cout << current->data;
            current = current->next;
        }
        cout << endl;
    }

  int getLength(){
        int count=0;
        if(head == NULL)
        {
            cout << "Empty Linked List!";
            return count;
        }
        current = head;
        while (current != NULL)
        { 
            // cout << current->data;
            current = current->next;
            count++;
        }
        cout << endl;
        return count;
    }

    void insertNodeFront(int data){
        Node* node = new Node(data);
        /*
        Node* node = new Node;
        node->data = data;
        */
        node->next = head;
        head = node;
    }

    void insertNodeEnd(int data){
        Node* node = new Node(data);
        /*
        Node* node = new Node;
        node->data = data;
        node->next = NULL:
        */
       current = head;
       if(current != NULL)
       {
            while(current->next != NULL)
            {
                current = current->next;           
            }
            current->next = node;
       }
       else{
            head = node;
       }
    }

    void insertNodeWill(int data){
        Node* node = new Node(data);
        /*
        node->data = data;
        node->next = NULL;
        */
       current = head;
       if (current != NULL)
       {
            while (current->next != NULL)
            {
                if (current->data == data)
                {
                    node->next = current->next;
                    current->next = node;
                }
                else{
                    current = current->next;
                }
            }
       }
    }

    void deleteNodeFront(int data){
        if(head == NULL)
        {
            cout << "Empty Linked List";
        }
        else
        {
            current = head;
            head = head->next;
            delete current;
        }
    }

    void deleteNodeEnd(int data){
        if(head == NULL)
        {
            cout << "Empty Linked List";
        }
        else if(head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            delete current->next;
            current->next = NULL;
        }
    }

    void deleteNodeWill(int data){
        current = head;
        Node* temp = new Node;
        while (current->next != NULL)
        {
            if(current->data == data)
            {
                temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void deleteLinkedList()
    {
        if(head!=NULL)
        {
            current = head;
            while (current->next != NULL)
            {
                current = current->next;
                delete head;
                head = current;
            }
        }
    }

    void reverseLinkedList()
    {
        if (head != NULL){
            current = head;
            Node* temp = new Node;
            temp = current;
            Node* prev = new Node;
            prev = 0;
            while(current->next != NULL)
            {
                current = current->next;
                temp->next = prev;
                prev = temp;
                temp = current;
            }
            head = prev;
        }
    }
};

int main() {
    LinkedList myList;

    myList.insertNodeFront(4);
    myList.insertNodeFront(3);
    myList.insertNodeEnd(5);
    myList.insertNodeEnd(6);

    cout << "Linked List: ";
    myList.traverseNode(); // Output: 3 4 5 6

    cout << "Length: " << myList.getLength() << endl; // Output: 4

    myList.deleteNodeFront(3);
    myList.deleteNodeEnd(6);

    cout << "Linked List after deletion: ";
    myList.traverseNode(); // Output: 4 5

    myList.reverseLinkedList();

    cout << "Reversed Linked List: ";
    myList.traverseNode(); // Output: 5 4

    myList.deleteLinkedList();

    cout << "Linked List after deletion: ";
    myList.traverseNode(); // Output: Empty Linked List

    return 0;
}

