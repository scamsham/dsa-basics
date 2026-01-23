#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
#include <climits>
#include <vector>

using namespace std;

class Node
{
public:
    string name;
    unordered_map<Node *, int> neighbors; // adjacency list with weights

    Node(string name)
    {
        this->name = name;
    }
};

class Compare
{
public:
    bool operator()(pair<Node *, int> &a, pair<Node *, int> &b)
    {
        return a.second > b.second; // min-heap based on distance
    }
};

int dijkstra(unordered_map<string, Node *> &graph, string start, string end)
{
    unordered_map<Node *, int> dist;
    priority_queue<pair<Node *, int>, vector<pair<Node *, int>>, Compare> pq;

    for (auto &entry : graph)
    {
        dist[entry.second] = INT_MAX;
    }

    Node *startNode = graph[start];
    dist[startNode] = 0;
    pq.push({startNode, 0});

    while (!pq.empty())
    {
        auto [current, currDist] = pq.top();
        pq.pop();

        if (current->name == end)
        {
            return currDist;
        }

        for (auto &[neighbor, weight] : current->neighbors)
        {
            int newDist = currDist + weight;
            if (newDist < dist[neighbor])
            {
                dist[neighbor] = newDist;
                pq.push({neighbor, newDist});
            }
        }
    }

    return -1; // unreachable
}

int main()
{
    unordered_map<string, Node *> graph;

    graph["A"] = new Node("A");
    graph["B"] = new Node("B");
    graph["C"] = new Node("C");
    graph["D"] = new Node("D");

    graph["A"]->neighbors[graph["B"]] = 1;
    graph["A"]->neighbors[graph["C"]] = 4;
    graph["B"]->neighbors[graph["C"]] = 2;
    graph["B"]->neighbors[graph["D"]] = 5;
    graph["C"]->neighbors[graph["D"]] = 1;

    cout << "Shortest path from A to D: " << dijkstra(graph, "A", "D") << endl;

    // Cleanup
    for (auto &entry : graph)
    {
        delete entry.second;
    }

    return 0;
}
