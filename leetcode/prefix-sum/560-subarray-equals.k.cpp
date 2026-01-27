class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size(), sum = 0;
        // we store frequency here 
        unordered_map<int, int> um;

        // base case - to handle the case when sum itself is equal to k
        um[0] = 1;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];

            if(um.find(sum - k) != um.end()){
                count += um[sum - k];
            }

            // increase the count of number of times a sum occurs in the array
            um[sum]++;
        }

        return count;
    }
};