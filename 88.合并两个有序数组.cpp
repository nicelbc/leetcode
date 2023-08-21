#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(nums1.begin(), nums1.begin() + m);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < m || j < n)
        {
            int a = INT_MAX;
            int b = INT_MAX;
            if (i < m)
            {
                a = tmp[i];
            }
            if(j < n) {
                b = nums2[j];
            }
            if(a <= b){
                nums1[k++] = a;
                i++;
            } else {
                nums1[k++] = b;
                j++;
            }
        }
    }
};
// @lc code=end

