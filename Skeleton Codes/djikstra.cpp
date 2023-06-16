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
        // Uncomment the following line if the graph is undirected
        // adjList[dest].push_back(make_pair(src, weight));
    }

    vector<int> dijkstra(int source) {
        vector<int> dist(numVertices, INF);
        dist[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, source));

        while (!pq.empty()) {
            int u = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();

            if (currDist > dist[u])
                continue;

            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph graph(6);

    // Add edges with weights
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 1);
    graph.addEdge(3, 5, 5);
    graph.addEdge(4, 5, 2);

    int source = 0;
    vector<int> shortestDistances = graph.dijkstra(source);

    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < shortestDistances.size(); ++i) {
        cout << "Vertex " << i << ": ";
        if (shortestDistances[i] == INF)
            cout << "INF";
        else
            cout << shortestDistances[i];
        cout << endl;
    }

    return 0;
}
