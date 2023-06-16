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

class Graph {
private:
    int numVertices;
    Node** adjList;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjList = new Node*[numVertices];
        for (int i = 0; i < numVertices; ++i)
            adjList[i] = nullptr;
    }

    void addEdge(int src, int dest) {
        Node* newNode = new Node(dest);
        newNode->next = adjList[src];
        adjList[src] = newNode;

        // Uncomment the following lines if the graph is undirected
        // newNode = new Node(src);
        // newNode->next = adjList[dest];
        // adjList[dest] = newNode;
    }

    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Adjacency list of vertex " << i << ": ";
            Node* currNode = adjList[i];
            while (currNode) {
                cout << currNode->data << " ";
                currNode = currNode->next;
            }
            cout << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            Node* currNode = adjList[i];
            while (currNode) {
                Node* nextNode = currNode->next;
                delete currNode;
                currNode = nextNode;
            }
        }
        delete[] adjList;
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the graph
    graph.printGraph();

    return 0;
}
