class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        long long ans = 0;

        sort(power.begin(), power.end());
        
        vector<pair<int,int>> vec;
        int same = 1;
        for(int i = 1; i < n; i++) {
            if(power[i-1] == power[i]) same++;
            else {
                vec.push_back({power[i-1], same});
                same = 1;
            }
        }
        vec.push_back({power[n-1], same});

        vector<long long> dp(3, 0);
        for(int i = 0; i < vec.size(); i++) {
            long long currAns = 1LL * vec[i].first * vec[i].second;

            if(i - 1 >= 0 && vec[i-1].first < vec[i].first - 2)
                currAns = max(currAns, dp[2] + 1LL * vec[i].first * vec[i].second);

            if(i - 2 >= 0 && vec[i-2].first < vec[i].first - 2)
                currAns = max(currAns, dp[1] + 1LL * vec[i].first * vec[i].second);

            if(i - 3 >= 0)
                currAns = max(currAns, dp[0] + 1LL * vec[i].first * vec[i].second);

            ans = max(ans, currAns);
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = max(currAns, ans);
        }

        return ans;
    }
};
