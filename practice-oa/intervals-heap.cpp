#include <bits/stdc++.h>
using namespace std;

/*
Intervals / Meeting Rooms pattern (Amazon OA style)

We have N campaign windows: [start, end)  (end is EXCLUSIVE)
Meaning:
- Active at time start
- NOT active at time end
So if one campaign ends at time t and another starts at time t,
they DO NOT overlap and can reuse the same slot.

Goal:
Return:
1) minSlots: minimum number of ad delivery slots needed so no overlap in same slot
2) peakConcurrency: maximum number of simultaneously active campaigns
These values are equal, but we compute both (Amazon likes redundant verification outputs).

Core idea (Min-Heap of end times):
- Sort windows by start time.
- Maintain a min-heap of end times for campaigns currently occupying slots.
- When a new campaign starts at time s:
    - If the earliest-ending campaign ends <= s, that slot is freed (because end is exclusive).
      Pop it (possibly multiple).
    - Allocate a slot for this campaign by pushing its end time.
- Heap size at any time = number of slots currently in use = current concurrency.
- The maximum heap size across the scan = minSlots = peakConcurrency.

Time Complexity:
- Sorting: O(N log N)
- Each interval pushed once, popped once: O(N log N)
Space Complexity:
- Heap holds at most N end times: O(N)
*/

pair<int,int> minAdDeliverySlots(const vector<pair<int,int>>& windows) {
    // Edge case: no windows (not expected by constraints, but safe)
    if (windows.empty()) return {0, 0};

    // 1) Copy and sort by start time (and optionally by end time for determinism)
    vector<pair<int,int>> sortedWindows = windows;
    sort(sortedWindows.begin(), sortedWindows.end(),
         [](const pair<int,int>& a, const pair<int,int>& b) {
             if (a.first != b.first) return a.first < b.first; // earlier start first
             return a.second < b.second;                       // earlier end first (tie-break)
         });

    // 2) Min-heap of end times of currently active campaigns
    //    Top is the smallest end time => the next slot that will free earliest
    priority_queue<int, vector<int>, greater<int>> activeEndTimes;

    int peakConcurrency = 0;

    // 3) Sweep through campaigns in increasing start time
    for (const auto& [startTime, endTime] : sortedWindows) {

        // 3a) Free any slots whose campaign ended at or before this start time.
        //     Because intervals are [start, end), an endTime == startTime means
        //     it is already inactive, so we can reuse that slot.
        while (!activeEndTimes.empty() && activeEndTimes.top() <= startTime) {
            activeEndTimes.pop();
        }

        // 3b) Allocate a slot for current campaign by pushing its end time
        activeEndTimes.push(endTime);

        // 3c) Track maximum number of concurrent active campaigns
        peakConcurrency = max(peakConcurrency, (int)activeEndTimes.size());
    }

    // minSlots equals peakConcurrency in this model
    int minSlots = peakConcurrency;
    return {minSlots, peakConcurrency};
}

// ---------- Tests ----------
static void assertEq(const pair<int,int>& got, const pair<int,int>& exp) {
    if (got != exp) {
        cerr << "Assertion failed.\nGot: (" << got.first << "," << got.second << ")"
             << "\nExp: (" << exp.first << "," << exp.second << ")\n";
        abort();
    }
}

int main() {
    // Test 1: overlap + end-exclusive boundary
    {
        vector<pair<int,int>> windows = {{1,4},{2,6},{4,7}};
        assertEq(minAdDeliverySlots(windows), {2,2});
    }

    // Test 2: back-to-back, no overlap
    {
        vector<pair<int,int>> windows = {{1,2},{2,3},{3,4}};
        assertEq(minAdDeliverySlots(windows), {1,1});
    }

    // Test 3: one long + multiple short disjoint inside
    {
        vector<pair<int,int>> windows = {{1,10},{2,3},{4,5},{6,7}};
        assertEq(minAdDeliverySlots(windows), {2,2});
    }

    // Test 4: all fully overlapping
    {
        vector<pair<int,int>> windows = {{1,5},{1,5},{1,5}};
        assertEq(minAdDeliverySlots(windows), {3,3});
    }

    // Test 5: same start, different ends
    {
        vector<pair<int,int>> windows = {{1,3},{1,2},{1,4}};
        assertEq(minAdDeliverySlots(windows), {3,3});
    }

    // Test 6: same end, different starts
    {
        vector<pair<int,int>> windows = {{1,5},{2,5},{4,5}};
        assertEq(minAdDeliverySlots(windows), {3,3});
    }

    // Test 7: tricky tie — end at t frees slot for start at t
    {
        vector<pair<int,int>> windows = {{1,2},{2,4},{2,3},{3,5}};
        assertEq(minAdDeliverySlots(windows), {2,2});
    }

    cerr << "All tests passed.\n";
    return 0;
}
