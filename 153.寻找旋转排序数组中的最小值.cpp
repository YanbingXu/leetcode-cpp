/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 根据旋转排序数组一定是部分有序的，算法复杂度为logn，想到解法是二分查找
        // 旋转数组画图示意，我们要找最小值，我们考虑数组中最后一个数：最小值右侧的数都比他小
        // 最小值左侧的数都比他大

        int left = 0;
        int right = nums.size() - 1;
        // cout << "left:"<<left << ",right:"<<right<<endl;
        while (left < right) // 等号的时候直接结束二分查找
        {
            int mid = (left + right) / 2;
            cout << "mid:"<< mid <<endl;
            //那中间值与最右值进行比较
            if (nums[mid] <= nums[right])
            {
                // 最小值一定在左边，右半部分可省去
                right = mid; // 根据测试用例【3，1， 2】得到该行修改
                // cout<<"test right:"<< right <<endl;
            } else {
                // 最小值在右边，左边可以省去
                left = mid + 1;
                // cout<<"test left:"<<left<<endl;
            }

        }
        return nums[left];


    }
};
// @lc code=end

