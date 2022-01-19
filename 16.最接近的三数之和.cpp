/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        // 排序 + 双指针？
        // 最接近：abs(threeSums - target)
        int closestSum = nums[0] + nums[1] + nums[2];
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int threeSum = nums[i] + nums[left] + nums[right];
                if (abs(threeSum - target) < abs(closestSum - target))
                {
                    closestSum = threeSum;
                }
                if (threeSum < target)
                {
                    left++;
                }
                else if (threeSum > target)
                {
                    right--;
                }
                else
                {
                    return target;
                }
            }
        }
        return closestSum;
    }
};
// @lc code=end
