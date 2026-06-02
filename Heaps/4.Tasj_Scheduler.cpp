class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            vector<int> count(26, 0);
            for (char task : tasks) {
                count[task - 'A']++;
            }
    
            priority_queue<int> pq;
            for (int freq : count) {
                if (freq > 0) pq.push(freq);
            }
    
            queue<pair<int, int>> cooldown; // {remaining freq, next valid time}
            int time = 0;
    
            while (!pq.empty() || !cooldown.empty()) {
                time++;
    
                // Release task from cooldown if it's time
                if (!cooldown.empty() && cooldown.front().second == time) {
                    pq.push(cooldown.front().first);
                    cooldown.pop();
                }
    
                // Run task if available
                if (!pq.empty()) {
                    int freq = pq.top(); pq.pop();
                    if (--freq > 0) {
                        cooldown.push({freq, time + n + 1});
                    }
                }
                // else: no task available to run -> idle
            }
    
            return time;
        }
    };
    