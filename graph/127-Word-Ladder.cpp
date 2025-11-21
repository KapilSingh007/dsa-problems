class Solution {
    public:
        int ladderLength(string b, string e, vector<string>& w) {
            int n = b.size(), l = w.size();
            string word, temp;
            unordered_set<string> st(w.begin(), w.end());
    
            queue<pair<string, int>> q;
    
            q.push({b, 1});
            st.erase(b);
    
            while (!q.empty()) {
                word = q.front().first;
                if (word == e) {
                    return q.front().second;
                }
    
                for (int j = 0; j < n; j++) {
    
                    temp = word;
                    for (char i = 'a'; i <= 'z'; i++) {
    
                        temp[j] = i;
    
                        if (st.find(temp) != st.end()) {
                            q.push({temp, q.front().second + 1});
                            st.erase(temp);
                        }
                    }
                }
                q.pop();
            }
    
            return 0;
        }
    };