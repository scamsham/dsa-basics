/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> um;
        queue<Node*> q;
        
        // queue helps iterate over original graph
        q.push(node);        

        if(node == NULL){
            return NULL;
        }

        Node *clonedGraph = new Node(node->val);
        um[node] = clonedGraph;

        while(!q.empty()){
            Node* f = q.front();
            q.pop();
            for(auto &neighbor: f->neighbors){
                // check the map if the clone is made
                if(um.find(neighbor) == um.end()){
                    Node* newNode = new Node(neighbor->val);
                    um[neighbor] = newNode;

                    // push the original graph neighbor in the queue
                    q.push(neighbor);
                }
                // create the adjacency list for cloned one
                // um[f] is cloned graph node, um[neighbor] is pushed to adjacency list of cloned graph
                um[f]->neighbors.push_back(um[neighbor]);
            }
        }
        
        return clonedGraph;
    }
};