#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, int &size)
{
    visited[node] = true;
    size++;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, size);
        }
    }
}

int count_pairs(int N, vector<pair<int, int>> astronauts)
{
    vector<vector<int>> adj(N);
    for (auto &p : astronauts)
    {
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }

    vector<bool> visited(N, false);
    vector<int> component_sizes;

    // Find connected components
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            int size = 0;
            dfs(i, adj, visited, size);
            component_sizes.push_back(size);
        }
    }

    // Calculate total pairs
    long long total_pairs = (1LL * N * (N - 1)) / 2;
    long long same_country_pairs = 0;

    for (int size : component_sizes)
    {
        same_country_pairs += (1LL * size * (size - 1)) / 2;
    }

    return total_pairs - same_country_pairs;
}

int main()
{
    int N = 5;
    vector<pair<int, int>> astronauts = {{0, 1}, {2, 3}, {0, 4}};

    cout << count_pairs(N, astronauts) << endl; // Expected output: 6
    return 0;
}
