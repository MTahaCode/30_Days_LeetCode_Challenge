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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preIndex = 0;
        return recurBuildTree(preorder, inorder, preIndex, 0, inorder.size() - 1);
        
    }
    
    TreeNode* recurBuildTree(
        vector<int>& preorder,
        vector<int>& inorder,
        int& preIndex,
        int start,
        int end)
    {
        if (preIndex > preorder.size() || start > end)
        {
            return nullptr;
        }

        int rootIndex = start;
        for (int index = start; index <= end; index++)
        {
            if (inorder[index] == preorder[preIndex])
            {
                rootIndex = index;
                break;
            }
        }

        TreeNode* curr = new TreeNode(preorder[preIndex++]);
        curr->left = recurBuildTree(preorder, inorder, preIndex, start, rootIndex - 1);
        curr->right = recurBuildTree(preorder, inorder, preIndex, rootIndex + 1, end);

        return curr;
    }
};