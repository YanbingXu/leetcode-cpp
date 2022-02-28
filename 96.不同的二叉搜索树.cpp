/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    // 这个方法超时了
    // vector<TreeNode*> generateTrees(int start, int end){
    //     if (start > end)
    //     {
    //         return {nullptr};
    //     }
    //     vector<TreeNode*> res;
    //     for (int i = start; i <= end; i++) //枚举根节点
    //     {
    //         vector<TreeNode*> leftTrees = generateTrees(start, i-1);
    //         vector<TreeNode*> rightTrees = generateTrees(i+1, end);
    //         for (auto &leftTree : leftTrees)
    //         {
    //             for (auto &rightTree : rightTrees)
    //             {
    //                 TreeNode* curr = new TreeNode(i);
    //                 curr->left = leftTree;
    //                 curr->right = rightTree;
    //                 res.push_back(curr);
    //             }
    //         }
    //     }
    //     return res;
    // }
    // int numTrees(int n) {
    //     // 思路：参考95题的做法，返回值从原来的结果改成size
    //     vector<TreeNode*> res = generateTrees(1, n);
    //     return res.size();
    // }

    // 动态规划，参考答案https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode-solution/
    int numTrees(int n) {
        vector<int>dp = vector<int>(n+1);
        dp[0]=dp[1]=1;

        for (int i = 2; i <= n; i++)
        {
           for (int j = 1; j < i+1; j++)
           {
               dp[i] += dp[j-1] * dp[i-j];
           }

        }
        return dp[n];

    }
};
// @lc code=end

