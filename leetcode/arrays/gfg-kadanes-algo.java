/**
 * IMPORTANT: Kadane's algo
 * You are given an integer array arr[]. You need to find the maximum sum of a
 * subarray (containing at least one element) in the array arr[].
 * 
 * https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
 */

class Solution {
    int maxSubarraySum(int[] arr) {
        // Code here
        int largest = Integer.MIN_VALUE, n = arr.length;
        int maxValueInArray = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            maxValueInArray = Math.max(maxValueInArray, arr[i]);
        }
        int sum = 0;
        maxValueInArray = maxValueInArray < 0 ? maxValueInArray : 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum < maxValueInArray) {
                sum = maxValueInArray;
            }
            largest = Math.max(sum, largest);
        }
        return largest;
    }
}
