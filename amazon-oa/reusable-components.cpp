#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

/**
 * PROBLEM: Cross-Team Reuse Signal (Amazon OA)
 * * Description:
 * Identify "reusable components" across internal teams. A component is 
 * considered "cross-team reusable" if it has been used by at least K 
 * distinct teams.
 * * Input:
 * - N usage records (teamId, componentName)
 * - K threshold
 * * Constraints:
 * - N up to 200,000
 * - teamId up to 10^9
 * - componentName length up to 40
 * - A team may use the same component multiple times; count distinct teams only.
 * * Goal:
 * Return the number of components used by >= K distinct teams.
 */

class Record {
    public:
        int teamId;
        string componentName;
    
        Record(int tId, string cName){
            this->teamId = tId;
            this->componentName = cName;
        }
};

class Solution {
public:
    /**
     * @param N: Number of usage records
     * @param K: Minimum distinct teams required
     * @param records: Vector of Record structs containing teamId and componentName
     * @return: Number of cross-team reusable components
     */
    int countReusableComponents(int N, int K, vector<Record>& records) {
        // TODO: Implement your logic here
        // Hint: Sorting or HashMap + HashSet approach
        int count = 0;
        unordered_map<string, set<int>> componentTeamMap;

        for(auto record: records){
            componentTeamMap[record.componentName].insert(record.teamId);
        }

        for(auto entry: componentTeamMap){
            if(componentTeamMap[entry.first].size() >= K){
                count++;
            }
        }
        
        return count;
    }
};

// --- Test Harness ---
int main() {
    Solution sol;

    // Test Case 1: Standard case
    // K = 2. 
    // billing_sdk: teams {1, 2} (2 teams) -> Pass
    // auth_lib: teams {3, 4, 5} (3 teams) -> Pass
    // search_index: teams {2} (1 team) -> Fail
    vector<Record> records1 = {
        {1, "billing_sdk"}, {1, "billing_sdk"}, {2, "billing_sdk"},
        {3, "auth_lib"}, {3, "auth_lib"}, {4, "auth_lib"}, {5, "auth_lib"},
        {2, "search_index"}
    };
    cout << "Test Case 1: " << (sol.countReusableComponents(8, 2, records1) == 2 ? "PASSED" : "FAILED") << endl;

    // Test Case 2: K = 1 (Everything qualifies)
    vector<Record> records2 = {
        {10, "a"}, {11, "a"}, {12, "b"}, {12, "b"}
    };
    cout << "Test Case 2: " << (sol.countReusableComponents(4, 1, records2) == 2 ? "PASSED" : "FAILED") << endl;

    // Test Case 3: Heavy duplicates from same team
    // K = 3. 
    // x: teams {7, 8, 9} (3 teams) -> Pass
    vector<Record> records3 = {
        {7, "x"}, {7, "x"}, {7, "x"}, {8, "x"}, {9, "x"}, {9, "x"}
    };
    cout << "Test Case 3: " << (sol.countReusableComponents(6, 3, records3) == 1 ? "PASSED" : "FAILED") << endl;

    return 0;
}