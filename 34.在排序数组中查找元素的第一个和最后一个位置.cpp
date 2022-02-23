/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool has_equal) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums.size(); // 为什么要设置nums.size（），就是为了[0], target=0这种情况吗
        while (left <= right) // 注意=号
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (has_equal && nums[mid] >= target))
            {
                right = mid - 1;
                ans = mid;
            }else {
                left = mid +1;
            }

        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // 升序，代表target在一块,o(logn)想到二分查找
        // 利用两次二分查找分别找start和end，start是第一个=target的idx，也就是二分查找>=target的索引
        // end是查找第一个>target的索引-1

        int start = binarySearch(nums,target, true);
        int end = binarySearch(nums, target, false) - 1;
        cout << "start:" << start<< endl;
        cout << "end:" << end<< endl;
        if (start <= end && start >= 0 && end <= nums.size() -1 && nums[start] == target && nums[start] == target)
        {
            return {start, end};
        }
        return {-1, -1};

    }


};
// @lc code=end

