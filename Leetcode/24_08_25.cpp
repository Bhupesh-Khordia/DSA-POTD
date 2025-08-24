class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> cnt(2, 0);

        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0;
        while(j < n) {
            cnt[nums[j++]]++;
            while(cnt[0] > 1) {
                cnt[nums[i++]]--;
            }
            ans = max(ans, cnt[0] == 0 ? cnt[1] - 1: cnt[1]);
        }

        return ans;
    }
};
