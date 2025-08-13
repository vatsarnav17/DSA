class Solution{
private:
    bool detect(int src,vector<int> adj[],int vis[])
    {
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjnodes:adj[node])
            {
                if(!vis[adjnodes]){
                    vis[adjnodes]=1;
                    q.push({adjnodes,node});
                }
                else if(parent != adjnodes){
                     return true;
                }
            }
        } 
        return false;
    }
public:
    bool isCycle(int v, vector<int> adj[]) {
        int vis[v] = {0};
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }
};
