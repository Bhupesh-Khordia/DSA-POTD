class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prev = 0, curr = 1;
        int longest = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] >= nums[i]) {
                prev = curr;
                curr = 1;
            }
            else ++curr;

            longest = max(longest, min(prev, curr));
            longest = max(longest, curr >> 1);
        }

        return longest >= k;
    }
};
