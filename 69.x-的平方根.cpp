/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        // 解法一：数学公式近似 sqrt(x) = exp(0.5 * log(x))
        // if (x == 0)
        // {
        //     return 0;
        // }
        // int res = exp(0.5 * log(x));
        // return  (long long)(res + 1) * (res + 1) > x ? res : (res + 1);

        // 解法二：二分查找
        int start = 0, end = x, res = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if ((long)mid * mid <= x)
            {
                start = mid + 1;
                res = mid;
            }else {
                end = mid - 1;
            }

        }
        return res;

        // 法三：牛顿迭代：todo



    }
};
// @lc code=end

