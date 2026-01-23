#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void printSubsequences(string &a, char b[], vector<string> &v, int i, int j)
{
    if (i == a.length())
    {
        b[j] = '\0';
        v.push_back(b);
        return;
    }
    b[j] = a[i];
    printSubsequences(a, b, v, i + 1, j + 1);
    printSubsequences(a, b, v, i + 1, j);

    return;
}

bool compare(string s1, string s2)
{
    if (s1.length() == s2.length())
    {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main()
{
    string a = "codie";
    int n = a.length();
    char b[n + 1];
    vector<string> v;

    printSubsequences(a, b, v, 0, 0);

    sort(v.begin(), v.end(), compare);

    for (string s : v)
    {
        cout << s << ", ";
    }
}