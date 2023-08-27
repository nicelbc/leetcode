/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 *
 * https://leetcode.cn/problems/rotate-image/description/
 *
 * algorithms
 * Medium (74.81%)
 * Likes:    1705
 * Dislikes: 0
 * Total Accepted:    477.7K
 * Total Submissions: 637.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 * 
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
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
    void rotate(vector<vector<int>>& matrix) {
        //[i][j] -> [j][n - i - 1]   n = matrix.size();
        // [i][j] -> [j][n - i -1] -> [n - i - 1][n - j - 1] -> [n - j - 1][i] -> [i][j]

        int tmp;
        int n = matrix.size();
        int row = n % 2 ? n / 2 + 1 : n / 2;
        int col = n / 2;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
        }
    }
};
// @lc code=end

