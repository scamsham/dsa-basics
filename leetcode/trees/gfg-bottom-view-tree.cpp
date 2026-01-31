/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> view;
        map<int, Node*> um;
        
        queue<pair<Node*, int>> q;
        
        
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int> f = q.front();
            q.pop();
            
            Node* fNode = f.first;
            int dist = f.second;
            
            
            um[dist] = fNode;
            
            
            if(fNode->left){
                q.push({fNode->left, dist - 1});
            }
            if(fNode->right){
                q.push({fNode->right, dist + 1});
            }
            
        }
        
        
        for(auto &[key, node] : um){
            view.push_back(node->data);
        }
        
        return view;
    }
};