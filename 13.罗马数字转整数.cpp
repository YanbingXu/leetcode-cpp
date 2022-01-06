/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        if (s == "IV") {
            return 4;
        }else if (s == "IX") {
            return 9;
        }else if ()
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char& temp = s[i];
            switch (temp)
            {
            case 'I':
                res += 1;
                break;
            case 'V':
                res += 5;
                break;
            case 'X':
                res += 10;
                break;
            case 'L':
                res += 50;
                break;
            case 'C':
                res += 100;
                break;
            case 'D':
                res += 500;
                break;
            case 'M':
                res += 1000;
                break;
            default:
                break;
            }
        }
        return res;   
    }
};
// @lc code=end

