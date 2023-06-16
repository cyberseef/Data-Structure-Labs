#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void traverse() {
        if (head == nullptr) {
            cout << "Empty Double Linked List" << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int getLength() {
        int count = 0;
        if (head == nullptr) {
            cout << "Empty Double Linked List" << endl;
            return count;
        }

        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void insertNodeFront(int data) {
        Node* node = new Node(data);

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void insertNodeEnd(int data) {
        Node* node = new Node(data);

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void deleteNodeFront() {
        if (head == nullptr) {
            cout << "Empty Double Linked List" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    void deleteNodeEnd() {
        if (head == nullptr) {
            cout << "Empty Double Linked List" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void deleteLinkedList() {
        if (head == nullptr) {
            cout << "Empty Double Linked List" << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    DoubleLinkedList dll;

    dll.insertNodeFront(1);
    dll.insertNodeFront(2);
    dll.insertNodeEnd(3);
    dll.insertNodeEnd(4);

    dll.traverse(); // Output: 2 1 3 4

    dll.deleteNodeFront();
    dll.deleteNodeEnd();

    dll.traverse(); // Output: 1 3

    dll.deleteLinkedList();

    dll.traverse(); // Output: Empty Double Linked List

    return 0;
}
