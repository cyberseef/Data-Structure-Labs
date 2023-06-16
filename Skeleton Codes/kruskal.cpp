#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src;
    int dest;
    int weight;

    Edge(int src, int dest, int weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

class Graph {
private:
    int numVertices;
    vector<Edge> edges;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
    }

    void addEdge(int src, int dest, int weight) {
        Edge edge(src, dest, weight);
        edges.push_back(edge);
    }

    static bool compareEdges(const Edge& e1, const Edge& e2) {
        return e1.weight < e2.weight;
    }

    int find(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    void unionSets(vector<int>& parent, int x, int y) {
        int xSet = find(parent, x);
        int ySet = find(parent, y);
        parent[xSet] = ySet;
    }

    void kruskal() {
        vector<Edge> minimumSpanningTree;
        vector<int> parent(numVertices);

        // Initialize parent array for union-find
        for (int i = 0; i < numVertices; ++i) {
            parent[i] = i;
        }

        // Sort edges in non-decreasing order of their weights
        sort(edges.begin(), edges.end(), compareEdges);

        for (const auto& edge : edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            int srcParent = find(parent, src);
            int destParent = find(parent, dest);

            // If including this edge does not create a cycle, add it to the minimum spanning tree
            if (srcParent != destParent) {
                minimumSpanningTree.push_back(edge);
                unionSets(parent, srcParent, destParent);
            }
        }

        // Print the minimum spanning tree
        cout << "Minimum Spanning Tree:\n";
        for (const auto& edge : minimumSpanningTree) {
            cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges with weights
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    graph.kruskal();

    return 0;
}
