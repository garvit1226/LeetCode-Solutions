class Twitter {
public:

    int time = 0;

    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int, int>> pq;

        
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);
        }

        
        for (int user : following[userId]) {

            for (auto tweet : tweets[user]) {
                pq.push(tweet);
            }
        }

        vector<int> ans;

        
        while (!pq.empty() && ans.size() < 10) {

            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        if (followerId == followeeId)
            return;

        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};