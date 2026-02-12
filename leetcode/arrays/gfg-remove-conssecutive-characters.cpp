class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        // code here.
        int n = s.size();
        if(n == 0 || n == 1){
            return s;
        }
        
        string ans = "";
        char ch = s[0];
        ans += ch;
        
        for(int i = 1; i < n; i++){
            if(s[i] == ch){
                continue;
            }else{
                ch = s[i];
                ans += ch;
            }
        }
        
        return ans;
    }
};