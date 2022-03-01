/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 动态规划
        int fi = nums[0];
        int pre = nums[0]; //fi-1
        int maxRes = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            pre = fi+nums[i];
            // cout<<"pre:"<<pre<<endl;
            fi = max(pre, nums[i]);

            // cout<<"fi:"<<fi<<endl;
            maxRes = max(fi, maxRes);
            // cout<<"maxRes:"<< maxRes<<endl;
        }
        return maxRes;

    }
};
// @lc code=end

