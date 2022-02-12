/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    // 竖式相加，逐位相加，有进位需要进位，长度不一样在前面补零
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int ans = 0;
        string rev_string = "";
        if (len1 < len2)
        {
            num1.insert(0, len2-len1, '0');
        }else if (len1 > len2)
        {
            num2.insert(0, len1-len2, '0');
        }

        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int x = num1[i] - '0';
            int y = num2[i] - '0';
            int temp = x + y + ans;
            if (temp >= 10)
            {
                ans = 1;
                temp = temp % 10;
            }else {
                ans = 0;
            }
            rev_string.push_back('0' + temp);

        }

        // 避免出现 num1 = {"1"}, num2={"9"}
        if (ans == 1)
        {
            rev_string.push_back('1');
        }

        reverse(rev_string.begin(), rev_string.end());
        return rev_string;


        // 官方解法：一样的思路但是实现更加聪明
        // int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        // string ans = "";
        // while (i >= 0 || j >= 0 || add != 0) {
        //     int x = i >= 0 ? num1[i] - '0' : 0;
        //     int y = j >= 0 ? num2[j] - '0' : 0;
        //     int result = x + y + add;
        //     ans.push_back('0' + result % 10);
        //     add = result / 10;
        //     i -= 1;
        //     j -= 1;
        // }
        // // 计算完以后的答案需要翻转过来
        // reverse(ans.begin(), ans.end());
        // return ans;


    }
};
// @lc code=end

