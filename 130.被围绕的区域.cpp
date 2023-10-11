/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode.cn/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (46.26%)
 * Likes:    1023
 * Dislikes: 0
 * Total Accepted:    243.3K
 * Total Submissions: 525.7K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X'
 * 填充。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * 输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * 解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["X"]]
 * 输出：[["X"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 
 * board[i][j] 为 'X' 或 'O'
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(m < 2 || n < 2)
            return;
        // row 0  m - 1;
        for (int i = 0; i < n; i++)
        {
            if(board[0][i] == 'O')
                dfs(board, 0, i);
            if(board[m - 1][i] == 'O')
                dfs(board, m - 1, i);
        }
        for (int i = 0; i < m; i++){
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }
        update(board);
        
    }

    void dfs(vector<vector<char>>& board, int r, int c){
        if(!inArea(board, r, c) || board[r][c] != 'O')
        return;
        board[r][c] = 'T';
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
    }

    bool inArea(const vector<vector<char>>& board, int r, int c){
        int m = board.size();
        int n = board[0].size();
        if(r < 0 || c < 0 || r >= m || c >= n)
            return false;
        return true;
    }

    void update(vector<vector<char>>& board){
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'T')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end

