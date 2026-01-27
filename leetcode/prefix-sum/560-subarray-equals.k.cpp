class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size(), sum = 0;
        // we store frequency here 
        unordered_map<int, int> frequency;

        // base case - to handle the case when sum itself is equal to k
        frequency[0] = 1;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];

            if(frequency.find(sum - k) != frequency.end()){
                count += frequency[sum - k];
            }

            // increase the count of number of times a sum occurs in the array
            frequency[sum]++;
        }

        return count;
    }
};