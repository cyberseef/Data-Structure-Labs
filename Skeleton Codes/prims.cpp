#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

class Graph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight)); // Add this line for an undirected graph
    }

    int prim() {
        vector<bool> visited(numVertices, false);
        vector<int> key(numVertices, INF);
        vector<int> parent(numVertices, -1);

        // Priority queue to store vertices and their corresponding key values
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int source = 0;
        pq.push(make_pair(0, source));
        key[source] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            visited[u] = true;

            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (visited[v] == false && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                }
            }
        }

        int minCost = 0;
        for (int i = 1; i < numVertices; ++i) {
            minCost += key[i];
        }

        return minCost;
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

    int minCost = graph.prim();

    cout << "Minimum cost of the minimum spanning tree: " << minCost << endl;

    return 0;
}
