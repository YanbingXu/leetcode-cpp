/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*>generateTrees(int start, int end) {
        if (start > end)
        {
            return {nullptr}; //当前二叉搜索树为空，返回空节点
        }

        vector<TreeNode*>res;
        //枚举所有可能的根节点 递归生成左子树和右子树
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode*>leftTrees = generateTrees(start, i-1);
            vector<TreeNode*>rightTrees = generateTrees(i+1, end);
            // 从左子树和右子树中随机选一个子树组成一个二叉搜索树
            for (auto& leftTree : leftTrees)
            {
                for (auto& rightTree : rightTrees)
                {
                    TreeNode* curr = new TreeNode(i);
                    curr->left = leftTree;
                    curr->right = rightTree;
                    res.push_back(curr);
                }
            }
        }
        // cout<<res.size()<<endl;
        return res;

    }
    vector<TreeNode*> generateTrees(int n) {
        // 思路：回溯
        // 二叉搜索树重要性质：左子树节点值小于根节点，右子树节点值大于根节点
        return generateTrees(1, n);

    }

};
// @lc code=end

