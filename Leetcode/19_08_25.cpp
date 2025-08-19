class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count = 0;
        for (int x : nums) {
            if (x == 0) {
                count++;       // extend zero streak
                ans += count;  // add new subarrays ending here
            } else {
                count = 0;     // reset streak
            }
        }
        return ans;
    }
};
