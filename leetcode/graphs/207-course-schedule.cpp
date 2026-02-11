class Solution {
public:
    bool dfsCycle(unordered_map<int, vector<int>> &um, int index, vector<bool> &visited, vector<bool> &recStack){
        visited[index] = true;
        recStack[index] = true;

        for(int &child: um[index]){
            if(!visited[child]){
                bool cycleFound = dfsCycle(um, child, visited, recStack);
                if(cycleFound){
                    return true;
                }
            }else if(recStack[child]){
                // if it is already in the stack
                // cycle found 
                return true;
            }
        }

        recStack[index] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> um;
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        for(vector<int> &prereq: prerequisites){
            um[prereq[1]].push_back(prereq[0]);
        }

        // 0 -> 1

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(dfsCycle(um, i, visited, recStack)){
                    // if cycle found is true we return false
                    return false;
                }
            }
        }

        // no cycle found
        return true;
    }
};