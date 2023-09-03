/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.84%)
 * Likes:    1591
 * Dislikes: 0
 * Total Accepted:    509K
 * Total Submissions: 750.5K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 
 * 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * 示例 2:
 * 
 * 
 * 输入: strs = [""]
 * 输出: [[""]]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> umap;

        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end()); // 将字符串排序，使异位词具有相同的排序后的字符串

            umap[sorted_s].push_back(s); // 将排序后的字符串作为键，原字符串作为值，存入哈希表
        }

        for (auto& kv : umap)
        {
            ret.push_back(kv.second); // 将哈希表中的值（同一排序后的字符串的原字符串）放入结果中
        }

        return ret;
    }
};

// @lc code=end

