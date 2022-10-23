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
    
    int height(TreeNode* root){
        
        if(!root) return 0;
        
        int heightLST = height(root->left);
        int heightRST = height(root->right);
        
        return max(heightLST, heightRST) + 1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        // height of lst + height of rst = diameter
        // max(height of lst, height of rst) = height
        
        if(!root) return 0;
        
        int diaLST = diameterOfBinaryTree(root->left);
        int diaRST = diameterOfBinaryTree(root->right);
        int dia = height(root->left) + height(root->right);
        
        return max(dia, max(diaRST, diaLST));
    }
};