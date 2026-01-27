// https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        this->prefixSum.resize(n, 0);
        this->prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            this->prefixSum[i] = this->prefixSum[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return this->prefixSum[right];
        }else{
            return this->prefixSum[right] - this->prefixSum[left - 1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */