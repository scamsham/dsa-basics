class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // create a next greater map that you can iterate over for nums1
        int n = nums2.size();
        stack<int> s;

        // if all elements are unique we use map else we use a vector array
        unordered_map<int, int> um;
        
        for(int i = 0; i < n; i++){
            while(!s.empty() && nums2[i] > nums2[s.top()]){
                int index = s.top();
                s.pop();
                um[nums2[index]] = nums2[i];
            }

            s.push(i);
        } 

        while(!s.empty()){
            int index = s.top();
            s.pop();
            int x = nums2[index];
            um[x] = -1;
        }

        vector<int> v;
        for(int &x: nums1){
            v.push_back(um[x]);    
        }
           
        return v;
    }
};