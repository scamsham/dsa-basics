#include <iostream>
#include <vector>

using namespace std;

int findUpperBound(vector<int> v, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (v[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (v[mid] > k)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int findLowerBound(vector<int> v, int n, int k)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == k)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (v[mid] > k)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 8, 8, 9, 10};
    int n = v.size();
    int k = 6;
    cout << "Length: " << n << endl;
    cout << "Upper bound is " << findUpperBound(v, n, 6) << endl;
    cout << "Lower bound is " << findLowerBound(v, n, 6) << endl;
    cout << "Frequency is " << findUpperBound(v, n, 6) - findLowerBound(v, n, 6) + 1;

    return 0;
}