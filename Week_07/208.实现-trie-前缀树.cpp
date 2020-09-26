/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        isString = false;
    }
    ~Trie() {
        for (int i=0; i<26; i++) {
            if (!next[i])
                continue;
            delete(next[i]);
            next[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (auto a : word) {
            if (!node->next[a-'a'])
                node->next[a-'a'] = new Trie();
            node = node->next[a-'a'];
        }
        node->isString = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (auto a : word) {
            if (!node->next[a-'a'])
                return false;
            node = node->next[a-'a'];
        }
        return node->isString;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto a : prefix) {
            if (!node->next[a-'a'])
                return false;
            node = node->next[a-'a'];
        }
        return true;
    }
private:
    Trie* next[26]{nullptr};
    bool isString;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

