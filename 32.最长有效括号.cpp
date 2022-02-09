/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        // 法一：考虑用栈，因为栈在处理合法括号上有天然优势
        stack<int> sk;
        int res = 0;
        for (int i = 0, start = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                //将下标压栈
                sk.push(i);

            }else {
                // 栈不为空，弹栈
                if (!sk.empty())
                {
                    sk.pop();
                    // 此时栈为空，有效括号长度为i - start +1
                    if (sk.empty())
                    {
                        res = max(res, i - start +1);
                    }else {
                        // 如果不为空，则有效括号的长度为 i - (sk.top + 1) + 1
                        res = max(res, i - sk.top());
                    }
                }else {
                    // 栈为空，右括号开头不为有效括号,start 更新为i + 1
                    start = i + 1;
                }
            }

        }
        return res;


    }
};
// @lc code=end

