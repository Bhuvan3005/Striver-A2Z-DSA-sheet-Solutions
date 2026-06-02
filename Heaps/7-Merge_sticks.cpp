//takr to smallest stick , add them and push the result back to the heap

class Solution {
    public:
        int connectSticks(vector<int>& sticks) {
    
            priority_queue<
                int,
                vector<int>,
                greater<int>
            > pq;
    
            for(int x : sticks)
                pq.push(x);
    
            int ans = 0;
    
            while(pq.size() > 1) {
    
                int a = pq.top();
                pq.pop();
    
                int b = pq.top();
                pq.pop();
    
                int cost = a + b;
    
                ans += cost;
    
                pq.push(cost);
            }
    
            return ans;
        }
    };