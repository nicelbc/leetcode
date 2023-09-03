/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (54.51%)
 * Likes:    1786
 * Dislikes: 0
 * Total Accepted:    432.9K
 * Total Submissions: 798.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> umap;
        sort(nums.begin(), nums.end());
        int ret_max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            if(umap.count(n - 1)){
                umap[n] = umap[n - 1] + 1;
            } else{
                umap[n] = 1;
            }
            ret_max = max(ret_max, umap[n]);
        }
        return ret_max;
    }
};
// @lc code=end

