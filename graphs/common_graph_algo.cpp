// ======================
// 1. Detect Cycle in Directed Graph
// ======================
#include <iostream>
#include <vector>
using namespace std;

class GraphCycle
{
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack)
    {
        visited[node] = true;
        recStack[node] = true; // mark node as being in current recursion stack

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, adj, visited, recStack))
                    return true;
            }
            else if (recStack[neighbor])
            {
                // If neighbor is already in the recursion stack, cycle detected
                return true;
            }
        }

        recStack[node] = false; // remove from recursion stack
        return false;
    }

    bool hasCycle(int n, vector<vector<int>> &adj)
    {
        vector<bool> visited(n, false);
        vector<bool> recStack(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, recStack))
                    return true;
            }
        }
        return false;
    }
};

// ======================
// 2. Kahn's Algorithm (Topological Sort using BFS)
// ======================
#include <queue>

class KahnTopoSort
{
public:
    vector<int> topologicalSort(int n, vector<vector<int>> &adj)
    {
        vector<int> inDegree(n, 0);

        // Step 1: Calculate in-degrees for each node
        for (int i = 0; i < n; i++)
        {
            for (int neighbor : adj[i])
            {
                inDegree[neighbor]++;
            }
        }

        queue<int> q;
        // Step 2: Push nodes with in-degree 0 into the queue
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> topoOrder;

        // Step 3: Process the queue
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            for (int neighbor : adj[node])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        // If topoOrder doesn't contain all nodes, there's a cycle
        if (topoOrder.size() != n)
            return {}; // return empty if cycle exists

        return topoOrder;
    }
};

// ======================
// 3. Clone Graph (Leetcode 133)
// ======================
#include <unordered_map>

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node() : val(0), neighbors({}) {}
    Node(int _val) : val(_val), neighbors({}) {}
    Node(int _val, vector<Node *> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class GraphClone
{
public:
    unordered_map<Node *, Node *> visited;

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        if (visited.find(node) != visited.end())
        {
            return visited[node];
        }

        Node *clone = new Node(node->val);
        visited[node] = clone;

        for (Node *neighbor : node->neighbors)
        {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};

int main()
{

    return 0;
}