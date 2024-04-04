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
    bool isSymmetric(TreeNode* root) {
        
        if (!root)
        {
            return true;
        }
        
        return isRecurrSymmetric(root->left, root->right);
    }
    
    bool isRecurrSymmetric(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)
        {
            return true;
        }
        else if (!left || !right)
        {
            return false;
        }
        
        return (left->val == right->val) && 
            isRecurrSymmetric(left->left, right->right) && 
            isRecurrSymmetric(left->right, right->left);
    }
};