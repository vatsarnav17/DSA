class Solution {
private: 
    bool dfs(int node,int col,vector<int>&color,vector<vector<int>>&graph){
        color[node] = col;
        for(auto it : graph[node]){
            if(color[it]== -1){
                if(dfs(it,!col,color,graph)==false) return false;
            }
            else if(color[it]==col){
                return false;   
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> col(v,-1);
        for(int i=0;i<v;i++){
            if(col[i]==-1){
                if(dfs(i,0,col,graph) == false) return false;
            }
        }
        return true;
    }
};