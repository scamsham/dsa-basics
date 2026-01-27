#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0;
        int n = nums.size();
        unordered_map<int, int> um;
        um[0] = -1;
        // -1 1 1 1 1 1 -1 -1 -1
        // -1 0 1 2 3 4 3 2 1 
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i] == 0 ? -1 : 1;

            if(um.find(sum) != um.end()){
                // if the number is found in map
                cout<<"Matched: "<<um[sum]<<endl;
                maxLength = max(maxLength, i - um[sum]);
            }else{
               um[sum] = i;
            }
        }

        return maxLength;
    }
};

// --- Test Runner ---
struct TestCase {
    vector<int> nums;
    int expected;
    string description;
};

int main() {
    Solution sol;
    
    vector<TestCase> tests = {
        {{0, 1}, 2, "Simple pair"},
        {{0, 1, 0}, 2, "Extra zero at end"},
        {{0, 0, 1, 1, 0}, 4, "Longer balanced middle"},
        {{1, 1, 1, 1}, 0, "No balance possible"},
        {{0, 0, 0, 1, 1, 1}, 6, "Full array balanced"}
    };

    for (int i = 0; i < tests.size(); ++i) {
        int result = sol.findMaxLength(tests[i].nums);
        if (result == tests[i].expected) {
            cout << "Test " << i + 1 << " (" << tests[i].description << "): ✅ PASS" << endl;
        } else {
            cout << "Test " << i + 1 << " (" << tests[i].description << "): ❌ FAIL" << endl;
            cout << "   Expected: " << tests[i].expected << ", Got: " << result << endl;
        }
    }

    return 0;
}