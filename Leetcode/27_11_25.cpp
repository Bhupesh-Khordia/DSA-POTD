class Solution {
    const long long INF = 1e15;
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPref(k, INF);
        minPref[0] = 0;
        long long ans = -INF, currPref = 0;
        for(int i = 1; i <= n; i++) {
            int rem = i % k;
            currPref += nums[i-1];
            ans = max(ans, currPref - minPref[rem]);
            minPref[rem] = min(minPref[rem], currPref);
        }
        return ans;
    }
};
