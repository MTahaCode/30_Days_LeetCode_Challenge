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
    int kthSmallest(TreeNode* root, int k) {

        int nodeIndex = 0;
        return helperSmallest(root, k, nodeIndex);
    }

    int helperSmallest(TreeNode* root, int k, int& nodeIndex) {
        if (!root) return -1;

        int left = helperSmallest(root->left, k, nodeIndex);

        nodeIndex++;
        if (nodeIndex == k)
        {
            return root->val;
        }

        int right = helperSmallest(root->right, k, nodeIndex);

        if (left != -1) {
            return left;
        }
        else if (right != -1) {
            return right;
        }

        return -1;
    }
};