#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

// Function to generate all possible transformations
vector<string> generateTransformations(string s)
{
    vector<string> transformations;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        string newStr = s.substr(0, i) + s.substr(i + 1); // Remove digit
        char newDigit = min(char(s[i] + 1), '9');         // Compute new digit to insert

        // Insert new digit at all positions
        for (int j = 0; j <= newStr.size(); j++)
        {
            string transformed = newStr.substr(0, j) + newDigit + newStr.substr(j);
            transformations.push_back(transformed);
        }
    }

    return transformations;
}

// BFS to find lexicographically minimal string
string getMinimumString(string s_id)
{
    queue<string> q;
    unordered_set<string> visited; // Track visited configurations
    q.push(s_id);
    visited.insert(s_id);

    string minString = s_id;

    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        if (curr < minString)
        {
            minString = curr; // Update the lexicographically smallest string
        }

        vector<string> nextTransforms = generateTransformations(curr);
        for (string next : nextTransforms)
        {
            if (!visited.count(next))
            {
                q.push(next);
                visited.insert(next);
            }
        }
    }

    return minString;
}

// Driver Code
int main()
{
    string s_id;
    cin >> s_id;
    cout << getMinimumString(s_id) << endl;
    return 0;
}
