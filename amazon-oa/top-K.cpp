#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include <algorithm>
# include <math.h>
using namespace std;

/*
Pattern: HashMap aggregation + Top-K (heap) with tie-breaking

We have records: (serviceName, errorCode, cost)
Dedup rule: for each (serviceName, errorCode), keep MAX(cost)
Then for each serviceName, totalCost = sum of kept costs over its errorCodes
Return top K services by totalCost desc, tie: name asc
*/

class Service {
    public:
    string name;
    long long totalCost;
    int code;
    Service(string n, long long tc, int c){
        this->name = n;
        this->totalCost = tc;
        this->code = c;
    }
};

int findIndexOf_(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '_'){
            return i;
        }
    }
    return -1;
}

vector<string> topKImpactedServices(
    int k,
    const vector<tuple<string,int,long long>>& records
) {
    // service -> (errorCode -> maxCost)
    unordered_map<string, unordered_map<int, long long>> maxCostPerErrorByService;
    maxCostPerErrorByService.reserve(records.size());

    for (const auto& [serviceName, errorCode, cost] : records) {
        long long &storedMax = maxCostPerErrorByService[serviceName][errorCode];
        storedMax = max(storedMax, cost);
    }

    // service -> totalCost
    unordered_map<string, long long> totalCostByService;
    totalCostByService.reserve(maxCostPerErrorByService.size());

    for (const auto& [serviceName, errorMap] : maxCostPerErrorByService) {
        long long totalCost = 0;
        for (const auto& [errorCode, maxCost] : errorMap) {
            totalCost += maxCost;
        }
        totalCostByService[serviceName] = totalCost;
    }

    // Sort all services by (totalCost desc, name asc)
    vector<pair<string, long long>> serviceTotals;
    serviceTotals.reserve(totalCostByService.size());
    for (const auto& [serviceName, totalCost] : totalCostByService) {
        serviceTotals.push_back({serviceName, totalCost});
    }

    sort(serviceTotals.begin(), serviceTotals.end(),
         [](const auto& a, const auto& b) {
             if (a.second != b.second) return a.second > b.second; // totalCost desc
             return a.first < b.first;                             // name asc
         });

    vector<string> result;
    int limit = min<int>(k, serviceTotals.size());
    result.reserve(limit);
    for (int i = 0; i < limit; i++) {
        result.push_back(serviceTotals[i].first);
    }
    return result;
}

// ---------- Tests ----------
static void assertEqVec(const vector<string>& got, const vector<string>& exp) {
    if (got != exp) {
        cerr << "Assertion failed.\nGot: ";
        for (auto &s : got) cerr << s << " ";
        cerr << "\nExp: ";
        for (auto &s : exp) cerr << s << " ";
        cerr << "\n";
        abort();
    }
}

int main() {
    // Test 1: basic + dedup max per (service,error)
    {
        int K = 2;
        vector<tuple<string,int,long long>> rec = {
            {"auth",101,5},
            {"auth",101,7}, // max for (auth,101) => 7
            {"auth",102,3}, // auth total = 10
            {"pay",201,9},
            {"pay",201,2},  // max for (pay,201) => 9, pay total = 9
            {"search",301,10} // search total = 10
        };
        // totals: auth=10, search=10, pay=9 -> top2: auth, search (tie by name)
        assertEqVec(topKImpactedServices(K, rec), vector<string>({"auth","search"}));
    }

    // Test 2: fewer services than K
    {
        int K = 5;
        vector<tuple<string,int,long long>> rec = {
            {"a",1,1},
            {"b",1,2},
            {"b",2,3} // b total = 5
        };
        // totals: b=5, a=1 -> return both
        assertEqVec(topKImpactedServices(K, rec), vector<string>({"b","a"}));
    }

    // Test 3: tie on total, lexicographic name
    {
        int K = 3;
        vector<tuple<string,int,long long>> rec = {
            {"svc2",10,5},
            {"svc1",20,5},
            {"svc3",30,5},
            {"svc1",20,4}, // dedup keeps max=5
            {"svc2",10,5}  // dedup keeps 5
        };
        // totals: svc1=5, svc2=5, svc3=5 -> order by name asc
        assertEqVec(topKImpactedServices(K, rec), vector<string>({"svc1","svc2","svc3"}));
    }

    // Test 4: dedup across multiple error codes
    {
        int K = 2;
        vector<tuple<string,int,long long>> rec = {
            {"x",1,10},
            {"x",2,1},
            {"x",2,7},  // keep 7
            {"y",9,8},
            {"y",9,8},  // keep 8
            {"z",3,100}
        };
        // totals: x=17, y=8, z=100 -> top2: z, x
        assertEqVec(topKImpactedServices(K, rec), vector<string>({"z","x"}));
    }

    cerr << "All tests passed.\n";
    return 0;
}
