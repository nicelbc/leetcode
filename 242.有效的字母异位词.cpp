/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode.cn/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.86%)
 * Likes:    838
 * Dislikes: 0
 * Total Accepted:    645.4K
 * Total Submissions: 979K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * s 和 t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ms;
        unordered_map<char, int> mt;
        if(s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            ms[s[i]]++;
            mt[t[i]]++;
        }
        for(auto& iter : ms){
            char c = iter.first;
            if(ms[c] != mt[c])
                return false;
        }
        unordered_map<char, int>::iterator it;
        it = ms.begin();
        cout << it -> first << " " << it -> second;
        return true;
    }
};
// @lc code=end

