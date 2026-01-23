#include <iostream>
#include <vector>

using namespace std;

bool compare(vector<int> v1, vector<int> v2)
{
    return v1[2] < v2[2];
}

int findMaxHeight(vector<vector<int>> boxes)
{
    int n = boxes.size();
    vector<int> dp(n, 0);

    dp[0] = boxes[0][2];

    int maxHeight = max(0, dp[0]);

    for (int i = 0; i < n; i++)
    {
        dp[i] = boxes[i][2];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // If the width and length of boxes kept above are less
            if (boxes[i][0] > boxes[j][0] && boxes[i][1] > boxes[j][1])
            {
                dp[i] = max(dp[i], boxes[i][2] + dp[j]);
                maxHeight = max(maxHeight, dp[i]);
            }
        }
    }
    return maxHeight;
}

int main()
{
    vector<vector<int>> boxes = {
        {2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4}, {2, 2, 1}, {4, 4, 5}};

    sort(boxes.begin(), boxes.end(), compare);

    for (int i = 0; i < boxes.size(); i++)
    {
        cout << boxes[i][0] << ", " << boxes[i][1] << " " << boxes[i][2] << endl;
    }

    cout << "The maximum height by stacking boxes with constraints that bigger boxes should be at bottom are: " << findMaxHeight(boxes);

    return 0;
}