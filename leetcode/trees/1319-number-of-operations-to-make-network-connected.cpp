class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &um, unordered_map<int, bool> &visited, int currentNode){
        visited[currentNode] = true;
        
        for(auto &childNode: um[currentNode]){
            if(!visited[childNode]){
                dfs(um, visited, childNode);
            }
        }

        return ;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // count number of unconnected graphs or nodes
        // count total numbr of edges
        // if number of unconnected graphs/nodes
        // for a graph to be connected it needs to have n - 1 connections
        
        int edges = connections.size();
        unordered_map<int, vector<int>> um;
        unordered_map<int, bool> visited;

        // create a graph
        for(int i = 0; i < edges; i++){
            int x = connections[i][0];
            int y = connections[i][1];
            um[x].push_back(y);
            um[y].push_back(x);
        }

        int unconnectedGraphs = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(um, visited, i);
                unconnectedGraphs++;
            }
        }

        // if number of edges is less than n - 1 nodes, you cannot connect all components
        if(edges  < n - 1){
            return -1;
        }

        return unconnectedGraphs - 1;
    }
};