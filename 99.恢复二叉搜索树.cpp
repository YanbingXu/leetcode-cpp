/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {
        // 参考98题的思路，一个二叉搜索树的中序遍历一定是升序，那找到错误的两个节点再交换回来
        stack<TreeNode*>sk;
        TreeNode* pre = nullptr;
        TreeNode* err1 = nullptr;
        TreeNode* err2 = nullptr;
        while (!sk.empty() || root !=nullptr)
        {
            while(root != nullptr){
                // 当前节点不为空，就压栈以及找左子节点
                sk.push(root);
                root = root->left;
            }
            // 现在开始弹栈
            root = sk.top();

            sk.pop();
            // 需要暂存前一个节点，然后两个节点之间比较大小，如果<=就交换两个节点
            if (pre != nullptr && root->val <= pre->val)
            {
                err1 = root;
                if (err2 == nullptr) // 看不懂
                {
                    err2 = pre;
                }else {
                    break;
                }
            }

            pre = root;
            // 遍历右子节点
            root = root->right;
        }
        swap(err1->val, err2->val);

    }
};
// @lc code=end

