/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        // 斐波那契翻译
        // if (n == 0)
        // {
        //     return 0;
        // }else if(n == 1) {
        //     return 1;
        // }else {
        //     return fib(n-1) + fib(n - 2);
        // }


        // 注意和79题的区别！！
        int p = 0, q = 1, r = 1;
        for (int i = 1; i <= n; i++)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return p;

    }
};
// @lc code=end

