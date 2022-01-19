/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 排序+去重+双指针
        int size = nums.size();
        if (size < 3) // 特殊判断
        {
            return {};
        }
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end()); //排序(快排)， 默认从小到大，时间复杂度nlog2(n)

        if (nums[0] > 0 ){ //最小的数都大于0，不可能有三数相加和为0
            return res;
        }
        for (int i = 0; i < size; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue; //去重
            int left = i + 1;
            int right = size - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > -nums[i]) {
                    right --;
                }else if (nums[left] + nums[right] < -nums[i]) {
                    left ++;
                }else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    right --;
                    left ++;
                    // left 和 right也要去重，比如[-2,0,0,2,2]
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }
            }

        }
        return res;
    }
};
// @lc code=end

