#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void min_pair(vector<int> a1, vector<int> a2)
{
    int diff = INT_MAX;
    pair<int, int> p;
    // Sort either one of the arrays (preferable the smaller one)
    sort(a2.begin(), a2.end());
    for (int i = 0; i < a1.size(); i++)
    {
        // lower_bound function returns an iterator so remember to subtract it with a2.begin() - starting iterator
        // That is why x gives index value
        int x = lower_bound(a2.begin(), a2.end(), a1[i]) - a2.begin();
        if (x >= 1 && abs(a1[i] - a2[x - 1]) < diff)
        {
            p.first = a1[i];
            p.second = a2[x - 1];
            diff = abs(a1[i] - a2[x - 1]);
        }
        if (x < a2.size() && abs(a1[i] - a2[x]) < diff)
        {
            p.first = a1[i];
            p.second = a2[x];
            diff = abs(a1[i] - a2[x]);
        }
    }
    cout << "The minimum pair is { " << p.first << ", " << p.second;
}

int main()
{
    vector<int> a1 = {-1, 5, 10, 20, 3};
    vector<int> a2 = {26, 134, 135, 15, 17};
    min_pair(a1, a2);
}