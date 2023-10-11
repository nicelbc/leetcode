/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 *
 * https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (76.09%)
 * Likes:    775
 * Dislikes: 0
 * Total Accepted:    289.1K
 * Total Submissions: 379K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,1,4,null,2], k = 1
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [5,3,6,2,4,null,null,1], k = 3
 * 输出：3
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数为 n 。
 * 1 
 * 0 
 * 
 * 
 * 
 * 
 * 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int kthSmallest(TreeNode *root, int k)
    {
        if(root == nullptr)
            return -1;
        stack<TreeNode *> sta;
        while(root || !sta.empty()){
            while(root){
                sta.push(root);
                root = root->left;
            }
            if(k == 1)
                return sta.top()->val;
            k--;
            TreeNode *tmp = sta.top();
            sta.pop();
            root = tmp->right;
        }

        return -1;
    }
};
// @lc code=end

