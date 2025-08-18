class Solution{
public:
    vector<int> topoSort(int v, vector<int> adj[]){
        int indeg[v]={0}; 
        queue<int>q;  

        for(int i=0;i<v;i++){
            for(auto it:adj[i]){
                indeg[it]++;         //marking indegrees for all the nodes of the graph
            }
        } 
        for(int i=0;i<v;i++){
            if(indeg[i]==0){
                q.push(i);      //all nodes with indegree 0 into the queue
            }
        } 
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node); //the ones in queue have 0 adjency/remaining connnections , they are our answer , push to queue

            for(auto it:adj[node]){
                indeg[it]--;    //adjecent of the node in stack being visited , subtracted
                if(indeg[it]==0){
                    q.push(it); //indegree 0 , means adjency empty 
                }
            }
        }
        return topo;
    }
};
