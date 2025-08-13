class Solution{
private:
    bool dfs(int node,int parent,vector<int> adj[],vector<int>& vis){
        vis[node]=1;
        for(auto adjnodes:adj[node]){
            if(!vis[adjnodes]){
                if(dfs(adjnodes,node,adj,vis)==true){
                    return true;
                }
            }
            else if(adjnodes!=parent){
                return true;
            }            
        }
        return false; 
    }
public:
    bool isCycle(int n, vector<int> adj[]) {
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};