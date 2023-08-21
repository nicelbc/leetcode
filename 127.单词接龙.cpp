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
        unordered_set<string> uset(wordList.begin(), wordList.end());
        queue<string> que;
        unordered_set<string> visited;
        // bool find = false;
        int step = 1;
        //for(auto str : wordList) uset.insert(str);
        if(uset.count(endWord) == 0) return 0;
        //uset.erase(beginWord);
        que.push(beginWord);
        visited.insert(beginWord);
        while(!que.empty()){
            int sz = que.size();
            //Print(que);
            for(int i = 0; i < sz; i++){
                //cout << que.front() << " ";
                string str = que.front();
                que.pop();
                //visited.insert(str);
                for(int j = 0; j < str.size(); j++){//hit --> h
                    for(int k = 0; k < 26; k++){
                        if(k + 'a' == str[j]) continue;
                        string tword = str;
                        tword[j] = k + 'a';
                        if(tword == endWord){
                            //find = true;
                            return step + 1;
                        } 
                        if(uset.count(tword) && !visited.count(tword)) {
                            que.push(tword);
                            visited.insert(tword);
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
