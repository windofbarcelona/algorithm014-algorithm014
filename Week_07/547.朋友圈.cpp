 /*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
class Solution {
public:
    int find(vector<int> &Vec,int n){
        if(Vec[n]==-1)
            return n;
        return find(Vec,Vec[n]);
    }

    void Union(vector<int> &Vec,int m,int n){
        int parent_m=find(Vec,m);
        int parent_n=find(Vec,n);
        if(parent_m!=parent_n)
            Vec[parent_m]=parent_n;
    }

    int findCircleNum(vector<vector<int>>& M) {
        int N=M.size();
        vector<int> parent(N,-1);
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(M[i][j]==1 && i!=j)
                    Union(parent,i,j);
            }
        }
        int count=0;
        for(int i=0;i<N;++i)
            if(parent[i]==-1)
                count++;
        return count;
    }
};
// @lc code=end

