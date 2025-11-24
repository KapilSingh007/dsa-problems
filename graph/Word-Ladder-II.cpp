// User function Template for C++

class Solution {
    public:
      vector<vector<string>> findSequences(string b, string e, vector<string>& w) {
          // code here
          
          int n = b.size(), qSz, minLen = -1, currVtSize;
          vector<vector<string>> res;
          unordered_set<string> st(w.begin(), w.end()),
              tempSt(w.begin(), w.end());
  
          queue<pair<vector<string>, int>> q;
          pair<vector<string>, int> topEle;
          string last, modified;
          vector<string> modifiedVt;
  
          q.push({{b}, 1});
  
          while (!q.empty()) {
              qSz = q.size();
              while (qSz--) {
                  topEle = q.front();
                  q.pop();
                  currVtSize = topEle.second;
                  last = topEle.first[currVtSize - 1];
  
                  if (last == e && (minLen == -1 || currVtSize == minLen)) {
                      res.push_back(topEle.first);
                      minLen = currVtSize;
                  }
  
                  for (int j = 0; j < n; j++) {
                      modified = last;
                      for (char i = 'a'; i <= 'z'; i++) {
                          modified[j] = i;
                          if (st.find(modified) != st.end()) {
                              tempSt.erase(modified);
                              modifiedVt = topEle.first;
                              modifiedVt.push_back(modified);
                              q.push({modifiedVt, currVtSize + 1});
                          }
                      }
                  }
              }
  
              st = tempSt;
          }
  
          return res;
          
      }
  };