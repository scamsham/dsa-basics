// Subset sum X
/*
Given an array of integers and a target integer X, find all subsets of the array whose elements sum exactly to X.
Return or print these subsets.
*/
#include <iostream>
#include <vector>

using namespace std;

int printSubsets(vector<int> v, vector<int> &x, int i, int X, int n)
{
    // Base case
    if (i == n)
    {
        // 2 conditions if sum adds up to X
        if (X == 0)
        {
            for (int xn : x)
            {
                cout << xn << " ";
            }
            cout << endl;
            return 1;
        }
        // else it does not
        else
        {
            return 0;
        }
    }
    x.push_back(v[i]);
    printSubsets(v, x, i + 1, X - v[i], n);
    x.pop_back();
    printSubsets(v, x, i + 1, X, n);

    return 0;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int X = 6;
    vector<int> x;
    printSubsets(v, x, 0, X, v.size());
}
