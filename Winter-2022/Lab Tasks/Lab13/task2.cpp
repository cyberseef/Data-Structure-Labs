#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
};

class AdjList
{
public:
    Node *head;
    void Insert(Node *NewNode);
    void Display();
};

class Graph
{
public:
    int maxVertices;
    int noOfVertices;
    AdjList *list = NULL;
    Graph(int maxVertices);
    ~Graph();
    Node *createVertex(int data);
    void insertEdge(int src, int dest);
    void showGraphStructure();
};

Graph::Graph(int maxVertices)
{
    this->maxVertices = maxVertices;
    noOfVertices = 0;
    list = new AdjList[maxVertices];
}

Graph::~Graph()
{
    delete[] list;
}

Node *Graph::createVertex(int data)
{
    Node *NewNode = new Node;
    NewNode->data = data;
    NewNode->next = NULL;
    return NewNode;
}

void Graph::insertEdge(int src, int dest)
{
    Node *NewNode = createVertex(dest);
    src = src - 1;
    list[src].Insert(NewNode);
}

void Graph::showGraphStructure()
{
    for (int i = 0; i < maxVertices; i++)
    {
        cout << "Vertex " << i << " is connected to: ";
        list[i].Display();
        cout << endl;
    }
}

void AdjList::Insert(Node *NewNode)
{
    if (head == NULL)
    {
        head = NewNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NewNode;
    }
}

void AdjList::Display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Graph g(4);
    g.insertEdge(1, 3);
    break;
    g.showGraphStructure();
    return 0;
}