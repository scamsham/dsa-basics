#include <iostream>
#include <vector>

using namespace std;

bool canPutBirdHere(vector<int> v, int birds, int dist, int n)
{
    int count = 1;
    int last = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] - last >= dist)
        {
            last = v[i];
            count++;
            if (count >= birds)
                return true;
        }
    }

    return false;
}

int findMaxDistance(vector<int> nests, int birds, int n)
{
    int start = nests[0];
    int end = nests[n - 1];
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (canPutBirdHere(nests, birds, mid, n))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int B = 3;                           // Number of birds
    vector<int> nests = {1, 2, 4, 8, 9}; // Nests at following locations (it can be unsorted so in that case sort it)
    int N = nests.size();
    // find the maximum distance you can keep the birds in the nest
    cout << findMaxDistance(nests, B, N);
}