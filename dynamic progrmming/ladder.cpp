#include <iostream>
#include <vector>

using namespace std;

int climbLadder(int n, int k)
{
    if (n < 0)
        return 0;
    if (n == 0)
    {
        return 1;
    }
    int count = 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int j = 0; j <= n; j++)
    {
        for (int i = 1; i <= k; i++)
        {
            if (j - i >= 0)
                dp[j] += dp[j - i];
        }
    }
    return dp[n];
}

int main()
{
    int ladder_size = 4;
    int num_jumps = 3;
    cout << "Number of ways to climb ladder: " << climbLadder(ladder_size, num_jumps);
}