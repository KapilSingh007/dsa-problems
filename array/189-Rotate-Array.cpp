class Solution {
    public:
        void rotate(vector<int>& nums, int k) {

            int n = nums.size();
            k = k % n;
            //method 1
            if (k == 0 || k >= n) {
                return;
            }
            vector<int> temp;
    
            for (int i = 1; i <= k; i++) {
                temp.push_back(nums[n - i]);
            }
    
            int i = n - k - 1;
            while (i >= 0) {
                nums[i + k] = nums[i];
                i--;
            }
    
            for (int i = 0; i < k; i++) {
                nums[k - 1 - i] = temp[i];
            }
    
            return;// method 2 bases on reversing the array

            reverseArrayByIndex(nums, 0, n - k - 1);
            reverseArrayByIndex(nums, n - k, n - 1);
            reverseArrayByIndex(nums, 0, n - 1);
        }
    
        void reverseArrayByIndex(vector<int>& nums, int i, int j) {
            int temp;
            while (i < j) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
    
                i++;
                j--;
            }
        }
    };