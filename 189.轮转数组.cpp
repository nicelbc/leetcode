#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;

        vector<int> tmp_nums{nums.end() - k, nums.end()};
        // for (int i = 0; i < tmp_nums.size(); i++){
        //     cout << tmp_nums[i] << " ";
        // }
        for (int i = len - k - 1; i >= 0; i--){
            nums[i + k] = nums[i];
        }
        for (int i = 0; i < k; i++){
            nums[i] = tmp_nums[i];
        }
    }

 
};
// @lc code=end

