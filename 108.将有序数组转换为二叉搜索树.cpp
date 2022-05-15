/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* buildTree(vector<int>& nums, int left, int right){
        if (left > right)
        {
            return nullptr;
        }

        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, left, mid-1);
        root->right = buildTree(nums, mid+1, right);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 选择中间位置作为根节点，那么左右子树的高度差不超过1
        return buildTree(nums, 0, nums.size()-1);

    }
};
// @lc code=end

