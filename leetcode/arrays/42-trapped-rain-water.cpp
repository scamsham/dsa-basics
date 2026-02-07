/*
    https://leetcode.com/problems/trapping-rain-water/description/
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        // 0 1 0 2 1 0 1 3 2 1 2 1  ->  array of heights
        // 0 1 1 2 2 2 2 3 3 3 3 3  ->  left max array
        // 3 3 3 3 3 3 3 3 2 2 2 1  -> right max array

        // 0 1 1 2 2 2 2 3 2 2 2 1  -> min(left max, right max)
        // 0 0 1 0 1 2 1 0 0 1 0 0  -> 1 + 1 + 2 + 1 + 1 = 6  -> trapped water = min(left max, right max) - height

        int n = height.size();
        vector<int> left(n, 0), right(n, 0);
        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i]);
            right[n - i - 1] = max(right[n - i], height[n - i - 1]);
        }

        int trappedWater = 0;
        for (int i = 0; i < n; i++)
        {
            trappedWater += min(left[i], right[i]) - height[i];
        }
        return trappedWater;
    }
};