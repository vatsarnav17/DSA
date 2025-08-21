class Solution{
public:
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s) {
        set<pair<int,int>> st;
        vector<int> dist(v,1e9);
        st.insert({0,s});  
        dist[s]=0;
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for(auto it:adj[node]){x
                int adjnode=it[0];
                int ewt = it[1];
                if(dis +ewt < dist[adjnode]){
                    if(dist[adjnode] != 1e9){
                        st.erase({dist[adjnode],adjnode});
                    }
                    dist[adjnode]=dis+ewt;
                    st.insert({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }
};