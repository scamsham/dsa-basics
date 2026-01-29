class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        if (wordSet.find(beginWord) != wordSet.end()) wordSet.erase(beginWord);

        queue<pair<string, int>> q;
        int result = 0;

        q.push({beginWord, 1});

        while(!q.empty()){
            string f = q.front().first;
            int dist = q.front().second;
            q.pop();
            int wordLength = f.size();
            
            for(int i = 0; i < wordLength; i++){
                char original = f[i];
                for(char x = 'a'; x <= 'z'; x++){
                    if(x == original){
                        continue;
                    }

                    f[i] = x;
                    
                    if(f == endWord){
                        return dist + 1;
                    }

                    if(wordSet.find(f) != wordSet.end()){
                        // if word found in the set
                        cout<<f<<" "<<dist + 1<<endl;
                        wordSet.erase(f);
                        q.push({f, dist + 1});
                    }
                    f[i] = original;
                }
                
            }
        }

        return 0;
    }
};