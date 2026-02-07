/*
    https://leetcode.com/problems/container-with-most-water/description/
*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int answer = 0;

        while (left < right)
        {
            int width = right - left;
            int currentWater = width * min(height[left], height[right]);

            answer = max(answer, currentWater);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return answer;
    }
};