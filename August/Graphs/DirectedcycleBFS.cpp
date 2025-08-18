class Solution{
public:
    bool isCyclic(int n, vector<int> adj[]) {
        int indeg[n]={0};
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }    
        }
        if(count==n){
            return false;
        }
        return true;
    }
};

