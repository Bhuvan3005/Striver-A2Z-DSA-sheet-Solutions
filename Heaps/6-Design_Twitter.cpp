class Twitter {
    private:
    
        unordered_map<int, unordered_set<int>> follows;
        unordered_map<int, vector<pair<int,int>>> tweets;
    
        int timestamp;
    
    public:
        Twitter() {
            timestamp = 0;
        }
    
        void postTweet(int userId, int tweetId) {
            tweets[userId].push_back({timestamp++, tweetId});
        }
    
        //like K-sorted linked list
        //store index of a particular vector to get the next value like linked list ->next
        
        vector<int> getNewsFeed(int userId) {
    
            vector<int> ans;
    
            priority_queue<vector<int>> pq;
    
            if(tweets.count(userId) && !tweets[userId].empty()) {
                int idx = tweets[userId].size() - 1;
    
                pq.push({
                    tweets[userId][idx].first,  
                    tweets[userId][idx].second, 
                    userId,
                    idx
                });
            }
    
            for(int followee : follows[userId]) {
    
                if(tweets.count(followee) && !tweets[followee].empty()) {
    
                    int idx = tweets[followee].size() - 1;
    
                    pq.push({
                        tweets[followee][idx].first,
                        tweets[followee][idx].second,
                        followee,
                        idx
                    });
                }
            }
    
            while(!pq.empty() && ans.size() < 10) {
    
                auto cur = pq.top();
                pq.pop();
    
                int tweetId = cur[1];
                int uid = cur[2];
                int idx = cur[3];
    
                ans.push_back(tweetId);
    
                idx--;
    
                if(idx >= 0) {
                    pq.push({
                        tweets[uid][idx].first,
                        tweets[uid][idx].second,
                        uid,
                        idx
                    });
                }
            }
    
            return ans;
        }
        
        void follow(int followerId, int followeeId) {
            follows[followerId].insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            follows[followerId].erase(followeeId);
        }
    };
    
    /**
     * Your Twitter object will be instantiated and called as such:
     * Twitter* obj = new Twitter();
     * obj->postTweet(userId,tweetId);
     * vector<int> param_2 = obj->getNewsFeed(userId);
     * obj->follow(followerId,followeeId);
     * obj->unfollow(followerId,followeeId);
     */