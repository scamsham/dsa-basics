#include <iostream>
#include <vector>

using namespace std;

int findElementIndex(vector<int> v, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == k)
        {
            return mid;
        }
        // 2 cases
        if (v[start] <= v[mid])
        {
            // mid lies on line 1 (elements between mid and start are sorted order)
            if (v[mid] >= k && v[start] <= k)
            {
                // all elements between this will be sorted if condition true
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            // mid lies on line 2
            if (v[mid] <= k && k <= v[end])
            {
                // all elements between this will be sorted if condition true
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6};
    int k;
    cin >> k;

    cout << findElementIndex(v, v.size(), k);
}