/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 动态规划 dp[m][n] = dp[m-1][n] + dp[m][n-1];
        vector<vector<int>>dp(m, vector<int>(n)); // 利用vector创建二维数组
        for (int j = 0; j < m; j++)
        {
            dp[j][0] = 1;
        }
        for (int k = 0; k < n; k++)
        {
            dp[0][k] = 1;
        }
        // 所有的边都是边界问题


        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                // cout<<dp[i][j]<<endl;
            }

        }
        return dp[m-1][n-1];

    }
};
// @lc code=end

