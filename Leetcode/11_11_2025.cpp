class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // dp[k][i][j]=maximum number of strings we can form using the first k strings, with at most i zeros and j ones.

        for (int k = 1; k <= sz; k++) {
            int cntZeroes = 0, cntOnes = 0;
            for (char c : strs[k - 1]) {
                if (c == '0') cntZeroes++;
                else cntOnes++;
            }

            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    dp[k][i][j] = dp[k - 1][i][j];  // skip current string
                    if (i >= cntZeroes && j >= cntOnes)
                        dp[k][i][j] = max(dp[k][i][j],
                                          dp[k - 1][i - cntZeroes][j - cntOnes] + 1);
                }
            }
        }

        return dp[sz][m][n];
    }
};
