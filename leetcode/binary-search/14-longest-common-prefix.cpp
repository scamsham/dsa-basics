class Solution {
public:
    bool commonPrefixFound(vector<string> &strs, int len, int m){
        if(len == 0){
            return true;
        }
        string prefix = strs[0].substr(0, len);
        for(int i = 1; i < m; i++){
            if(prefix != strs[i].substr(0, len)){
                return false;
            }
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n = INT_MAX, ans = 0, m = strs.size();
        for(string &s: strs){
            if(n > s.length())
            {
                n = s.length();
            }
        }

        if(n == 0){
            return "";
        }
        
        if(m == 1){
            return strs[0];
        }

        int left = 0, right = n;
        while(left <= right){
            // avoid overflow
            int mid = left + (right - left) / 2;

            if(commonPrefixFound(strs, mid, m)){
                // if found, we look for greater value
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return strs[0].substr(0, ans);
    }
};