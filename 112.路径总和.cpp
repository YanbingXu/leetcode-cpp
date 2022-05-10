/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    // 方法一：递归
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if(root == nullptr) return false;

    //     if (root->left == nullptr && root->right == nullptr)
    //     {
    //         return root->val == targetSum;
    //     }

    //     return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum - root->val);
    // }

    // 方法二：bfs
    bool hasPathSum(TreeNode* root, int targetSum){
        if (root == nullptr)
        {
            return false;
        }

        // 借助栈，层序遍历
        queue<TreeNode*>q_node;
        queue<int>q_val;
        q_node.push(root);
        q_val.push(root->val);
        while (!q_node.empty())
        {
            TreeNode* temp_node = q_node.front();
            int temp_val = q_val.front();
            // temp_sum += temp_node->val;
            cout<<"temp_val:"<<temp_val<<endl;
            q_node.pop();
            q_val.pop();
            if (temp_node->left == nullptr && temp_node->right == nullptr)
            {
                if(temp_val == targetSum){
                    return true;
                }
                continue;
            }

            if (temp_node->left != nullptr)
            {
                q_node.push(temp_node->left);
                // temp_sum +=temp_node->left->val;
                q_val.push(temp_val + temp_node->left->val);
            }
            if (temp_node->right != nullptr)
            {
                q_node.push(temp_node->right);
                // temp_sum +=temp_node->right->val;
                q_val.push(temp_val + temp_node->right->val);
            }
        }

        return false;


    }
};
// @lc code=end

