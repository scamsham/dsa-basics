class myCompare{
    public:
        bool operator()(const vector<int> &a, const vector<int> &b){
            return a[0] < b[0]; 
        }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), myCompare());
        for(vector<int> & interval: intervals){
            cout<<interval[0]<<", "<<interval[1]<<endl;
        }
        result.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(result.back()[1] >= start){
                result.back()[1] = result.back()[1] > end? result.back()[1]: end;
            }else{
                result.push_back(intervals[i]);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};