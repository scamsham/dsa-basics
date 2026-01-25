#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Monotonic stack pattern:
We want next index j>i such that score[j] >= score[i] (next greater OR equal).
Maintain a stack of indices with strictly decreasing scores (so when we see a score
that is >= top's score, we can resolve top).
*/

vector<int> getShadowWindows(const vector<int>& score) {
    // TODO: implement
    int n = score.size();
    vector<int> result(n, 0);

    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && score[st.top()] <= score[i]){
            result[st.top()] = i - st.top() - 1;
            st.pop();
        }

        st.push(i);
    }


    return result;
}

// ---------- Tests ----------
static void assertEq(const vector<int>& got, const vector<int>& exp) {
    if (got != exp) {
        cerr << "Assertion failed.\nGot: ";
        for (int x : got) cerr << x << " ";
        cerr << "\nExp: ";
        for (int x : exp) cerr << x << " ";
        cerr << "\n";
        abort();
    }
}

int main() {
    // Test 1: sample-like
    {
        vector<int> score = {5, 3, 4, 4, 2};
        assertEq(getShadowWindows(score), vector<int>({0,0,0,0,0}));
    }

    // Test 2: mixed increases
    {
        vector<int> score = {2, 1, 2, 1, 3};
        assertEq(getShadowWindows(score), vector<int>({1,0,1,0,0}));
    }

    // Test 3: strictly increasing -> each dominated immediately => window 0
    {
        vector<int> score = {1,2,3,4};
        assertEq(getShadowWindows(score), vector<int>({0,0,0,0}));
    }

    // Test 4: strictly decreasing -> nobody gets dominated => all 0
    {
        vector<int> score = {9,7,5,3,1};
        assertEq(getShadowWindows(score), vector<int>({0,0,0,0,0}));
    }

    // Test 5: equal values matter (>= not >)
    {
        vector<int> score = {4,4,4};
        // i=0 next >=4 at 1 -> window 0
        // i=1 next >=4 at 2 -> window 0
        // i=2 none -> 0
        assertEq(getShadowWindows(score), vector<int>({0,0,0}));
    }

    // Test 6: larger gaps
    {
        vector<int> score = {3,1,1,1,3};
        // i=0 next >=3 at 4 -> window 3
        // i=1 next >=1 at 2 -> window 0
        // i=2 next >=1 at 3 -> window 0
        // i=3 next >=1 at 4 -> window 0
        // i=4 none -> 0
        assertEq(getShadowWindows(score), vector<int>({3,0,0,0,0}));
    }

    cerr << "All tests passed.\n";
    return 0;
}
