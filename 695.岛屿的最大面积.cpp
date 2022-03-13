/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    // void dfs(vector<vector<int>>& grid, int r, int c, int row, int col, int& resArea) {
    //     // 搜索过的都置0
    //     grid[r][c] = 0;
    //     resArea++;
    //     // 往四个方向搜索
    //     if (r-1 >= 0 && grid[r-1][c] == 1)
    //     {
    //         dfs(grid, r-1, c, row, col, resArea);
    //         // cout<<"test area1 resArea:"<<resArea<<endl;
    //     }
    //     if (r+1 <= row-1 && grid[r+1][c] == 1)
    //     {
    //         dfs(grid, r+1, c, row, col, resArea);
    //         // cout<<"test area2 resArea:"<<resArea<<endl;
    //     }

    //     if (c-1 >= 0 && grid[r][c-1] == 1)
    //     {
    //         dfs(grid, r, c-1, row, col, resArea);
    //         // cout<<"test area3 resArea:"<<resArea<<endl;
    //     }

    //     if (c+1 <= col-1 && grid[r][c+1] == 1)
    //     {
    //         dfs(grid, r, c+1, row, col, resArea);
    //         // cout<<"test area4 resArea:"<<resArea<<endl;
    //     }
    // }

    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     // 法一：dfs
    //     int row = grid.size();
    //     int col = grid[0].size();

    //     int maxArea = 0;
    //     int resArea = 0;
    //     // cout<< "row:"<<row <<",col:"<<col<<endl;

    //     for (int r = 0; r < row; r++)
    //     {
    //         for (int c = 0; c < col; c++)
    //         {
    //             if (grid[r][c] == 1)
    //             {
    //                 // cout<<"test 11"<<endl;
    //                 dfs(grid, r, c, row, col, resArea);
    //                 // cout << "area:"<<area<<endl;
    //                 maxArea = max(maxArea, resArea);
    //                 resArea = 0;
    //             }

    //         }

    //     }
    //     return maxArea;
    // }

    // 法二：迭代
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int row = grid.size();
        int col = grid[0].size();

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if
            }

        }

    }
};
// @lc code=end

