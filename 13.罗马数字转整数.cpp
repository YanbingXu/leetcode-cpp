/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, int> table = {
            {'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000},
    };
    int romanToInt(string s) {
        int res = 0;
        // 如果左边数字比右边数字小，则左边取反再相加
        //否则依次相加
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (table[s[i]] < table[s[i + 1]])
            {
                res += -table[s[i]];
            }else {
                res += table[s[i]];
            }

        }

        res += table[s[s.size() - 1]];
        return res;

    }
};
// @lc code=end

