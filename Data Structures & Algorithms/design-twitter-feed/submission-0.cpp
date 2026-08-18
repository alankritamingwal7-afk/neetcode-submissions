#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Twitter {
    int ts; // timestamp counter
    unordered_map<int, unordered_set<int>> follows; // user -> followees
    unordered_map<int, vector<pair<int,int>>> tweets; // user -> list of (timestamp, tweetId)

public:
    Twitter() {
        ts = 0;
    }

    void postTweet(int userId, int tweetId) {
        ts++;
        tweets[userId].push_back({ts, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> maxh; // (timestamp, tweetId)

        // add user's own tweets
        for (auto &tw : tweets[userId]) {
            maxh.push(tw);
        }

        // add followees' tweets
        for (auto f : follows[userId]) {
            for (auto &tw : tweets[f]) {
                maxh.push(tw);
            }
        }

        vector<int> res;
        int count = 0;
        while (!maxh.empty() && count < 10) {
            res.push_back(maxh.top().second);
            maxh.pop();
            count++;
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // can't follow itself
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (follows.count(followerId)) {
            follows[followerId].erase(followeeId);
        }
    }
};

