#include <iostream>
#include <vector>

using namespace std;

int findMinimumJumps(vector<int> &arr, int i, int n, vector<int> &dp)
{
    if (i >= n - 1)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int count = INT_MAX;

    for (int k = i + 1; k <= i + arr[i] && k < n; k++)
    {
        int jumps = findMinimumJumps(arr, k, n, dp);
        count = min(jumps + 1, count);
    }

    dp[i] = count;
    return dp[i];
}

int main()
{
    vector<int> arr = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5};
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    cout << findMinimumJumps(arr, 0, n, dp);

    return 0;
}