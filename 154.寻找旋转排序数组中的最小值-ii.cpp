/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 参考153解题思路：画示意图
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[right])
            {
                right = mid;
            }else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }else {
                // nums[mid]==nums[right], 由于有重复数字，无法确定在左半部分还是在右半部分
                right--;
            }

        }
        return nums[left];

    }
};
// @lc code=end

