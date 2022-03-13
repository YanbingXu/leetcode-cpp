/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c, int row, int col) {
        // 递归停止条件是什么呢？
        grid[r][c] = '0';
        // 往四个方向搜索
        if (r-1>=0 && grid[r-1][c] == '1')
        {
            dfs(grid, r-1, c, row, col);
        }
        if (r+1 <= row-1 && grid[r+1][c] == '1')
        {
            dfs(grid, r+1, c, row, col);
        }
        if (c-1 >= 0 && grid[r][c-1] == '1')
        {
            dfs(grid, r, c-1, row, col);
        }
        if (c+1 <= col -1 && grid[r][c+1] == '1')
        {
            dfs(grid, r, c+1, row, col);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // 法一：dfs（看到岛屿类题目想到dfs可以做），对于每一个已经搜索过的“1”重新置为0，然后继续进行下一次的dfs。
        // 岛屿的数量就是进行dfs的数量

        int row = grid.size();
        int col = grid[0].size();
        cout<<"row:"<<row<<",col:"<<col<<endl;

        int num_lands = 0;
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (grid[r][c] == '1')
                {
                    num_lands++;
                    dfs(grid, r, c, row, col);
                }


            }

        }

        return num_lands;
    }
};
// @lc code=end

