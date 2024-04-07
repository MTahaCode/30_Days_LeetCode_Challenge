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
        
        map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        
        return recurBuildTree(preorder, inorderMap, preIndex, 0, inorder.size() - 1);
        
    }
    
    TreeNode* recurBuildTree(
        vector<int>& preorder,
        map<int, int>& inorderMap,
        int& preIndex,
        int start,
        int end)
    {
        if (start > end)
        {
            return nullptr;
        }

        int rootIndex = inorderMap[preorder[preIndex]];

        TreeNode* curr = new TreeNode(preorder[preIndex++]);
        curr->left = recurBuildTree(preorder, inorderMap, preIndex, start, rootIndex - 1);
        curr->right = recurBuildTree(preorder, inorderMap, preIndex, rootIndex + 1, end);

        return curr;
    }
};