#include <bits/stdc++.h>
using namespace std;

bool dfsHelper(int v, unordered_map<int, vector<int>> um, vector<bool> &vis, unordered_map<int, int> &parent)
{
    vis[v] = true;

    for (int x : um[v])
    {
        if (!vis[x])
        {
            parent[x] = v;
            if (dfsHelper(x, um, vis, parent))
            {
                return true;
            }
        }
        else if (x != parent[v])
        {
            // x is visited and is not the parent of v -> cycle found
            return true;
        }
    }
    return false;
}

bool contains_cycle(int V, vector<pair<int, int>> edges)
{
    // Complete this method
    vector<bool> visited(V + 1, false);
    unordered_map<int, int> parent;
    unordered_map<int, vector<int>> um;
    for (pair<int, int> p : edges)
    {
        um[p.first].push_back(p.second);
    }
    parent[0] = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool ans = dfsHelper(i, um, visited, parent);
            if (ans == true)
                return true;
        }
    }
    return false;
}