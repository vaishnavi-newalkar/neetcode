class Twitter {
public:
    int timer;

    unordered_map<int, unordered_set<int>> users;
    unordered_map<int, vector<pair<int,int>>> tweets;

    struct Node {
        int time;
        int tweetId;
        int userId;
        int idx;

        bool operator<(const Node &other) const {
            return time < other.time;      // Max Heap
        }
    };

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timer, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<Node> pq;

        // Push user's latest tweet
        if (!tweets[userId].empty()) {
            int idx = tweets[userId].size() - 1;
            pq.push({tweets[userId][idx].first,
                     tweets[userId][idx].second,
                     userId,
                     idx});
        }

        // Push latest tweet of each followee
        for (int followee : users[userId]) {
            if (!tweets[followee].empty()) {
                int idx = tweets[followee].size() - 1;
                pq.push({tweets[followee][idx].first,
                         tweets[followee][idx].second,
                         followee,
                         idx});
            }
        }

        while (!pq.empty() && ans.size() < 10) {
            Node cur = pq.top();
            pq.pop();

            ans.push_back(cur.tweetId);

            // Push previous tweet of the same user
            if (cur.idx > 0) {
                int newIdx = cur.idx - 1;
                pq.push({
                    tweets[cur.userId][newIdx].first,
                    tweets[cur.userId][newIdx].second,
                    cur.userId,
                    newIdx
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        users[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId);
    }
};