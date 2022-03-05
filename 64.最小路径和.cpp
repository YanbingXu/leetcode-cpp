/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 动态规划 状态转移方程：dp[m][n]表示（m,n）格子上的最小数字总和
        // dp[m][n] = min(dp[m-1][n], dp[m][n-1] + curr[m][n]),注意边界条件
        int row = grid.size();
        int col = grid[0].size();


        vector<vector<int>>dp(row, vector<int>(col));
        // 注意边界条件
        dp[0][0] = grid[0][0];
        for (int k = 1; k < row; k++)
        {
            dp[k][0] = dp[k-1][0] + grid[k][0];
        }
        for (int t = 1; t < col; t++)
        {
            dp[0][t] = dp[0][t-1]+ grid[0][t];
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }

        }

        return dp[row-1][col-1];

    }
};
// @lc code=end

