class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int n = nums.size();


        for(int i = 0; i < n; i++){
            // 1) Remove indices that are out of this window [i-k+1, i]
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            // 2) Maintain decreasing order in dq (front is max)
            while(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
    
            // 3) Add current index
            dq.push_back(i);

            // 4) Window formed -> record max
            // at the end because it will never go out of bounds 
            // since `i`th index is pushed in step 3)
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};