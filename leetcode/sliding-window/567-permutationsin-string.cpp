/*
    https://leetcode.com/problems/permutation-in-string/description/
*/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> um, window;
        int match = 0;

        int m = s1.length(), n = s2.length();

        // if the string 1 is longer than string 2, no way string s2 can have permutation of s1 in it.
        if (m > n)
        {
            return false;
        }

        // fill the map with frequency if char
        for (char &c : s1)
        {
            um[c]++;
        }

        int left = 0, right = 0;

        while (right < n)
        {
            char d = s2[right];
            // increase window size
            right++;

            if (um.find(d) != um.end())
            {
                // add to window
                window[d]++;
                if (window[d] == um[d])
                {
                    match++;
                }
            }

            // shrink window from left to maintain size of string s1
            while (right - left > m)
            {
                char f = s2[left];
                left++;

                if (window.find(f) != window.end())
                {
                    // !!! Check out
                    if (window[f] == um[f])
                    {
                        match--;
                    }
                    window[f]--;
                }
            }

            // If the number of unique characters that meet the frequency requirement
            // equals the total number of unique characters in s1, and because our
            // window size is exactly 'm', we have found a valid permutation!
            if (match == um.size())
            {
                return true;
            }
        }

        return false;
    }
};