/*
    https://leetcode.com/problems/valid-palindrome/description/
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string cs = "";
        for (char c : s)
        {
            if (isalnum(c))
            {
                cs += tolower(c);
            }
        }
        cout << cs << endl;
        int left = 0, right = cs.length();
        if (right == 0 || right == 1)
        {
            return true;
        }
        right -= 1;

        while (left < right)
        {
            if (cs[left] != cs[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};