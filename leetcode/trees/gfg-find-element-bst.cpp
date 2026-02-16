/*

https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1

class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        if(!root){
            return false;
        }
        
        if(root->data == key){
            return true;
        }
        
        
        if(root->data < key){
            return  search(root->right, key);
        }else{
            return search(root->left, key);
        }
        
        return false;
    }
};