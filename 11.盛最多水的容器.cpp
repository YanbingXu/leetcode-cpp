/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        // maxArea = (j-i) * min(aj, ai)

        // 法一：暴力遍历（不可行，超时）
        // int maxArea = 0;
        // for (int i = 0; i < height.size(); i++)
        // {
        //     for (int j = 0; j < i; j++)
        //     {
        //         int tempArea = (i-j) * min(height[i], height[j]);
        //         maxArea = max(maxArea, tempArea);
        //     }

        // }
        // return maxArea;

        // 法二：双指针法，移动height较小的那个指针
        int maxArea = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            int tempArea = (j - i) * min(height[i], height[j]);
            maxArea = max(maxArea, tempArea);
            if (height[i] < height[j])
            {
                i++;
            }else {
                j--;
            }
        }
        return maxArea;
    }
};
// @lc code=end

