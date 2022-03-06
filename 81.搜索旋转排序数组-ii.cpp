/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // 为了二分法而二分的一道题。
        // 加入出现nums[mid]=nums[left]=nums[right],那么这个时候没法判定哪边有序（参考33题）
        // 此时就需要将left++， right--,在新区间上重新做二分。最坏可能行o（n）

        // 边界判断
        if (nums.size() == 0)
        {
            return false;
        }
        if (nums.size() == 1)
        {
            return nums[0] == target ? true : false;
        }

        int left = 0;
        int right = nums.size() -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            // cout << "mid:"<<mid<<endl;
            if(nums[left] == nums[mid] && nums[right] == nums[mid]){
                left++;
                right--;
            } else if(nums[left]<=nums[mid]){ // 左边有序
                if (nums[mid] >= target && nums[left] <= target) // todo：这里正确的等号分析一下
                {
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }

            }else { // 右边有序
                if (nums[mid] <= target && nums[nums.size() - 1] >= target)
                {
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }

            }

        }
        return false;

    }
};
// @lc code=end

