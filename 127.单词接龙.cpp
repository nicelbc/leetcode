#include<bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> hashmap;
        unordered_map<string, int> visited;
        queue<string> que;
        int step = 0;
     
        for(auto& str : wordList){
            hashmap[str] = 1;
        }
        if(!hashmap.count(endWord))
            return step;
        que.push(beginWord);
        while(!que.empty()){

            int sz = que.size();
            while(sz--){
                string curr = que.front();
                que.pop();
                if (curr == endWord)
                    return step+1;
                visited[curr] = 1;
                for (int i = 0; i < curr.size(); i++)
                {
                    string next = curr;
                    for (int j = 0; j < 26; j++)
                    {
                        if(next[i] == j + 'a')
                            continue;
                        next[i] = j + 'a';
                        if (hashmap.count(next) && !visited.count(next))
                        {
                            que.push(next);
                        }
                    }
                }
            }
            step++;
        }

        return 0;
    }
};
// @lc code=end
