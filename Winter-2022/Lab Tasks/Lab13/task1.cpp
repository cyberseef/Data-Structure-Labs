#include <iostream>
using namespace std;

class Graph
{
private:
    bool **adjMatrix;
    int numVertices;

public:
    Graph(int numVertices);
    ~Graph();
    void addEdge(int i, int j);
    void removeEdge(int i, int j);
    bool isEdge(int i, int j);
    void printGraph();
};

Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;
    adjMatrix = new bool *[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        adjMatrix[i] = new bool[numVertices];
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = false;
    }
}

Graph::~Graph()
{
    for (int i = 0; i < numVertices; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void Graph::addEdge(int i, int j)
{
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
}

void Graph::removeEdge(int i, int j)
{
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
}

bool Graph::isEdge(int i, int j)
{
    return adjMatrix[i][j];
}

void Graph::printGraph()
{
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.printGraph();
    return 0;
}