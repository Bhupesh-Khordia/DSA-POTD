class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> dp(n+1), pref(n+1);
        dp[0] = pref[0] = 1;

        deque<int> minD, maxD;
        int L = 0;

        for (int i = 0; i < n; i++) {
            while (!minD.empty() && nums[minD.back()] > nums[i]) minD.pop_back();
            minD.push_back(i);
            while (!maxD.empty() && nums[maxD.back()] < nums[i]) maxD.pop_back();
            maxD.push_back(i);

            while (L <= i && nums[maxD.front()] - nums[minD.front()] > k) {
                if (minD.front() == L) minD.pop_front();
                if (maxD.front() == L) maxD.pop_front();
                L++;
            }

            dp[i+1] = pref[i] - (L > 0 ? pref[L-1] : 0);
            dp[i+1] = (dp[i+1] % MOD + MOD) % MOD;
            pref[i+1] = (pref[i] + dp[i+1]) % MOD;
        }

        return dp[n];
    }
};
