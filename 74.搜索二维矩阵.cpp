/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // // 由于第一列也是升序的，先对第一列进行二分查找确定在哪一行（找到第一个比target大的数，定位在它的上一行）
        // // 然后在该行二分查找target
        // int row = matrix.size();
        // int col = matrix[0].size();
        // // cout << "row:" << row << ", col:"<< col <<endl;

        // if (row == 0 && col == 0)
        // {
        //     return false;
        // }
        // if (row == 1 && col == 1)
        // {
        //     return target == matrix[0][0] ? true : false;
        // }

        // //假设只有一行，单独处理
        // int mark_row = -1;
        // if (row == 1)
        // {
        //     if (matrix[0][0] > target || matrix[0][col-1] < target)
        //     {
        //         return false;
        //     }
        //     mark_row = 1;

        // } else {
        //     for (int i = 0; i < row; i++)
        //     {
        //         if (matrix[i][0] == target)
        //         {
        //             return true;
        //         }

        //         if (matrix[i][0] > target)
        //         {
        //             mark_row = i;
        //             break;
        //         }
        //     }
        //     // cout<<"mark_row:"<<mark_row<<endl;
        //     // 都遍历完了，再确认一下可能在最后一行
        //     if (mark_row == -1 && matrix[row-1][col-1] >= target)
        //     {
        //         mark_row = row;
        //     }
        // }
        // //-----------------找列这里都变成面向测试用例编程了---------------

        // // 找到target可能在的行数是 mark_row - 1;
        // int left = 0, right = col-1;
        // while (left <= right && mark_row - 1 >= 0)
        // {
        //     int mid = (left + right) / 2;
        //     // cout << "mid:" << mid <<endl;
        //     if (matrix[mark_row - 1][mid] == target)
        //     {
        //         return true;
        //     }
        //     if (target < matrix[mark_row -1][mid]) // 在左半部分
        //     {
        //         right =  mid - 1;
        //     }else { // 在右半部分
        //         left =  mid + 1;
        //     }
        // }
        // return false;

        // 方法二：一次二分查找（把二维数组拉平成一维的）
        int row = matrix.size();
        int col = matrix[0].size();

        // 拉平
        int left = 0;
        int right = col * row - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            // 一维需要重新定位到二维的索引，此处难想
            if (matrix[mid / col][mid % col] == target)
            {
                return true;
            }

            if (matrix[mid / col][mid % col] > target) // 在左边
            {
                right = mid - 1;
            }else {
                left = mid + 1;
            }

        }
        return false;


    }
};
// @lc code=end

