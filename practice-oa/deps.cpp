#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

/*
Multi-source BFS on directed graph:
Input dependencies: (A depends on B)
Propagation: if B unhealthy => A unhealthy next minute
So edges: B -> A

Return:
- total unhealthy after stabilization
- timeUnhealthy[i] earliest minute, or -1 if never
*/

pair<int, vector<int>> getBlastRadius(
    int numServices,
    const vector<pair<int,int>>& dependencies,
    const vector<int>& initiallyUnhealthy
) {
    vector<vector<int>> dependents(numServices);
    dependents.reserve(numServices);

    // Build edges: B -> A
    for (const auto& [A, B] : dependencies) {
        if (B >= 0 && B < numServices && A >= 0 && A < numServices) {
            dependents[B].push_back(A);
        }
    }

    vector<int> timeUnhealthy(numServices, -1);
    queue<int> q;

    // Multi-source init (dedupe via time array)
    for (int s : initiallyUnhealthy) {
        if (s < 0 || s >= numServices) continue;
        if (timeUnhealthy[s] == -1) {
            timeUnhealthy[s] = 0;
            q.push(s);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : dependents[u]) {
            if (timeUnhealthy[v] == -1) {
                timeUnhealthy[v] = timeUnhealthy[u] + 1;
                q.push(v);
            }
        }
    }

    int totalUnhealthy = 0;
    for (int t : timeUnhealthy) {
        if (t != -1) totalUnhealthy++;
    }

    return {totalUnhealthy, timeUnhealthy};
}

// ---------- Tests ----------
static void assertEqPair(const pair<int, vector<int>>& got,
                         const pair<int, vector<int>>& exp) {
    if (got.first != exp.first || got.second != exp.second) {
        cerr << "Assertion failed.\nGot total: " << got.first << "\nGot times: ";
        for (int x : got.second) cerr << x << " ";
        cerr << "\nExp total: " << exp.first << "\nExp times: ";
        for (int x : exp.second) cerr << x << " ";
        cerr << "\n";
        abort();
    }
}

int main() {
    // Test 1: chain-like propagation
    {
        int n = 6;
        vector<pair<int,int>> deps = {{1,0},{2,1},{3,1},{4,2},{4,3},{5,4}};
        vector<int> init = {0};
        assertEqPair(getBlastRadius(n, deps, init),
                     {6, vector<int>({0,1,2,2,3,4})});
    }

    // Test 2: multiple initial sources (multi-source BFS)
    {
        int n = 5;
        vector<pair<int,int>> deps = {{1,0},{2,1},{3,2},{4,3}};
        vector<int> init = {0,2};
        // 0 unhealthy at 0
        // 2 unhealthy at 0
        // 1 depends on 0 => 1 at 1
        // 3 depends on 2 => 3 at 1
        // 4 depends on 3 => 4 at 2
        assertEqPair(getBlastRadius(n, deps, init),
                     {5, vector<int>({0,1,0,1,2})});
    }

    // Test 3: cycles should not loop forever
    {
        int n = 4;
        vector<pair<int,int>> deps = {{1,0},{2,1},{0,2},{3,2}}; // cycle 0->1->2->0 via depends
        vector<int> init = {1};
        // propagation edges are reversed:
        // 0->1,1->2,2->0,2->3
        // start 1 at 0 => 2 at 1 => 0 at 2 => 3 at 2
        assertEqPair(getBlastRadius(n, deps, init),
                     {4, vector<int>({2,0,1,2})});
    }

    // Test 4: disconnected nodes stay healthy
    {
        int n = 5;
        vector<pair<int,int>> deps = {{1,0},{2,1}};
        vector<int> init = {4};
        // only 4 unhealthy, others never impacted
        assertEqPair(getBlastRadius(n, deps, init),
                     {1, vector<int>({-1,-1,-1,-1,0})});
    }

    // Test 5: duplicates in input should not break
    {
        int n = 3;
        vector<pair<int,int>> deps = {{1,0},{1,0},{2,1},{2,1}};
        vector<int> init = {0,0};
        assertEqPair(getBlastRadius(n, deps, init),
                     {3, vector<int>({0,1,2})});
    }

    cerr << "All tests passed.\n";
    return 0;
}
