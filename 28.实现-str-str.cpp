/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution
{
public:
    /**
     * 本题是经典的字符串单模匹配的模型，
     * 因此可以使用字符串匹配算法解决，
     * 常见的字符串匹配算法包括暴力匹配、
     * Knuth-Morris-Pratt 算法、
     * Boyer-Moore 算法、
     * Sunday 算法等
     */
    int strStr(string haystack, string needle)
    {
        // 暴力匹配：将needle与haystack所有长度为m的子串都匹配一遍
        if (needle == "")
        {
            return 0;
        }
        if (needle.size() > haystack.size())
        {
            return -1;
        }
        for (int i = 0; i + needle.size() <= haystack.size(); i++)
        {
            int flag = 0;
            for (int j = 0; j < needle.size(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    flag = -1;
                    break;
                }
            }
            if (flag == 0)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
