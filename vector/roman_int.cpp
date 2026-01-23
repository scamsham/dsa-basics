#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string intToRoman(int num)
{
    vector<pair<int, string>> romanVec = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};
    string res = "";
    for (pair<int, string> p : romanVec)
    {
        while (num >= p.first)
        {
            num -= p.first;
            res += p.second;
        }
    }
    return res;
}

int romanToInt(string s)
{
    unordered_map<char, int> romanMap{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int result = 0;
    int n = s.size();

    // Loop through each character in the string.
    for (int i = 0; i < n; i++)
    {
        // If the current number is less than the next number then subtract else add them
        if (i < n - 1 && romanMap[s[i]] < romanMap[s[i + 1]])
            result -= romanMap[s[i]]; // Subtract the value of the current numeral.
        else
            result += romanMap[s[i]];
    }

    return result;
}

int main()
{

    return 0;
}