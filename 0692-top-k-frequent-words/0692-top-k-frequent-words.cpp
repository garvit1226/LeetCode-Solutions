
class Solution {

public:

    struct compare {
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            if (a.second == b.second)
                return a.first < b.first;

            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        priority_queue<
            pair<string, int>,
            vector<pair<string, int>>,
            compare
        > pq;

        for (auto& it : mp) {
            pq.push({it.first, it.second});

            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};