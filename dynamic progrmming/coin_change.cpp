#include <iostream>
#include <vector>

using namespace std;

int numberOfCoins(vector<int> coins, int total)
{
    vector<int> dp(total + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < total + 1; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] = 1 + min(dp[i], dp[i - coins[j]]);
            }
        }
    }
    return dp[total] == INT_MAX ? -1 : dp[total];
}

int main()
{
    vector<int> coins = {1, 5, 7, 10};
    int total = 16;
    cout << "The number of coins: " << numberOfCoins(coins, total);
    return 0;
}