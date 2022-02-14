/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        //斐波那契，超时。。打扰了
        // if (n == 0 || n == 1)
        // {
        //     return 1;

        // }else {
        //     return climbStairs(n-1) + climbStairs(n - 2);
        // }

        // 动态规划 + 滚动数组
        // r----p-----q
        // 0----1-----1
        // 1----1-----2 n = 0
        // 1----2-----3 n = 1
        // 2----3-----5 n = 2
        long r = 0, p = 1, q = 1;
        for (int i = 0; i <= n; i++)
        {
            r = p;
            p = q;
            q = r + p;
        }
        return r;

        // 矩阵快速幂：to-do：



    }
};
// @lc code=end

