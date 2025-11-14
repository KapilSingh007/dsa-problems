class Solution {
    public:
        vector<int> approach1Tabulation(vector<int>& nums, int n) {
            vector<int> dp(n, 1), prev(n, -1), res;
            int mxSz = 1, mxInd = 0;
    
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if ((nums[i] % nums[j] == 0) && dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
    
                if (mxSz < dp[i]) {
                    mxSz = dp[i];
                    mxInd = i;
                }
            }
    
            while (mxInd != -1) {
                res.insert(res.begin(), nums[mxInd]);
                mxInd = prev[mxInd];
            }
    
            return res;
        }
    
        void approach2Recurrsion(vector<int>& nums, int n, int i, vector<int>& res,
                                 vector<int>& temp, int prev) {
    
            if (i == n) {
                if (res.size() < temp.size()) {
                    res = temp;
                }
                return;
            }
            if (prev == -1 || nums[i] % prev == 0) {
                temp.push_back(nums[i]);
                approach2Recurrsion(nums, n, i + 1, res, temp, nums[i]);
                temp.pop_back();
            }
    
            approach2Recurrsion(nums, n, i + 1, res, temp, prev);
        }
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
    
            // return approach1Tabulation(nums,n);
    
            // this approach is correct but it will give TLE in the last test cases and work for the most of the test cases
            // the reason for not use dp here is to because maintaing the array till certain index is little bit cucumbersome so for print use tabulation
            vector<int> res, temp;
            approach2Recurrsion(nums, n, 0, res, temp, -1);
            return res;
        }
    };