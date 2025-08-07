class Solution {
  private:
  void dfs(int start,vector<int> adj[],int vis[],vector<int> &ls){
    vis[start]= 1;
    ls.push_back(start);
    for(auto it:adj[start]){
      if(!vis[it]){
        dfs(it,adj,vis,ls);
      }
    }
  }
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
     int vis[V] = {0};
     int start = 0;
     vector<int> ls;
     dfs(start,adj,vis,ls);
      return ls;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0]=1;
      queue<int> q;
      q.push(0);
      vector<int> bfs;
      while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it:adj[node]){
          if(!vis[it]){
            vis[it]=1;
            q.push(it);
          }
        }
      } 
      return bfs;
    }
};
