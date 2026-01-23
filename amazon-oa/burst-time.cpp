/**
Keywords: "subarray," "substring," "continuous window," "consecutive elements."

*/

/**
Background 
Amazon S3 manages billions of objects across various storage clusters. 
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
        // TODO: Implement O(N) Monotonic Queue logic here
        deque<int> dq;
        int answer = INT_MAX;

        if(K == 1){
            return *min_element(utilization.begin(), utilization.end());
        }

        for(int i = 0; i < N; i++){
            while(!dq.empty() && dq.front() <= i - K){
                dq.pop_front();
            }

            while(!dq.empty() && utilization[dq.back()] <= utilization[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            
            if(i >= K - 1){
                answer = min(answer, utilization[dq.front()]);
            }            
        }

        return answer; 
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