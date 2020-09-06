/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        //BFS
        queue<string>qu;
		qu.push(start);
		int res = 0;
		unordered_map<string, int> vis;
		while (!qu.empty()) {
			int size = qu.size();
			for (int i = 0; i < size; i++) {
				string cur = qu.front();
				vis[cur] = 1;
				qu.pop();
				if (cur == end)return res;
				for (int i = 0; i < bank.size(); i++) {
					if (Dif_num(cur, bank[i]) == 1 && !vis[bank[i]]) 
						qu.push(bank[i]);
				}
			}
			res++;
		}
		return -1;
        /*
        minStepCount = INT_MAX;
        set<string> st;
        buildRes(st, 0, start, end, bank);
        return minStepCount==INT_MAX?-1:minStepCount;
        */
    }
    int Dif_num(string& s1, string& s2){
		int cnt = 0;
		for (int i = 0; i < s1.size(); i++){
			if (s1[i] != s2[i])cnt++;
		}
		return cnt;
	}
    void buildRes(set<string>& st, int count, string current, string end, vector<string>& bank) {
        //这种做法感觉特别像是跳板，不断从基因库中找到与当前只有一处不同的序列，以此为基础继续向下跳

        //跳出条件
        if (count > minStepCount)
            return;
        //处理当前层
        if (end == current)
            minStepCount = min(count, minStepCount);
        for (auto str : bank) {
            int diff = 0;
            for (int i=0; i<str.size(); i++)
                if(current[i]!=str[i])
                    //找到仅有一个碱基对不同的序列，作为跳板
                    if (++diff > 1)
                        break;
            if (diff == 1 &&!st.count(str)) {
                st.emplace(str);
                buildRes(st, count+1, str, end, bank);
                st.erase(str);
            }
        }
    }
private:
    int minStepCount;
};
// @lc code=end

