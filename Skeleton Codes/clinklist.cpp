#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    void traverse() {
        if (head == nullptr) {
            cout << "Empty Circular Linked List" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    int getLength() {
        int count = 0;
        if (head == nullptr) {
            cout << "Empty Circular Linked List" << endl;
            return count;
        }

        Node* current = head;
        do {
            count++;
            current = current->next;
        } while (current != head);
        return count;
    }

    void insertNodeFront(int data) {
        Node* node = new Node(data);

        if (head == nullptr) {
            head = node;
            node->next = head;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = node;
            node->next = head;
            head = node;
        }
    }

    void insertNodeEnd(int data) {
        Node* node = new Node(data);

        if (head == nullptr) {
            head = node;
            node->next = head;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = node;
            node->next = head;
        }
    }

    void deleteNode(int data) {
        if (head == nullptr) {
            cout << "Empty Circular Linked List" << endl;
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            if (head->next == head) {
                head = nullptr;
            } else {
                Node* current = head;
                while (current->next != head) {
                    current = current->next;
                }
                current->next = head->next;
                head = head->next;
            }
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        while (current->next != head) {
            prev = current;
            current = current->next;
            if (current->data == data) {
                prev->next = current->next;
                delete current;
                return;
            }
        }

        cout << "Node with data " << data << " not found" << endl;
    }

    void deleteLinkedList() {
        if (head == nullptr) {
            cout << "Empty Circular Linked List" << endl;
            return;
        }

        Node* current = head;
        Node* next = nullptr;
        while (current->next != head) {
            next = current->next;
            delete current;
            current = next;
        }
        delete current;
        head = nullptr;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertNodeFront(1);
    cll.insertNodeFront(2);
    cll.insertNodeEnd(3);
    cll.insertNodeEnd(4);

    cll.traverse(); // Output: 2 1 3 4

    cout << "Length: " << cll.getLength() << endl; // Output: 4

    cll.deleteNode(3);
    cll.deleteNode(2);

    cll.traverse(); // Output: 1 4

    cll.deleteLinkedList();

    cll.traverse(); // Output: Empty Circular Linked List

    return 0;
}
