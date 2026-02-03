/**
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
Note: You need to solve this problem without utilizing the built-in sort function.

https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
*/

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        
        int n = arr.size();
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0){
                count0++;
            }
            if(arr[i] == 1){
                count1++;
            }
            if(arr[i] == 2){
                count2++;
            }
        }
        
        int k = 0;
        
        while(k < count0){
            arr[k] = 0;
            k++;
        }
        
        while(k < count0 + count1){
            arr[k] = 1;
            k++;
        }
        
        while(k < count0 + count1 + count2){
            arr[k] = 2;
            k++;
        }
        
    }
};