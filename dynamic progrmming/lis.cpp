#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> a)
{
    int n = a.size();
    vector<int> dp(n, 1);
    dp[0] = 1;

    // We use this variable because what if the last number in the array is not the greatest
    int length = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(1 + dp[j], dp[i]);
                length = max(length, dp[i]);
            }
        }
    }
    return length;
}

int main()
{

    vector<int> a = {50, 8, 40, 10, 8, 30, 100, 9};
    cout << lis(a) << endl;

    return 0;
}