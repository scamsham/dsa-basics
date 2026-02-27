class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0, n = heights.size();
        if(n == 0){
            return area;
        }
        if(n == 1){
            return heights[0];
        }
        stack<int> s;

        int i = 0;
        for(i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] > heights[i]){
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                area = max(area, h * w);
            }

            s.push(i);
        }

        while(!s.empty()){
            int h = heights[s.top()];
            s.pop();
            int w = s.empty() ? i : i - s.top() - 1;
            area = max(area, h * w);
        }

        return area;
    }
};