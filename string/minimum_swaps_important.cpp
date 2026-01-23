#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimum_swaps(vector<int> arr)
{
    int n = arr.size();
    pair<int, int> x[n];
    for (int i = 0; i < n; i++)
    {
        x[i].first = arr[i];
        x[i].second = i;
    }

    sort(x, x + n);

    vector<bool> visited(n, false);
    int cycle = 0;
    for (int i = 0; i < n; i++)
    {
        // If the element is visited or already in the right place
        if (visited[i] || x[i].second == i)
        {
            continue;
        }

        // Count number of non intersecting cycles
        // cycle = 0;
        int node = i;
        while (visited[node] != true)
        {
            visited[node] = true;
            int nextNode = x[i].second;
            cycle += 1;
            node = nextNode;
        }
    }

    return cycle;
}

int main()
{
    vector<int> arr{2, 4, 5, 1, 3, 6};
    int answer = minimum_swaps(arr);
    cout << answer << endl;
    return 0;
}
