/**
 * Given an array arr[] denoting heights of n towers and a positive integer k.
 * For each tower, you must perform exactly one of the following operations
 * exactly once.
 * Increase the height of the tower by k
 * Decrease the height of the tower by k
 * Find out the minimum possible difference between the height of the shortest
 * and tallest towers after you have modified each tower.
 * 
 * You can find a slight modification of the problem here.
 * Note: It is compulsory to increase or decrease the height by k for each
 * tower. After the operation, the resultant array should not contain any
 * negative integers.
 * 
 * https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1
 */

class Solution {
    public int getMinDiff(int[] arr, int k) {
        // code here
        int n = arr.length;

        if (n == 1) {
            return 0;
        }

        Arrays.sort(arr);

        int ans = arr[n - 1] - arr[0];

        for (int i = 0; i < n - 1; i++) {
            // tallest tower
            int currentMax = Math.max(arr[i] + k, arr[n - 1] - k);

            // shortest tower
            int currentMin = Math.min(arr[0] + k, arr[i + 1] - k);

            if (currentMin < 0) {
                continue;
            }

            ans = Math.min(currentMax - currentMin, ans);
        }

        return ans;
    }
}
