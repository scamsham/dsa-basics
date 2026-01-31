/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void leftViewUtil(Node *root, vector<int> &view, int level){
        if(!root){
            return ;
        }
        
        if(level == view.size()){
            view.push_back(root->data);
        }
        
        leftViewUtil(root->left, view, level + 1);
        leftViewUtil(root->right, view, level + 1);
        
        return ;
    }
  
    vector<int> leftView(Node *root) {
        // code here
        vector<int> view;
        
        if(!root){
            return view;
        }
        
        leftViewUtil(root, view, 0);
    }
};