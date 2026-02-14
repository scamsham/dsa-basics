/*
    https://leetcode.com/problems/next-permutation/
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1, n = nums.size();
        if(n == 1){
            return ;
        }

        for(int j = n - 2; j >= 0; j--){
            if(nums[j] < nums[j + 1]){
                pivot = j;
                break;
            }
        }

        if(pivot == -1){
            // already sorted so we reverse the array
            reverse(nums.begin(), nums.end());
            return ;`
        } 

        // find the right most element greater than pivot element
        for(int j = n - 1; j > pivot; j--){
            if(nums[j] > nums[pivot]){
                swap(nums[j], nums[pivot]);
                break;
            }
        }

        reverse(nums.begin() + pivot + 1, nums.end());

        return ;
    }
};