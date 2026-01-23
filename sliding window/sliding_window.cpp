#include <iostream>
#include <vector>
using namespace std;

void printWindows(vector<int> plots, int k)
{
    int i = 0, j = 0, cs = 0;
    int n = plots.size();
    int sm_w = n;
    pair<int, int> sw;
    int lg_w = 0;
    pair<int, int> lw;
    // Dynamic Sliding window (J moves to N and I moves to J)
    while (j < n)
    {
        cs += plots[j];

        // i moves to j only if the current sum exceeds the value k
        while (i < j && cs > k)
        {
            cs -= plots[i];
            i++;
        }

        if (cs == k)
        {
            if (j - i < sm_w)
            {
                sm_w = j - i;
                sw.first = i;
                sw.second = j;
            }
            if (j - i > lg_w)
            {
                lg_w = j - i;
                lw.first = i;
                lw.second = j;
            }
            cout << i << " --> " << j << endl;
        }
        j++;
    }
    cout << "The smallest window is " << sw.first << " -- " << sw.second << endl;
    cout << "The largest window is " << lw.first << " -- " << lw.second << endl;
}

int main()
{
    vector<int> plots = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    // Find the window in which the sum is 8
    int k = 8;
    printWindows(plots, k);
}