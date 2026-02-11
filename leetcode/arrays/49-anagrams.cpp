class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        vector<vector<string>> result;

        for(string &s: strs){
            string temp = s;
            sort(temp.begin(), temp.end());

            um[temp].push_back(s);
        }

        for(auto &s: um){
            string key = s.first;
            vector<string> children = s.second;
            
            result.push_back(children);
        }

        return result;
    }
};