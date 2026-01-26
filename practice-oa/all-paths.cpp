#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Node {
    public: 
        string city;
};

class Graph {
public:
   unordered_map<string, vector<string>> um;

    void addEdge(string u,string v) {
        um[u].push_back(v);
    }

    void printAllPathsBFS(string start, string dest) {
        queue<vector<string>> q;
        q.push({start});


        while (!q.empty()) {
            vector<string> path = q.front();
            q.pop();

            string last = path.back();

            // If we reached the destination, print the path
           if (last == dest) {
                for(auto &p: path){
                    cout<<p<<" --> ";
                }
                cout<<endl;
            }

            // Explore neighbors
            for (string &nbr : um[last]) {
                if (find(path.begin(), path.end(), nbr) == path.end()) {
                    vector<string> newPath = path;
                    newPath.push_back(nbr);
                    q.push(newPath);
                }
            }
        }
    }


    void dfs(string start, unordered_map<string, bool> &visited, vector<string> &path, string dest){
        visited[start] = true;
        path.push_back(start);

        if(start == dest){
            for(auto &p: path){
                cout<<p<<" --> ";
            }
            cout<<endl;     
        }else{
            for(auto &nbr: um[start]){
                if(!visited[nbr]){
                    dfs(nbr, visited, path, dest);
                }
            }
        }
        path.pop_back();
        visited[start] = false;
        return ;
    }

    void dfs1(string current, unordered_map<string, bool> &visited, vector<string> &path, string dest) {
    // 1. Add current node to path and mark visited
    visited[current] = true;
    path.push_back(current);

    // 2. Base Case: Destination reached
    if (current == dest) {
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " --> ");
        }
        cout << endl;
    } else {
        // 3. Recur for all neighbors
        for (const string& nbr : um[current]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, path, dest);
            }
        }
    }

    // 4. BACKTRACK: Remove node from path and mark unvisited
    path.pop_back();
    visited[current] = false; 
}

    // This is where your logic goes!
    void printAllPaths(string start,string end) {
        // Your code here
        unordered_map<string, bool> visited;
        vector<string> path;

        dfs(start, visited, path, end);
    }
};

int main() {
    Graph g;
    
    // Core paths
    g.addEdge("NY", "CHI");
    g.addEdge("NY", "SF");
    g.addEdge("CHI", "DEN");
    g.addEdge("CHI", "SF");
    g.addEdge("DEN", "SF");
    g.addEdge("DEN", "LA");
    g.addEdge("SF", "LA");
    
    // Potential cycle/backtrack test
    g.addEdge("SF", "NY"); 

   cout << "Finding all flight paths from NY to SF:" <<endl;
    g.printAllPaths("NY", "SF");
    cout<<endl;
    g.printAllPathsBFS("NY", "SF");

    return 0;
}