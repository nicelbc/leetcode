/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (53.53%)
 * Likes:    1176
 * Dislikes: 0
 * Total Accepted:    358.6K
 * Total Submissions: 669.2K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,3,4,4,5]
 * 输出：[1,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,1,1,2,3]
 * 输出：[2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围 [0, 300] 内
 * -100 <= Node.val <= 100
 * 题目数据保证链表已经按升序 排列
 * 
 * 
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode* next):val(x), next(next){}
};
// @lc code=start
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode *dmNode = new ListNode(0);
        dmNode->next = head;
        ListNode *cur = head;
        ListNode *pre = dmNode;
        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                int tmp = cur->val;
                while (cur && cur->val == tmp)
                {
                    pre->next = pre->next->next;
                    cur = cur->next;
                }
            }
            else
            {
                cur = cur->next;
                pre = pre->next;
            }
        }

        return dmNode->next;
    }
};
// @lc code=end

