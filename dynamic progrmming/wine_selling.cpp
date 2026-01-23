/*
Maximum profit from sale of wines
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> a, int i, int j, int years, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (i == j)
    {
        return years * a[j];
    }

    int leftInc = a[i] * years + maxProfit(a, i + 1, j, years + 1, dp);
    int rightInc = a[j] * years + maxProfit(a, i, j - 1, years + 1, dp);
    return dp[i][j] = max(leftInc, rightInc);
}

int main()
{
    vector<int> a = {2, 4, 6, 2, 5};
    // ans - 64
    int n = a.size() - 1;
    int year = 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    maxProfit(a, 0, n, year, dp);
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[0][n];
    return 0;
}
