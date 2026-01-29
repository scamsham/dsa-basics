class Solution {
public:
    void printAllPaths(unordered_map<int, vector<int> > &um, int source, int target, vector<int> &path, vector<vector<int>>&paths){
        if(source == target){
            path.push_back(target);
            paths.push_back(path);
            path.pop_back();
        }

        path.push_back(source);

        for(auto &element: um[source]){
            // each element in adj vector
            printAllPaths(um, element, target, path, paths);
        }

        path.pop_back();
        return ;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<int> > um;
        int n = graph.size();
        // create the graph
        for(int i = 0; i < n; i++){
            for(int &x: graph[i]){
                um[i].push_back(x);
            }
        }

        vector<vector<int>> paths;
        vector<int> path;
        printAllPaths(um, 0, n - 1, path, paths);

        return paths;
    }
};