/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
    bool isCompleteTree(TreeNode* root) {
        // 奇思妙想：nullptr的后面如果有值，一定不是完全二叉树
        //遍历树，借助queue
        queue<TreeNode*>q;
        bool reachNull = false;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == nullptr)
            {
                reachNull = true;
                continue;
            }else{
                if (reachNull)
                {
                    return false;
                }
                q.push(curr->left);
                q.push(curr->right);
            }

        }
        return true;
    }



};
// @lc code=end

