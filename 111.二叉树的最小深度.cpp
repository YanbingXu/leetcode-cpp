/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
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
    int minDepth(TreeNode* root) {
        // bfs,广度优先保证了最先搜到的肯定是最小深度。
        if (root ==  nullptr)
        {
            return 0;
        }

        queue<pair<TreeNode*, int>>q;
        q.push(pair<TreeNode*, int>(root, 1));
        while (!q.empty())
        {
            TreeNode* front_node = q.front().first;
            int depth = q.front().second;

            q.pop();
            if (front_node->left != nullptr)
            {
                q.push(pair<TreeNode*, int>(front_node->left, depth+1));
            }
            if (front_node->right != nullptr)
            {
                q.push(pair<TreeNode*, int>(front_node->right, depth+1));
            }

            if (front_node->left == nullptr && front_node->right == nullptr){
                return depth;
            }
        }
        return 0;
    }
};
// @lc code=end

