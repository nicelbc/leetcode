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

#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int x) : val(x){}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ret = new ListNode(0);
        ListNode *p = ret;

        while(list1 != NULL && list2 != NULL){
            if(list1 -> val >= list2 -> val){
                p->next = list1;
                list1 = list1->next;
            }
            else
            {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        if(list1 != NULL){
            p->next = list1;
        }
        if(list2 != NULL){
            p->next = list2;
        }
        return ret;
    }
};