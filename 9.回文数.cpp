/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) {
            return false;
        }
        // get the reversed number
        long res = 0;
        int temp_x = x;
        while (temp_x)
        {
            res = res * 10 + temp_x % 10;
            temp_x /= 10;
        }
        // compare
        if (res == x) {
            return true;
        }
        return false;
    }
};
// @lc code=end

