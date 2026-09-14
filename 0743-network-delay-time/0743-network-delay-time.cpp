class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int node = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            for(auto it: adj[node]){
                int child = it.first;
                int ewd = it.second;

                if(w+ ewd < dist[child]){
                    dist[child]= w+ewd;
                    pq.push({w+ewd,child});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};