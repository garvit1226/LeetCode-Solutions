
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        set<int> available;
        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {endTime, serverIndex}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> busy;

        vector<int> cnt(k, 0);

        for(int i = 0; i < arrival.size(); i++) {

            // Release all servers that have finished
            while(!busy.empty() &&
                  busy.top().first <= arrival[i]) {

                available.insert(busy.top().second);
                busy.pop();
            }

            if(available.empty()) continue;

            int target = i % k;

            // Find first available server >= target
            auto it = available.lower_bound(target);

            // If not found, wrap around to smallest index
            if(it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            available.erase(it);

            cnt[server]++;

            busy.push({arrival[i] + load[i], server});
        }

        int maxi = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(cnt[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
