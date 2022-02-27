/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     // 法一：递归
    //     // 中序遍历：左-根-右

    //     vector<int>res;
    //     inorder(root, res);

    //     return res;

    // }

    // void inorder(TreeNode* root, vector<int>& res){
    //     // 递归停止条件:碰到空节点
    //     if (root == nullptr)
    //     {
    //         return;
    //     }

    //     inorder(root->left, res); // 递归左子树
    //     res.push_back(root->val);
    //     inorder(root->right, res); // 递归右子树
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        // 法一：迭代（自己维护一个栈）
        // 中序遍历：左-根-右，也就是出栈顺序是左-根-右，那么入栈顺序：右-根-左
        // 参考https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/yan-se-biao-ji-fa-yi-chong-tong-yong-qie-jian-ming/ 设置一个标志is_visit, 默认是false
        // 当is_visit为0，将其置1，依次入栈右-根-左。 is_visit为1(第二次遇到该节点)，直接记录res
        stack<pair<TreeNode*, int>>sk;
        vector<int>res;

        sk.push(make_pair(root, 0));
        while (!sk.empty())
        {
            auto[root, is_visit] = sk.top();
            sk.pop();
            if (root == nullptr){
                continue;
            }

            if (is_visit == 0)
            {
                sk.push(make_pair(root->right, 0));
                sk.push(make_pair(root, 1));
                sk.push(make_pair(root->left, 0));
            }else {
                res.push_back(root->val);
            }
        }
        return res;


    }
};
// @lc code=end

