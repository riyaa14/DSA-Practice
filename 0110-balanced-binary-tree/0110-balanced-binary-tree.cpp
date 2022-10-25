/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool balanced = true;
    
   int height(TreeNode* root){
       
       if(!root) return 0;
       
       int heightLST = height(root->left);
       int heightRST = height(root->right);
       
       if(abs(heightLST-heightRST) > 1) balanced = false;
       
       return max(heightLST, heightRST) + 1;
       
   }
    
    bool isBalanced(TreeNode* root) {
        
        if(!root) return true;
        height(root);
        return balanced;
        
    }
};