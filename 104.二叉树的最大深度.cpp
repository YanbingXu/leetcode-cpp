/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        // 法一：深度优先搜索，假如我们知道左子树和右子树的最大深度为l和r，那么maxDepth=max（l，r）+1
        // 而求解左子树和右子树的深度可以递归

        if (root == nullptr)
        {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;


    }
};
// @lc code=end

