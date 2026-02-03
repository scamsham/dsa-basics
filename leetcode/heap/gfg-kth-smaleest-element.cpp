/**
Given an integer array arr[] and an integer k, your task is to find and return the kth smallest element in the given array.
https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
*/

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        int n = arr.size();
        
        if(k > n){
            return -1;
        }
        
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }
        
        for(int i = k; i < n; i++){
            if(pq.top() > arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};