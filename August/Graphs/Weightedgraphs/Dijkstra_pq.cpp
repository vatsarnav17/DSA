class Solution{
public:
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(v,1e9);
        dist[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int wt=it[1];
                int adjnode=it[0];
                if(dis+wt<dist[adjnode]){
                    dist[adjnode]=dis+wt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }
};