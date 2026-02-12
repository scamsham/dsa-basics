class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        unordered_map<char, int> um;
        int start = -1, length = 1e6;
        
        int left = 0, right = 0, n = s.length();
        
        for(char &ch: p){
            um[ch]++;
        }
        
        int count = um.size();
        
        while(right < n){
            char ch = s[right];
            
            if(um.find(ch) != um.end()){
                um[ch]--;
                if(um[ch] == 0){
                    count--;
                }
            }
            
            while(count == 0){
                
                if(right - left + 1 < length){
                    length = right - left + 1;
                    start = left;
                }
                
                char lch = s[left];
                if(um.find(lch) != um.end()){
                    if(um[lch] == 0){
                        count++;
                    }
                    um[lch]++;
                }
                
                left++;
            }
            
            right++;
        }
        
        
        
        if (length == 1e6){
            return "";
        }
        
        return s.substr(start, length);
    }
};