#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V + 1];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    }

    int minCostBFS(int src, int dest)
    {
        queue<int> q;
        vector<bool> visited(V, false);
        vector<int> dist(V, 0);

        q.push(src);
        visited[src] = true;
        dist[src] = 0;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            for (int nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    dist[nbr] = dist[f] + 1;
                }
            }
        }
        return dist[dest];
    }
};

int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders)
{
    vector<int> board(n + 1, 0);

    // board to graph conversion
    for (auto sp : snakes)
    {
        int s = sp.first;
        int e = sp.second;
        board[s] = e - s;
    }

    for (auto lp : ladders)
    {
        int s = lp.first;
        int e = lp.second;
        board[s] = e - s;
    }

    // Graph
    Graph g(n + 1);
    for (int u = 1; u < n; u++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int v = u + dice;
            v += board[v];
            if (v <= n)
            {
                g.addEdge(u, v);
            }
        }
    }
    return g.minCostBFS(1, n);
}

int main()
{

    int n = 36;

    // Define snake endpoints: (start, end)
    vector<pair<int, int>> snakes = {
        {27, 1}, // Snake from 27 to 1
        {21, 9}, // Snake from 21 to 9
        {17, 4}, // Snake from 17 to 4
        {19, 7}  // Snake from 19 to 7
    };

    // Define ladder endpoints: (start, end)
    vector<pair<int, int>> ladders = {
        {3, 22},  // Ladder from 3 to 22
        {5, 8},   // Ladder from 5 to 8
        {11, 26}, // Ladder from 11 to 26
        {20, 29}  // Ladder from 20 to 29
    };

    int result = min_dice_throws(n, snakes, ladders);
    cout << "Minimum dice throws required: " << result << endl;

    return 0;
}