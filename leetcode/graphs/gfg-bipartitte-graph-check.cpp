/*
    https://www.geeksforgeeks.org/problems/bipartite-graph/1#
*/

class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        unordered_map<int, vector<int>> um;
        
        for(int i = 0; i < edges.size(); i++){
            int x = edges[i][0], y = edges[i][1];
            um[x].push_back(y);
            um[y].push_back(x);
        }
        
        unordered_map<int, int> color;
        queue<int> q;
        q.push(0);
        color[0] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int& nbr: um[node]){
                if(color.find(nbr) == color.end()){
                    // if not colored
                    color[nbr] = 1 - color[node];
                    q.push(nbr);
                }else if(color[nbr] == color[node]){
                    // if neighbor is same color then its not bipartite
                    return false;
                }
            }
        }
        
        return true;
    }
};