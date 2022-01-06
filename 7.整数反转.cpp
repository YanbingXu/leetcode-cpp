/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        

        if (res>__INT_MAX__ || res < -__INT_MAX__-1) {
            return 0;
        }

        return res;

        // return (res>__INT_MAX__) || (res < (-__INT_MAX__-1)) ? 0 : res;
    }
};
// @lc code=end

