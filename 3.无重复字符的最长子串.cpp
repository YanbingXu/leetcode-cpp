/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑窗：没有重复字符就右指针+1， 一旦出现重复字符就把左边的字符移除。
        if (s.size() == 0)
        {
            return 0;
        }
        // 用无序set存放无重复字符子串
        unordered_set<char> window;
        int maxStr = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while (window.find(s[i]) != window.end())
            {
                window.erase(s[left]);
                left++;
            }
            maxStr = max(maxStr, i-left+1); // 更新maxStr
            window.insert(s[i]);
        }
        return maxStr;
    }
};
// @lc code=end

