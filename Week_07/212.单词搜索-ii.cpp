/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start

class TrieNode{
public:
    string word = "";
    vector<TrieNode*> nodes;
    TrieNode():nodes(26, 0){}
};

class Solution {
private:
    int rows, cols;
    vector<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();
        TrieNode* root = new TrieNode();
        for (auto word : words) {
            TrieNode* cur = root;
            for (auto ch : word) {
                if (!cur->nodes[ch-'a'])
                    cur->nodes[ch-'a'] = new TrieNode();
                cur = cur->nodes[ch-'a'];
            }
            cur->word = word;
        }
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
                dfs(board, root, i, j);
        return res;
    }
    void dfs(vector<vector<char>>& board, TrieNode* root, int x, int y) {
        char c = board[x][y];
        //点是为了防止在一次dfs过程中走回头路，另一个条件是为了不走words中没出现的字母
        if (c == '.' || !root->nodes[c-'a'])
            return;
        root = root->nodes[c-'a'];
        if (root->word != "") {
            res.emplace_back(root->word);
            root->word = "";
        }

        board[x][y] = '.';
        if (x > 0)
            dfs(board, root, x-1, y);
        if (y > 0)
            dfs(board, root, x, y-1);
        if (x+1 < rows)
            dfs(board, root, x+1, y);
        if (y+1 <cols)
            dfs(board, root, x, y+1);
        board[x][y] = c;
    }
};

// @lc code=end

