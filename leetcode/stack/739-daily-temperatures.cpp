class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> result(n, 0);

        s.push(0);

        for(int i = 0; i < n; i++){
            while(!s.empty() && temperatures[s.top()] < temperatures[i]){
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        
        return result;
    }
};