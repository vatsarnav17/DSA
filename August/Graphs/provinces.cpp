class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjls, vector<int>& vis) {
        vis[node] = 1;
        for (int it=0;it<adjls.size();it++) {
            if (adjls[node][it] && !vis[it]) {
                dfs(it, adjls, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adjls) {
        int n = adjls.size();
        vector<int> vis(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adjls, vis);
            }
        }
        return count;
    }
};
