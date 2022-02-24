/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int>in_map;

    TreeNode* buildMyTree(unordered_map<int, int>& map, int in_left, int in_right, vector<int>& postorder, int post_left, int post_right){
        if (in_left > in_right || post_left > post_right)
        {
            return nullptr;
        }

        // 确定根节点的值
        int root_val = postorder[post_right];
        // 确定根节点在中序遍历中的索引
        int pivot_idx = map[root_val];
        // 创建根节点
        TreeNode* root = new TreeNode(root_val);

        // 递归创建左子树，画图！计算各边界索引
        root->left = buildMyTree(map, in_left, pivot_idx-1, postorder, post_left, pivot_idx-1-in_left+post_left);
        // 递归创建右子树
        root->right = buildMyTree(map, pivot_idx+1, in_right, postorder, pivot_idx-in_left+post_left, post_right-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 思路参考105，递归方法：
        // 中序：左-根-右
        // 后序：左-右-根

        int size = inorder.size();

        // 用哈希表来存储中序遍历的索引和值
        for (int i = 0; i < size; i++)
        {
            in_map[inorder[i]] = i;
        }

        return buildMyTree(in_map, 0, size-1, postorder, 0, size-1);


    }


};
// @lc code=end

