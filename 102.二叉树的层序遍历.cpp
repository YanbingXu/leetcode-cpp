/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 层序遍历通常我们会借助queue
        // 根节点入队-> 节点出队-> 左子节点入队 -> 右子节点入队 ->节点出队（循环） 直到queue为空
        // 怎么存？ que.size()可以对应每一层的res
        queue<TreeNode*>que;
        vector<vector<int>>res;
        // 注意判空
        if (root == nullptr)
        {
            return res;
        }

        que.push(root);
        // cout<<"root->val:"<<root->val<<endl;
        while (!que.empty())
        {

            // 利用这个来记录res每一层的个数
            int currSize = que.size();
            // cout<<"currSize:"<<currSize<<endl;
            res.push_back(vector<int>()); //这里注意定义一个vector
            for (int i = 0; i < currSize; i++)
            {
                // 记录当前node，为了索引到左子节点和右子节点
                TreeNode* curr = que.front();
                // cout<<"curr->val:"<<curr->val<<endl;
                res.back().push_back(curr->val); //注意语法
                // cout<<"res:"<<res.size()<<endl;
                que.pop();
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
                // cout<<"curr->left->val:"<<curr->left->val<<", curr->right->val:"<<curr->right->val<<endl;
            }
        }
        return res;

    }
};
// @lc code=end

