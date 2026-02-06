#include <iostream>
#include <string>

using namespace std;

void printAllSubsequences(string s, int start, int end, string current)
{
    if (start >= end)
    {
        cout << current << endl;
        return;
    }

    printAllSubsequences(s, start + 1, end, current + s[start]);
    printAllSubsequences(s, start + 1, end, current);

    return;
}

int main()
{
    string s = "helloo";
    printAllSubsequences(s, 0, s.length() - 1, "");

    return 0;
}