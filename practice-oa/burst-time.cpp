/**
Keywords: "subarray," "substring," "continuous window," "consecutive elements."

*/

/**
Background 
My S3 manages billions of objects across various storage clusters. 
To ensure high availability, engineers monitor the health scores of instances within these clusters. 
A "Cluster Group" is defined as a contiguous sequence of K instances.

Problem Statement 
You are given an array of integers utilization, where utilization[i] represents the 
CPU health score of the i_th instance (higher score means higher stress). 
To identify potential bottlenecks, you must analyze every possible contiguous cluster group of size K.

For each group, identify the maximum stress score. 
Among all these group maximums, find the minimum value. 
This value represents the "Optimized Peak Stress" across the fleet.

Input Format
The first line of input contains two space-separated integers, 
N (number of instances) and 
K (cluster group size). 

The second line contains N space-separated integers representing the utilization scores.
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cassert>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     * @param N: Number of instances
     * @param K: Cluster size
     * @param utilization: CPU logs for each instance
     * @return: The minimum value among all contiguous cluster maximums
     */
    int solve(int N, int K, const vector<int>& utilization) {
        deque<int> dq;
        int result = INT_MAX;

        // 100, 80, 60, 40, 20
        // i = 0, dq -> 0 
        // i = 1, dq -> 0, 1
        // i = 2, dq -> 0, 1, 2 , Since i == K - 1 (2), we store result = 100
        // i = 3, dq -> 1, 2 (pop from since 0 <= i - K (3 - 3 = 0)), dq -> 1, 2, 3, we store result result = min(100, 80) = 100
        // .....
        
        for(int i = 0; i < N; i++){
            // 1. Make sure that out of index element is not in deque (shrinking from left)
            while(!dq.empty() && dq.front() <= i - K){
                dq.pop_front();
            }

            // 2. Make sure we add the maximum to back of the deque
            while(!dq.empty() && utilization[dq.back()] <= utilization[i]){
                dq.pop_back();
            }

            // 3. Push the indexes in the deque
            dq.push_back(i);

            // 4. Some condition to store answer (min max)
            if(i >= K - 1){ // 2
                result = min(result, utilization[dq.front()])
            }
        }

        return result;
    }
};

// --- Test Harness ---
int main() {
    Solution sol;


    // Test Case 1: Standard Example
    // Window Maxes: [50, 70, 70, 70] -> Min: 50
    assert(sol.solve(6, 3, {20, 50, 30, 70, 60, 40}) == 50);

    // Test Case 2: K = 1 (Every element is its own window max)
    // Window Maxes: [10, 5, 20, 15] -> Min: 5
    assert(sol.solve(4, 1, {10, 5, 20, 15}) == 5);

    // Test Case 3: K = N (One window, the max of the whole array)
    // Window Maxes: [100] -> Min: 100
    assert(sol.solve(5, 5, {10, 20, 100, 40, 50}) == 100);
    

    // Test Case 4: Decreasing Values
    // Window Maxes: [100, 80, 60] -> Min: 60
    assert(sol.solve(5, 3, {100, 80, 60, 40, 20}) == 60);

    // Test Case 5: All same values
    assert(sol.solve(4, 2, {10, 10, 10, 10}) == 10);

    // Test Case 6: Window of 0 or large W (Handled by constraints 1 <= K <= N)
    assert(sol.solve(3, 2, {1, 5, 1}) == 5);

    cout << "All test cases passed!" << endl;
    return 0;
}