/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start

// 解法：自动机
class Automaton
{
public:
// 状态表
unordered_map<string, vector<string>> table  = {
    {"start", {"start", "signed", "in_number", "end"}},
    {"signed", {"end", "end", "in_number", "end"}},
    {"in_number", {"end", "end", "in_number", "end"}},
    {"end", {"end", "end", "end", "end"}}
};

string state = "start";
int sign = 1;
long ans = 0;

int getCol(char c){
    if (c == ' ') return 0;
    if (c == '+' || c == '-') return 1;
    if (c >= '0' && c <= '9') return 2;
    return 3;
    // if (isspace(c)) return 0;
    // if (c == '+' or c == '-') return 1;
    // if (isdigit(c)) return 2;
    // return 3;

}

void get(char c) {
    state = table[state][getCol(c)];
    if (state == "in_number")
    {
        ans = ans * 10 + c - '0';
        ans = sign == 1 ? min(ans, (long)__INT_MAX__) : min(ans, -(long)(-__INT_MAX__-1)); // sign = -1 时的判断是因为，ans始终是一个正数。所以判断的时候其实做的是符号位后的数字的判断，所以-（-2^31 - 1）
    }else if (state == "signed") {
        sign = c == '+' ? 1 : -1;
    }
}
// void get(char c) {
//         state = table[state][getCol(c)];
//         if (state == "in_number") {
//             ans = ans * 10 + c - '0';
//             ans = sign == 1 ? min(ans, (long)INT_MAX) : min(ans, -(long)INT_MIN);
//         }
//         else if (state == "signed")
//             sign = c == '+' ? 1 : -1;
// }

};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};

// @lc code=end

