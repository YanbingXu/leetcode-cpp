/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // 相比118题，返回的是第三行的内容，可以先参照118写出全部的，return res【rowIndex】
        vector<vector<int>>res(rowIndex + 1);
        for (int i = 0; i < rowIndex + 1; i++)
        {
            res[i].resize(i+1);
            res[i][0] = res[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }

        }
        return res[rowIndex];

    }
};
// @lc code=end

