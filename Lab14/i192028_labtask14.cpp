#include <iostream>
using namespace std;

class dijkstra
{
    int n;
    int cost[10][10];
    int dist[10];
    int visited[10];
    int source;
    int min;
    int nextnode;

public:
    void init()
    {
        cout << "Enter the number of nodes: ";
        cin >> n;
        cout << "Enter the cost matrix: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> cost[i][j];
            }
        }
        cout << "Enter the source node: ";
        cin >> source;
    }

    int GetNearestNode()
    {
        min = 999;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] < min && !visited[i])
            {
                min = dist[i];
                nextnode = i;
            }
        }
        return nextnode;
    }

    void Dijkstra()
    {
        for (int i = 0; i < n; i++)
        {
            dist[i] = cost[source][i];
            visited[i] = 0;
        }
        dist[source] = 0;
        visited[source] = 1;
        for (int i = 0; i < n - 1; i++)
        {
            nextnode = GetNearestNode();
            visited[nextnode] = 1;
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    if (min + cost[nextnode][i] < dist[i])
                    {
                        dist[i] = min + cost[nextnode][i];
                    }
                }
            }
        }
    }

    void Display()
    {
        int i;
        cout << "Shortest path from source node: " << endl;
        for (i = 0; i < n; i++)
        {
            if (i != source)
            {
                cout << source << "->" << i << "=" << dist[i] << endl;
            }
        }
        cout << "Path: " << source;
        for (int j = i - 1; j > 0; j--)
        {
            if (i != source)
            {
                cout << "->" << j;
            }
        }
    }
};

int main()
{
    dijkstra d;
    d.init();
    d.Dijkstra();
    d.Display();
    return 0;
}