class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k>0) {
            int size = arr.size();
            for (int i=0;i<size;i++) {
                if (i < k)
                    que.push(arr[i]);
                else if (arr[i] < que.top()) {
                    que.push(arr[i]);
                    que.pop();
                }
            }
            size = que.size();
            for (int i=0; i<size; i++) {
                res.emplace_back(que.top());
                que.pop();
            }
        }
        return res;
    }
private:
    vector<int> res;
    priority_queue<int, vector<int>, less<int>> que;
};
