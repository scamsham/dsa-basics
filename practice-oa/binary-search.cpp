#include <iostream>
#include <vector>
#include <cassert>
#include<algorithm>
using namespace std;

/*
Binary Search on Answer

Goal: minimum number of workers k such that
we can partition work[] into <= k contiguous groups
and each group sum <= D.

feasible(k):
  greedy count how many groups needed with max group sum D
*/

bool isFeasible(long long maxLoad, vector<long long> work, long long maxWorkers){
    long long currentLoad = 0;
    long long numOfWorkers = 1;
    for(long long w: work){
        if(w > maxLoad){
            return false;
        }
        if(currentLoad + w <= maxLoad){
            currentLoad += w;
        }else{
            currentLoad = w;
            numOfWorkers++;
            if(numOfWorkers > maxWorkers){
                return false;
            }
        }
    }
    return true;
}

int minWorkersToMeetDeadline(long long D,  vector<long long>& work) {
    // TODO: implement
    int n = work.size();
    sort(work.begin(), work.end());
    long long l = work[0];
    long long r = work[n - 1] - work[0];

    if(l > D){
        return -1;
    }

    int ans = -1;
    while(l < r){
        long long mid = (r - l)/2 + l;
        if(isFeasible(mid, work, D)){
            ans = mid;
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    
    return ans;
}

// ---------- Tests ----------
int main() {
    // Test 1: classic split array / minimize workers given max load D
    {
        vector<long long> work = {7, 2, 5, 10, 8};
        long long D = 15;
        // Need 3 workers: [7,2,5]=14, [10]=10, [8]=8
        assert(minWorkersToMeetDeadline(D, work) == 3);
       
    }

    // Test 2: already fits in 1 worker
    {
        vector<long long> work = {3, 3, 3};
        long long D = 9;
        assert(minWorkersToMeetDeadline(D, work) == 1);
    
    }

    // Test 3: impossible because a single batch exceeds D
    {
        vector<long long> work = {5, 100, 6};
        long long D = 50;
        assert(minWorkersToMeetDeadline(D, work) == -1);
    }

    // Test 4: tight deadline forces many workers
    {
        vector<long long> work = {4, 4, 4, 4};
        long long D = 4;
        // Each worker can only take one batch
        assert(minWorkersToMeetDeadline(D, work) == 4);
    }

    // Test 5: large values (overflow safety)
    {
        vector<long long> work = {1000000000000LL, 1000000000000LL, 1000000000000LL};
        long long D = 2000000000000LL;
        // 2 workers: [1e12,1e12]=2e12, [1e12]=1e12
        assert(minWorkersToMeetDeadline(D, work) == 2);
    }

    cerr << "All tests passed.\n";
    return 0;
}
