/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode.cn/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (63.40%)
 * Likes:    929
 * Dislikes: 0
 * Total Accepted:    269.3K
 * Total Submissions: 423.2K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个仅使用常量空间的解决方案吗？
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        bool row_flag = false;
        bool col_flag = false;
        for (int i = 0; i < col; i++){
            if(matrix[0][i] == 0)
                row_flag = true;
        }
        for (int i = 0; i < row; i++){
            if(matrix[i][0] == 0)
                col_flag = true;
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < row; i++){
            for (int j = 1; j < col; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(row_flag){
            for (int i = 0; i < col; i++){
                matrix[0][i] = 0;
            }
        }

        if(col_flag){
            for (int i = 0; i < row; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end

