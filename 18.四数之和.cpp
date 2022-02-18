/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 参考三数之和：双指针 + 排序
        std::sort(nums.begin(), nums.end());
        int n_size = nums.size();
        if (n_size < 4)
        {
            return {};
        }
        // 定义a,b,c,d四个指针（从小到大），固定a.b，c=b+1, d=size-1包夹
        vector<vector<int>>res;
        int a, b, c, d;
        for (a = 0; a <= n_size - 4; a++)
        {
            if (a>0 && nums[a] == nums[a-1])
            {
                continue; //去重
            }
            for (b = a + 1; b <= n_size - 3; b++)
            {
                if (b > a+1 && nums[b] == nums[b-1])
                {
                    continue; //去重
                }
                c = b + 1;
                d = n_size - 1;
                while (c < d)
                {
                    // if (nums[a] + nums[b] + nums[c] + nums[d] < target) // int溢出
                    if (nums[a] + nums[b] - target  < -(nums[c] + nums[d])) // int溢出
                    {
                        c++;
                    }else if (nums[a] + nums[b] - target  > -(nums[c] + nums[d]))
                    {
                        d--;
                    }else {
                        res.push_back({nums[a], nums[b],nums[c], nums[d]});
                        c++;
                        d--;
                        // c和d也需要去重
                        while (c<d && nums[c] == nums[c-1])
                        {
                            c++;
                        }
                        while (c<d && nums[d] == nums[d+1])
                        {
                            d--;
                        }
                    }


                }

            }


        }
        return res;


    }
};
// @lc code=end

