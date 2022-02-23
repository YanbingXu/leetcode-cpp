/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 解题详解见https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/
        // 1. 从后向前查找第一组相邻升序（i, i+1）
        int i = nums.size() - 2;
        while (i>=0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        // 2. 此时在（i+1, end）中后向前查找第一个k值，使得nums[k]>nums[i]
        if (i >= 0)
        {
            int k = nums.size() - 1;
            while (k>=0 && nums[k]<=nums[i])
            {
                k--;
            }
            // 3.交换nums[k]和nums[i]
            swap(nums[i],nums[k]);
        } // 如果i< 0表示找不到相邻生序，也就是说nums是最大数列，下一数列就直接reverse

        // 4.此时（i + 1, end）一定是降序排列， 对他们进行reverse
        reverse(nums.begin() + (i+1), nums.end());

    }
};
// @lc code=end

