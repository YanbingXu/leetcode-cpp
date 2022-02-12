/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        // 实际上就是有x个连续的y
        string prev = "1";
        for (int i = 2; i <= n; ++i)
        {
            string cur = "";
            int start = 0;
            int pos = 0;

            while (pos < prev.size())
            {
                while (pos < prev.size() && prev[start] == prev[pos])
                {
                    pos++;
                }
                cur += to_string(pos - start) + prev[start];
                start = pos;
            }
            prev = cur;
        }
        return prev;

    }
};
// @lc code=end

