class disjoint{
public:
    vector<int> rank,parent;
    disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int finduparent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = finduparent(parent[node]);
    }

    void unionbyrank(int u, int v){
        int ulp_u = finduparent(u);
        int ulp_v = finduparent(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_v]<rank[ulp_u]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjoint ds(n);
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail] = i;
                }
                else{
                    ds.unionbyrank(i,mpp[mail]);
                }
            }
        }

        vector<string> merged[n];
        for(auto it : mpp){
            string mail = it.first;
            int node = ds.finduparent(it.second);
            merged[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};