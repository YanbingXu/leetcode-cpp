/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    // string longestPalindrome(string s)
    // {
    //     // 解法一：暴力破解
    //     if (s.length() < 2)
    //     {
    //         return s;
    //     }

    //     int maxLen = 1;
    //     int begin = 0;
    //     char *cs = (char *)s.c_str();
    //     for (int i = 0; i < s.length()-1 ; i++)
    //     {
    //         for (int j = i + 1; j < s.length(); j++)
    //         {
    //             if ((j - i + 1 > maxLen) && isPalindrome(cs, i, j))
    //             {
    //                 maxLen = j - i + 1;
    //                 begin = i;
    //             }
    //         }
    //     }
    //     return s.substr(begin, maxLen); // c++里substr(起始位置， 长度) 而java中substring（起始位置， 终止位置）
    // }

    // bool isPalindrome(char *cs, int i, int j)
    // {
    //     while (i <= j)
    //     {
    //         if (cs[i] != cs[j])
    //         {
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    string longestPalindrome(string s){
        // 解法二：动态规划（为什么这个更慢？）
        int n = s.size();
        // dp[left][right]标记从i到j是否是字串
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        // length表示判断的字串的长度
        // left表示字串的左边起始位置
        // right表示字串的右边起始位置
        for(int length = 0; length < n; length++){
            for(int left = 0; left + length < n; left++){
                int right = left + length;
                // 即字符串长度为1时，矩阵对角线
                if(length == 0) dp[left][right] = 1;
                // 字符串长度为2的时候，只需判断两者是否相等
                else if(length == 1) dp[left][right] = (s[left] == s[right]);
                else{  // 字符串长度大于等于3之后
                       // 其是否是回文串取决于当前left和right及更小一号的字符串
                       // 更新参考值为矩阵的左下方
                    dp[left][right] = (s[left] == s[right] && dp[left + 1][right - 1]);
                }
                // 如果当前left位置到right位置的字串能够构成回文串，并且现在长度+1后大于之前记忆中的子回文串的长度，那么更新回文串！这里也可以优化成记录起始位置和长度的两个int，返回时再截取
                if(dp[left][right] && (length + 1) > ans.size()){
                    ans = s.substr(left, length + 1);
                }
            }
        }
        return ans;

    }
};
// @lc code=end
