class Solution {
public:
    bool dfsCyclic(unordered_map<int, vector<int>> &um, int source, vector<bool> &visited, vector<bool> &recStack, stack<int> &s){
        visited[source] = true;
        recStack[source] = true;

        for(int &x: um[source]){
            if(!visited[x]){
                if(dfsCyclic(um, x, visited, recStack, s)){
                    return true;
                }
            }else if(recStack[x]){
                return true;
            }
        }

        recStack[source] = false;
        // Post-order: push to stack after visiting all dependencies
        s.push(source);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Clearly a DAG problem
        // Topological sort since they are asking about sequence of execution 
        // based on task B execution depending on task A
        // Check for a cycle
        // If Yes, return {}
        // If No, return sequence.
        unordered_map<int, vector<int>> um;
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        stack<int> s;

        // create a graph
        for(vector<int> &prereq: prerequisites){
            um[prereq[1]].push_back(prereq[0]);
        }


        for(int i = 0; i < numCourses; i++){
            // iterate over each vertex
            if(!visited[i]){
                if(dfsCyclic(um, i, visited, recStack, s)){
                    return {};
                }
            }
        }

        vector<int> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }

        return v;
    }
};