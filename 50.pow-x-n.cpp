/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double quickMul(double x, int a) {
        if (a == 0)
        {
            return 1.0;
        }
        double y = quickMul(x, a / 2);
        if (a % 2 == 0)
        {
            return y * y;
        }else {
            return y * y * x;
        }



    }
    double myPow(double x, int n) {
        // 快速幂：先递归的计算出y = x^[n/2],如果n为偶数，x^n = y^2,否则，x^n = y^2 * x
        // n=0结束递归
        return n>=0 ? quickMul(x, n) : 1.0 / quickMul(x, n);
    }
};
// @lc code=end

