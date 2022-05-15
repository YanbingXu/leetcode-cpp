/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* getMedium(ListNode* left, ListNode* right){
        ListNode* slow = left;
        ListNode* fast = left;
        while (fast != right && fast->next != right) // 注意这里的判断条件
        {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
    TreeNode* buildTree(ListNode* left, ListNode* right){
        if (left == right)
        {
            return nullptr;
        }

        ListNode* mid = getMedium(left, right);

        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(left, mid);
        root->right = buildTree(mid->next, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // 1. 找到链表的中位数。根据中位数的定义，中位数左边为左子树，右边为右子树，高度差一定不超过1。
        // 2. 快慢指针找到中位数，快指针移动两次，慢指针移动一次，快指针到右端点，慢指针到中位数。
        // 3. 递归构造左右子树

        return buildTree(head, nullptr);
    }
};
// @lc code=end

