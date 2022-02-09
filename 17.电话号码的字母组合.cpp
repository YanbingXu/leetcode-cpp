/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

class Solution {
public:
    std::unordered_map<char, string> digits_letter = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
    vector<string> res;
    string cur;

    // 回溯法解决n个for循环的问题
    vector<string> letterCombinations(string digits) {
        res.clear();
        cur.clear();

        if(digits.size() == 0)
            return res;
        DFS(digits, 0);
        return res;
    }

    void DFS(const string& digit, int depth){
        if(digit.size() == depth){
            res.push_back(cur);
            return;

        }

        char num = digit[depth];
        string letter = digits_letter[num];
        for(int i=0;i<letter.size();++i)
        {   cur.push_back(letter[i]);
            DFS(digit, depth + 1);
            cur.pop_back();
        }


    }
};
// @lc code=end

