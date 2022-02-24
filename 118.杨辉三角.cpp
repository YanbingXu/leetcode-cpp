/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 每个数字等于上一行的左右两个数字之和，可用此性质写出整个杨辉三角。
        vector<vector<int>>res(numRows);
        for (int i = 0; i < numRows; i++)
        {
            res[i].resize(i + 1); // 第0行1个数，第1行2个数.....
            res[i][0] = res[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                res[i][j] = res[i - 1][j - 1] + res[i-1][j];
            }

        }
        return res;

    }
};
// @lc code=end

