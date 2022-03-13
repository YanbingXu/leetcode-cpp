/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // // 深度优先搜索：先比较跟节点，再比较左子树和右子树
        // if (p == nullptr && q == nullptr)
        // {
        //     return true;
        // }else if (p == nullptr && q != nullptr || p != nullptr && q == nullptr)
        // {
        //     return false;
        // }else {
        //     // 二者都不是空树
        //     // 先判断当前节点值是否相同
        //     if (p->val != q->val)
        //     {
        //         return false;
        //     }
        //     // 递归比较左子树和右子树
        //     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        // }

        // 方法二：广度优先搜索, 把每一个节点依次入队，出队做比较
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        // 1. 首先判断两棵树是否为空
        if (p == nullptr && q == nullptr)
        {
            return true;
        }else if (p == nullptr || q == nullptr) {
            return false;
        }else {
            // 2. 两棵树都不为空，使用两个队列分别存储二叉树的节点。初识时加入根节点
            q1.push(p);
            q2.push(q);
            cout<<"test111"<<endl;
            // 3. 每次从两个队列各取一个节点，进行如下比较操作
            while (!q1.empty() && !q2.empty())
            {
                TreeNode* cur_p = q1.front();
                q1.pop();
                TreeNode* cur_q = q2.front();
                q2.pop();
                cout<<"test222"<<endl;
                // 4. 比较两个节点的值，如果两个节点的值不相同，那么一定是不同的树
                if(cur_p->val != cur_q ->val) {
                    return false;
                }else {
                    // 5. 如果两个节点的值相同，就判断他们的子节点，如果只有一个节点的子节点为空，那么也不相同
                    if (cur_p->left == nullptr && cur_q->left != nullptr || (cur_p->left != nullptr && cur_q->left == nullptr))
                    {
                        return false;
                    }
                    if (cur_p->right == nullptr && cur_q->right != nullptr || (cur_p->right != nullptr && cur_q->right == nullptr)) {
                        return false;
                    }
                    // 6. 所有子节点都不为空，将子节点依次入队，先加入左子节点，再加入右子节点
                    if (cur_p->left != nullptr)
                    {
                        q1.push(cur_p->left);
                    }
                    if (cur_p->right != nullptr)
                    {
                        q1.push(cur_p->right);
                    }
                    if (cur_q->left != nullptr)
                    {
                        q2.push(cur_q->left);
                    }
                    if (cur_q->right != nullptr)
                    {
                        q2.push(cur_q->right);
                    }
                }
            }
        }
        // 7. 如果搜索结束两个队列都为空，则二叉树相同，只有一个队列为空，则二叉树不同
        return q1.empty() && q2.empty();





    }
};
// @lc code=end

