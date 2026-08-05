class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        vector<bool> check(n, false);

        for(auto& edge: invocations){
            int u= edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        // bfs
        queue<int> que;
        que.push(k);
        check[k] = true;

        while(!que.empty()){
            int curr = que.front();
            que.pop();
            for(int& ngb : adj[curr]){
                indeg[ngb]--;
                if(!check[ngb]){
                    que.push(ngb);
                    check[ngb]= true;
                }
            }
        }

        vector<int> ans;
        bool temp= false;
        for(int i=0;i<n;i++){
            if(check[i] && indeg[i]>0){
                temp= true;
                break;

            }
            if(!check[i]){
                ans.push_back(i);
            }
        }
        if(temp){
            vector<int> res;
            for(int i=0;i<n;i++){
                res.push_back(i);
            }
            return res;
        }
        else{
        return ans;
        }


    }
};