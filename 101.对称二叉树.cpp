/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if (p == nullptr || q == nullptr)
        {
            return false;
        }
        return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);

    }
    bool isSymmetric(TreeNode* root) {
        // 左子树和右子树镜像对称，那么这棵树就是镜像的
        // 用两个指针，首先都指向root，p指针右移时q指针左移，递归判断每一个节点是否相同
        return isSymmetric(root, root);
    }
};
// @lc code=end

