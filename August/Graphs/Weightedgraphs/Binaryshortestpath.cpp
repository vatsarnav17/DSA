class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1 && grid[0][0]==0){
            return 1;
        }
        if(grid[0][0] == 1 || grid[n-1][n-1]==1){
            return -1;
        }
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        int drow[] = {-1,-1,0,1,1,1,0,-1};
        int dcol[] = {0,1,1,1,0,-1,-1,-1};
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0;i<8;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr<n && nr>=0 && nc<n && nc >= 0 && grid[nr][nc]==0 && dis + 1 < dist[nr][nc]){
                    dist[nr][nc]=dis+1;
                    if( nr == n-1 && nc == n-1){
                        return dis+1;
                    }
                    q.push({1+dis,{nr,nc}});
                }
            }
        }
        return -1;
    }
};