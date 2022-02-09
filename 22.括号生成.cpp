/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    // string cur = "";
    vector<string> generateParenthesis(int n) {
        // if (/* condition */)
        // {
        //     /* code */
        // }


        dfs("", n, n);

        return res;
    }

    void dfs(string cur, int left, int right) {
        if (left == 0 && right == 0)
        {
            res.push_back(cur);
            return;
        }
        // 如果剩下的左括号比右括号多，这个是无效的组合
        if (left < right)
        {
            // 如果剩下的左括号比剩下的括号少，下一个可以是左括号也可以是右括号
            if (left > 0)
            {
                dfs(cur + "(", left -1, right);
            }
            dfs(cur + ")", left, right - 1);

        }else if (left == right) {
            // 如果剩下的左括号和右括号一样多，下一个只可以是左括号
            dfs(cur + "(", left -1, right);
        }
    }
};
// @lc code=end

