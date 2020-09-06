/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //BFS
        unordered_multimap<string, string> mp;
        unordered_set<string> st;
        bool isValid = false;
        for (auto word : wordList) {
            string temp = word;
            if (word == endWord)
                isValid = true;
            for (int i=0; i<word.length(); i++) {
                temp[i] = '*';
                mp.emplace(temp, word);
                temp[i] = word[i];
            }
        }
        if (!isValid)
            return 0;
        queue<string> que;
        que.emplace(beginWord);
        int step = 1;
        while (!que.empty()) {
            int size = que.size();
            step++;
            while (size--) {
                string cur = que.front();
                que.pop();
                for (int i=0; i<cur.length(); i++) {
                    char ch = cur[i];
                    cur[i] = '*';
                    auto range = mp.equal_range(cur);
                    for (auto begin = range.first; begin!=range.second; begin++) {
                        if (!st.count(begin->second)) {
                            if (begin->second == endWord)
                                return step;
                            que.emplace(begin->second);
                            st.emplace(begin->second);
                        }
                    }
                    cur[i] = ch;
                }
            }
        }
        return 0;
    }
};
// @lc code=end

