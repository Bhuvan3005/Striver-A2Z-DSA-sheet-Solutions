class Solution {
    public:
        string reorganizeString(string s) {
    
            vector<int> freq(26, 0);
    
            for(char ch : s)
                freq[ch - 'a']++;
    
            priority_queue<pair<int,char>> pq;
    
            for(int i = 0; i < 26; i++) {
                if(freq[i] > 0)
                    pq.push({freq[i], char('a' + i)});
            }
    
            string ans;
    
            pair<int,char> prev = {0, '#'}; // {remaining_freq, character}
    
            while(!pq.empty()) {
    
                auto [cnt, ch] = pq.top();
                pq.pop();
    
                ans += ch;
                cnt--;
    
                // Previous character becomes available again
                if(prev.first > 0)
                    pq.push(prev);
    
                prev = {cnt, ch};
            }
    
            if(ans.size() != s.size())
                return "";
    
            return ans;
        }
    };