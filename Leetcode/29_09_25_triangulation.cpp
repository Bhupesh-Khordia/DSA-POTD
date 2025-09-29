class Solution {
private:
    // Recursion Solulu
    int solveRec (vector<int>& values, int i, int j) {
        // Base Case - You need atleast 3 edges for trangulation
        if(j <= i + 1) {
            return 0;
        }

        int ans = INT_MAX;
        for(int x = i + 1; x < j; x++) {
            int temp = values[i] * values[j] * values[x];
            ans = min (ans, temp + solveRec(values, i, x) + solveRec(values, x, j));
        }
        return ans;
    }

    // DP Solulu
    int solveDP (vector<int>& values, int i, int j, vector<vector<int>> &dp) {
        // Base Case - You need atleast 3 edges for trangulation
        if(j <= i + 1) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int x = i + 1; x < j; x++) {
            int temp = values[i] * values[j] * values[x];
            ans = min (ans, temp + solveDP(values, i, x, dp) + solveDP(values, x, j, dp));
        }
        return dp[i][j] = ans;
    }

    // Tabulation Solulu
    int solveTab(vector<int>& values) {
        int n = values.size();

        vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 2; j < n; j++) {
                int ans = INT_MAX;
                for(int x = i + 1; x < j; x++) {
                    int temp = values[i] * values[j] * values[x];
                    ans = min (ans, temp + dp[i][x] + dp[x][j]);
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][n-1];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        // Recursion Solulu

        // int n = values.size();
        // return solveRec(values, 0, n - 1);


        // DP Solulu

        // int n = values.size();
        // vector<vector<int>> dp (n + 1, vector<int> (n + 1, -1));
        // return solveDP(values, 0, n - 1, dp);


        // Tabulation Solulu

        return solveTab(values);
    }
};
