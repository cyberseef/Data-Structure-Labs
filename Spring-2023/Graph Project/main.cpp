#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits.h>
#include <map>
#include <cstdlib>

using namespace std;

const int ROWS = 20;
const int COLS = 20;
class Node
{
public:
    int id;
    int reward_score;
    int count;
    int height;
    Node *left, *right;

    Node(int id, int reward_score)
        : id(id), reward_score(reward_score), count(1), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree
{
public:
    AVLTree() : root(nullptr) {}

    void insert(int id, int reward_score)
    {
        root = insert(root, id, reward_score);
    }

    void remove(int id)
    {
        root = remove(root, id);
    }

private:
    Node *root;

    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int balanceFactor(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node *node)
    {
        if (node != nullptr)
        {
            node->height = max(height(node->left), height(node->right)) + 1;
        }
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node *insert(Node *node, int id, int reward_score)
    {
        if (node == nullptr)
        {
            return new Node(id, reward_score);
        }

        if (id < node->id)
        {
            node->left = insert(node->left, id, reward_score);
        }
        else if (id > node->id)
        {
            node->right = insert(node->right, id, reward_score);
        }
        else
        {
            node->count++;
            return node;
        }

        updateHeight(node);

        int balance = balanceFactor(node);

        if (balance > 1)
        {
            if (id < node->left->id)
            {
                return rotateRight(node);
            }
            else
            {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balance < -1)
        {
            if (id > node->right->id)
            {
                return rotateLeft(node);
            }
            else
            {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    Node *remove(Node *node, int id)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (id < node->id)
        {
            node->left = remove(node->left, id);
        }
        else if (id > node->id)
        {
            node->right = remove(node->right, id);
        }
        else
        {
            if (node->count > 1)
            {
                node->count--;
            }
            else
            {
                if (node->left == nullptr || node->right == nullptr)
                {
                    Node *temp = node->left ? node->left : node->right;

                    if (temp == nullptr)
                    {
                        temp = node;
                        node = nullptr;
                    }
                    else
                    {
                        *node = *temp;
                    }

                    delete temp;
                }
                else
                {
                    Node *temp = minValueNode(node->right);
                    node->id = temp->id;
                    node->reward_score = temp->reward_score;
                    node->count = temp->count;
                    temp->count = 1;

                    node->right = remove(node->right, temp->id);
                }
            }
        }

        if (node == nullptr)
        {
            return node;
        }

        updateHeight(node);

        int balance = balanceFactor(node);

        if (balance > 1)
        {
            if (balanceFactor(node->left) >= 0)
            {
                return rotateRight(node);
            }
            else
            {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balance < -1)
        {
            if (balanceFactor(node->right) <= 0)
            {
                return rotateLeft(node);
            }
            else
            {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }
};

class UnionFind
{
public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int Find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    bool Union(int x, int y)
    {
        int rootX = Find(x);
        int rootY = Find(y);

        if (rootX == rootY)
        {
            return false;
        }

        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootX] = rootY;
            if (rank[rootX] == rank[rootY])
            {
                ++rank[rootY];
            }
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

struct Edge
{
    int src, dest, weight;
};
vector<Edge> getEdgesFromPred(const vector<int> &pred, int start, int end)
{
    vector<Edge> edges;
    int current = end;

    while (current != start)
    {
        int parent = pred[current];
        edges.push_back({parent, current, 1}); // Assuming all edge weights are 1
        current = parent;
    }

    return edges;
}

vector<vector<int>> convertToAdjMatrix(char graph[][COLS], int rows, int cols)
{
    const int INF = 1e9;
    const int OBSTACLE = 100;

    vector<vector<int>> adj(rows * cols, vector<int>(rows * cols, INF));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int u = i * cols + j;
            adj[u][u] = 0;

            vector<pair<int, int>> neighbors = {
                {i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};

            for (const auto &neighbor : neighbors)
            {
                int ni = neighbor.first;
                int nj = neighbor.second;
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
                {
                    int v = ni * cols + nj;
                    int weight = (graph[ni][nj] == '@') ? OBSTACLE : 1;
                    adj[u][v] = weight;
                }
            }
        }
    }

    return adj;
}

vector<pair<int, int>> prim(const vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        int u = -1;

        for (int j = 0; j < n; ++j)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; ++v)
        {
            if (adj[u][v] && !visited[v] && adj[u][v] < dist[v])
            {
                dist[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    vector<pair<int, int>> edges;
    for (int i = 1; i < n; ++i)
    {
        edges.push_back({parent[i], i});
    }
    return edges;
}

vector<int> dijkstra(const vector<vector<int>> &adj, int start)
{
    const int INF = 1e9;
    int n = adj.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (int v = 0; v < n; ++v)
        {
            if (adj[u][v] != INF && !visited[v])
            {
                int newDist = dist[u] + adj[u][v];
                if (newDist < dist[v])
                {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
    }

    return dist;
}

vector<Edge> adjMatrixToEdgeList(const vector<vector<int>> &adj)
{
    vector<Edge> edges;
    int n = adj.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (adj[i][j])
            {
                edges.push_back({i, j, adj[i][j]});
            }
        }
    }
    return edges;
}

vector<Edge> kruskal(vector<Edge> &edges, int n)
{
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    vector<Edge> mst_edges;
    UnionFind uf(n);

    for (const Edge &edge : edges)
    {
        if (uf.Union(edge.src, edge.dest))
        {
            mst_edges.push_back(edge);
        }
    }

    return mst_edges;
}

vector<int> retrievePath(const vector<int> &dist, int start, int end)
{
    vector<int> path;

    if (dist[end] == INT_MAX)
    {
        return path; // No path found
    }

    path.push_back(end);
    int cur = end;

    while (cur != start)
    {
        for (int i = 0; i < dist.size(); ++i)
        {
            if (dist[cur] - dist[i] == 1)
            {
                path.push_back(i);
                cur = i;
                break;
            }
        }
    }

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    char graph[ROWS][COLS];

    //--------------------------------------Read Map from file------------------------------------------

    ifstream inputFile("C:/Users/Cyberseef/Desktop/touseef_DS/output.txt");

    if (!inputFile.is_open())
    {
        cout << "Failed to open the file." << endl;
        return 0;
    }

    for (int i = 0; i < ROWS; i++)
    {
        string line;
        getline(inputFile, line);

        istringstream lineStream(line);
        for (int j = 0; j < COLS; j++)
        {
            string cell;
            getline(lineStream, cell, ' ');

            graph[i][j] = cell[0];
        }
    }

    inputFile.close();

    int rows = ROWS;
    int cols = COLS;

    int parent[5][5];

    int score = 0;
    AVLTree inventory;

    cout << "Welcome to the Enchanted Forest!" << endl;

    while (true)
    {
        cout << "1. Shortest path from current location (0,0)" << endl;
        cout << "2. Shortest path from custom location" << endl;
        cout << "3. Minimum spanning tree (Prim's algorithm)" << endl;
        cout << "4. Minimum spanning tree (Kruskal's algorithm)" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            // Convert the graph to an adjacency matrix
            vector<vector<int>> adj = convertToAdjMatrix(graph, rows, cols);

            // Calculate the shortest path distances from (0,0) using Dijkstra's algorithm
            int start = 0;
            vector<int> dist = dijkstra(adj, start);

            // Get the shortest path distance to the crystal
            int crystal_pos = -1;
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    if (graph[i][j] == '$')
                    {
                        crystal_pos = i * cols + j;
                        break;
                    }
                }
                if (crystal_pos != -1)
                    break;
            }
            int shortest_path_1 = dist[crystal_pos];

            cout << "Shortest path: " << shortest_path_1 << endl;

            // Traverse the shortest path and update the score and inventory
            vector<int> path(crystal_pos);
            int current = crystal_pos;
            map<char, int> inventory;
            while (current != start)
            {
                path.push_back(current);
                int parent = -1;
                for (int i = 0; i < adj.size(); ++i)
                {
                    if (dist[i] + adj[i][current] == dist[current])
                    {
                        parent = i;
                        break;
                    }
                }

                int x1 = current / cols, y1 = current % cols;
                int x2 = parent / cols, y2 = parent % cols;

                char symbol = graph[x1][y1];
                cout << symbol << "->";
                if (symbol >= 'A' && symbol <= 'Z')
                {
                    score += symbol - 'A' + 1;
                    inventory[symbol]++;
                }

                current = parent;
            }

            cout << "\nScore: " << score << endl;
            cout << "Inventory: " << endl;
            for (auto &item : inventory)
            {
                cout << item.first << ": " << item.second << endl;
            }
        }

        else if (choice == 2)
        {
            // Convert the graph to an adjacency matrix
            vector<vector<int>> adj = convertToAdjMatrix(graph, rows, cols);

            // Get custom starting location from the user
            int start_x, start_y;
            cout << "Enter custom starting location (x y):" << endl;
            cout << "x: ";
            cin >> start_x;
            cout << "y: ";
            cin >> start_y;

            // Validate the input
            if (start_x < 0 || start_x >= rows || start_y < 0 || start_y >= cols)
            {
                cerr << "Invalid custom location. Please try again." << endl;
                return 1;
            }

            // Calculate the shortest path distances from the custom location using Dijkstra's algorithm
            int start = start_x * cols + start_y;
            vector<int> dist = dijkstra(adj, start);

            // Get the shortest path distance to the crystal
            int crystal_pos = -1;
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    if (graph[i][j] == '$')
                    {
                        crystal_pos = i * cols + j;
                        break;
                    }
                }
                if (crystal_pos != -1)
                    break;
            }
            int shortest_path_1 = dist[crystal_pos];

            cout << "Shortest path: " << shortest_path_1 << endl;

            // Traverse the shortest path and update the score and inventory
            vector<int> path(crystal_pos);
            int current = crystal_pos;
            map<char, int> inventory;
            vector<bool> visited(adj.size(), false);
            while (current != start)
            {
                path.push_back(current);
                visited[current] = true;
                int parent = -1;
                for (int i = 0; i < adj.size(); ++i)
                {
                    if (!visited[i] && adj[current][i] != INT_MAX && dist[i] + adj[current][i] == dist[current])
                    {
                        parent = i;
                        break;
                    }
                }
                if (parent == -1)
                {
                    cerr << "Path not found. Exiting." << endl;
                    return 1;
                }

                int x1 = current / cols, y1 = current % cols;
                int x2 = parent / cols, y2 = parent % cols;

                char symbol = graph[x1][y1];
                cout << symbol << "->";
                if (symbol >= 'A' && symbol <= 'Z')
                {
                    score += symbol - 'A' + 1;
                    inventory[symbol]++;
                }

                current = parent;
            }

            cout << "\nScore: " << score << endl;
            cout << "Inventory: " << endl;
            for (auto &item : inventory)
            {
                cout << item.first << ": " << item.second << endl;
            }
        }

        else if (choice == 3)
        {
            // Convert the graph to an adjacency matrix
            vector<vector<int>> adj = convertToAdjMatrix(graph, rows, cols);
            vector<pair<int, int>> mst_edges = prim(adj);
            int mst_cost = 0;
            map<char, int> inventory;

            for (const auto &edge : mst_edges)
            {
                int u = edge.first;
                int v = edge.second;
                mst_cost += adj[u][v];

                // Get the coordinates of the two vertices of the edge
                int x1 = u / cols, y1 = u % cols;
                int x2 = v / cols, y2 = v % cols;

                // Update the score and inventory for the edge
                for (int r : {x1, x2})
                {
                    for (int c : {y1, y2})
                    {
                        char symbol = graph[r][c];
                        cout << symbol << "->";
                        if (symbol >= 'A' && symbol <= 'Z')
                        {
                            score += symbol - 'A' + 1;
                            inventory[symbol]++;
                        }
                    }
                }
            }

            cout << "\nMinimum spanning tree cost (Prim's algorithm): " << mst_cost << endl;
            cout << "Score: " << score << endl;
            cout << "Inventory: " << endl;
            for (auto &item : inventory)
            {
                cout << item.first << ": " << item.second << endl;
            }
        }

        else if (choice == 4)
        {
            // Convert the graph to an adjacency matrix
            vector<vector<int>> adj = convertToAdjMatrix(graph, rows, cols);
            vector<Edge> edges = adjMatrixToEdgeList(adj);
            vector<Edge> mst_edges = kruskal(edges, rows * cols);
            int mst_cost = 0;
            map<char, int> inventory;

            for (const auto &edge : mst_edges)
            {
                mst_cost += edge.weight;

                // Get the coordinates of the two vertices of the edge
                int u = edge.src;
                int v = edge.dest;
                int x1 = u / cols, y1 = u % cols;
                int x2 = v / cols, y2 = v % cols;

                // Update the score and inventory for the edge
                for (int r : {x1, x2})
                {
                    for (int c : {y1, y2})
                    {
                        char symbol = graph[r][c];
                        cout << symbol << "->";
                        if (symbol >= 'A' && symbol <= 'Z')
                        {
                            score += symbol - 'A' + 1;
                            inventory[symbol]++;
                        }
                    }
                }
            }

            cout << "\nMinimum spanning tree cost (Kruskal's algorithm): " << mst_cost << endl;
            cout << "Score: " << score << endl;
            cout << "Inventory: " << endl;
            for (auto &item : inventory)
            {
                cout << item.first << ": " << item.second << endl;
            }
        }

        else if (choice == 5)
        {
            break;
        }

        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    cout << "Final score: " << score << endl;

    return 0;
}
