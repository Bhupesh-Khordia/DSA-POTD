class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<vector<long long>> dp(2, vector<long long>(n+1, 0));

        // Base case: first wizard brews all potions
        for (int i = 0; i < n; ++i)
            dp[0][i+1] = dp[0][i] + 1LL * mana[0] * skill[i];

        // Process remaining wizards
        for (int i = 1; i < m; ++i) {
            dp[1][0] = dp[0][1];
            long long error = 0;

            for (int j = 0; j < n; ++j) {
                dp[1][j+1] = dp[1][j] + 1LL * mana[i] * skill[j];
                error = max(error, dp[0][j+1] - dp[1][j]);
            }

            for (int j = 0; j <= n; ++j)
                dp[0][j] = dp[1][j] + error;
        }

        return dp[0][n];
    }
};
