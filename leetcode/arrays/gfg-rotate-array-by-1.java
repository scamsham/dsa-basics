/**
 * Given an array, rotate the array by one position in clock-wise direction.
 * https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
 */

class Solution {
    public void rotate(int[] arr) {
        // code here
        int n = arr.length;
        
        int k = arr[n - 1];
        for(int i = 0; i < n; i++){
            int temp = arr[i];
            arr[i] = k;
            k = temp;
        }
    }
}