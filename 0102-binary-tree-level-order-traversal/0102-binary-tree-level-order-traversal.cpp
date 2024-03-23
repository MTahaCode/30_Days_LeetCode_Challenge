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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> NodeQueue;

        vector<vector<int>> MasterVector;

        if (!root) return {};

        NodeQueue.push(root);

        while (!NodeQueue.empty())
        {
            vector<int> temp;
            int n = NodeQueue.size();

            for (int i = 0; i < n; i++)
            {
                temp.push_back(NodeQueue.front()->val);

                if (NodeQueue.front()->left)
                {
                    NodeQueue.push(NodeQueue.front()->left);
                }
                if (NodeQueue.front()->right)
                {
                    NodeQueue.push(NodeQueue.front()->right);
                }

                NodeQueue.pop();
            }
            MasterVector.push_back(temp);
        }
        return MasterVector;
    }
};