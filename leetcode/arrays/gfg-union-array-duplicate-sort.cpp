/*
You are given two arrays a[] and b[], return the Union of both the arrays in any order.
The Union of two arrays is a collection of all distinct elements present in either of the arrays. If an element appears more than once in one or both arrays, it should be included only once in the result.

https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1
*/

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int> s;
        vector<int> v;
        for(int i = 0; i < a.size(); i++){
            s.insert(a[i]);
        }
        
        for(int i = 0; i < b.size(); i++){
            s.insert(b[i]);
        }
        
        for(int x: s){
            v.push_back(x);
        }
        
        
        return v;
    }
};