class Solution{
private:
    bool dfs(int idx,vector<int> adj[],vector<int>&vis,vector<int>& path){
        vis[idx]=1;
        path[idx]=1;

        for( auto it:adj[idx]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path)==true) return true;
            }
            else if(path[it]){
                return true;
            }
        }

        path[idx]=0;
        return false;
    }
public:
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> vis(N,0);
        vector<int> path(N,0);
        for(int i=0;i<N;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)==true) return true;;
            }
        }
        return false;
    }
};
