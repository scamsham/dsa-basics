/*
    https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
*/

class Solution {
  public:
    int minJumpsHelper(vector<int> &arr, int index, int n, vector<int> &dp){
        if(index >= n - 1){
            return 0;
        }
        
        if(arr[index] == 0){
            return 1e9;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        
        int totalJumps = 1e9;
        
        for(int jump = 1; jump <= arr[index]; jump ++){
            if(index + jump >= n - 1){
                totalJumps = 1;
                break;
            }
            
            int result = minJumpsHelper(arr, index + jump, n, dp);
            if(result != 1e9){
                totalJumps = min(totalJumps, 1 + result);
                
            }
            
        }
        
        dp[index] = totalJumps;
        
        return dp[index];
    }
  
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, -1);
        
        int ans = minJumpsHelper(arr, 0, n, dp);
        
        return ans >= 1e9 ? -1 : ans;
    }
};
