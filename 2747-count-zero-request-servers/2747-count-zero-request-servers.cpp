class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int m = queries.size();
        vector<int> ans(m);

     
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

      
        vector<pair<int,int>> q;
        for(int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        unordered_map<int,int> mp;

        int left = 0, right = 0;

        for(auto &[time, idx] : q) {

         
            while(right < logs.size() && logs[right][1] <= time) {
                mp[logs[right][0]]++;
                right++;
            }

       
            while(left < right && logs[left][1] < time - x) {
                mp[logs[left][0]]--;

                if(mp[logs[left][0]] == 0) {
                    mp.erase(logs[left][0]);
                }

                left++;
            }

            ans[idx] = n - mp.size();
        }

        return ans;
    }
};