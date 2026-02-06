/*
    https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#
*/

class Solution
{
public:
    void findPermutationHelper(string &s, set<string> &v, int index, int n)
    {
        if (index == n)
        {
            v.insert(s);
            return;
        }

        for (int i = index; i < n; i++)
        {
            swap(s[i], s[index]);
            findPermutationHelper(s, v, index + 1, n);
            swap(s[i], s[index]);
        }
    }

    vector<string> findPermutation(string &s)
    {
        // Code here there
        set<string> v;
        findPermutationHelper(s, v, 0, s.length());

        vector<string> result;

        for (auto &s : v)
        {
            result.push_back(s);
        }

        return result;
    }
};
