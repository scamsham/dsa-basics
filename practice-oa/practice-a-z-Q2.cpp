#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

string getMinimumString(string s_id) {
    string kept_stack = "";
    vector<char> moved_chars;

    for (char c : s_id) {
        // Monotonic Stack Logic:
        // While the last kept character is bigger than the current one,
        // it is better to remove the last character (taking the +1 penalty)
        // to allow the smaller current character to appear earlier.
        while (!kept_stack.empty() && kept_stack.back() > c) {
            char popped = kept_stack.back();
            kept_stack.pop_back();
            
            // The operation: Remove digit, insert min(digit + 1, 9)
            // We cast to int for math, then back to char
            char new_val = min((char)(popped + 1), '9');
            moved_chars.push_back(new_val);
        }
        kept_stack.push_back(c);
    }

    // The moved characters can be inserted "at any position".
    // To minimize the result, we should use them in sorted order.
    sort(moved_chars.begin(), moved_chars.end());

    // Merge the kept string (which is sorted due to stack logic) 
    // and the moved characters to create the final minimal string.
    string result = "";
    int i = 0; // Pointer for kept_stack
    int j = 0; // Pointer for moved_chars

    while (i < kept_stack.length() && j < moved_chars.size()) {
        if (moved_chars[j] < kept_stack[i]) {
            result += moved_chars[j++];
        } else {
            result += kept_stack[i++];
        }
    }

    // Append whatever is remaining
    while (i < kept_stack.length()) {
        result += kept_stack[i++];
    }
    while (j < moved_chars.size()) {
        result += moved_chars[j++];
    }

    return result;
}

// // TODO: Implement this function
// string getMinimumString(string s_id) {
//     // Write your logic here
//     int n = (int)s_id.size();

//     // suffixMin[i] = minimum digit in s_id[i..n-1]
//     vector<char> suffixMin(n + 1, ':'); // ':' is just after '9' in ASCII
//     suffixMin[n] = ':';                 // bigger than any digit
//     for (int i = n - 1; i >= 0; --i) {
//         suffixMin[i] = min(s_id[i], suffixMin[i + 1]);
//     }

//     // movedCnt[d] = how many digits (after increment) we can insert later
//     array<int, 10> movedCnt{};
//     movedCnt.fill(0);

//     string kept;
//     kept.reserve(n);

//     for (int i = 0; i < n; ++i) {
//         char c = s_id[i];

//         // If there exists a smaller digit to the right, this digit is blocking.
//         if (c > suffixMin[i + 1]) {
//             int d = c - '0';
//             d = min(d + 1, 9);
//             movedCnt[d]++;
//         } else {
//             kept.push_back(c);
//         }
//     }

//     // Merge: place smallest moved digits as early as possible.
//     string ans;
//     ans.reserve(n);

//     int d = 0; // pointer over moved digits 0..9
//     for (char c : kept) {
//         int cur = c - '0';
//         while (d < cur) {
//             while (movedCnt[d] > 0) {
//                 ans.push_back(char('0' + d));
//                 movedCnt[d]--;
//             }
//             d++;
//         }
//         ans.push_back(c);
//     }

//     // Append remaining moved digits
//     while (d <= 9) {
//         while (movedCnt[d] > 0) {
//             ans.push_back(char('0' + d));
//             movedCnt[d]--;
//         }
//         d++;
//     }

//     return ans;
// }

int main() {
    // Test cases
    vector<pair<string, string>> testCases = {
        {"26547", "24677"},  // Example case
        {"04829", "02599"},  // Sample Case 0
        {"34892", "24599"}   // Sample Case 1
    };
    
    cout << "Running test cases...\n" << endl;
    
    for (int i = 0; i < testCases.size(); i++) {
        string input = testCases[i].first;
        string expected = testCases[i].second;
        string result = getMinimumString(input);
        
        cout << "Test Case " << i << ":" << endl;
        cout << "Input:    " << input << endl;
        cout << "Expected: " << expected << endl;
        cout << "Got:      " << result << endl;
        cout << "Status:   " << (result == expected ? "PASS ✓" : "FAIL ✗") << endl;
        cout << "-----------------------------------" << endl;
    }
    
    return 0;
}