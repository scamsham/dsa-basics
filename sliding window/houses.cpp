#include <iostream>
#include <vector>

using namespace std;

void printWindows(vector<int> plots, int k){
    int n = plots.size();
    int r = 0, l = 0;
    int currentSum = 0;
    for(r = 0; r < n; r++){
        currentSum += plots[r];

        while(currentSum > k){
            currentSum -= plots[l];
            l++;
        }

        if(currentSum == k){
            cout<<l<<" --> "<<r<<endl;
        }
    }
    return ;
}

int main(){

    vector<int> plots = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    // Find the window in which the sum is 8
    int k = 8;
    printWindows(plots, k);
}