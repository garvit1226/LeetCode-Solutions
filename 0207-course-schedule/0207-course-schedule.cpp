class Solution {
public:

    bool helper(int node, vector<vector<int>>& adj, vector<int>& vis) {

        vis[node] = 1;  // currently visiting

        for(auto it : adj[node]) {

            if(vis[it] == 0) {
                if(helper(it, adj, vis))
                    return true;
            }

            else if(vis[it] == 1) {
                // cycle found
                return true;
            }
        }

        vis[node] = 2;  // completely processed

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto p : prerequisites) {
            // p[1] -> p[0]
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {

            if(vis[i] == 0) {

                if(helper(i, adj, vis))
                    return false;
            }
        }

        return true;
    }
};