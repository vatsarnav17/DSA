class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m){
      vector<vector<int>> adj(n);
      for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
      }        
        vector<int> dist(n,1e9);
        dist[0]=0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
          int node = q.front();
          q.pop();
          for(auto it:adj[node]){
            if(dist[node]+1<dist[it]){
              dist[it]=1+dist[node];
              q.push(it);
            }
          }
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
          if(dist[i]!=1e9){
            ans[i]=dist[i];
          }
        }
        return ans;
      }
    };
