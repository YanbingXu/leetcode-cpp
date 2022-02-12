/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
public:
    // 长度为1，只追加字符
    // 长度为n， 追加字符和n
    // 如果n >= 10, 会被拆分写成'1', '0'
    // 只使用常量额外空间的算法。
    // 需要修改输入数组
    int compress(vector<char>& chars) {
        // 双指针法：read和write，记录一个开始位置start，长度为read - start， 记录的字符其实是一段相同字符的最右侧那个值，此时可以同时记录 字符和 长度
        int write = 0;
        int start = 0;
        for (int read = 0; read < chars.size(); read++)
        {
            if (read == chars.size() - 1 || chars[read] != chars[read + 1])
            {
                chars[write] = chars[read];
                write++;

                int len = read - start + 1;
                if (len > 1)
                {
                    string nums = to_string(len);
                    for (int i = 0; i < nums.size(); i++)
                    {
                        chars[write] = nums[i];
                        write++;
                    }
                }

                // int num = read - start + 1;
                // if (num > 1) {
                //     int anchor = write;
                //     while (num > 0) {
                //         chars[write++] = num % 10 + '0';
                //         num /= 10;
                //     }
                //     reverse(&chars[anchor], &chars[write]);
                // }

                start = read + 1;
            }


        }
        return write;


    }
};
// @lc code=end

