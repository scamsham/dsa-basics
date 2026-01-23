#include <iostream>
#include <cstring>

using namespace std;

bool string_match(string a, string b)
{
    int m = a.length();
    int n = b.length();
    int i = m - 1;
    int j = n - 1;
    while (i >= 0 and j >= 0)
    {
        if (a[i] == b[j])
        {
            i--;
            j--;
            if (j == -1)
                return true;
        }
        else
        {
            i--;
        }
    }

    return false;
}

int main()
{
    string a;
    string b;
    cin >> a >> b;
    cout << string_match(a, b) << endl;
}