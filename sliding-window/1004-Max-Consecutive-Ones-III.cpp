class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size(), res = 0;

        while (i < n) {
            if (nums[i] == 0) {
                if (k > 0) {
                    k--;
                } else {
                    while (k == 0) {
                        if (nums[j] == 0) {
                            k++;
                        }
                        j++;
                    }
                    k--;
                }
            }
            res = max(res, i - j + 1);
            i++;
        }
        return res;
    }
};