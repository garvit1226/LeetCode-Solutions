class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if (hand.size() % groupSize != 0)
            return false;

        unordered_map<int, int> mp;

        for (int x : hand) {
            mp[x]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto it : mp) {
            pq.push(it.first);
        }

        while (!pq.empty()) {

            int start = pq.top();

            for (int i = 0; i < groupSize; i++) {

                int x = start + i;

                if (mp[x] == 0)
                    return false;

                mp[x]--;
            }

            
            while (!pq.empty() && mp[pq.top()] == 0) {
                pq.pop();
            }
        }

        return true;
    }
};