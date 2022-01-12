/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        // // 如果长度为奇数，直接return
        // if (s.size() % 2 == 1)
        // {
        //     return false;
        // }

        // 栈的简单应用，遇到左括号就入栈，遇到右括号就弹栈，如果括号类型不匹配就是false
        stack<char> stackStore;

        unordered_map<char, char> dict = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        for (char c : s)
        {
            if (dict.count(c)) //找不到
            {
                if (stackStore.empty() || stackStore.top() != dict[c])
                {
                    return false;
                }
                stackStore.pop();
            }
            else
            {
                stackStore.push(c);
            }
        }
        return stackStore.empty();
    }
};
// @lc code=end
