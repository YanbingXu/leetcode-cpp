/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    // const 表示只读，constexpr表示const。constexpr后一定是 static data
    constexpr static int dx[4] = {0,-1, 0, 1};
    constexpr static int dy[4] = {-1, 0, 1, 0};
    int islandPerimeter(vector<vector<int>>& grid) {
        // 判断这个格式是不是边界或者相邻水域，是的话那条边就是周长！
        int row = grid.size();
        int col = grid[0].size();
        int resPerimeter = 0;
        // 遍历每个格子
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == 1)
                {
                    // 效率低
                    // // 分别判断四个方向：是水域或者边界就+1
                    // if ( r <= 0 || grid[r-1][c] == 0 )
                    // {
                    //     resPerimeter++;
                    // }
                    // if ( r >= row-1 || grid[r+1][c] == 0)
                    // {
                    //     resPerimeter++;
                    // }
                    // if ( c <= 0 || grid[r][c-1] == 0)
                    // {
                    //     resPerimeter++;
                    // }
                    // if (c >= col-1 || grid[r][c+1] == 0)
                    // {
                    //     resPerimeter++;
                    // }

                    int res = 0;
                    for (int i = 0; i < 4; i++)
                    {
                       int tx = r + dx[i];
                       int ty = c + dy[i];
                       if (tx < 0 || tx >= row || ty<0 || ty>= col || grid[tx][ty] == 0)
                       {
                           res++;
                       }
                    }
                    resPerimeter += res;
                }

            }
        }
        return resPerimeter;

    }
};
// @lc code=end

