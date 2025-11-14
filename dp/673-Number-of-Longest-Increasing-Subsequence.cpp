class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n, 1),temp(n,1);
            int mxSz = 1, res=0;
    
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] > nums[j]) {
                       
                        if (dp[i] < dp[j] + 1) {
                            dp[i] = dp[j] + 1;
                            temp[i] = temp[j];
                        }else if(dp[i] == dp[j] + 1){
                            temp[i] += temp[j];
                        }
                        
                    }
                }
    
                if (mxSz < dp[i]) {
                    mxSz = dp[i];
                }
               
            }
    
            for (int i = 0; i < n; i++) {
                if (dp[i] == mxSz) {
                    res += temp[i];
                }
            }
            return res;
        }
    };