/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 暴力竟然通过了
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (target == nums[i])
        //     {
        //         return i;
        //     }

        // }
        // return -1;

        // 有序就要想到二分查找。因为旋转了升序数组，我们找到一个mid点，一定有
        // 一部分是有序的，另一部分可能有序可能无序
        int size = nums.size();
        if (size == 0)
        {
            return -1;
        }
        if (size == 1)
        {
            return nums[0] == target ? 0 : -1;
        }

        int left = 0, right = size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            // cout << "mid:" << mid << endl;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[0] <= nums[mid]) // 左边有序
            {
                // target 在左边
                if (target >= nums[0] && target <= nums[mid])
                {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }

            } else { // 右边有序
                if (target >= nums[mid] && target <= nums[right])
                {
                    // target在右边
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }
            }

        }
        return -1;
    }
};
// @lc code=end

