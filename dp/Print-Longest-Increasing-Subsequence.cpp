class Solution {
    public:
        vector<int> approach1Tabulation(vector<int>& arr, int n) {
    
            vector<int> dp(n, 1);
            vector<vector<int>> vt(n);
            int mx = 0;
            vector<int> res, temp;
    
            for (int i = 0; i < n; i++) {
    
                temp = {arr[i]};
                for (int j = 0; j < i; j++) {
                    if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        temp = {arr[i]};
                        temp.insert(temp.begin(), vt[j].begin(), vt[j].end());
                    }
                }
    
                vt[i] = temp;
                if (temp.size() > mx) {
                    res = temp;
                    mx = temp.size();
                }
            }
    
            return res;
        }

        vector<int> approach2Tabulation(vector<int>& arr, int n) {

            vector<int> dp(n, 1),prevInd(n,-1);
         
            int mx = 1,mxInd=0;
            vector<int> res;
    
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prevInd[i] = j;
                    }
                }
    
                if(mx<dp[i]){
                    mx = dp[i];
                    mxInd = i;
                }
            }
            
            while(mxInd != -1){
                res.insert(res.begin(),arr[mxInd]);
                mxInd = prevInd[mxInd];
            }
           
    
            return res;
        }
        vector<int> getLIS(vector<int>& arr) {
            // Code here
            int n = arr.size();
    
           // below approach is corrent but it will give TLE in the last test cases and work for the most of the test cases
            // return approach1Tabulation(arr, n);


            return approach2Tabulation(arr, n);

        }
    };