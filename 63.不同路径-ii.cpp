/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 参考62的思路，列出动态规划的转移方程，考虑障碍物所以会比较复杂
        // 考虑边界条件
        int col = obstacleGrid[0].size();
        int row = obstacleGrid.size();

        vector<vector<int>>dp(row, vector<int>(col));

        // 写边界条件
        for (int i = 0; i < row && obstacleGrid[i][0] == 0; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < col && obstacleGrid[0][j] == 0 ; j++)
        {
             dp[0][j] = 1;
        }

        for (int m = 1; m < row; m++)
        {
            for (int n = 1; n < col; n++)
            {
                if(obstacleGrid[m][n] == 0) {
                    dp[m][n] = dp[m-1][n] + dp[m][n-1];
                }
            }

        }

        return dp[row-1][col-1];


        // 法二：滚动数组思想优化：todo



    }
};
// @lc code=end

