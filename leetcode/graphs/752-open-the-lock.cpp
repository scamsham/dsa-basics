class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        int numberOfTurns = 0;

        if(target == "0000"){
            return 0;
        }

        if(deadset.find("0000") != deadset.end()){
            // if 0000 is present in the deadends set then it will be over before starting
            return -1;
        }

        q.push("0000");
        q.push("-1");

        while(!q.empty()){
            string f = q.front();
            q.pop();

            // !!!!! IMPORTANT: Don't forget to check for the target 
            if(f == target){
                return numberOfTurns;
            }

            // This indicates that we have completed one level and we need to increase the number of turns
            if(f == "-1"){
                if(!q.empty()){
                    q.push("-1");
                }
                numberOfTurns++;
                continue;
            }
            visited.insert(f);
            for(int k = 0; k < 4; k++){
                // kth index
                
                char up = f[k] == '9' ? '0' : f[k] + 1;
                char down = f[k] == '0' ? '9' : f[k] - 1;

                string upString = f, downString = f;
                upString[k] = up;
                downString[k] = down;

                if(deadset.find(upString) == deadset.end() && visited.find(upString) == visited.end()){
                    // if not in deadends set and not visited
                    q.push(upString);
                    visited.insert(upString);
                }

                if(deadset.find(downString) == deadset.end() && visited.find(downString) == visited.end()){
                    // if not in deadends set and not visited
                    visited.insert(downString);
                    q.push(downString);
                }

            }
        }

        return -1;
    }
};