/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode.cn/problems/partition-list/description/
 *
 * algorithms
 * Medium (64.24%)
 * Likes:    751
 * Dislikes: 0
 * Total Accepted:    232.3K
 * Total Submissions: 361.2K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
 * 
 * 你应当 保留 两个分区中每个节点的初始相对位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,4,3,2,5,2], x = 3
 * 输出：[1,2,2,4,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [2,1], x = 2
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 200] 内
 * -100 
 * -200 
 * 
 * 
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *pre = new ListNode(0);
        ListNode *last = new ListNode(0);
        ListNode *p_pre = pre;
        ListNode *p_last = last;
        while (head)
        {
            int tmp = head->val;
            // cout << tmp << " ";
            if (tmp < x)
            {
                p_pre->next = head;
                p_pre = p_pre->next;
                //p_pre->next = NULL;
            }
            else
            {
                p_last->next = head;
                p_last = p_last->next;
            }
            head = head->next;
        }
        p_last->next = NULL;
        p_pre->next = last->next;
        return pre->next;
    }
};
// @lc code=end
ListNode* createList(vector<int> vec);
ListNode *print(ListNode *head);
int main()
{
    vector<int> vec{1, 4, 3, 2, 5, 2};
    ListNode *head;
    head = createList(vec);
    ListNode *ret;
    Solution so;
    ret = so.partition(head, 3);
    print(ret);
}

ListNode* createList(vector<int> vec){
    int n = vec.size();
    if(n == 0)
        return nullptr;
    ListNode *head = new ListNode(-1);
    ListNode *cur = head;
    for (auto val:vec){
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return head->next;
}

ListNode *print(ListNode *head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
