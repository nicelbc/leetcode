/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 *
 * https://leetcode.cn/problems/lru-cache/description/
 *
 * algorithms
 * Medium (53.46%)
 * Likes:    2855
 * Dislikes: 0
 * Total Accepted:    522.6K
 * Total Submissions: 977.3K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
 * 
 * 实现 LRUCache 类：
 * 
 * 
 * 
 * 
 * LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组
 * key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
 * 
 * 
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= capacity <= 3000
 * 0 <= key <= 10000
 * 0 <= value <= 10^5
 * 最多调用 2 * 10^5 次 get 和 put
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
struct DListNode
{
    /* data */
    int key;
    int value;
    DListNode *pre;
    DListNode *next;
    DListNode() : key(-1) ,value(-1),pre(nullptr), next(nullptr){}
    DListNode(int k, int value):key(k), value(value),pre(nullptr), next(nullptr){}
};

class LRUCache
{
    private:
        int capacbility;
        int size;
        unordered_map<int, DListNode *> cache;
        DListNode *dummyhead;
        DListNode *dummytail;
        // DListNode *list;

    public:
        LRUCache(int capacity) : capacbility(capacity)
        {
            size = 0;
            dummyhead = new DListNode();
            dummytail = new DListNode();
            dummyhead->next = dummytail;
            dummytail->pre = dummyhead;
            //list = dummyhead;
            //cache[-1] = dummyhead;
        }

    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DListNode* node = cache[key];
        remove_node(node);
        move_to_head(node);
        return node->value;
    }

    void put(int key, int value) {
        if(cache.count(key)){
            cache[key]->value = value;
            // move to head;
            remove_node(cache[key]);
            move_to_head(cache[key]);
        }
        else{
            DListNode* n = new DListNode(key,value);
            cache[key] = n;
            move_to_head(n); // insert to head;

            size++;
            if(size > capacbility){
                DListNode *rmnode = dummytail->pre;
                remove_node(rmnode);
                cache.erase(rmnode->key);
                delete rmnode;
                size--;
            }
        }
    }

    void move_to_head(DListNode* node){
        node->next = dummyhead->next;
        dummyhead->next->pre = node;
        dummyhead->next = node;
        node->pre = dummyhead;
    }
    void remove_node(DListNode* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

