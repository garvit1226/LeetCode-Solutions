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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol =0;
        for(auto it:stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }
        disjoint ds(maxrow + maxcol+1);
        set<int> nodes;
        for(auto it :stones){
            int row = it[0];
            int col = it[1] + maxrow +1;
            ds.unionbyrank(row,col);
            nodes.insert(row);
            nodes.insert(col);
        }

        int com=0;
        for(auto i : nodes){
            if(ds.parent[i]==i) com++;
        }
        return stones.size()-com;
    }
};