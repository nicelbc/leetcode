/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.25%)
 * Likes:    2077
 * Dislikes: 0
 * Total Accepted:    530.7K
 * Total Submissions: 744.9K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
 * 
 * 
 */
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};
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
    unordered_map<int, int> index;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
        int n = preorder.size();
        for (int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preorder_left, int preorder_right, int inorder_left, int inordered_right){
        if(preorder_left > preorder_right)
            return nullptr;
        TreeNode *preorder_root = new TreeNode(preorder[preorder_left]); // 先序遍历第一个节点为根结点
        int inorder_index = index[preorder[preorder_left]];//定位中序遍历根结点位置
        int left_nums = inorder_index - inorder_left;//确定左子树节点数目

        preorder_root->left = build(preorder, inorder, preorder_left + 1, inorder_index+preorder_left-inorder_left, inorder_left, inorder_index - 1);
        preorder_root->right = build(preorder, inorder, inorder_index + preorder_left - inorder_left+1, preorder_right, inorder_index+1, inordered_right);

        return preorder_root;
    }
};
// @lc code=end

