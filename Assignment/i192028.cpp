#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int adjancent[100][100];
string city[100];
int COST[100][100];
int DIST[100];
bool VISITED[100];
int PARENT[100];

void init()
{
    for (int i = 0; i < 100; i++)
    {
        PARENT[i] = i;
        DIST[i] = 5000;
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i == j)
            {
                COST[i][j] = 0;
            }
            else if (adjancent[i][j] != 0)
            {
                COST[i][j] = adjancent[i][j];
            }
            else
            {
                COST[i][j] = 5000;
            }
        }
    }
}

int minimum(int index)
{
    int minval = 5000;
    int minv = 0;
    for (int i = 0; i < index; i++)
    {
        if (VISITED[i] != true && DIST[i] < minval && DIST[i] != 0)
        {
            minval = DIST[i];
            minv = i;
        }
    }
    return minv;
}

void shortest(int src, int index)
{
    init();

    DIST[src] = 0;

    for (int i = 0; i < index; i++)
    {
        int nearest = minimum(index);
        VISITED[nearest] = true;

        for (int adj = 0; adj < index; adj++)
        {
            if (COST[nearest][adj] != 5000 && DIST[adj] > (DIST[nearest] + COST[nearest][adj]))
            {

                DIST[adj] = DIST[nearest] + COST[nearest][adj];
                PARENT[adj] = nearest;
            }
        }
    }
}

void SHORTESTPATH(int i, int s, int index)
{
    cout << "DESTINATION : " << city[i] << endl;
    cout << "COST        : " << DIST[i] << "      " << endl;
    cout << "PATH        : " << city[i] << " ";
    int p = PARENT[i];
    while (p != s)
    {
        cout << " <- " << city[p] << "  ";
        p = PARENT[p];

        if (p == PARENT[p])
        {
            break;
        }
    }
    cout << " <- " << city[s];
    cout << endl;

    for (int f = 0; f < index; f++)
    {
        cout << " " << PARENT[f];
    }
}

void allnodes(int s, int index)
{
    for (int i = 0; i < index; i++)
    {
        cout << city[i] << "             " << DIST[i] << "                     "
             << "   ";
        cout << city[i] << "  ";
        int p = PARENT[i];

        while (p != s)
        {
            cout << "  <- " << city[p] << " ";
            int a1 = p; // for peshawar
            p = PARENT[p];

            if (p == PARENT[p])
            {
                break;
            }
        }
        cout << endl;
    }
}

void display(int l)
{
    for (int i = 0; i < l; i++)
    {
        cout << city[i] << " : ";
        for (int j = 0; j < l; j++)
        {
            cout << "  " << adjancent[i][j];
        }
        cout << endl;
    }
}

int addcity(string n, int index)
{
    city[index] = n;
    index = index + 1;
    return index;
}

int findcity(string n, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (city[i] == n)
        {
            return i;
        }
    }
}

void printsinglelink(string n, int index)
{
    string s = "";
    s = s + n;
    s = s + ":  ";
    int c1 = findcity(n, index);

    for (int j = 0; j < index; j++)
    {
        if (adjancent[c1][j] > 0)
        {
            s = s + "-> " + city[j];
        }
    }

    cout << s;
}

void addedge(string n1, string n2, int dist, int index)
{
    int c1 = findcity(n1, index);
    int c2 = findcity(n2, index);

    adjancent[c1][c2] = dist;
    adjancent[c2][c1] = dist;
}

void deletedge(string n1, string n2, int index)
{
    int c1 = findcity(n1, index);
    int c2 = findcity(n2, index);

    adjancent[c1][c2] = 0;
    adjancent[c2][c1] = 0;
}

int main()
{
    ifstream MyReadFile("C:\\Users\\SOULREAPER\\Desktop\\GraphData.csv");
    string txt;
    int currIndex = 0;
    int lastIndex = 0;

    getline(MyReadFile, txt);

    while (getline(MyReadFile, txt))
    {
        currIndex = 0;
        int i = 0;
        string cityname = "";
        string edge = "";

        while (txt[i] != ',')
        {
            cityname = cityname + txt[i];
            i++;
        }

        city[lastIndex] = cityname;
        i++;
        while (txt[i] != '\0')
        {

            if (txt[i] == ',')
            {
                int num = stoi(edge);

                adjancent[lastIndex][currIndex] = num;
                currIndex++;
                edge = "";
            }
            else
            {
                edge = edge + txt[i];
            }

            i++;
        }
        int num = stoi(edge);
        adjancent[lastIndex][currIndex] = num;
        currIndex++;
        edge = "";
        lastIndex++;
    }

    cout << endl
         << endl
         << endl;
    display(lastIndex);
    cout << endl;

    printsinglelink("Mansehra", lastIndex);
    int n = findcity("Mansehra", lastIndex);
    int n1 = findcity("Islamabad", lastIndex);
    shortest(n, lastIndex);
    SHORTESTPATH(n1, n, lastIndex);

    cout << endl;
    cout << endl;
    allnodes(n, lastIndex);
}