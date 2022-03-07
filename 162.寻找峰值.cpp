/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 方法一：最大值一定是个峰值 o(n)复杂度

        // 峰值是指其值严格大于左右相邻值的元素
        // logn复杂度想到用二分查找

        // 首先要注意题目条件，在题目描述中出现了 nums[-1] = nums[n] = -∞，
        // 这就代表着 只要数组中存在一个元素比相邻元素大，那么沿着它一定可以找到一个峰值

        int left = 0, right = nums.size()-1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid+1])
            {
                // 找右边
                left = mid + 1;
            }else {
                right = mid;
            }
        }
        return left;

    }
};
// @lc code=end

