/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // bool isValidBST(TreeNode* root, long lower, long upper) {
    //     if (root == nullptr) // 递归停止条件
    //     {
    //         return true;
    //     }
    //     if (root->val <= lower || root->val >= upper) // 注意（lower,upper）是开区间。
    //     {
    //         return false;
    //     }
    //     // 递归左右子树
    //     return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);

    // }
    // bool isValidBST(TreeNode* root) {
    //     // 法一：递归。二叉搜索树左子树小于当前节点，右子树大于当前节点

    //     return isValidBST(root, LONG_MIN, LONG_MAX); // 初始上下界分别是-inf 和 inf

    // }

    // 法二：根据二叉搜索树的性质，我们采用中序遍历（左根右）一定会得到一个升序序列。
    bool inorderTraversal(TreeNode* root) {
        // 用迭代的方法进行中序遍历，自己维护一个栈
        if (root == nullptr)
        {
            return false;
        }

        stack<TreeNode*> sk;
        long pre_val = LONG_MIN; // pre-val初始化为-inf
        while (!sk.empty() || root != nullptr)
        {
            while (root!=nullptr) // 当前节点不为空的时候，就推进栈，往下遍历左子树
            {
                sk.push(root);
                root = root->left;
            }
            // 此时左子树已全遍历完，就要开始pop
            root = sk.top();
            sk.pop();
            // 要确保中序是升序就要把当前值和前一个值做比较，因此前一个值要暂存起来
            if (root->val <= pre_val)
            {
                return false;
            }
            pre_val = root->val;
            root = root->right;
        }
        return true;


    }
    bool isValidBST(TreeNode* root){
        return inorderTraversal(root);
    }
};
// @lc code=end

