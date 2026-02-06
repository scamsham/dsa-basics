/*
    https://leetcode.com/problems/3sum/description/?source=submission-noac
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        set<vector<int>> s;
        vector<vector<int>> result;

        if (n < 3)
        {
            return result;
        }

        sort(nums.begin(), nums.end());

        // -4 -1 -1 0 1 2
        // -4 2 (-1 -1 0 1)
        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    s.insert({nums[i], nums[left], nums[right]});
                    right--;
                    left++;
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }

        for (auto &v : s)
        {
            result.push_back(v);
        }

        return result;
    }
};