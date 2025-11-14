class Solution {
    public:
        vector<int> tabulation(vector<int>& nums,int n){
    
            sort(nums.begin(),nums.end());
            vector<int> dp(n,1),prev(n,-1),res;
            int mxSz = 1, mxInd =0;
    
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    if((nums[i]%nums[j] == 0) && dp[i]<dp[j]+1){
                        dp[i] =dp[j]+1;
                        prev[i] = j;
                    }
                }
    
                if(mxSz < dp[i]){
                    mxSz = dp[i];
                    mxInd = i;
                }
            }
    
            while(mxInd != -1){
                res.insert(res.begin(),nums[mxInd]);
                mxInd = prev[mxInd];
            }
    
            return res;
    
        }
        vector<int> largestDivisibleSubset(vector<int>& nums) {
    
            int n = nums.size();
    
            return tabulation(nums,n);
        }
    };