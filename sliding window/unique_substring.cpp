// Sliding window problem
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

string unique_substring(string s)
{
    int i = 0, j = 0, starting_index = -1, n = s.length();
    int window_size = 0;
    int max_window_size = 0;
    unordered_map<char, int> um;

    while (j < n)
    {
        // If the character exists in the map and same character is appearing afterwards (checking index)
        char ch = s[j];
        if (um.find(ch) != um.end() && um[ch] >= i)
        {
            // Move the i pointer of the window after the occurance of same character
            i = um[ch] + 1;
            window_size = j - i;
        }

        // Update the last occurance in the map or insert in the map
        um[ch] = j;
        window_size++;
        j++;

        if (window_size > max_window_size)
        {
            max_window_size = window_size;
            starting_index = i;
        }
    }
    return s.substr(starting_index, max_window_size);
}

int main()
{
    string s = "abcabedfgab";
    cout << unique_substring(s);
}