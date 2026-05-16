/*
    Problem: Word Ladder
    Approach: BFS + String Transformation

    Time Complexity  : O(N * WordLength * 26)
    Space Complexity : O(N)
*/

class Solution {
    public:
    
        int ladderLength(string beginWord,
                         string endWord,
                         vector<string>& wordList) {
    
            queue<pair<string, int>> q;
    
            set<string> st(wordList.begin(), wordList.end());
    
            st.erase(beginWord);
    
            q.push({beginWord, 1});
    
            // BFS Traversal
            while (!q.empty()) {
    
                string word = q.front().first;
    
                int step = q.front().second;
    
                q.pop();
    
                // Reached Target Word
                if (word == endWord) {
                    return step;
                }
    
                // Try Replacing Every Character
                for (int i = 0; i < word.size(); i++) {
    
                    char original = word[i];
    
                    for (char ch = 'a'; ch <= 'z'; ch++) {
    
                        word[i] = ch;
    
                        // Valid Transformation
                        if (st.find(word) != st.end()) {
    
                            st.erase(word);
    
                            q.push({word, step + 1});
                        }
                    }
    
                    // Restore Original Character
                    word[i] = original;
                }
            }
    
            return 0;
        }
    };