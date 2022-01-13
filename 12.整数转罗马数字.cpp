/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
// 一定要在类外初始化
const pair<int, string> valueSymbol[] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
};
class Solution
{
public:
    string intToRoman(int num){
        // 根据罗马数字的唯一表示法，为了表示一个给定的整数num，
        // 我们寻找不超过num 的最大符号值，将 num 减去该符号值，
        // 然后继续寻找不超过 num 的最大符号值，将该符号拼接在上一个找到的符号之后，
        // 循环直至 num 为 0。

        string roman;
        for(auto &[val, symbol] : valueSymbol){
            while (num >= val)
            {
                num -= val;
                roman += symbol;
            }
            if (num == 0)
            {
                break;
            }

        }
        return roman;
    }
};
// @lc code=end
