#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (43.43%)
 * Likes:    2873
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 *
 *
 * 示例 2：
 *
 *
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        int index = 0;
        int col = INT_MAX;
        for (int i = 0; i < strs.size(); i++)
        {
            col = min(strs[i].size(), col);
        }

        for (int i = 0; i < col; i++){
            bool flag = true;
            for (int j = 1; j < strs.size(); j++)
            {
                if(strs[j][i] != strs[j - 1][i]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ret += strs[0][i];
            else
                break;
        }

        return ret;
    }

    int min(int a, int b){
        return a < b ? a : b;
    }
};
// @lc code=end

