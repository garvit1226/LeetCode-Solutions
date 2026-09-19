class disjoint{
public:
    vector<int> rank,parent;
    disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjoint ds(n);
        int extra =0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.finduparent(u)==ds.finduparent(v)){
                extra++;
            }
            else{
                ds.unionbyrank(u,v);
            }
        }
        int com =0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) com++;
        }
        int ans = com-1;
        if(extra>=ans) return ans;
        else return -1;
    }
};