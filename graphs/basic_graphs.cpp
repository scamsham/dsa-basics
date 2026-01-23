#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

class Node
{
public:
    string data;
    list<string> edges;
    Node(string s)
    {
        this->data = s;
    }
};

class Graph
{
    unordered_map<string, Node *> um;

public:
    Graph(vector<string> cities)
    {
        for (string s : cities)
        {
            um[s] = new Node(s);
        }
    }

    void addEdges(string x, string y, bool bidir = false)
    {
        um[x]->edges.push_back(y);
        if (bidir)
        {
            um[y]->edges.push_back(x);
        }
    }

    void printGraph()
    {
        for (auto x : um)
        {
            auto city = x.first;
            cout << city << " --> ";
            Node *nodes = x.second;
            for (auto nbrs : nodes->edges)
            {
                cout << nbrs << ", ";
            }
            cout << endl;
        }
    }

    void printBfs(string startingPoint)
    {
        unordered_map<string, bool> visited;
        queue<string> q;
        unordered_map<string, string> parent;
        unordered_map<string, int> distance;
        for (const auto &pair : um)
        { // assuming 'um' is accessible and holds the vertices
            distance[pair.first] = -1;
        }
        // Initialize
        q.push(startingPoint);
        parent[startingPoint] = startingPoint;
        distance[startingPoint] = 0;
        while (!q.empty())
        {
            cout << q.front() << ", ";
            string temp = q.front();
            q.pop();
            visited[temp] = true;
            for (string s : um[temp]->edges)
            {
                if (!visited[s])
                {
                    q.push(s);
                    visited[s] = true;
                    parent[s] = temp;
                    distance[s] = distance[temp] + 1;
                }
            }
        }

        // Distance
        for (auto x : distance)
        {
            cout << x.first << " --> " << x.second << endl;
        }
        int count = 0;
        string dest = "Chicago";
        while (dest != startingPoint)
        {
            count++;
            dest = parent[dest];
        }
        cout << startingPoint << " to Chicago is: " << count << " stops.";
    }
};

int main()
{
    vector<string> cities = {"New York", "Paris", "SF", "Vancouver", "Navi Mumbai", "Hyderabad", "Chicago"};
    Graph g(cities);

    g.addEdges("New York", "SF");
    g.addEdges("Vancouver", "SF", true);
    g.addEdges("Vancouver", "New York", true);
    g.addEdges("Paris", "SF");
    g.addEdges("Navi Mumbai", "Paris", true);
    g.addEdges("Hyderabad", "SF", true);
    g.addEdges("New York", "Navi Mumbai", true);
    g.addEdges("Paris", "Chicago", true);

    g.printGraph();
    cout << endl;
    g.printBfs("New York");

    return 0;
}