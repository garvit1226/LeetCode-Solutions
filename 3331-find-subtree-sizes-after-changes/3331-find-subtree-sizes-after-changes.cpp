class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        vector<int> newParent(n, -1);
        vector<int> last(26, -1);

        
        stack<pair<int, bool>> st;
        st.push({0, false});

        while(!st.empty()) {
            auto [u, exit] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if(!exit) {
                
                newParent[u] = last[c];
                last[c] = u;

                st.push({u, true});

                for(int v : adj[u]) {
                    st.push({v, false});
                }
            }
            else {
                

                last[c] = newParent[u];

                int p = newParent[u];

                if(p == -1)
                    p = parent[u];

                if(p != -1) {
                    ans[p] += ans[u];
                }
            }
        }

        return ans;
    }
};