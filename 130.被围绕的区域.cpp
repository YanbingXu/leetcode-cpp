/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
// 题目理解：其实一共有三种字符：
// 1.被x包围的o
// 2.不被x包围的o
// 3.x
// 根据题目提示，所有在边界上的o，都无法被包围，因此想到可以从边界出发，dfs找到所有与边界联通的o，他们一定是无法被x包围的

    void dfs(int row, int col, vector<vector<char>>& board){
        // if (board[row][col] == 'O')
        // {
        //     board[row][col] = 'a';
        // }else{
        //     return;
        // }
        // if (row-1>=0) dfs(row-1, col, board);
        // if(row+1<=board.size()-1) dfs(row+1, col, board);
        // if(col-1>=0) dfs(row, col-1, board);
        // if (col+1<=board[0].size()) dfs(row, col+1, board);

        if (row<0||row>board.size()-1||col<0||col>board[0].size()-1||board[row][col]!='O')
        {
            return;
        }
        board[row][col] = 'a';
        dfs(row-1, col, board);
        dfs(row+1, col, board);
        dfs(row, col-1, board);
        dfs(row, col+1, board);
    }

    void solve(vector<vector<char>>& board) {
        // 从四个边界开始做dfs
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++)
        {
            dfs(i, 0, board);
            dfs(i, col-1, board);
        }

        for (int j = 0; j <col; j++)
        {
            dfs(0, j, board);
            dfs(row-1, j, board);
        }

        for (int i = 0; i < row; i++)
        {
            for(int j = 0; j<col;j++){
                if (board[i][j] == 'a')
                {
                    board[i][j] = 'O';
                }else{
                    board[i][j]='X';
                }
            }
        }
    }
};
// @lc code=end

