#include <iostream>

using namespace std;

int catalan(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
        return dp[n];

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int left = catalan(i - 1, dp);
        int right = catalan(n - i, dp);
        ans += left * right;
    }

    dp[n] = ans;
    return dp[n];
}

int main()
{
    // This is also the code to check number of BSTs to generate from number n
    int n = 6;
    vector<int> dp(n + 1, -1);
    cout << catalan(n, dp);
}