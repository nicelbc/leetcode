/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.43%)
 * Likes:    1468
 * Dislikes: 0
 * Total Accepted:    397.2K
 * Total Submissions: 801.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;

        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = col - 1;
        int up = 0, down = row - 1;
        int i = 0;
        while (true)
        {
            i = left;
            while (i <= right)
            {
                ret.push_back(matrix[up][i]);
                i++;
            }
            up++;
            if(up > down)
                break;
            i = up;
            while(i <= down){
                ret.push_back(matrix[i][right]);
                i++;
            }
            right--;
            if(right < left)
                break;
            i = right;
            while(i >= left){
                ret.push_back(matrix[down][i]);
                i--;
            }
            down--;
            if(down < up)
                break;
            i = down;
            while(i >= up){
                ret.push_back(matrix[i][left]);
                i--;
            }
            left++;
            if(left > right)
                break;
        }

        return ret;
    }
};
// @lc code=end

int main(){
    vector<vector<int> > matrix = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}
        };
    vector<int> result;
    Solution solution;
    result = solution.spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}