// To find max profit from rod of size n
#include <iostream>
#include <vector>
using namespace std;

int cutRodRecur(int i, vector<int> &price, vector<int> &dp)
{

    // Base case
    if (i == 0)
        return 0;

    // If value is dpized
    if (dp[i - 1] != -1)
        return dp[i - 1];

    int ans = 0;

    // Find maximum value for each cut.
    // Take value of rod of length j, and
    // recursively find value of rod of
    // length (i-j).
    for (int j = 1; j <= i; j++)
    {
        ans = max(ans, price[j - 1] + cutRodRecur(i - j, price, dp));
    }

    return dp[i - 1] = ans;
}

int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<int> dp(price.size(), -1);
    return cutRodRecur(n, price, dp);
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price);
    return 0;
}
