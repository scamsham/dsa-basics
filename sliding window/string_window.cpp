#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

string find_window(string s, string p)
{
    int ws[256] = {0};
    int wp[256] = {0};

    int count = 0;
    int window_size = 0;
    int min_window_size = INT_MAX;

    // Set the pattern map with count
    for (int i = 0; p[i] != '\0'; i++)
    {
        wp[p[i]] += 1;
    }

    int start = 0;
    int end = 0;
    int fstart = 0;

    while (end < s.length())
    {
        char ch = s[end];
        ws[ch]++;
        // If the character exists in the pattern map and its count in pattern map is greater than string map
        if (wp[ch] != 0 && wp[ch] >= ws[ch])
        {
            count++;
        }

        // If we have counted all the elements that exist in pattern we will start contracting the window from left
        if (count == p.length())
        {
            char leftChar = s[start];
            // If the count of char in string is greater than pattern
            // OR that char does not exist in pattern, move start to right
            while (ws[leftChar] > wp[leftChar] or wp[leftChar] == 0)
            {
                ws[leftChar]--;
                leftChar = s[start + 1];
                start++;
            }
            window_size = end - start + 1;
            if (min_window_size > window_size)
            {
                min_window_size = window_size;
                fstart = start;
            }
        }
        end++;
    }
    return s.substr(fstart, min_window_size);
}

int main()
{
    string s = "Helloroworld", p = "lowor";
    cout << find_window(s, p);
}